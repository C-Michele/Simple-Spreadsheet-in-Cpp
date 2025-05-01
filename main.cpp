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
    spreadsheetController = std::make_unique<SpreadsheetController>(spreadsheet.get());
    spreadsheetView = std::make_unique<SpreadsheetView>(spreadsheet.get(), spreadsheetController.get());
    spreadsheetView->Show(true);
    return true;
}

wxIMPLEMENT_APP(SimpleSpreadsheet);