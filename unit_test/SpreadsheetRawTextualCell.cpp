#include "gtest/gtest.h"

#include "../src/SpreadsheetCell.h"
#include "../src/SpreadsheetEmptyCell.h"
#include "../src/SpreadsheetNotEmptyCell.h"
#include "../src/SpreadsheetNumericCell.h"
#include "../src/SpreadsheetFunctionCell.h"
#include "../src/SpreadsheetRawTextualCell.h"

TEST(SpreadsheetRawTextualCell,is_a_SpreadsheetCell) {
    SpreadsheetRawTextualCell cell("text");
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    ASSERT_FALSE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawTextualCell,is_not_a_SpreadsheetEmptyCell) {
    SpreadsheetRawTextualCell cell("text");
    SpreadsheetEmptyCell* const convertedPointer = dynamic_cast<SpreadsheetEmptyCell*>(&cell);
    ASSERT_TRUE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawTextualCell,is_a_SpreadsheetNotEmptyCell) {
    SpreadsheetRawTextualCell cell("text");
    SpreadsheetNotEmptyCell* const convertedPointer = dynamic_cast<SpreadsheetNotEmptyCell*>(&cell);
    ASSERT_FALSE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawTextualCell,is_not_a_SpreadsheetNumericCell) {
    SpreadsheetRawTextualCell cell("text");
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&cell);
    ASSERT_TRUE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawTextualCell,is_not_a_SpreadsheetFunctionCell) {
    SpreadsheetRawTextualCell cell("text");
    SpreadsheetFunctionCell* const convertedPointer = dynamic_cast<SpreadsheetFunctionCell*>(&cell);
    ASSERT_TRUE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawTextualCell,is_not_empty) {
    SpreadsheetRawTextualCell cell("text");
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    if (convertedPointer!=nullptr) {
        ASSERT_FALSE( convertedPointer->isEmpty() );
    }
}

TEST(SpreadsheetRawTextualCell,constructor_and_getAsText) {
    const std::string value("A text");
    SpreadsheetRawTextualCell cell(value);
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    if (convertedPointer!=nullptr) {
        ASSERT_EQ(convertedPointer->getAsText(),value);
    }
}

TEST(SpreadsheetRawTextualCell,setText) {
    SpreadsheetRawTextualCell cell("A text");
    const std::string value("Another text");
    cell.setText(value);
    ASSERT_EQ(cell.getAsText(),value);
}