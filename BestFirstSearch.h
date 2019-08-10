//
// Created by gal on 1/5/19.
//

#ifndef PART2_BESTFIRSTSEARCH_H
#define PART2_BESTFIRSTSEARCH_H

#include "ISearchable.h"
#include "PrioritySearcher.h"
#include <unordered_set>
#include <deque>


using namespace std;

/*
 * This class implements the PrioritySearcher abstract class as a Best First Search algorithm
 */
template<class solution, class T>
class BestFirstSearch : public PrioritySearcher<solution, T> {
public:

    /*
     * This method gets a searchable problem runs the Best First Search algorithm and returns
     * the minimal path it found
     */
    solution search(ISearchable<T> *searchable) {
        PrioritySearcher<solution, T>::addToOpenList(searchable->getInitialState()); // inherited from PrioritySearcher
        multiset<State<T>*,CompareCost<T>> closed; // This list hold all the states that have already been processed
        while (PrioritySearcher<solution, T>::openList.size() > 0)
        {
            State<T>* n = PrioritySearcher<solution, T>::popOpenList(); // inherited from PrioritySearcher, removes the best state
            closed.insert(n); // We insert it into the close list so it won't be processed again
            // If we have reached the goal state we will trace back the path wee found and return it
            if (searchable->isGoalState(n))
            {
                return PrioritySearcher<solution, T>::backTrace(n, searchable);
            }

            list<State<T>*> successors = searchable->getAllPossibleStates(n); // calling the delegated method, returns a list of states with n as a parent

            // We iterate through all the successors state
            for (auto it = successors.begin(); it != successors.end(); it++) {
                // if the state isn't found in the open list and also the closed list we will add it to the open list
                if ((!isInSet(PrioritySearcher<solution, T>::openList,*it)) && (!(isInSet(closed,*it)))) {
                    State<T>* s = *it;
                    this->addToOpenList(s);
                }

                /* if the state isn't found in the closed list but is found in the open list, we will check if it has smaller
                * cost then what is already found in the open list and if it has we will replace the old cost with the new one
                */
                else if (!(isInSet(closed,*it)))
                {
                    saveMin(*it);
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

};


#endif //PART2_BESTFIRSTSEARCH_H
