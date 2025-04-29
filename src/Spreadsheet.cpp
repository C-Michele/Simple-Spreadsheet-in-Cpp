#include <stdexcept>

#include "Spreadsheet.h"
#include "SpreadsheetEmptyCell.h"
#include "SpreadsheetFunctionCell.h"
#include "SpreadsheetNumericCell.h"
#include "SpreadsheetRawNumericCell.h"
#include "SpreadsheetRawTextualCell.h"
#include "SpreadsheetSumCell.h"

Spreadsheet::Spreadsheet(std::size_t const numberOfColumns, std::size_t const numberOfRows) : numberOfColumns(numberOfColumns) {
    if ( numberOfRows != 0 ) {
        cells.reserve(numberOfRows);
        while ( cells.size() != numberOfRows ) {
            cells.emplace_back();
            if (numberOfColumns != 0) {
                auto& rowToPopulate = cells.back();
                try {
                    rowToPopulate.reserve(numberOfColumns);
                } catch (...) {
                    cells.clear();
                    this->numberOfColumns = 0;
                    throw;
                }
                while ( rowToPopulate.size() != numberOfColumns ) {
                    rowToPopulate.emplace_back( new SpreadsheetEmptyCell() );
                }
            }
        }
    }
}

std::size_t Spreadsheet::getNumberOfColumns() const {
    return numberOfColumns;
}

std::size_t Spreadsheet::getNumberOfRows() const {
    return cells.size();
}

bool Spreadsheet::emptyCellAt(const SpreadsheetCellCoordinates& coordinates) const {
    return getCellAt(coordinates)->isEmpty();
}

void Spreadsheet::deleteCellContentAt(const SpreadsheetCellCoordinates& coordinates) {
    outOfRangeCheck(coordinates);
    if ( ! emptyCellAt(coordinates) ) {
        auto& rowContainingTheCellToDelete = cells[coordinates.getRowIndex()-1];
        auto itrPointingTheCellToDelete = rowContainingTheCellToDelete.begin();
        for (std::size_t j = 1; j != coordinates.getColumnIndexAsInteger(); ++j) {
            ++itrPointingTheCellToDelete;
        }
        const auto cellObservers = (*itrPointingTheCellToDelete)->getObservers();
        const auto itrPointingNewCell =
            rowContainingTheCellToDelete.emplace(
                rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) ,
                new SpreadsheetEmptyCell() );
        for (auto itr = cellObservers.cbegin(); itr != cellObservers.cend(); ++itr) {
            if ( dynamic_cast<SpreadsheetFunctionCell*>(*itr) != nullptr ) {
                dynamic_cast<SpreadsheetFunctionCell*>(*itr)->addArgument( (*itrPointingNewCell).get() );
            }
        }
        //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
    }
}

bool Spreadsheet::numericCellAt(const SpreadsheetCellCoordinates& coordinates) const {
    outOfRangeCheck(coordinates);
    return isNumericCell(coordinates);
}

std::string Spreadsheet::getCellAsTextAt(const SpreadsheetCellCoordinates& coordinates) const {
    outOfRangeCheck(coordinates);
    return getCellAt(coordinates)->getAsText();
}

