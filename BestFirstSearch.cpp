//
// Created by gal on 1/5/19.
//

#include "BestFirstSearch.h"

/*
vector<State> BestFirstSearch::search(ISearchable* searchable) {
    addToOpenList(searchable->getInitialState()); // inherited from PrioritySearcher
    set<State> *closed = new set<State>();
    while (openList.size() > 0) {
        State n = popOpenList(); // inherited from PrioritySearcher, removes the best state
        closed->insert(n);
        if (searchable->isGoalState(n))
            return backTrace(); // private method, back traces through the parents
// calling the delegated method, returns a list of states with n as a parent
        set<State> succerssors = searchable->getAllPossibleStates(n);
        for (set<State>::iterator it = succerssors.begin(); it != succerssors.end(); it++) {
            if (closed->count(*it) == 0 && openList.count(*it) == 0) {
                State s = *it;
                s.setCameFrom(n);
                addToOpenList(s);
            } else {
                saveMin(*it);
            }
        }
    }
}

void BestFirstSearch::saveMin(State currState)
{
    for (auto it = this->openList.begin(); it != this->openList.end(); it++)
    {
        it.
        {
            if (currState.getCost() > (*it).getCost())
            {
                openList.erase(*it);
                openList.insert(currState);
                return;
            }
        }
    }
    openList.insert(currState);
    return;
}


        void BestFirstSearch::saveMin(State currState)
        {
            for (set<State>::iterator it = openList.begin(); it != openList.end(); it++)
            {
                if (*it).Equals(currState)
                {
                    if (currState.getCost() > (*it).getCost())
                    {
                        openList.erase(*it);
                        openList.insert(currState);
                        return;
                    }
                }
            }
            openList.insert(currState);
            return;
        }

        */