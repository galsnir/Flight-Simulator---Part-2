//
// Created by gal on 1/5/19.
//

#ifndef PART2_ISEARCHABLE_H
#define PART2_ISEARCHABLE_H
#include <set>
#include <list>
#include "State.h"

template <class T>
class ISearchable {
public:
    virtual State<T>* getInitialState() = 0; // Get the state you want to search a path from
    virtual bool isGoalState(State<T>* curState) = 0; // checks if a state is the goal state
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) = 0; // returns all the possible states you can get to from an input state
    virtual int getProblemSize() = 0; // returns the size of the problem
    virtual T getGoalState() = 0; // returns the state you want to search a path to
    virtual ~ISearchable(){}
};

#endif //PART2_ISEARCHABLE_H
