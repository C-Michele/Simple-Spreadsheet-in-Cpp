#ifndef SPREADSHEETNUMERICCELL_H
#define SPREADSHEETNUMERICCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetNotEmptyCell.h"

class Spreadsheet::NumericCell : public virtual Spreadsheet::NotEmptyCell {
    public:
        virtual ~NumericCell() = default;
        virtual std::string getAsText() const override final;
        virtual double getAsNumericValue() const = 0;
};

#endif //SPREADSHEETNUMERICCELL_H
