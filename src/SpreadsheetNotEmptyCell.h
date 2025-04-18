#ifndef SPREADSHEETNOTEMPTYCELL_H
#define SPREADSHEETNOTEMPTYCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetCell.h"

class Spreadsheet::NotEmptyCell : public Spreadsheet::Cell {
    public:
        virtual ~NotEmptyCell() = default;
        virtual bool isEmpty() const;
};

#endif //SPREADSHEETNOTEMPTYCELL_H
