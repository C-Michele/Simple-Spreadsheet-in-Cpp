#ifndef SPREADSHEETRAWTEXTUALCELL_H
#define SPREADSHEETRAWTEXTUALCELL_H

#include "Spreadsheet.h"
#include "SpreadsheetNotEmptyCell.h"

class Spreadsheet::RawTextualCell final : public Spreadsheet::NotEmptyCell {
    public:
        virtual ~RawTextualCell() = default;
        RawTextualCell(const std::string& text);
        virtual std::string getAsText() const override;
        void setText(const std::string& text);
    private:
        std::string cellText;
};

#endif //SPREADSHEETRAWTEXTUALCELL_H
