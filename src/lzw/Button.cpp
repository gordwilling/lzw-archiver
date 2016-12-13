#include "Button.h"
#include "ButtonOutputStream.h"
#include "UnButtonInputStream.h"

unsigned long long Button::compress( std::istream &source, ButtonOutputStream &target )
{
    unsigned long long bytesWritten = 0;    

	// this map will track the unique character sequences encountered during 
	// traversal of the input stream, binding each to a unique integer code
	code_map_t codeMap;
	initCodeMap( codeMap );

    // as we're starting with a new code map, 
    // reset the target stream's code length
    target.resetCodeLength();

	// maintains the code for the next unique character sequence 
	unsigned int nextCode = codeMap.size() + 1;	
	std::string s;
	char c;

    while ( source.get( c ) )
	{
		// build up a character sequence until we find one that isn't in
		// the sequence map
		s = s + c;
		if ( codeMap.count( s ) == 0 )
		{
			// the current character sequence is not in the map.
			// add it to the map, bound to the next sequence number
			if ( nextCode <= MAX_CODE )
			{
				codeMap.insert( code_map_value_t( s, nextCode++ ) );
			}
			
			// now write the code corresponding to the prior sequence to the
			// output stream. the prior sequence is the same as the current
			// sequence, minus the last character.
			bytesWritten += target.put( codeMap[s.substr( 0, s.size() - 1 )] );
			
			// the most recent sequence ended with the most recently read character.
			// start a brand new sequence, this time starting with the most recently read
			// character
			s = c;
		}
	}

	if ( !s.empty() )
	{
		// all the sequences and codes have been placed in the map, but the most recently 
		// generated code has not yet been written to the output stream. do that here,
		// and also write the end of file indicator
		bytesWritten += target.put( codeMap[s] );
		bytesWritten += target.put( END_OF_FILE );
	}

	return bytesWritten;
}

void Button::decompress( UnButtonInputStream &source, std::ostream &target )
{
	// this map will track the codes encountered during traversal of the input 
	// stream and enable reconstruction and subsequent tracking of the patterns 
	// they represent
	pattern_map_t patternMap;
	initPatternMap( patternMap );

    // reset the code length used by the source stream so it's
    // in sync with the pattern map
    source.resetCodeLength();

	// maintains the code for the next unique character sequence 
	unsigned int nextCode = patternMap.size() + 1;
	unsigned int code;
	std::string previousPattern;

	while ( source.get( code ) != END_OF_FILE )
	{
		if ( patternMap.count( code ) == 0 )
		{
			// although infrequent, sometimes we encounter a code in the input stream that
			// has not already been inserted into the pattern map. This occurs when the code 
			// encountered comes immediately after the last code in the pattern map created in
			// the encoding stage.  From the encoding algorithm, we know that this pattern is the 
			// same as the previous pattern, plus its first character
			patternMap.insert( pattern_map_value_t( code, previousPattern + previousPattern[0] ) );
		}

		if ( !previousPattern.empty() && nextCode <= MAX_CODE )
		{
			// this is the usual case. the next pattern consists of the previous 
			// pattern, plus the first character of the current pattern
			patternMap.insert( pattern_map_value_t( nextCode++, previousPattern + patternMap[code][0] ) ); 
		}
		
		previousPattern = patternMap[code];		
		target << previousPattern;
	}    
}

void Button::initCodeMap( code_map_t &codeMap )
{
	// the first 256 "patterns" are actually single characters, and their corresponding codes are 
	// the same as their ASCII codes. during both compression and decompression, the first character 
	// read from the input stream is guaranteed to match one of these.
	for ( unsigned int code = 0; code < INITIAL_MAP_SIZE; code++ )
	{
		codeMap.insert( code_map_value_t( std::string( 1, static_cast<char>(code) ), code ) );	
	}
}

void Button::initPatternMap( pattern_map_t &patternMap )
{
	// maps the first 256 codes to their patterns
	for ( unsigned int code = 0; code < INITIAL_MAP_SIZE; code++ )
	{
		patternMap.insert( pattern_map_value_t( code, std::string( 1, static_cast<char>(code) ) ) );	
	}
}