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
int visited[100000];
int pre[1000000];
int color[1000000];
int timeCheck;
int truoc[1000000];
int low[1000000]; // thoi diem tham som nhat cua v
int num[1000000];
int curNum;
typedef pair<int, int> ii;
vector<ii> iiBridges;
typedef pair<int, ii> iii;
struct DisjointSets
{
    int *parent, *number;
    int n;
    DisjointSets(int numV)
    {
        n = numV;
        parent = new int[n + 1];
        number = new int[n + 1];
        for (int i = 0; i < n; i++)
        {
            number[i] = 1;
            parent[i] = i;
        }
    }
    int find(int x)
    {
        while (x != parent[x])
        {
            x = parent[x];
        }
    }
    void Union(int x, int y)
    {
        int u = find(x);
        int v = find(y);
        if (num[u] <= num[v])
        {
            parent[u] = v;
            num[v] += num[u];
        }
        else
        {
            parent[v] = u;
            num[u] += num[v];
        }
    }
};
class Graph
{
    int V, E;
    vector<iii> edges;

public:
    int numVertex();
    Graph(int V, int E);
    void addEdge(int v, int w, int weight);
    void BFS(int s);
    void DFS(int s);
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
    int kruskal_disjointSet();
};

Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
    // adj = new list<int>[V];
}

int Graph::numVertex()
{
    return V;
}

void Graph::addEdge(int u, int v, int weight) // do thi co huong
{
    pair<int, int> b = make_pair(u, v);
    iii a = make_pair(weight, b);
    edges.push_back(a); // add v to u's list
}

int Graph::kruskal_disjointSet()
{
    DisjointSets ds(V);
    sort(edges.begin(), edges.end());
    vector<iii>::iterator it;
    int res = 0;
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int rootU = ds.find(u);
        int rootV = ds.find(v);
        if (rootU != rootV)
        {
            res += it->first;
            ds.Union(rootU, rootV);
        }
    }
    return res;
}
int main()
{
    Graph g(9, 14);

    g.addEdge(0, 1, 4);
    g.addEdge(1, 0, 4);

    g.addEdge(0, 7, 8);
    g.addEdge(7, 0, 8);

    g.addEdge(1, 7, 11);
    g.addEdge(7, 1, 11);

    g.addEdge(1, 2, 8);
    g.addEdge(2, 1, 8);

    g.addEdge(7, 8, 7);
    g.addEdge(8, 7, 7);

    g.addEdge(7, 6, 1);
    g.addEdge(6, 7, 1);

    g.addEdge(2, 8, 2);
    g.addEdge(8, 2, 2);

    g.addEdge(8, 6, 6);
    g.addEdge(6, 8, 6);

    g.addEdge(6, 5, 2);
    g.addEdge(5, 6, 2);

    g.addEdge(2, 5, 4);
    g.addEdge(5, 2, 4);

    g.addEdge(2, 3, 7);
    g.addEdge(3, 2, 7);
    g.addEdge(3, 5, 14);
    g.addEdge(5, 3, 14);

    g.addEdge(3, 4, 9);
    g.addEdge(4, 3, 9);
    g.addEdge(5, 4, 10);
    g.addEdge(4, 5, 10);
    cout << g.kruskal_disjointSet() << endl;
    return 0;
}