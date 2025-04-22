#include "SpreadsheetNumericFunctionCell.h"

SpreadsheetNumericFunctionCell::SpreadsheetNumericFunctionCell(SpreadsheetCell* const argument) : SpreadsheetFunctionCell(argument) {}

SpreadsheetNumericFunctionCell::SpreadsheetNumericFunctionCell(const std::set<SpreadsheetCell*>& args) : SpreadsheetFunctionCell(args) {}