//
// Created by gal on 1/5/19.
//

#ifndef PART2_SEARCHER_H
#define PART2_SEARCHER_H
#include <queue>
#include "ISearcher.h"
#include "State.h"
#include "CompareCost.h"
using namespace std;

template <class solution,class T>
class PrioritySearcher : public ISearcher<solution,T>
{
protected:
    /* This multiset holds the states which are waiting to be processed, it is sorted from the smallest cost
    * to the largest cost to represent an priority queue
    */
    multiset<State<T>*,CompareCost<T>> openList;
    int evaluatedNodes;
    int pathLength;

    /* When we will want to insert a state to the open list we will insert it into the open list
     * and the multiset will sort itself according to it's cost value
     */
    void addToOpenList(State<T>* s)
    {
        this->openList.insert(s);
    }

    /* When we will want to extract a state from the open list we will erase it from the open list,
     * return it, and the multiset will sort itself accordingly
     */
    State<T>* popOpenList()
    {
        evaluatedNodes++;
        auto it = openList.begin();
        State<T>* sa = *it;
        openList.erase(it);
        return sa;
    }

public:
    PrioritySearcher()
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
    solution backTrace(State<T>* currState, ISearchable<T> *searchable)
    {
        deque<string> path;
        string ans = "";
        this->pathLength = currState->getCost();
        State<T>* initState = searchable->getInitialState();

        while (!(currState->Equals(initState)))
        {
            path.push_front(currState->getCameFromDir());
            currState = currState->getCameFrom();
        }

        auto it = path.begin();
        ans += *it;
        it++;

        for (; it != path.end(); it++)
        {
            ans += ",";
            ans += *it;
        }
        return ans;
    }
};

#endif //PART2_SEARCHER_H
