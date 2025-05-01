#include "SpreadsheetView.h"

SpreadsheetView::SpreadsheetView(Spreadsheet* const spreadsheet, SpreadsheetController* const spreadsheetController) :
wxFrame(NULL, wxID_ANY, "Simple Spreadsheet"),
spreadsheet(spreadsheet),
spreadsheetController(spreadsheetController),
menuFile(new wxMenu),
menuHelp(new wxMenu),
menuBar(new wxMenuBar),
grid( new wxGrid( this,-1 ) ) {
    spreadsheet->addObserver(this);

    menuFile->Append(wxID_EXIT);
    menuHelp->Append(wxID_ABOUT);
    wxFrame::SetMenuBar(menuBar.get());
    menuBar->Append(menuFile.get(), "&File");
    menuBar->Append(menuHelp.get(), "&Help");
    Bind(wxEVT_MENU,
    [=](const wxCommandEvent&) {
            wxMessageBox("This is a simple spreadsheet","About this program",wxOK | wxICON_INFORMATION);
        },
        wxID_ABOUT);
    Bind(wxEVT_MENU,
        [=](const wxCommandEvent&) {
            wxFrame::Close(true);
        },
        wxID_EXIT );

    grid->CreateGrid( spreadsheet->getNumberOfRows(), spreadsheet->getNumberOfColumns() );
    this->SpreadsheetView::update();
    Bind(wxEVT_GRID_CELL_CHANGING,
        [=](wxGridEvent& event) {
            const std::string insertedString(event.GetString() );
            spreadsheetController->setCellAt(
                SpreadsheetCellCoordinates(event.GetCol()+1,event.GetRow()+1),
                insertedString );
        });

}

void SpreadsheetView::update() {
    for (std::size_t rowIndex = 0; rowIndex < spreadsheet->getNumberOfRows(); ++rowIndex ) {
        for (std::size_t columnIndex = 0; columnIndex < spreadsheet->getNumberOfColumns(); ++columnIndex ) {
            grid->SetCellValue(rowIndex,columnIndex,spreadsheet->getCellAsTextAt(SpreadsheetCellCoordinates(columnIndex+1,rowIndex+1)) );
        }
    }
}
