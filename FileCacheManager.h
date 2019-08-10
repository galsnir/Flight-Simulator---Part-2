//
// Created by gal on 1/3/19.
//

#ifndef PART2_FILECACHEMANAGER_H
#define PART2_FILECACHEMANAGER_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class FileCacheManager {
    map<string,string> oldDB;
    map<string,string> newDB;
public:

    FileCacheManager();
    bool isInTable (string problem);
    void addToTable(string problem,string solution);
    string getFromTable(string problem);
    vector<string> splitLine(string s,string parser);
    ~FileCacheManager();
};


#endif //PART2_FILECACHEMANAGER_H
