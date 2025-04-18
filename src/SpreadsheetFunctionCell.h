#ifndef SPREADSHEETFUNCTIONCELL_H
#define SPREADSHEETFUNCTIONCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetNotEmptyCell.h"
#include "utility/Observer.h"

class Spreadsheet::FunctionCell : public Spreadsheet::NotEmptyCell, public Observer {
    public:
        virtual ~FunctionCell() = default;
        virtual Spreadsheet::Function getFunction() const = 0;
        void addArgument(Spreadsheet::Cell* argumentToAdd);
        void removeArgument(Spreadsheet::Cell* argumentToRemove);
        std::set<Spreadsheet::Cell*> getArguments() const;
    private:
        std::set<Spreadsheet::Cell*> cellsArguments;
};

#endif //SPREADSHEETFUNCTIONCELL_H
