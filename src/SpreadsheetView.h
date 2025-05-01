#ifndef SPREADSHEETVIEW_H
#define SPREADSHEETVIEW_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/grid.h>

#include <memory>
#include "utility/Observer.h"
#include "Spreadsheet.h"
#include "SpreadsheetController.h"

class SpreadsheetView : public wxFrame, public Observer { // TODO: Continue this class implementation
    public:
        SpreadsheetView(Spreadsheet* spreadsheet, SpreadsheetController* spreadsheetController);
        virtual ~SpreadsheetView() = default;

        virtual void update() override;

    private:
        Spreadsheet* spreadsheet;
        SpreadsheetController* spreadsheetController;

        std::unique_ptr<wxMenu> menuFile;
        std::unique_ptr<wxMenu> menuHelp;
        std::unique_ptr<wxMenuBar> menuBar;
        std::unique_ptr<wxGrid> grid;
};

#endif //SPREADSHEETVIEW_H
