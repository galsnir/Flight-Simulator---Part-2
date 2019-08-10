//
// Created by gal on 1/12/19.
//

#ifndef PART2_STACKSEARCHER_H
#define PART2_STACKSEARCHER_H
#include "ISearcher.h"
#include "CompareCost.h"
#include <deque>


/**
 * This class extends the ISearcher interface, and represents an abstract class of an algorithm
 * which solve a search problem using a stack
 */
template <class solution,class T>
class StackSearcher : public ISearcher<solution,T>{
protected:
    deque<State<T>*> openList; // This dequeue holds the states which are waiting to be processed
    int pathLength;
    int evaluatedNodes;

    /* When we will want to insert a state to the open list we will push it to the front of the
     * list to represents pushing an object to a stack
    */
    void addToOpenList(State<T>* s)
    {
        this->openList.push_front(s);
    }

    /* When we will want to extract a state from the open list we will return it and erase him from the list
    * to represents popping an object form a stack
    */
    State<T>* popOpenList()
    {
        evaluatedNodes++;
        State<T>* s  = *(openList.begin());
        openList.pop_back();
        return s;
    }

public:
    StackSearcher()
    {
        evaluatedNodes = 0;
    }
    virtual solution search (ISearchable<T>* searchable) = 0; // the search method
    int getNumberOfNodesEvaluated() // get how many nodes were evaluated by the algorithm
    {
        return evaluatedNodes;
    }

    /* This method returns what is the the min path we found using the algorithm
    */
    virtual int getPathLength()
    {
        return pathLength;
    }

    /* This method traces back the path the algorithm found, and returns which steps were taken on this path
    */
    solution backTrace(State<T>* currState, ISearchable<T> *searchable) {
        deque<string> path;
        string ans = "";
        this->pathLength = currState->getCost();
        State<T> *initState = searchable->getInitialState();
        while (!(currState->Equals(initState))) {
            path.push_front(currState->getCameFromDir());
            currState = currState->getCameFrom();
        }

        auto it = path.begin();
        ans += *it;
        it++;

        for (; it != path.end(); it++) {
            ans += ",";
            ans += *it;
        }
        return ans;
    }
};


#endif //PART2_STACKSEARCHER_H
