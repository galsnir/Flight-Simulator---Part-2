//
// Created by gal on 1/5/19.
//

#ifndef PART2_BFS_H
#define PART2_BFS_H

#include "ISearchable.h"
#include "QueueSearcher.h"
#include <list>

/*
 * This class implements the PrioritySearcher abstract class as a BFS algorithm
 */
template <class solution,class T>
class BFS : public QueueSearcher<solution,T> {
public:

    /*
     * This method gets a searchable problem runs the BFS algorithm and returns
     * the minimal path it found
     */
    solution search(ISearchable<T>* searchable)
    {
        State<T>* s = searchable->getInitialState(); // inherited from QueueSearcher
        deque<State<T>*> closed; // This list hold all the states that have already been processed
        QueueSearcher<solution, T>::addToOpenList(s);

        while (QueueSearcher<solution, T>::openList.size() > 0)
        {
            State<T>* n = QueueSearcher<solution, T>::popOpenList(); // inherited from QueueSearcher, removes the best state
            closed.push_back(n); // We insert it into the close list so it won't be processed again
            // If we have reached the goal state we will trace back the path wee found and return it
            if (searchable->isGoalState(n))
                return QueueSearcher<solution, T>::backTrace(n, searchable);
            list<State<T>*> successors = searchable->getAllPossibleStates(n); // calling the delegated method, returns a list of states with n as a parent
            // We iterate through all the successors state
            for (auto it = successors.begin(); it != successors.end(); it++)
            {
                // if the state isn't found in the open list and also the closed list we will add it to the open list
                if ((!(isInSet(QueueSearcher<solution, T>::openList,*it))) && !(isInSet(closed,*it)))
                {
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


#endif //PART2_BFS_H
