#ifndef SPREADSHEETNUMERICFUNCTIONCELL_H
#define SPREADSHEETNUMERICFUNCTIONCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetNumericCell.h"
#include "SpreadsheetFunctionCell.h"

class Spreadsheet::NumericFunctionCell : public Spreadsheet::NumericCell, public Spreadsheet::FunctionCell {
    public:
        virtual ~NumericFunctionCell() = default;
        NumericFunctionCell();
        NumericFunctionCell(Spreadsheet::Cell* argument);
        NumericFunctionCell(const std::set<Spreadsheet::Cell*>& args);
};

#endif //SPREADSHEETNUMERICFUNCTIONCELL_H
