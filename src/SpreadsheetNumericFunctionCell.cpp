#include "SpreadsheetNumericFunctionCell.h"

Spreadsheet::NumericFunctionCell::NumericFunctionCell() : Spreadsheet::FunctionCell() {}

Spreadsheet::NumericFunctionCell::NumericFunctionCell(Spreadsheet::Cell* const argument) : Spreadsheet::FunctionCell(argument) {}

Spreadsheet::NumericFunctionCell::NumericFunctionCell(const std::set<Spreadsheet::Cell*>& args) : Spreadsheet::FunctionCell(args) {}