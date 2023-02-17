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
vector<int> w[100000];
vector<int> newG[100000];
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
int dist[100000][100000];
int C[100000];
int D[100000];
int c[100000];
int d[100000];
int V, E;
void BFS(int s)
{
    queue<int> Q;
    Q.push(s);
    for (int i = 0; i < V; i++)
    {
        d[i] = -1;
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i != g[u].size(); i++)
        {
            w[i][u] = C[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}