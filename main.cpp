#include <iostream>
#include <string>

#include "CompareCost.h"
#include "State.h"
#include <set>
#include <string>
#include "matrixProblem.h"
#include "ISearcher.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"

using namespace std;
int main() {

    //string line1 = " 1, 1, 1"; //, 5, 7, 0, 7, 6, 3, 7, 8";
    //string line2 = " 1, 2, 1"; //, 8, 1, 0, 5, 5, 7, 8, 4";
    //string line3 = " 1, 1, 1"; //, 8, 1, 1, 9, 3, 3, 0, 7";

    string line1 = " 4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8";
    string line2 = " 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4";
    string line3 = " 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7";
    string line4 = " 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7";
    string line5 = " 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1";
    string line6 = " 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9";
    string line7 = " 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8";
    string line8 = "10, 8, 0, 2, 3, 8, 0,10,10, 2, 7";
    string line9 = " 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1";
    string line10 = " 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1";
    string line11 = " 5,10, 1,10, 7, 7, 3,10, 8, 0, 6";
    //string line11 = "5,10,1,10,7,7,3,10,8,0,6";
    //string line1 = "1,0,100";
    //string line2 = "100,0,100";
   /// string line3 = "100,0,1";

    vector<string> matrix = {line1,line2,line3,line4,line5,line6,line7,line8,line9,line10,line11};
    vector<int> enter = {0,0};
    vector<int> exit = {10,10};
    ISearchable<vector<int>>* mat = new matrixProblem(matrix,enter,exit);
    ISearcher<string,vector<int>>* algo = new AStar<string,vector<int>>();
    string sol = algo->search(mat);
    int numberOfNodes = algo->getNumberOfNodesEvaluated();
    int minPathLength = algo->getPathLength();

    delete mat;
    delete algo;
    return 0;
}