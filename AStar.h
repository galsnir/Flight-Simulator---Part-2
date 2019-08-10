//
// Created by gal on 1/10/19.
//

#ifndef PART2_ASTAR_H
#define PART2_ASTAR_H

#include "PrioritySearcher.h"

/*
 * This class implements the PrioritySearcher abstract class as a A* algorithm
 */
template<class solution, class T>
class AStar : public PrioritySearcher<solution, T> {

public:

    /*
     * This method gets a searchable problem runs the A* algorithm and returns
     * the minimal path it found
     */
    solution search(ISearchable<T> *searchable) {
        State<T>* initState = searchable->getInitialState();
        initState->setCost(initState->getCost() + getManDist(initState,searchable->getGoalState()));
        PrioritySearcher<solution, T>::addToOpenList(initState); // inherited from PrioritySearcher
        multiset<State<T>*,CompareCost<T>> closed; // This list hold all the states that have already been processed
        while (PrioritySearcher<solution, T>::openList.size() > 0) {
            State<T>* n = PrioritySearcher<solution, T>::popOpenList(); // inherited from PrioritySearcher, removes the best state
            closed.insert(n); // We insert it into the close list so it won't be processed again
            // If we have reached the goal state we will trace back the path wee found and return it
            if (searchable->isGoalState(n))
            {
                n->setCost(n->getCost() - getManDist(n,searchable->getGoalState())); // We decrease the last huristic from the goal state
                return PrioritySearcher<solution, T>::backTrace(n,searchable); // private method, back traces through the parents
            }

            list<State<T>*> successors = searchable->getAllPossibleStates(n); // calling the delegated method, returns a list of states with n as a parent

            // We iterate through all the successors state
            for (auto it = successors.begin(); it != successors.end(); it++) {

                State<T>* s = *it;
                // if the state isn't found in the open list and also the closed list we will add it to the open list
                if ((!isInSet(PrioritySearcher<solution, T>::openList,s)) && (!(isInSet(closed,s)))) {
                    // We add to the coat of each state his distance from the goal state and decrease the distance from goal state from his parent state
                    s->setCost(s->getCost() + getManDist(s,searchable->getGoalState()) - getManDist(n,searchable->getGoalState()));
                    this->addToOpenList(s);
                }

                /* if the state isn't found in the closed list but is found in the open list, we will check if it has smaller
                * cost then what is already found in the open list and if it has we will replace the old cost with the new one
                */
                else if (!(isInSet(closed,s)))
                {
                    saveMin(s);
                }
            }
        }
    }

    /* This method checks if a state is found in the open list, and if it's cost is smaller then the state inside
     * the open list we will replace it's cost with the new cost
     */
    virtual void saveMin(State<T>* currState)
    {
        for (auto it = PrioritySearcher<solution,T>::openList.begin(); it != PrioritySearcher<solution,T>::openList.end(); it++)
        {

            State<T>* s = *it;
            if(s->Equals(currState))
            {
                if (currState->getCost() < s->getCost())
                {
                    PrioritySearcher<solution,T>::openList.erase(it);
                    this->addToOpenList(currState);
                }
                return;
            }
        }
        this->addToOpenList(currState);
        return;
    }

    // This method checks if a state is inside a multiset
    bool isInSet(multiset<State<T>*,CompareCost<T>> setOfState,State<T>* currState)
    {
        for (auto it = setOfState.begin(); it != setOfState.end(); it++)
        {
            State<T>* s = *it;
            if(s->Equals(currState))
                return true;
        }
        return false;
    }

    // This method calculates the Manhattan distance of a state from the goal state and returns it
    int getManDist(State<T>* currState, T goalState)
    {
        int xDist = goalState[0] - currState->getState()[0];
        int yDist = goalState[1] - currState->getState()[1];
        return abs(xDist) + abs(yDist);
    }
};


#endif //PART2_ASTAR_H
