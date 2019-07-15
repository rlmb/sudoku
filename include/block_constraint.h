#pragma once

#include <vector>
#include <unordered_set>

class Place;

class BlockConstraint
{

private:
    std::vector<const Place*> nummer_places;

public:
    /**
     * @brief Constructor
     */
    BlockConstraint();

    /**
     * @brief Add a place to this constraint
     *
     * @param reference to the place to add
     */  
    void addPlace(Place& place);    
    
    /**
     * @brief Check if the constraint is satisfied
     *
     * @return true if satisfied, false otherwise
     */
    bool isSatisfied() const;
    
    /**
     * @brief Get the already set values for this constraint
     *
     * @return set of set values
     */ 
    std::unordered_set<int> getSetValues() const;
};
