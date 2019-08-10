//
// Created by gal on 1/6/19.
//

#ifndef PART2_SOLVER_H
#define PART2_SOLVER_H
#include "ISearcher.h"
template <class problem,class solution,class T>
class Solver {
    ISearcher<solution,T>* searcher;
public:
    virtual solution solve(problem p) = 0;
};


#endif //PART2_SOLVER_H
