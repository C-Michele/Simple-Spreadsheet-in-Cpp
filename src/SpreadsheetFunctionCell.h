#ifndef SPREADSHEETFUNCTIONCELL_H
#define SPREADSHEETFUNCTIONCELL_H

#include <set>

#include "Spreadsheet.h"
#include "SpreadsheetNotEmptyCell.h"
#include "utility/Observer.h"

class SpreadsheetFunctionCell : public virtual SpreadsheetNotEmptyCell, public virtual Observer {
    public:
        SpreadsheetFunctionCell() = default;
        SpreadsheetFunctionCell(SpreadsheetCell* argument);
        SpreadsheetFunctionCell(const std::set<SpreadsheetCell*>& args);

        virtual ~SpreadsheetFunctionCell();

        virtual Spreadsheet::Function getFunction() const = 0;
        std::set<SpreadsheetCell*> getArguments() const;

        void addArgument(SpreadsheetCell* argumentToAdd);
        virtual void removeArgument(SpreadsheetCell* argumentToRemove);
    private:
        void addArgumentWithoutUpdate(SpreadsheetCell* argumentToAdd);
        void removeArgumentWithoutUpdate(SpreadsheetCell* argumentToRemove);
        std::set<SpreadsheetCell*> cellsArguments;
};



#endif //SPREADSHEETFUNCTIONCELL_H
