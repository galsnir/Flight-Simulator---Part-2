//
// Created by gal on 1/5/19.
//

#ifndef PART2_ISEARCHER_H
#define PART2_ISEARCHER_H

#include "ISearchable.h"
#include <vector>

template <class solution,class T>
class ISearcher {
public:
    virtual solution search (ISearchable<T>* searchable) = 0; // the search method
    virtual int getNumberOfNodesEvaluated() = 0; // get how many nodes were evaluated by the algorithm
    virtual int getPathLength() = 0; // get how many nodes were evaluated by the algorithm
};


#endif //PART2_ISEARCHER_H
