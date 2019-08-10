//
// Created by gal on 1/3/19.
//

#include "FileCacheManager.h"

FileCacheManager::FileCacheManager()
{
    string line;
    vector<string> splitedValues;
    ifstream infile("Solultions.txt");
    if(!infile.is_open())
    {
        ofstream out("Solultions.txt");
    }
    string problem;
    string solution;
    while (getline(infile, line)) {
        splitedValues = splitLine(line," ");
        problem = splitedValues[0];
        solution = splitedValues[1];
        this->addToTable(problem,solution);
    }
    infile.close();
}

/*This fuction get a Line and a parser and split the line bewteen all the parser appearences
* into a vector' and returns it*/
vector<string> FileCacheManager::splitLine(string s,string parser)
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


bool FileCacheManager::isInTable (string problem)
{
    if (this->oldDB.count(problem) > 0)
        return true;
    else
        return true;
}

void FileCacheManager::addToTable(string problem,string solution)
{
    this->oldDB[problem] = solution;
}

string FileCacheManager::getFromTable(string problem)
{
    return this->oldDB[problem];
}

FileCacheManager::~FileCacheManager()
{
    ofstream out("Solultions.txt",ios::app);
    for (map<string, string>::iterator it = newDB.begin(); it != newDB.end(); it++)
    {
        out<< it->first << " " << it->second << endl;
    }
    out.close();
}

