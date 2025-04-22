#ifndef SPREADSHEETRAWTEXTUALCELL_H
#define SPREADSHEETRAWTEXTUALCELL_H

#include <string>

#include "SpreadsheetNotEmptyCell.h"

class SpreadsheetRawTextualCell final : public SpreadsheetNotEmptyCell {
    public:
        SpreadsheetRawTextualCell(const std::string& text);

        virtual ~SpreadsheetRawTextualCell() = default;

        virtual std::string getAsText() const override;

        void setText(const std::string& text);
    private:
        std::string cellText;
};



#endif //SPREADSHEETRAWTEXTUALCELL_H
