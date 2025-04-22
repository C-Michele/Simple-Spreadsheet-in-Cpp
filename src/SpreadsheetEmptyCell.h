#ifndef SPREADSHEETEMPTYCELL_H
#define SPREADSHEETEMPTYCELL_H

#include "SpreadsheetCell.h"

class SpreadsheetEmptyCell final : public SpreadsheetCell {
    public:
        virtual ~SpreadsheetEmptyCell() = default;
        virtual bool isEmpty() const override;
        virtual std::string getAsText() const override;
};



#endif //SPREADSHEETEMPTYCELL_H
