#ifndef SPREADSHEETSUMCELL_H
#define SPREADSHEETSUMCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetNumericFunctionCell.h"

class Spreadsheet::SumCell final : public Spreadsheet::NumericFunctionCell {
    public:
        virtual ~SumCell() = default;
        SumCell();
        SumCell(Spreadsheet::Cell* argument);
        SumCell(const std::set<Spreadsheet::Cell*>& args);
        virtual void update() override;
        virtual double getAsNumericValue() const override;
        virtual Spreadsheet::Function getFunction() const override;
    private:
        double sumResult;
};

#endif //SPREADSHEETSUMCELL_H
