#ifndef SPREADSHEETRAWNUMERICCELL_H
#define SPREADSHEETRAWNUMERICCELL_H

#include "SpreadsheetNumericCell.h"

class SpreadsheetRawNumericCell final : public SpreadsheetNumericCell {
    public:
        SpreadsheetRawNumericCell() = delete;
        SpreadsheetRawNumericCell(double value);

        virtual ~SpreadsheetRawNumericCell() = default;

        virtual double getAsNumericValue() const override;

        void setNumericValue(double value);
    private:
        double cellValue;
};



#endif //SPREADSHEETRAWNUMERICCELL_H
