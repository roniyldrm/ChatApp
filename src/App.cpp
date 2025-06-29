#include "wx/App.h"
#include "wx/MainFrame.h"
#include <wx/wx.h>


wxIMPLEMENT_APP(App);


bool App::OnInit() {
	MainFrame* mainframe = new MainFrame("Template");
	mainframe->SetClientSize(800, 600);
	mainframe->Center();
	mainframe->Show();

	return true;
}