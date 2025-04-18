#ifndef SPREADSHEETEMPTYCELL_H
#define SPREADSHEETEMPTYCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetCell.h"

class Spreadsheet::EmptyCell final : public Spreadsheet::Cell {
    public:
        virtual ~EmptyCell() = default;
        virtual bool isEmpty() const override;
        virtual std::string getAsText() const override;
};

#endif //SPREADSHEETEMPTYCELL_H
