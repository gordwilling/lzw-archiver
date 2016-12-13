///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GuiBase.h"

#include "../../resources/button_about.png.h"
#include "../../resources/button_create_text.png.h"
#include "../../resources/button_extract_text.png.h"
#include "../../resources/close.png.h"
#include "../../resources/new.png.h"
#include "../../resources/open.png.h"

///////////////////////////////////////////////////////////////////////////

GuiBase::GuiBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	this->SetToolTip( wxT("Button. A File Compression and Archiving Utility") );
	
	m_menubar1 = new wxMenuBar( 0 );
	m_menubar1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_menubar1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	mnuFile = new wxMenu();
	wxMenuItem* mitmNew;
	mitmNew = new wxMenuItem( mnuFile, wxID_MITM_NEW, wxString( wxT("&New") ) + wxT('\t') + wxT("Ctrl+N"), wxT("Creates a new archive."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	mitmNew->SetBitmaps( new_png_to_wx_bitmap() );
	#elif defined( __WXGTK__ )
	mitmNew->SetBitmap( new_png_to_wx_bitmap() );
	#endif
	mnuFile->Append( mitmNew );
	
	wxMenuItem* mitmOpen;
	mitmOpen = new wxMenuItem( mnuFile, wxID_MITM_OPEN, wxString( wxT("&Open") ) + wxT('\t') + wxT("Ctrl+O"), wxT("Opens an existing archive."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	mitmOpen->SetBitmaps( open_png_to_wx_bitmap() );
	#elif defined( __WXGTK__ )
	mitmOpen->SetBitmap( open_png_to_wx_bitmap() );
	#endif
	mnuFile->Append( mitmOpen );
	
	mnuFile->AppendSeparator();
	
	wxMenuItem* mitmExit;
	mitmExit = new wxMenuItem( mnuFile, wxID_MITM_EXIT, wxString( wxT("E&xit") ) , wxT("Exits the application."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	mitmExit->SetBitmaps( close_png_to_wx_bitmap() );
	#elif defined( __WXGTK__ )
	mitmExit->SetBitmap( close_png_to_wx_bitmap() );
	#endif
	mnuFile->Append( mitmExit );
	
	m_menubar1->Append( mnuFile, wxT("File") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	statusBar->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	statusBar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	statusBar->SetToolTip( wxT("Status Bar") );
	
	wxBoxSizer* bSizerTop;
	bSizerTop = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerToolbars;
	bSizerToolbars = new wxBoxSizer( wxHORIZONTAL );
	
	toolBarLeft = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	toolBarLeft->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	toolBarLeft->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	toolBarLeft->AddSeparator(); 
	
	toolBarLeft->AddTool( wxID_TOOL_COMPRESS, wxT("Create"), button_create_text_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxT("Create an Archive"), wxT("Create an Archive"), NULL ); 
	
	toolBarLeft->AddSeparator(); 
	
	toolBarLeft->AddTool( wxID_TOOL_EXTRACT, wxT("Extract"), button_extract_text_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxT("Extract the Current Archive"), wxT("Extract the Current Archive"), NULL ); 
	
	toolBarLeft->Realize(); 
	
	bSizerToolbars->Add( toolBarLeft, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	
	bSizerToolbars->Add( 0, 0, 0, wxALIGN_BOTTOM, 0 );
	
	toolBarRight = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	toolBarRight->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	toolBarRight->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	toolBarRight->AddTool( wxID_TOOL_ABOUT, wxT("About Button"), button_about_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxT("About Button"), wxT("About Button"), NULL ); 
	
	toolBarRight->AddSeparator(); 
	
	toolBarRight->Realize(); 
	
	bSizerToolbars->Add( toolBarRight, 0, wxEXPAND, 5 );
	
	
	bSizerTop->Add( bSizerToolbars, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND, 1 );
	
	m_staticline16 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline16->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_staticline16->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	bSizerTop->Add( m_staticline16, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* gbSizer4;
	gbSizer4 = new wxGridBagSizer( 0, 0 );
	gbSizer4->SetFlexibleDirection( wxBOTH );
	gbSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	bSizer6->Add( gbSizer4, 0, wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer5;
	gbSizer5 = new wxGridBagSizer( 0, 0 );
	gbSizer5->SetFlexibleDirection( wxBOTH );
	gbSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	lblCurrentFile = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 538,-1 ), 0 );
	lblCurrentFile->Wrap( -1 );
	lblCurrentFile->SetFont( wxFont( 10, 74, 90, 90, false, wxT("Arial") ) );
	lblCurrentFile->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	lblCurrentFile->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	lblCurrentFile->SetToolTip( wxT("Location of currently loaded archive") );
	
	gbSizer5->Add( lblCurrentFile, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	bSizer6->Add( gbSizer5, 0, wxEXPAND, 5 );
	
	
	bSizerTop->Add( bSizer6, 0, wxEXPAND, 5 );
	
	m_staticline15 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline15->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_staticline15->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	bSizerTop->Add( m_staticline15, 0, wxEXPAND | wxALL, 5 );
	
	grid = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxNO_BORDER|wxVSCROLL );
	
	// Grid
	grid->CreateGrid( 0, 5 );
	grid->EnableEditing( false );
	grid->EnableGridLines( true );
	grid->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	grid->EnableDragGridSize( false );
	grid->SetMargins( 0, 0 );
	
	// Columns
	grid->SetColSize( 0, 457 );
	grid->SetColSize( 1, 84 );
	grid->SetColSize( 2, 114 );
	grid->SetColSize( 3, 41 );
	grid->SetColSize( 4, 35 );
	grid->EnableDragColMove( false );
	grid->EnableDragColSize( true );
	grid->SetColLabelSize( 20 );
	grid->SetColLabelValue( 0, wxT("File Name") );
	grid->SetColLabelValue( 1, wxT(" Original Size") );
	grid->SetColLabelValue( 2, wxT(" Compressed Size") );
	grid->SetColLabelValue( 3, wxT(" Ratio") );
	grid->SetColLabelValue( 4, wxT("    %") );
	grid->SetColLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Rows
	grid->AutoSizeRows();
	grid->EnableDragRowSize( true );
	grid->SetRowLabelSize( 0 );
	grid->SetRowLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Label Appearance
	grid->SetLabelBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	grid->SetLabelFont( wxFont( 10, 70, 90, 90, false, wxT("Arial") ) );
	grid->SetLabelTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	// Cell Defaults
	grid->SetDefaultCellBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	grid->SetDefaultCellTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	grid->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	grid->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	grid->SetToolTip( wxT("Contents of current archive") );
	
	bSizerTop->Add( grid, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerTop );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( mitmNew->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GuiBase::OnFileNew ) );
	this->Connect( mitmOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GuiBase::OnFileOpen ) );
	this->Connect( mitmExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GuiBase::OnFileExit ) );
	this->Connect( wxID_TOOL_COMPRESS, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GuiBase::OnCompress ) );
	this->Connect( wxID_TOOL_EXTRACT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GuiBase::OnExpand ) );
	this->Connect( wxID_TOOL_ABOUT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GuiBase::OnAbout ) );
}

GuiBase::~GuiBase()
{
	// Disconnect Events
	this->Disconnect( wxID_MITM_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GuiBase::OnFileNew ) );
	this->Disconnect( wxID_MITM_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GuiBase::OnFileOpen ) );
	this->Disconnect( wxID_MITM_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GuiBase::OnFileExit ) );
	this->Disconnect( wxID_TOOL_COMPRESS, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GuiBase::OnCompress ) );
	this->Disconnect( wxID_TOOL_EXTRACT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GuiBase::OnExpand ) );
	this->Disconnect( wxID_TOOL_ABOUT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GuiBase::OnAbout ) );	
}
