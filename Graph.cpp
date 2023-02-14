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

pair<int, int> Graph::BFS_LP(int s)
{
    int dis[V];
    for (int i = 0; i < V; i++)
    {
        dis[i] = -1;
    }
    queue<int> Q;
    dis[s] = 0;
    Q.push(s);
    list<int>::iterator i;
    while (!Q.empty())
    {
        s = Q.front();
        Q.pop();
        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            int v = *i;
            if (dis[v] != -1)
            {
                dis[v] = dis[s] + 1;
                Q.push(v);
            }
        }
    }
    int maxDis = 0;
    int index = 0;
    for (int i = 0; i < V; i++)
    {
        if (dis[i] > maxDis)
        {
            index = i;
            maxDis = dis[i];
        }
    }

    return make_pair(index, maxDis);
}
void Graph::LongestPathLength()
{
    pair<int, int> t1 = BFS_LP(0);
    pair<int, int> t2 = BFS_LP(t1.first);
    cout << "Do dai lon nhat tren cay: " << t2.second;
}

// DFS tim chu trinh : visited[v] = 0 : canh
// visited[v] =1 : den nhung chua duyet
// visited[v] = 2: den da duyet xong

void Graph::DFS_cycle(int u)

{
    visited[u] = 1;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (visited[v] == 1)
        {
            cout << "do thi co chu trinh";
            return;
        }
        else if (visited[v] == 0)
            DFS_cycle(v);
    }
    visited[u] = 2;
}

void Graph::BFS_cycle_noDirection(int s)
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

void Graph::cutVertex(int u, int p)
{
    visited[u] = true;
    low[u] = num[u] = ++curNum;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (v == p)
            continue;
        if (num[v] == -1)
        {
            cutVertex(v, u);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
        if (low[v] > num[u])
        {
            iiBridges.push_back(make_pair(u, v));
        }
    }
}

Graph Graph::getTranspose()
{
    Graph gt(V);
    list<int>::iterator i;
    for (int v = 0; v < V; v++)
    {
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            int u = *i;
            gt.addEdge(u, v);
        }
    }
    return gt;
}

bool Graph::kurasaju() // tim lien thong manh
{
    for (int v = 0; v < V; v++)
    {
        visited[v] = 0;
    }
    DFS(0);
    for (int v = 1; v < V; v++)
    {
        return false;
    }
    for (int v = 0; v < V; v++)
    {
        visited[v] = 0;
    }
    Graph gt = getTranspose();
    gt.DFS(0);
    for (int v = 1; v < V; v++)
    {
        return false;
    }
    return true;
}
int main()
{
    int topNum = 6;
    Graph g(topNum);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 2);

    int numV = g.numVertex();

    return 0;
}