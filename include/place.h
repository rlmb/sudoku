#pragma once

#include <vector>
#include <unordered_set>

class BlockConstraint;

class Place
{

private:
    int value;
    std::vector<const BlockConstraint*> constraints;

    std::unordered_set<int> failed_possibilities;

public:
    /**
     * @brief Constructor
     */
    Place();
   
    /**
     * @brief Set value for this place
     *
     * @param newValue
     */
    void setValue(int newValue);
    /**
     * @brief Get the value for this place
     *
     * @return value
     */
    int getValue() const;
    /**
     * @brief Unset value for this place
     */
    void unsetValue();
    /**
     * @brief Check if the value for this place is set, i.e. different from 0
     *
     * @return value
     */    
    bool isSet() const;
    
    /**
     * @brief Register a constraint associated to this place
     *
     * @param BlockConstraint pointer
     */    
    void registerConstraint(const BlockConstraint* constraint);
    
    /**
     * @brief Get the possibilities for this place satisfying the register constraints
     *
     * @return set of possibilities
     */    
    std::unordered_set<int> getPossibilities() const;
    
    /**
     * @brief Assign the next valid possibility
     *
     * @return true if possible, false otherwise
     */
    bool assignNextPossibility();
};
