///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIBASE_H__
#define __GUIBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/gbsizer.h>
#include <wx/stattext.h>
#include <wx/grid.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GuiBase
///////////////////////////////////////////////////////////////////////////////
class GuiBase : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			wxID_FRAME = 1000,
			wxID_MITM_NEW,
			wxID_MITM_OPEN,
			wxID_MITM_EXIT,
			wxID_TOOL_COMPRESS,
			wxID_TOOL_EXTRACT,
			wxID_TOOL_ABOUT
		};
		
		wxMenuBar* m_menubar1;
		wxMenu* mnuFile;
		wxStatusBar* statusBar;
		wxToolBar* toolBarLeft;
		wxToolBar* toolBarRight;
		wxStaticLine* m_staticline16;
		wxStaticText* lblCurrentFile;
		wxStaticLine* m_staticline15;
		wxGrid* grid;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFileNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCompress( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExpand( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GuiBase( wxWindow* parent, wxWindowID id = wxID_FRAME, const wxString& title = wxT("button"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 776,654 ), long style = wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~GuiBase();
	
};

#endif //__GUIBASE_H__
