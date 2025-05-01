#include "SpreadsheetController.h"
#include <stdexcept>

SpreadsheetController::SpreadsheetController(Spreadsheet* const spreadsheet) : spreadsheet(spreadsheet) {}

void SpreadsheetController::deleteCellContentAt(const std::string& cellCoordinatesAsString) const {
    const auto parseReturn = parseAsCellCoordinates(cellCoordinatesAsString);
    if ( parseReturn.first ) {
        spreadsheet->deleteCellContentAt(parseReturn.second);
    }
    else {
        throw std::invalid_argument(" "); //TODO: add error message
    }
}

void SpreadsheetController::deleteCellContentAt(const SpreadsheetCellCoordinates& coordinates) const {
    spreadsheet->deleteCellContentAt(coordinates);
}

void SpreadsheetController::setCellAt(const std::string& cellCoordinatesAsString, const std::string& string) const {
    const auto cellCoordinatesAsStringParseReturn = parseAsCellCoordinates(cellCoordinatesAsString);
    if ( cellCoordinatesAsStringParseReturn.first ) {
        const auto stringParseReturn = parseAsDouble(string);
        if ( string.empty() ) {
            spreadsheet->deleteCellContentAt(cellCoordinatesAsStringParseReturn.second);
        }
        else if ( stringParseReturn.first ) {
            spreadsheet->setValueAt(cellCoordinatesAsStringParseReturn.second, stringParseReturn.second);
        }
        else {
            spreadsheet->setValueAt(cellCoordinatesAsStringParseReturn.second, string);
        }
    }
    else {
        throw std::invalid_argument(" "); //TODO: add error message
    }
}

void SpreadsheetController::setCellAt(const SpreadsheetCellCoordinates& coordinates, const std::string& string) const {
    const auto stringParseReturn = parseAsDouble(string);
    if ( string.empty() ) {
        spreadsheet->deleteCellContentAt(coordinates);
    }
    else if ( stringParseReturn.first ) {
        spreadsheet->setValueAt(coordinates, stringParseReturn.second);
    }
    else {
        spreadsheet->setValueAt(coordinates, string);
    }
}

void SpreadsheetController::setSumCellAt(
    const std::string& cellCoordinatesAsString,
    const std::set<std::string>& argumentsCoordinatesAsString ) const {

    const auto cellCoordinatesAsStringParseReturn = parseAsCellCoordinates(cellCoordinatesAsString);
    if ( cellCoordinatesAsStringParseReturn.first ) {
        std::set<SpreadsheetCellCoordinates> argumentsCoordinates;
        for (auto itr = argumentsCoordinatesAsString.cbegin(); itr != argumentsCoordinatesAsString.cend(); ++itr) {
            const auto argumentParseReturn = parseAsCellCoordinates(*itr);
            if ( argumentParseReturn.first ) {
                argumentsCoordinates.emplace( argumentParseReturn.second );
            }
            else {
                throw std::invalid_argument(" "); //TODO: add error message
            }
        }
        spreadsheet->setFunctionAt(cellCoordinatesAsStringParseReturn.second, Spreadsheet::Function::sum, argumentsCoordinates);
    }
    else {
        throw std::invalid_argument(" "); //TODO: add error message
    }

}

void SpreadsheetController::setSumCellAt(
    const SpreadsheetCellCoordinates& coordinates,
    const std::set<SpreadsheetCellCoordinates>& argumentsCoordinates) const {
    spreadsheet->setFunctionAt(coordinates, Spreadsheet::Function::sum, argumentsCoordinates);
}

std::pair<bool, double> SpreadsheetController::parseAsDouble(const std::string& string) {
    const std::pair<bool,double> falseReturn = {false, 0.0};
    if ( string.empty() ) {
        return falseReturn;
    }
    std::size_t numberOfCharactersProcessed = 0;
    try {
        double returnValue = std::stod(string, &numberOfCharactersProcessed);
        if ( numberOfCharactersProcessed != string.size() ) {
            return falseReturn;
        }
        return {true, returnValue};
    }
    catch (const std::invalid_argument&) {
        return falseReturn;
    }
}

std::pair<bool,SpreadsheetCellCoordinates> SpreadsheetController::parseAsCellCoordinates(const std::string& string) {
    const std::pair<bool,SpreadsheetCellCoordinates> falseReturn = {false, SpreadsheetCellCoordinates(1,1)};
    for (std::size_t i = 0; i < string.size(); ++i) {
        if ( ( ! std::isalpha( string.at(i) ) ) || ( ! std::isupper( string.at(i) ) ) ) {
            if ( ( i == 0 ) || ( ! std::isdigit( string.at(i) ) ) ) {
                return falseReturn;
            }
            // Here i >= 1 && std::isdigit( string.at(i) )
            const std::string columnAsString = string.substr(0,i);

            const std::string possibleRowAsString = string.substr(i);
            std::size_t numberOfCharacterProcessed = 0;
            try {
                const auto rowValueAsUnsignedInteger = std::stoull(possibleRowAsString,&numberOfCharacterProcessed);
                if ( numberOfCharacterProcessed != possibleRowAsString.size() ) {
                    return falseReturn;
                }
                return {true, SpreadsheetCellCoordinates(columnAsString,rowValueAsUnsignedInteger) };
            }
            catch (const std::invalid_argument&) {
                return falseReturn;
            }
        }
    }
    return falseReturn;
}
