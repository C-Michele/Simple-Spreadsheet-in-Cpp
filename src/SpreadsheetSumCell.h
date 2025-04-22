#ifndef SPREADSHEETSUMCELL_H
#define SPREADSHEETSUMCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetNumericFunctionCell.h"

class SpreadsheetSumCell final : public SpreadsheetNumericFunctionCell {
    public:
        SpreadsheetSumCell() = default;
        SpreadsheetSumCell(SpreadsheetCell* argument);
        SpreadsheetSumCell(const std::set<SpreadsheetCell*>& args);

        virtual ~SpreadsheetSumCell() = default;

        virtual Spreadsheet::Function getFunction() const override;
        virtual double getAsNumericValue() const override;

        virtual void update() override;
    private:
        double sumResult;
};



#endif //SPREADSHEETSUMCELL_H
