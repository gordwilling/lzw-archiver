#include "Main.h"
#include "ArchiverException.h"
#include "ui/Gui.h"

IMPLEMENT_APP(Main)

bool Main::OnInit()
{
	wxInitAllImageHandlers();
    Gui* dialog = new Gui();
    dialog->Show();
    SetTopWindow(dialog);
    return true;
}

const bool Main::IsArchiveLoaded()
{
    return archiver().descriptor().entries().size() != 0;
}

void Main::OpenArchive(const std::string& archivePath)
{
	archiver().Load( archivePath );
}

void Main::NewArchive(const std::string& archivePath )
{
    archiver().New( archivePath );
}

void Main::ExtractArchive(const std::string& targetDirectory )
{
	if ( IsArchiveLoaded() )
	{
		archiver().Extract( targetDirectory );
	}
	else
	{        
		throw ArchiverException( "Unable to locate .pants" );
	}
}

void Main::AddToArchive(const std::string& filePath, const std::string& fileName)
{
    archiver().AddFile( filePath, fileName );
}

void Main::SaveArchive()
{
	archiver().Save(); 
}