double Spreadsheet::getCellAsNumericValueAt(const SpreadsheetCellCoordinates& coordinates) const {
    outOfRangeCheck(coordinates);
    if ( ! isNumericCell(coordinates) ) {
        throw std::invalid_argument(" "); //TODO: add an error message
    }
    return dynamic_cast<SpreadsheetNumericCell*>(getCellAt(coordinates))->getAsNumericValue();
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, double const value) {
    outOfRangeCheck(coordinates);
    if ( isRawNumericCell(coordinates) ) {
        const auto oldNumericValue = dynamic_cast<SpreadsheetRawNumericCell*>(getCellAt(coordinates))->getAsNumericValue();
        if (value != oldNumericValue) {
            dynamic_cast<SpreadsheetRawNumericCell*>(getCellAt(coordinates))->setNumericValue( value );
            //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
        }
    }
    else {
        auto& rowContainingTheCellToDelete = cells[coordinates.getRowIndex()-1];
        auto itrPointingTheCellToDelete = rowContainingTheCellToDelete.begin();
        for (std::size_t j = 1; j != coordinates.getColumnIndexAsInteger(); ++j) {
            ++itrPointingTheCellToDelete;
        }
        const auto cellObservers = (*itrPointingTheCellToDelete)->getObservers();
        if ( isNumericCell(coordinates) ) {
            const auto oldNumericValue = dynamic_cast<SpreadsheetNumericCell*>(getCellAt(coordinates))->getAsNumericValue();
            const auto itrPointingNewCell =
                rowContainingTheCellToDelete.emplace(
                    rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) ,
                    new SpreadsheetRawNumericCell( value ) );
            for (auto itr = cellObservers.cbegin(); itr != cellObservers.cend(); ++itr) {
                if ( dynamic_cast<SpreadsheetFunctionCell*>(*itr) != nullptr ) {
                    dynamic_cast<SpreadsheetFunctionCell*>(*itr)->addArgument( (*itrPointingNewCell).get() );
                }
            }
            if ( value != oldNumericValue ) {
                //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
            }
        }
        else {
            const auto itrPointingNewCell =
                rowContainingTheCellToDelete.emplace(
                    rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) ,
                    new SpreadsheetRawNumericCell( value ) );
            for (auto itr = cellObservers.cbegin(); itr != cellObservers.cend(); ++itr) {
                if ( dynamic_cast<SpreadsheetFunctionCell*>(*itr) != nullptr ) {
                    dynamic_cast<SpreadsheetFunctionCell*>(*itr)->addArgument( (*itrPointingNewCell).get() );
                }
            }
            //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
        }
    }
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, const std::string& value) {
    outOfRangeCheck(coordinates);
    if (value.empty()) {
        throw std::invalid_argument(" "); //TODO: add error message
    }
    const auto oldTextualValue = getCellAt(coordinates)->getAsText();
    if ( isRawOnlyTextualCell(coordinates) ) {
        if ( value != oldTextualValue ) {
            dynamic_cast<SpreadsheetRawTextualCell*>(getCellAt(coordinates))->setText( value );
            //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
        }
    }
    else {
        auto& rowContainingTheCellToDelete = cells[coordinates.getRowIndex()-1];
        auto itrPointingTheCellToDelete = rowContainingTheCellToDelete.begin();
        for (std::size_t j = 1; j != coordinates.getColumnIndexAsInteger(); ++j) {
            ++itrPointingTheCellToDelete;
        }
        const auto cellObservers = (*itrPointingTheCellToDelete)->getObservers();
        const auto itrPointingNewCell =
            rowContainingTheCellToDelete.emplace(
                rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) ,
                new SpreadsheetRawTextualCell( value ) );
        for (auto itr = cellObservers.cbegin(); itr != cellObservers.cend(); ++itr) {
            if ( dynamic_cast<SpreadsheetFunctionCell*>(*itr) != nullptr ) {
                dynamic_cast<SpreadsheetFunctionCell*>(*itr)->addArgument( (*itrPointingNewCell).get() );
            }
        }
        //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
    }
}

void Spreadsheet::setFunctionAt(
    const SpreadsheetCellCoordinates& coordinates,
    Function const function,
    const std::set<SpreadsheetCellCoordinates>& functionArguments ) {
    outOfRangeCheck(coordinates);
    outOfRangeCheck(functionArguments);
    if ( functionArguments.find(coordinates) != functionArguments.cend() ) {
        // This prevents the circular reference of a cell
        //TODO: Implement a system to detect more complex circular references
        throw std::invalid_argument(" "); //TODO: add error message
    }

    if ( function != Spreadsheet::Function::sum ) {  // For now only the sum function is supported
        throw std::runtime_error("Not implemented function");
    }

    auto& rowContainingTheOldCell = cells[coordinates.getRowIndex()-1];
    auto itrPointingTheOldCell = rowContainingTheOldCell.begin();
    for (std::size_t j = 1; j != coordinates.getColumnIndexAsInteger(); ++j) {
        ++itrPointingTheOldCell;
    }

    const auto oldCellObservers = (*itrPointingTheOldCell)->getObservers();
    const bool oldCellIsEmpty = (*itrPointingTheOldCell)->isEmpty();
    const std::string oldCellAsText = (*itrPointingTheOldCell)->getAsText();
    const bool oldCellIsNumeric = isNumericCell( (*itrPointingTheOldCell).get() );
    const double oldCellAsNumericValue =
        oldCellIsNumeric ?
        dynamic_cast<SpreadsheetNumericCell*>( (*itrPointingTheOldCell).get() )->getAsNumericValue() :
        0.0 ;
    const bool oldCellIsFunction = isFunctionCell( (*itrPointingTheOldCell).get() );
    const auto oldCellArguments =
        oldCellIsFunction ?
        dynamic_cast<SpreadsheetFunctionCell*>( (*itrPointingTheOldCell).get() )->getArguments() :
        std::set<SpreadsheetCell*>() ;
    const Spreadsheet::Function oldCellFunction =
        oldCellIsFunction ?
        dynamic_cast<SpreadsheetFunctionCell*>( (*itrPointingTheOldCell).get() )->getFunction() :
        Spreadsheet::Function::sum ;
    const std::set<SpreadsheetCell*> newFunctionCellArguments = getCellsAt(functionArguments);

    const auto itrFollowingTheDeletedCell = rowContainingTheOldCell.erase( itrPointingTheOldCell );

    std::vector< std::unique_ptr<SpreadsheetCell> >::iterator itrPointingTheNewCell;
    try {
        if ( function == Spreadsheet::Function::sum ) {
            itrPointingTheNewCell =
                rowContainingTheOldCell.emplace(
                    itrFollowingTheDeletedCell,
                    new SpreadsheetSumCell( newFunctionCellArguments )
                )
            ;
        }
        //TODO: add more "else if" for new supported functions
        for (auto itr = oldCellObservers.cbegin(); itr != oldCellObservers.cend(); ++itr) {
            if ( dynamic_cast<SpreadsheetFunctionCell*>(*itr) != nullptr ) {
                dynamic_cast<SpreadsheetFunctionCell*>(*itr)->addArgument( (*itrPointingTheNewCell).get() );
            }
        }
    }
    catch (...) {
        const auto itrFollowingTheLastDeletedCell =
            ( rowContainingTheOldCell.size() == numberOfColumns ) ?
            rowContainingTheOldCell.erase( itrPointingTheNewCell ) :
            itrFollowingTheDeletedCell
        ;
        if ( oldCellIsEmpty ) {
            rowContainingTheOldCell.emplace(
                itrFollowingTheLastDeletedCell,
                new SpreadsheetEmptyCell()
            );
        }
        else if ( ! oldCellIsFunction ) {
            if ( ! oldCellIsNumeric ) {
                rowContainingTheOldCell.emplace(
                    itrFollowingTheLastDeletedCell,
                    new SpreadsheetRawTextualCell(oldCellAsText)
                );
            }
            else {
                rowContainingTheOldCell.emplace(
                    itrFollowingTheLastDeletedCell,
                    new SpreadsheetRawNumericCell(oldCellAsNumericValue)
                );
            }
        }
        else {
            if ( oldCellFunction == Spreadsheet::Function::sum ) {
                rowContainingTheOldCell.emplace(
                    itrFollowingTheLastDeletedCell,
                    new SpreadsheetSumCell(oldCellArguments)
                );
            }
            // TODO: add more "else if" for more functions
        }
        for (auto itr = oldCellObservers.cbegin(); itr != oldCellObservers.cend(); ++itr) {
            if ( dynamic_cast<SpreadsheetFunctionCell*>(*itr) != nullptr ) {
                dynamic_cast<SpreadsheetFunctionCell*>(*itr)->addArgument( getCellAt(coordinates) );
            }
        }
        throw;
    }
    //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
}

