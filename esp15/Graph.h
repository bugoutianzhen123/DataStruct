#include <bits/stdc++.h>
using namespace std;

bool find(int src, int target, const vector<vector<int>> &graph, vector<bool> &visited)
{

    if (src == target)
    {
        return true;
    }

    visited[src] = true;

    for (int i = 0; i < graph.size(); ++i)
    {

        if (graph[src][i] == 1 && !visited[i])
        {
            if (find(i, target, graph, visited))
            {
                return true;
            }
        }
    }

    return false;
}

void directGraph()
{
    vector<vector<int>> g = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};

    int src = 0, target = 3;
    int n = g.size();
    vector<bool> visited(n, false);
    if (find(src, target, g, visited))
    {
        cout << src << "can reach" << target << endl;
    }
    else
    {
        cout << src << "can't do it" << target << endl;
    }
}

bool find_k(int u, int target, int k, int pathLength, const vector<vector<int>> &graph, vector<bool> &visited)
{
    if (pathLength == k)
    {
        return u == target;
    }

    visited[u] = true;

    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[u][i] == 1 && !visited[i])
        {
            if (find_k(i, target, k, pathLength + 1, graph, visited))
            {
                return true;
            }
        }
    }

    visited[u] = false;

    return false;
}

void noDirectGraph()
{
    vector<vector<int>> g = {
        {0, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};

    int src = 0;
    int target = 3;
    int k = 2;

    int n = g.size();
    vector<bool> visited(n, false);
    if (find_k(src, target, k, 0, g, visited))
    {
        cout << "There is " << k << " from " << src << " to " << target << endl;
    }
    else
    {
        cout << "No  " << k << " exists from " << src << " to " << target << endl;
    }
}