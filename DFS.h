//
// Created by gal on 1/5/19.
//

#ifndef PART2_DFS_H
#define PART2_DFS_H

#include "ISearchable.h"
#include "StackSearcher.h"
#include "DFS.h"
#include <stack>
#include <set>


/*
 * This class implements the PrioritySearcher abstract class as a DFS algorithm
 */
template <class solution,class T>
class DFS : public StackSearcher<solution,T> {
public:

     /* This method gets a searchable problem runs the DFS algorithm and returns
     * the minimal path it found
     */
    solution search(ISearchable<T> *searchable) {
        StackSearcher<solution, T>::addToOpenList(searchable->getInitialState()); // inherited from QueueSearcher
        deque<State<T>*> closed; // This list hold all the states that have already been processed

        while (StackSearcher<solution, T>::openList.size() > 0) {
            State<T>* n = StackSearcher<solution, T>::popOpenList(); // inherited from StackSearcher, removes the best state
            closed.push_back(n); // We insert it into the close list so it won't be processed again
            // If we have reached the goal state we will trace back the path wee found and return it
            if (searchable->isGoalState(n))
                return StackSearcher<solution, T>::backTrace(n, searchable);
            // We iterate through all the successors state
            list<State<T>*> successors = searchable->getAllPossibleStates(n); // calling the delegated method, returns a list of states with n as a parent
            for (auto it = successors.begin(); it != successors.end(); it++) {
                // if the state isn't found in the open list and also the closed list we will add it to the open list
                if ((!(isInSet(StackSearcher<solution, T>::openList,*it))) && !(isInSet(closed,*it))) {
                    State<T>* s = *it;
                    this->addToOpenList(s);
                }
            }
        }
    }

    // This method checks if a state is inside a dequeue
    bool isInSet(deque<State<T>*> setOfState,State<T>* currState)
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


#endif //PART2_DFS_H
