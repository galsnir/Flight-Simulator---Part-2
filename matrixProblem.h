//
// Created by gal on 1/6/19.
//

#ifndef PART2_MATRIXPROBLEM_H
#define PART2_MATRIXPROBLEM_H

#include "ISearchable.h"
#include "unordered_set"
#include <list>
#include <vector>
#include <iostream>

using namespace std;

/*
 * This class extends the ISearchable interface, and reprsent the problem of sreaching the
 * shortest path in a matrix maze
 */
class matrixProblem : public ISearchable<vector<int>>
{
    vector<vector<int>> matrix;
    int length;
    int width;
    vector<int> initState;
    vector<int> goalState;
    list<State<vector<int>>*> allocManger; // This vector will hold all of our dynamic allocations of the class

public:

     /**
     * The constructor of this class gets a matrix which is represented by a vector of strings,
     * the initial state which is represented by vector of int, and a goal state which is represented
     * the same way, the contructor builds a matrix of int using a split function, and
     * sets all of the class members
     */
    matrixProblem(vector<string> mat, vector<int> initState, vector<int> goalState)
    {
        vector<vector<int>> tempMat;
        // We create the matrix of ints out of the vector of strings
        for (auto it = mat.begin(); it != mat.end(); it++)
        {
            vector<int> line;
            vector<string> values = splitLine(*it,",");
            for (auto it = values.begin(); it != values.end(); it++)
            {
                line.push_back(std::stoi(*it));
            }
            tempMat.push_back(line);
        }

        this->matrix = tempMat;
        this->length = tempMat.size();
        this->width = tempMat[0].size();
        this->initState = initState;
        this->goalState = goalState;
        //this->allocManger = new list<State<vector<int>>*>();
    }

    /**
     * This method creates the initial state and returns it
     */
    virtual State<vector<int>>* getInitialState()
    {
        State<vector<int>>* s = new State<vector<int>>(initState,0,NULL,"");
        this->allocManger.push_back(s);
        return s;
    }

    /**
     * This method checks if the input string is the goal state
     */
    virtual bool isGoalState(State<vector<int>>* curState)
    {
        if (curState->getState() == goalState)
            return true;
        else
            return false;
    }

    /**
     * This method returns the coordinates of the goal state
     */
    virtual vector<int> getGoalState()
    {
            return goalState;
    }

    /**
     * This method returns all the possible states the we can get to from
     * the input state (in the matrix maze case they are up,down,left,right)
     */
    virtual list<State<vector<int>>*> getAllPossibleStates(State<vector<int>>* s)
    {
        int minCol = 0;
        int maxCol = width-1;
        int minRow = 0;
        int maxRow = length-1;
        int i = s->getState()[0]; // Setting the i coordinate from the input state
        int j = s->getState()[1]; // Setting the j coordinate from the input state
        list<State<vector<int>>*> posStates; // This vector will hold the possible states we can get to

        // We check if the up move is possible' and if it is we create the left state and add it to the posStates vector
        if ((i-1 >= minRow) && (matrix[i-1][j] != -1))
        {
            vector<int> up = {i - 1, j};
            State<vector<int>>* upState = new State<vector<int>>(up,s->getCost() + matrix[i-1][j], s, "Up");
            posStates.push_back(upState);
            this->allocManger.push_back(upState);
        }

        // We check if the down move is possible' and if it is we create the left state and add it to the posStates vector
        if ((i+1 <= maxRow) && (matrix[i+1][j] != -1))
        {
            vector<int> down = {i + 1, j};
            State<vector<int>>* downState = new State<vector<int>>(down,s->getCost() + matrix[i+1][j], s , "Down");
            posStates.push_back(downState);
            this->allocManger.push_back(downState);
        }

        // We check if the left move is possible' and if it is we create the left state and add it to the posStates vector
        if ((j-1 >= minCol) && (matrix[i][j-1] != -1))
        {
            vector<int> left = {i, j - 1};
            State<vector<int>>* leftState = new State<vector<int>>(left,s->getCost() + matrix[i][j-1], s, "Left");
            posStates.push_back(leftState);
            this->allocManger.push_back(leftState);
        }

        // We check if the right move is possible' and if it is we create the left state and add it to the posStates vector
        if ((j+1 <= maxCol)  && (matrix[i][j+1] != -1))
        {
            vector<int> right = {i, j + 1};
            State<vector<int>>* rightState = new State<vector<int>>(right,s->getCost() + matrix[i][j+1], s, "Right");
            posStates.push_back(rightState);
            this->allocManger.push_back(rightState);
        }

        return posStates;
    }


    // This method gets a string and a parser and splits the string between the pareser char apperences
    vector<string> splitLine(string s,string parser)
    {
        vector<string> vec;
        while(s.size() > 0)
        {
            int i = s.find(parser);
            if (i != string::npos)
            {
                vec.push_back(s.substr(0, i)); //We push the string between the parser appearences into the vector
                s = s.substr(i + parser.size());
                if (s.size() == 0)
                {
                    vec.push_back(s);
                }
            }

            else
            {
                vec.push_back(s);
                s="";
            }
        }
        return vec;
    }

    // This method returns the size of the matrix
    int getProblemSize ()
    {
        return length*width;
    }

    // The destructor deletes all the dynmic allocations we added to the allocManger vector
    ~matrixProblem()
    {
        for (auto it = this->allocManger.begin();it != this->allocManger.end(); it++)
        {
            delete *it;
        }
        //delete this->allocManger;
    }
};
#endif //PART2_MATRIXPROBLEM_H
