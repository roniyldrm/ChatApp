#include "wx/MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>



MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr,wxID_ANY,title){  //iki tane daha parametresi var size ve position
	wxPanel* panel = new wxPanel(this);

	wxButton* btn = new wxButton(panel, wxID_ANY,"press", wxPoint(250, 300), wxSize(100, -1));


	CreateStatusBar(); 
}
