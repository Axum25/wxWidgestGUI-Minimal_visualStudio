// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "fstream"
#include "string"
#include "iostream"
#include "iomanip"
#include "sstream"

using namespace std;

// Define a new application type, each program should derive a class from wxApp
class MyApp : public wxApp {
public:

  // this one is called on application startup and is a good place for the app
  // initialization (doing it here and not in the ctor allows to have an error
  // return: if OnInit() returns false, the application terminates)
  virtual bool OnInit() wxOVERRIDE;
};

// Define a new frame type: this is going to be our main frame
class ProjectFrame : public wxFrame {
public:
  // constructor(s)
  ProjectFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

  // event handlers (these functions should _not_ be virtual)
    //Functions for File Menu Items
  void OnOpenFile(wxCommandEvent& event);
  void OnSave(wxCommandEvent& event);
  void OnSaveAs(wxCommandEvent& event);
  void OnQuit(wxCommandEvent& event);
  //Functions for Help Menu Items
  void OnAbout(wxCommandEvent& event);

private:
  // any class wishing to process wxWidgets events must use this macro
  wxDECLARE_EVENT_TABLE();
};

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum {

  //File Menu Items
  ID_OpenFile = wxID_HIGHEST + 1,
  ID_Save,
  ID_SaveAs,
  Minimal_Quit = wxID_EXIT,

  // it is important for the id corresponding to the "About" command to have
  // this standard value as otherwise it won't be handled properly under Mac
  // (where it is special and put into the "Apple" menu)
  //Help Menu Items
  Minimal_About = wxID_ABOUT
};

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------

// the event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
wxBEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
//Events for the "File" Menu items

EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(Minimal_Quit, ProjectFrame::OnQuit)

//Events for the "Help" Menu Items

EVT_MENU(Minimal_About, ProjectFrame::OnAbout)

wxEND_EVENT_TABLE()

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
wxIMPLEMENT_APP(MyApp);

// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------

// 'Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{
  // call the base class initialization method, currently it only parses a
  // few common command-line options but it could be do more in the future
  if (!wxApp::OnInit())
    return false;

  // create the main application window
  ProjectFrame* frame = new ProjectFrame(wxT("Sunshine Airlines - Fly the friendly skies"), wxPoint(50, 50), wxSize(840, 600));

  // and show it (the frames, unlike simple controls, are not shown when
  // created initially)
  frame->Show(true);

  SetTopWindow(frame);

  // success: wxApp::OnRun() will be called which will enter the main message
  // loop and the application will run. If we returned false here, the
  // application would exit immediately.
  return true;
}



// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
ProjectFrame::ProjectFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title)
{
  // set the frame icon

  SetIcon(wxICON(wxT("Sunshine-Airlines.xpm")));

  /**
     // If menus are not available add a button to access the about box
       wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
      wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
      aboutBtn->Bind(wxEVT_BUTTON, &ProjectFrame::OnAbout, this);
      sizer->Add(aboutBtn, wxSizerFlags().Center());
  */

  /*
   #if wxUSE_STATUSBAR
     // create a status bar just for fun (by default with 1 pane only)
       CreateStatusBar(2);
       SetStatusText("Welcome to wxWidgets!");
   #endif // wxUSE_STATUSBAR
 */

 //Create menu items for menu bar
  wxMenu* menuFile = new wxMenu;

  //The "About" item should be in the help menu
  wxMenu* menuHelp = new wxMenu;

  //Help Menu
  menuHelp->Append(Minimal_About, wxT("&About...\tF1"), wxT("Show about dialog"));

  //File Menu

  menuFile->Append(ID_OpenFile, wxT("Open\tCtrl+O"), wxT("Open an Existing file"));

  menuFile->Append(ID_Save, wxT("Save\tCtrl+S"), wxT("Save opened file"));

  menuFile->Append(ID_SaveAs, wxT("Save &As..."), wxT("Save display as a new file"));

  menuFile->AppendSeparator();

  menuFile->Append(Minimal_Quit, wxT("E&xit\tAlt+X"), wxT("Close and Exit Program"));


  //Now append the freshly created menu to the menu bar...
  wxMenuBar* menuBar = new wxMenuBar();

  menuBar->Append(menuFile, wxT("&File"));
  menuBar->Append(menuHelp, wxT("&Help"));

  //...and attach this menue bar to the frame
  SetMenuBar(menuBar);

  //Create a status bar
  CreateStatusBar(3, wxST_SIZEGRIP);

  SetStatusText(wxT(" Ready... "), 0);

  SetStatusText(wxT("\tJoseph Buffong"), 1);

  SetStatusText(wxT("\tVersion 1.0"), 2);

}


// event handlers

//=========================================================================
//======== Definition for the File Functions ==============================
//=========================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent& event)
{
}

void ProjectFrame::OnSave(wxCommandEvent& event)
{
}

void ProjectFrame::OnSaveAs(wxCommandEvent& event)
{
}

void ProjectFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  // true is to force the frame to close
  Close(true);
}

void ProjectFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
  wxMessageBox(wxString::Format
  (
    "Welcome to %s!\n"
    "\n"
    "running under %s.",
    wxVERSION_STRING,
    wxGetOsDescription()
  ),
               "About Sunshine Airlines",
               wxOK | wxICON_INFORMATION,
               this);
}
