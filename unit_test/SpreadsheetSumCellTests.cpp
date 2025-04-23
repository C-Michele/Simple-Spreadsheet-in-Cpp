#include "SpreadsheetRawNumericCell.h"
#include "gtest/gtest.h"

#include "../src/SpreadsheetCell.h"
#include "../src/SpreadsheetEmptyCell.h"
#include "../src/SpreadsheetNotEmptyCell.h"
#include "../src/SpreadsheetFunctionCell.h"
#include "../src/SpreadsheetNumericCell.h"
#include "../src/SpreadsheetNumericFunctionCell.h"
#include "../src/SpreadsheetSumCell.h"

TEST(SpreadsheetSumCell,is_a_SpreadsheetCell) {
    SpreadsheetSumCell cell;
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    ASSERT_FALSE(convertedPointer == nullptr);
}

TEST(SpreadsheetSumCell,is_not_a_SpreadsheetEmptyCell) {
    SpreadsheetSumCell cell;
    SpreadsheetEmptyCell* const convertedPointer = dynamic_cast<SpreadsheetEmptyCell*>(&cell);
    ASSERT_TRUE(convertedPointer == nullptr);
}

TEST(SpreadsheetSumCell,is_a_SpreadsheetNotEmptyCell) {
    SpreadsheetSumCell cell;
    SpreadsheetNotEmptyCell* const convertedPointer = dynamic_cast<SpreadsheetNotEmptyCell*>(&cell);
    ASSERT_FALSE(convertedPointer == nullptr);
}

TEST(SpreadsheetSumCell,is_a_SpreadsheetFunctionCell) {
    SpreadsheetSumCell cell;
    SpreadsheetFunctionCell* const convertedPointer = dynamic_cast<SpreadsheetFunctionCell*>(&cell);
    ASSERT_FALSE(convertedPointer == nullptr);
}

TEST(SpreadsheetSumCell,default_constructor) {
    SpreadsheetSumCell cell;
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&cell);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),0);
    }
}

TEST(SpreadsheetSumCell,single_argument_constructor) {
    const double value = 12345.6789;
    SpreadsheetRawNumericCell rawNumericCell(value);
    SpreadsheetSumCell sumCell(&rawNumericCell);
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&sumCell);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),value);
    }
}

TEST(SpreadsheetSumCell,addArgument) {
    SpreadsheetSumCell sumCell;
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&sumCell);
    SpreadsheetRawNumericCell rawNumericCellA(73);
    sumCell.addArgument(&rawNumericCellA);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),73);
    }
    SpreadsheetRawNumericCell rawNumericCellB(27);
    sumCell.addArgument(&rawNumericCellB);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),100);
    }
}

TEST(SpreadsheetSumCell,removeArgument) {
    SpreadsheetRawNumericCell rawNumericCellA(73);
    SpreadsheetRawNumericCell rawNumericCellB(27);
    SpreadsheetSumCell sumCell({&rawNumericCellA,&rawNumericCellB});
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&sumCell);
    sumCell.removeArgument(&rawNumericCellA);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),27);
    }
    sumCell.removeArgument(&rawNumericCellB);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),0);
    }
}

TEST(SpreadsheetSumCell,observer_behavior_with_a_cell_change) {
    SpreadsheetRawNumericCell rawNumericCellA(73);
    SpreadsheetRawNumericCell rawNumericCellB(27);
    SpreadsheetSumCell sumCell({&rawNumericCellA,&rawNumericCellB});
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&sumCell);
    rawNumericCellA.setNumericValue(3);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),30);
    }
    rawNumericCellB.setNumericValue(8);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),11);
    }
}