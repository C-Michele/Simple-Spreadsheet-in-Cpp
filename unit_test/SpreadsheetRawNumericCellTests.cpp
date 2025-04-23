#include "gtest/gtest.h"

#include "../src/SpreadsheetCell.h"
#include "../src/SpreadsheetEmptyCell.h"
#include "../src/SpreadsheetNotEmptyCell.h"
#include "../src/SpreadsheetNumericCell.h"
#include "../src/SpreadsheetFunctionCell.h"
#include "../src/SpreadsheetRawNumericCell.h"

TEST(SpreadsheetRawNumericCell,is_a_SpreadsheetNumericCell) {
    SpreadsheetRawNumericCell cell(0);
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&cell);
    ASSERT_FALSE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawNumericCell,is_not_a_SpreadsheetFunctionCell) {
    SpreadsheetRawNumericCell cell(0);
    SpreadsheetFunctionCell* const convertedPointer = dynamic_cast<SpreadsheetFunctionCell*>(&cell);
    ASSERT_TRUE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawNumericCell,is_a_SpreadsheetNotEmptyCell) {
    SpreadsheetRawNumericCell cell(0);
    SpreadsheetNotEmptyCell* const convertedPointer = dynamic_cast<SpreadsheetNotEmptyCell*>(&cell);
    ASSERT_FALSE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawNumericCell,is_not_a_SpreadsheetEmptyCell) {
    SpreadsheetRawNumericCell cell(0);
    SpreadsheetEmptyCell* const convertedPointer = dynamic_cast<SpreadsheetEmptyCell*>(&cell);
    ASSERT_TRUE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawNumericCell,is_a_SpreadsheetCell) {
    SpreadsheetRawNumericCell cell(0);
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    ASSERT_FALSE( convertedPointer == nullptr );
}

TEST(SpreadsheetRawNumericCell,constructor_and_getAsNumericValue) {
    const double value = 123.456;
    SpreadsheetRawNumericCell cell(value);
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&cell);
    if (convertedPointer != nullptr) {
        ASSERT_EQ(convertedPointer->getAsNumericValue(),value);
    }
}

TEST(SpreadsheetRawNumericCell,is_not_empty) {
    const double value = 0;
    SpreadsheetRawNumericCell cell(value);
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    if (convertedPointer != nullptr) {
        ASSERT_FALSE(convertedPointer->isEmpty());
    }
}

TEST(SpreadsheetRawNumericCell,constructor_and_getAsText) {
    const double value = 123.456;
    SpreadsheetRawNumericCell cell(value);
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    if (convertedPointer != nullptr) {
        ASSERT_EQ(convertedPointer->getAsText(),std::to_string(value));
    }
}

TEST(SpreadsheetRawNumericCell,setNumericValue) {
    SpreadsheetRawNumericCell cell(0);
    const double value = 123.456;
    cell.setNumericValue(value);
    SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>(&cell);
    if (convertedPointer != nullptr) {
        ASSERT_EQ(cell.getAsNumericValue(),value);
    }
}