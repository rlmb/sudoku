#include "block_constraint.h"
#include <unordered_set>
#include <iostream>
#include "place.h"


BlockConstraint::BlockConstraint()
{
}

void BlockConstraint::addPlace(Place& place)
{
    nummer_places.push_back(&place);
    place.registerConstraint(this);
}


bool BlockConstraint::isSatisfied() const
{
    std::unordered_set<int> values;
    for (const auto& place: nummer_places) {
        if (!place->isSet()) {
            continue;
        }
    
        auto result = values.insert(place->getValue());
        if (!result.second) {
            // Value was not inserted meaning it already existed
            return false;
        }
    }
    
    return true;
}

std::unordered_set<int> BlockConstraint::getSetValues() const
{
    std::unordered_set<int> setValues;
    
    for (const auto& place: nummer_places) {
        if (place->isSet()) {
            setValues.insert(place->getValue());
        }
    }
    
    return setValues;
}

