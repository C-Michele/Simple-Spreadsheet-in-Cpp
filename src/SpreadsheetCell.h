#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H

#include <set>
#include <string>

#include "utility/Subject.h"
#include "utility/Observer.h"

class SpreadsheetCell : public virtual Subject {
    public:
        SpreadsheetCell() = default;
        SpreadsheetCell(const SpreadsheetCell&) = delete;
        SpreadsheetCell(SpreadsheetCell&&) = delete;
        virtual ~SpreadsheetCell();

        virtual bool isEmpty() const = 0;
        virtual std::string getAsText() const = 0;
        std::set<Observer*> getObservers() const;

        virtual void notify() override final;
        virtual void addObserver(Observer* observer) override final;
        virtual void removeObserver(Observer* observer) override final;

        SpreadsheetCell& operator=(SpreadsheetCell&) = delete;
        SpreadsheetCell& operator=(SpreadsheetCell&&) = delete;
    private:
        std::set<Observer*> functionCellsObservers;
};



#endif //SPREADSHEETCELL_H
