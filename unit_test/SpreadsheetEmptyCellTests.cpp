#include "gtest/gtest.h"

#include "../src/SpreadsheetCell.h"
#include "../src/SpreadsheetEmptyCell.h"
#include "../src/SpreadsheetNotEmptyCell.h"

TEST(SpreadsheetEmptyCell,is_a_SpreadsheetCell) {
    SpreadsheetEmptyCell cell;
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    ASSERT_FALSE( convertedPointer == nullptr );
}

TEST(SpreadsheetEmptyCell,is_not_a_SpreadsheetNotEmptyCell) {
    SpreadsheetEmptyCell cell;
    SpreadsheetNotEmptyCell* const convertedPointer = dynamic_cast<SpreadsheetNotEmptyCell*>(&cell);
    ASSERT_TRUE( convertedPointer == nullptr );
}

TEST(SpreadsheetEmptyCell,is_empty) {
    SpreadsheetEmptyCell cell;
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    if ( convertedPointer != nullptr ) {
        ASSERT_TRUE( convertedPointer->isEmpty() );
    }
}

TEST(SpreadsheetEmptyCell,getAsText) {
    SpreadsheetEmptyCell cell;
    SpreadsheetCell* const convertedPointer = dynamic_cast<SpreadsheetCell*>(&cell);
    if ( convertedPointer != nullptr ) {
        ASSERT_EQ( convertedPointer->getAsText() , "" );
    }
}

