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
bool visited[100000];
int pre[1000000];
int color[1000000];
class Graph
{
    int V;
    list<int> *adj;

public:
    int numVertex();
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    void topoSort();
    void DFS_topo(int s, stack<int> Stack);
    void topoSort_xoaDanDinh();
    bool isPiparate(int s);
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

void Graph::BFS(int s)
{
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        cout << u << " ";
        Q.pop();
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = *i;
            if (visited[v] == false)
            {
                visited[v] = true;
                Q.push(v);
            }
        }
    }
}
void Graph::DFS(int s)
{
    visited[s] = true;
    cout << s << " ";
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++)
    {
        int v = *i;
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

void Graph::topoSort()
{
    for (int s = 0; s < V; s++)
    {
        visited[s] = false;
    }
    stack<int> Stack;
    for (int s = 0; s < V; s++)
    {
        if (!visited[s])
        {
            DFS_topo(s, Stack);
        }
    }

    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

void Graph::DFS_topo(int s, stack<int> stack)
{
    visited[s] = true;
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++)
    {
        int v = *i;
        if (!visited[v])
        {
            DFS_topo(v, stack);
        }
    }
    stack.push(s);
}

void Graph::topoSort_xoaDanDinh()
{
    vector<int> in_degree(V, 0);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            in_degree[*i]++;
        }
    }
    queue<int> Q;
    for (int v = 0; v < V; v++)
    {
        if (in_degree[v] == 0)
        {
            Q.push(v);
        }
    }
    int num = 0;
    vector<int> topo_Order;
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        num++;

        topo_Order.push_back(v);
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            in_degree[*i] = in_degree[*i] - 1;
            if (in_degree[*i] == 0)
            {
                Q.push(*i);
            }
        }
    }
    if (num != V)
    {
        cout << "chu trinh";
        return;
    }
    for (int i = 0; i < topo_Order.size(); i++)
    {
        cout << topo_Order[i] << " ";
    }
}

bool Graph::isPiparate(int s)
{
    for (int v = 0; v < V; v++)
    {
        color[v] = -1;
    }
    color[s] = 1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = *i;
            if (v == u)
            {
                return false;
            }
            else if (color[v] != -1)
            {
                color[v] = 1 - color[u];
                Q.push(v);
            }
            else if (color[v] == color[u])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int topNum = 8;
    Graph g(topNum);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(2, 4);
    // g.addEdge(4, 0);
    // g.addEdge(3, 0);
    // g.addEdge(0, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 1);
    // g.addEdge(4, 1);
    // g.addEdge(4, 0);
    // g.addEdge(5, 0);
    // g.addEdge(5, 2);

    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 4);
    g.addEdge(4, 0);

    g.addEdge(1, 5);
    g.addEdge(5, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 1);

    g.addEdge(2, 6);
    g.addEdge(6, 2);

    g.addEdge(3, 7);
    g.addEdge(7, 3);

    g.addEdge(2, 3);
    g.addEdge(3, 2);

    g.addEdge(4, 5);
    g.addEdge(5, 4);

    g.addEdge(7, 5);
    g.addEdge(5, 7);

    g.addEdge(4, 6);
    g.addEdge(6, 4);
    int numV = g.numVertex();
    for (int i = 0; i < numV; i++)
    {
        visited[i] = false;
    }
    bool result = g.isPiparate(0);
    if (!result)
    {
        for (int i = 0; i < numV; i++)
        {
            cout << color[i] << " ";
        }
    }
    return 0;
}