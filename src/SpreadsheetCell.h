#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H

#include <set>

#include "Spreadsheet.h"
#include "utility/Subject.h"

class Spreadsheet::Cell : public Subject {
    public:
        virtual ~Cell();
        virtual bool isEmpty() const = 0;
        virtual std::string getAsText() const = 0;
        virtual void notify() override final;
        virtual void addObserver(Observer* observer) override final;
        virtual void removeObserver(Observer* observer) override final;
    private:
        std::set<Spreadsheet::FunctionCell*> functionCellsObservers;
};

#endif //SPREADSHEETCELL_H