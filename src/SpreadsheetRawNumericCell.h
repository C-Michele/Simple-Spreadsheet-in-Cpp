#ifndef SPREADSHEETRAWNUMERICCELL_H
#define SPREADSHEETRAWNUMERICCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetNumericCell.h"

class Spreadsheet::RawNumericCell final : public Spreadsheet::NumericCell {
    public:
        virtual ~RawNumericCell() = default;
        RawNumericCell(double value);
        virtual double getAsNumericValue() const override;
        void setNumericValue(double value);
    private:
        double cellValue;
};

#endif //SPREADSHEETRAWNUMERICCELL_H
