#ifndef SPREADSHEETAVGCELL_H
#define SPREADSHEETAVGCELL_H

#include "SpreadsheetNumericFunctionCell.h"
#include "utility/Latch.h"

class SpreadsheetAvgCell final : public SpreadsheetNumericFunctionCell {
    public:
        SpreadsheetAvgCell() = delete;
        SpreadsheetAvgCell(SpreadsheetCell* argument);
        SpreadsheetAvgCell(const std::set<SpreadsheetCell*>& args);

        virtual ~SpreadsheetAvgCell();

        Spreadsheet::Function getFunction() const override;
        double getAsNumericValue() const override;

        void removeArgument(SpreadsheetCell* argumentToRemove) override;
        void update() override;
    private:
        double avgResult;
        Latch isInDestruction;
};

#endif //SPREADSHEETAVGCELL_H
