cmake_minimum_required(VERSION 3.13)
project(part2)

set(CMAKE_CXX_STANDARD 14)

add_executable(part2 main.cpp FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h State.cpp State.h ISearchable.cpp ISearchable.h ISearcher.cpp ISearcher.h PrioritySearcher.cpp PrioritySearcher.h BestFirstSearch.cpp BestFirstSearch.h CompareCost.cpp CompareCost.h BFS.cpp BFS.h DFS.cpp DFS.h Solver.cpp Solver.h matrixProblem.cpp matrixProblem.h AStar.cpp AStar.h QueueSearcher.cpp QueueSearcher.h StackSearcher.cpp StackSearcher.h)