/**
 * \mainpage
 * <br>
 * <h3>Fall 2012
 * <br>ENGI-4557-FA Digital Communications
 * <br>
 * <br>Button. The LZW Compression Project.
 * <br>
 * </h3>
 * <b>Submitted to: Dr. Naser</b>
 * <br>
 * <br>
 * <b>By: Gordon Wallace</b>
 * <br>
 * \section intro_sec Introduction
 *
 * <b>Button</b> is a file compression and archiving utility which uses LZW compression to
 * reduce file size.  The LZW algorithm uses codewords to represent repeated
 * byte sequences in an input file.  These codewords can be much shorter than the sequences they
 * represent, thus achieving data compression.  The nature of the LZW compression algorithm enables 
 * runtime discovery of
 * the code-to-sequence mappings during the decompression process, which further supports compression
 * as there is no need to explicitly include a separate code mapping table in the compressed file.
 * <p>
 * This implementation of LZW uses a variable code length to achieve an even higher compression 
 * ratio.  Starting with a minimum codeword size of 9 bits, codeword length is increased only as
 * required by corresponding code values.  For example, codes from 256 to 511 require only nine bits
 * to be represented in binary.  Codes from 512 to 1023 require only 10 bits.  
 * <p>
 * Consider the case where a sequence consists of two characters. These two characters normally require
 * 16 bits of space in a file, at 8 bits per character.  If a codeword that is 9 bits long can be 
 * substituted for those two characters, the space required to store the value drops to 56% of the 
 * original amount.  This significantly increases the compression ratio provided by the most 
 * simple implementation of the algorithm which, assuming a minimum codeword size of 16 bits, would need
 * each codeword to represent at least 3 characters each before compression could be achieved.
 *
 * \section usage_sec Usage
 * Compression and decompression are provided by the following member functions of the Button class:
 * <p>
 * void Button::compress (std::istream &source, std::ostream &target)
 * <p>
 * void Button::decompress (std::istream &source, std::ostream &target)
 * <p>
 * Archive creation and extraction is provided by the Archiver class, which ultimately 
 * serves the high level functions of the user interface implemented in the Gui class.
 */