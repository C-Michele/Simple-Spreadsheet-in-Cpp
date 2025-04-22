#ifndef SPREADSHEETNUMERICCELL_H
#define SPREADSHEETNUMERICCELL_H

#include "SpreadsheetNotEmptyCell.h"

class SpreadsheetNumericCell : public virtual SpreadsheetNotEmptyCell {
    public:
        virtual ~SpreadsheetNumericCell() = default;

        virtual std::string getAsText() const override final;
        virtual double getAsNumericValue() const = 0;
};



#endif //SPREADSHEETNUMERICCELL_H
