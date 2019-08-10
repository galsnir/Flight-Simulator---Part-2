//
// Created by gal on 1/5/19.
//

#include "BFS.h"
/*
Solution BFS::search(ISearchable searchable)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<State> queue;

    // Mark the current node as visited and enqueue it
    State s = searchable.getInitialState();
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    set<State> adj;
    set<State>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        //cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        adj = searchable.getAllPossibleStates(s);
        for (i = adj.begin(); i != adj.end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}*/