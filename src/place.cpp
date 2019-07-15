#include "place.h"
#include <functional>
#include "block_constraint.h"
#include <iostream>


Place::Place()
{
    value = 0;
}
   
void Place::setValue(int newValue)
{
    value = newValue;
}

int Place::getValue() const
{
    return value;
}

void Place::unsetValue()
{
    value = 0;
}

bool Place::isSet() const
{
    return value > 0;
}

void Place::registerConstraint(const BlockConstraint* constraint)
{
    constraints.push_back(constraint);
}

std::unordered_set<int> Place::getPossibilities() const
{
    // Get already set values
    std::unordered_set<int> setValues;
    for (const auto& constraint: constraints) {
        const auto& values = constraint->getSetValues();
        setValues.insert(values.begin(), values.end());
    }
    
    // Derive remaining possibilities
    std::unordered_set<int> possibilities = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int setValue: setValues) {
        possibilities.erase(setValue);
    }
    return possibilities;
}

bool Place::assignNextPossibility()
{
    // If already set, it means the value failed
    if (this->isSet()) {
        failed_possibilities.insert(this->getValue());
    }

    // Try to assign a new value
    for (int possibility: this->getPossibilities()) {
        if (failed_possibilities.find(possibility) == failed_possibilities.end()) {
            this->setValue(possibility);
            return true;
        }
    }
    
    // No new value found
    this->unsetValue();
    failed_possibilities.clear();
    return false;
}

