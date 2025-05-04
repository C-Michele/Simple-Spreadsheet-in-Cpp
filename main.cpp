// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <memory>

#include "src/Spreadsheet.h"
#include "src/SpreadsheetView.h"
#include "src/SpreadsheetController.h"

class SimpleSpreadsheet : public wxApp {
    public:
        SimpleSpreadsheet() = default;
        virtual bool OnInit() override;
    private:
        std::unique_ptr<Spreadsheet> spreadsheet;
        std::unique_ptr<SpreadsheetController> spreadsheetController;
        std::unique_ptr<SpreadsheetView> spreadsheetView;
};

bool SimpleSpreadsheet::OnInit() {
    spreadsheet = std::make_unique<Spreadsheet>(5, 5);
    /*
    spreadsheet->setFunctionAt(SpreadsheetCellCoordinates(1,1),
        Spreadsheet::Function::sum,
        {
            SpreadsheetCellCoordinates(2,1),
            SpreadsheetCellCoordinates(3,1),
            SpreadsheetCellCoordinates(4,1),
            SpreadsheetCellCoordinates(5,1)
        });
    spreadsheet->setFunctionAt(SpreadsheetCellCoordinates(1,2),
        Spreadsheet::Function::max,
        {
            SpreadsheetCellCoordinates(2,2),
            SpreadsheetCellCoordinates(3,2),
            SpreadsheetCellCoordinates(4,2),
            SpreadsheetCellCoordinates(5,2)
        });
    spreadsheet->setFunctionAt(SpreadsheetCellCoordinates(1,3),
        Spreadsheet::Function::min,
        {
            SpreadsheetCellCoordinates(2,3),
            SpreadsheetCellCoordinates(3,3),
            SpreadsheetCellCoordinates(4,3),
            SpreadsheetCellCoordinates(5,3)
        });
    spreadsheet->setValueAt(SpreadsheetCellCoordinates(2,4),1);
    spreadsheet->setValueAt(SpreadsheetCellCoordinates(3,4),2);
    spreadsheet->setFunctionAt(SpreadsheetCellCoordinates(1,4),
        Spreadsheet::Function::avg,
        {
            SpreadsheetCellCoordinates(2,4),
            SpreadsheetCellCoordinates(3,4),
            SpreadsheetCellCoordinates(4,4),
            SpreadsheetCellCoordinates(5,4)
        });
    */
    spreadsheetController = std::make_unique<SpreadsheetController>(spreadsheet.get());
    spreadsheetView = std::make_unique<SpreadsheetView>(spreadsheet.get(), spreadsheetController.get());
    spreadsheetView->Show(true);
    return true;
}

wxIMPLEMENT_APP(SimpleSpreadsheet);