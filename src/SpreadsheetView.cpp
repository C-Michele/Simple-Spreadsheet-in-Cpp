#include "SpreadsheetView.h"

SpreadsheetView::SpreadsheetView(Spreadsheet* const spreadsheet, SpreadsheetController* const spreadsheetController) :
wxFrame(NULL, wxID_ANY, "Simple Spreadsheet"),
spreadsheet(spreadsheet),
spreadsheetController(spreadsheetController),
menuFile(new wxMenu),
menuHelp(new wxMenu),
menuBar(new wxMenuBar),
grid( new wxGrid( this,-1,wxPoint( 0, 0 ),wxSize( 400, 300 ) ) ) {
    menuFile->Append(wxID_EXIT);
    menuHelp->Append(wxID_ABOUT);
    wxFrame::SetMenuBar(menuBar.get());
    menuBar->Append(menuFile.get(), "&File");
    menuBar->Append(menuHelp.get(), "&Help");
    Bind(wxEVT_MENU,
    [=](wxCommandEvent&) {
            wxMessageBox("This is a simple spreadsheet","About this program",wxOK | wxICON_INFORMATION);
        },
        wxID_ABOUT);
    Bind(wxEVT_MENU,
        [=](wxCommandEvent&) {
            wxFrame::Close(true);
        },
        wxID_EXIT );
    grid->CreateGrid( spreadsheet->getNumberOfRows(), spreadsheet->getNumberOfColumns() );
}

void SpreadsheetView::update() {
    //TODO: implementation
}
