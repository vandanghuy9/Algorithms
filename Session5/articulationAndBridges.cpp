#include <iterator>
#include <map>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
vector<int> g[100000];
int visited[100000];
// int pre[1000000];
// int color[1000000];
// int timeCheck;
// int truoc[1000000];
int low[1000000]; // thoi diem tham som nhat cua v
int num[1000000];
int curNum;
int t;
int ap[100000];
int input[100000];
typedef pair<int, int> ii;
vector<ii> iiBridges;
class Graph
{
    int V;
    list<int> *adj;

public:
    int numVertex();
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s, int ps);
    void topoSort();
    void DFS_topo(int s, stack<int> Stack);
    void topoSort_xoaDanDinh();
    bool isPiparate(int s);
    void LongestPathLength();
    pair<int, int> BFS_LP(int s);
    void DFS_cycle(int u);
    void BFS_cycle_noDirection(int s);
    void cutVertex(int u, int p);
    Graph getTranspose();
    bool kurasaju();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

int Graph::numVertex()
{
    return V;
}

void Graph::addEdge(int u, int v) // do thi co huong
{
    adj[u].push_back(v); // add v to u's list
    // adj[v].push_back(u); // neu do thi vo huong
}

void DFS(int s, int ps)
{
    t++;
    num[s] = t;
    low[s] = num[s];
    visited[s] = true;

    for (int i = 0; i < g[s].size(); i++)
    {
        int v = g[s][i];
        if (v == ps)
            continue;
        if (visited[v])
        {
            low[s] = min(low[s], num[v]);
        }
        else
        {
            DFS(v, s);
            low[s] = min(low[s], low[v]);
            if (low[v] >= num[s])
            {

                ap[s] = 1;
            }
            if (low[v] > num[s])
            {
                iiBridges.push_back(make_pair(s, v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    t = 0;
    int countAP = 0;
    int countBridge = 0;
    DFS(1, 1);
    for (int i = 0; i < v; i++)
    {
        if (ap[i] != 0)
        {
            countAP++;
        }
    }
    countBridge = iiBridges.size();
    cout << countAP << " " << countBridge << endl;
    return 0;
    // kip 3 12h
}