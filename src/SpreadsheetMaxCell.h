#ifndef SPREADSHEETMAXCELL_H
#define SPREADSHEETMAXCELL_H

#include "SpreadsheetNumericFunctionCell.h"
#include "utility/Latch.h"

class SpreadsheetMaxCell final : public SpreadsheetNumericFunctionCell {
    public:
        SpreadsheetMaxCell() = delete;
        SpreadsheetMaxCell(SpreadsheetCell* argument);
        SpreadsheetMaxCell(const std::set<SpreadsheetCell*>& args);

        virtual ~SpreadsheetMaxCell();

        Spreadsheet::Function getFunction() const override;
        double getAsNumericValue() const override;

        void removeArgument(SpreadsheetCell* argumentToRemove) override;
        void update() override;
    private:
        double maxResult;
        Latch isInDestruction;
};

#endif //SPREADSHEETMAXCELL_H