SpreadsheetCell* Spreadsheet::getCellAt(const SpreadsheetCellCoordinates& coordinates) const {
    outOfRangeCheck(coordinates);
    return ( ( cells[coordinates.getRowIndex()-1] )[coordinates.getColumnIndexAsInteger()-1] ).get();
}

std::set<SpreadsheetCell*> Spreadsheet::getCellsAt(const std::set<SpreadsheetCellCoordinates>& coordinatesSet) const {
    std::set<SpreadsheetCell*> setToReturn;
    for (auto itr = coordinatesSet.cbegin(); itr != coordinatesSet.cend(); ++itr) {
        outOfRangeCheck(*itr);
        setToReturn.insert( getCellAt( *itr ) );
    }
    return setToReturn;
}

void Spreadsheet::outOfRangeCheck(const SpreadsheetCellCoordinates& coordinates) const {
    if ( coordinates.getRowIndex() > getNumberOfRows() || coordinates.getColumnIndexAsInteger() > getNumberOfColumns() ) {
        throw std::out_of_range("error"); //TODO: insert an error message
    }
}

void Spreadsheet::outOfRangeCheck(const std::set<SpreadsheetCellCoordinates>& coordinatesSet) const {
    for (auto itr = coordinatesSet.cbegin(); itr != coordinatesSet.cend(); ++itr) {
        outOfRangeCheck(*itr);
    }
}

bool Spreadsheet::isFunctionCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetFunctionCell*>(cell) != nullptr;
}

bool Spreadsheet::isFunctionCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isFunctionCell(getCellAt(coordinates));
}

bool Spreadsheet::isNumericCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetNumericCell*>(cell) != nullptr;
}

bool Spreadsheet::isNumericCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isNumericCell(getCellAt(coordinates));
}

bool Spreadsheet::isOnlyTextualCell(const SpreadsheetCell* const cell) {
    return !isNumericCell(cell);
}

bool Spreadsheet::isOnlyTextualCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isOnlyTextualCell(getCellAt(coordinates));
}

bool Spreadsheet::isRawNumericCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetRawNumericCell*>(cell) != nullptr;
}

bool Spreadsheet::isRawNumericCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isRawNumericCell(getCellAt(coordinates));
}

bool Spreadsheet::isRawOnlyTextualCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetRawTextualCell*>(cell) != nullptr;
}

bool Spreadsheet::isRawOnlyTextualCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isRawOnlyTextualCell(getCellAt(coordinates));
}
