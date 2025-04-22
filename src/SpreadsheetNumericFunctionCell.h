#ifndef SPREADSHEETNUMERICFUNCTIONCELL_H
#define SPREADSHEETNUMERICFUNCTIONCELL_H

#include "SpreadsheetCell.h"
#include "SpreadsheetFunctionCell.h"
#include "SpreadsheetNumericCell.h"

class SpreadsheetNumericFunctionCell : public SpreadsheetNumericCell, public SpreadsheetFunctionCell {
    public:
        SpreadsheetNumericFunctionCell() = default;
        SpreadsheetNumericFunctionCell(SpreadsheetCell* argument);
        SpreadsheetNumericFunctionCell(const std::set<SpreadsheetCell*>& args);

        virtual ~SpreadsheetNumericFunctionCell() = default;
};

#endif //SPREADSHEETNUMERICFUNCTIONCELL_H
