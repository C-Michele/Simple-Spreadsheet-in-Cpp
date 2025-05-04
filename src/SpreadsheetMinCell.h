#ifndef SPREADSHEETMINCELL_H
#define SPREADSHEETMINCELL_H

#include "SpreadsheetNumericFunctionCell.h"
#include "utility/Latch.h"

class SpreadsheetMinCell final : public SpreadsheetNumericFunctionCell {
    public:
        SpreadsheetMinCell() = delete;
        SpreadsheetMinCell(SpreadsheetCell* argument);
        SpreadsheetMinCell(const std::set<SpreadsheetCell*>& args);

        virtual ~SpreadsheetMinCell();

        Spreadsheet::Function getFunction() const override;
        double getAsNumericValue() const override;

        void removeArgument(SpreadsheetCell* argumentToRemove) override;
        void update() override;
    private:
        double minResult;
        Latch isInDestruction;
};

#endif //SPREADSHEETMINCELL_H