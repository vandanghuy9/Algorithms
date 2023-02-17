#include<bits/stdc++.h>

using namespace std;

bool visited[100];

class Graph {
    int V;    // No. of vertices
    list <int> *adj;    // Pointer to an array containing adjacency lists  (double linked list)
    
    public:
        int numVertex();
        Graph(int V);  // Constructor
        void addEdge(int v, int w);   // function to add an edge to graph
        void DFS(int s);        // prints BFS traversal from a given source s
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

int Graph::numVertex(){
    return V;
}

void Graph::addEdge(int u, int v) //do thi co huong
{
    adj[u].push_back(v); // Add v to u’s list.
   // adj[v].push_back(u);
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

int main(){
    Graph g(5);int V= g.numVertex();
    vector<bool> visited;
    visited.resize(V, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(4,0);
    g.addEdge(3,0);
    g.addEdge(0,2);

    int numV = g.numVertex();

    cout << "BFS(1) : ";
    g.DFS(1);
    return 0;
}