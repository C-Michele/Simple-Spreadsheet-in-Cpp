#ifndef SPREADSHEETNOTEMPTYCELL_H
#define SPREADSHEETNOTEMPTYCELL_H

#include "SpreadsheetCell.h"

class SpreadsheetNotEmptyCell : public SpreadsheetCell {
    public:
        virtual ~SpreadsheetNotEmptyCell() = default;
        virtual bool isEmpty() const override final;
};



#endif //SPREADSHEETNOTEMPTYCELL_H
