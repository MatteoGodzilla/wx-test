// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

enum {
    ID_Hello = 1
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit(){
        MyFrame *frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(NULL, wxID_ANY, "Hello World") {
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                        "Help string shown in status bar for this menu item");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT);
        wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);
        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");
        SetMenuBar(menuBar);
        CreateStatusBar();
        SetStatusText("Welcome to wxWidgets!");
        Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
        Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
        Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    }

private:
    void OnHello(wxCommandEvent &event){
        wxLogMessage("Hello world from wxWidgets!");
    }
    void OnExit(wxCommandEvent &event){
        Close(true);
    }
    void OnAbout(wxCommandEvent &event){
        wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK | wxICON_INFORMATION);
    }
};

wxIMPLEMENT_APP(MyApp);