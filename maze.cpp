#include <iostream>
#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
const int maxN = 100;
int a[maxN][maxN], m,n,r,c,d[maxN][maxN];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
queue <ii> topQueue;

int solve(){
    r = r-1;
    c= c-1;
    topQueue.push(ii(r,c));
    d[r][c]=0;
    a[r][c]=1;
    while (!topQueue.empty()){
        ii tmp = topQueue.front();
        topQueue.pop();
        for (int i=0;i<4;i++){
            int x = dx[i] + tmp.first;
            int y = dy[i] + tmp.second;
            if (x < 1|| x > m || y < 1 || y > n){
                return d[tmp.first][tmp.second] + 1;
            }
            if (a[x][y] != 1){
                d[x][y] = d[tmp.first][tmp.second]+1;
                topQueue.push(ii(x,y));
                a[x][y]= 1;
            }
        }
    }
    return -1;
}

void printMatrix(){
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> r >> c;
    for (int i=1;i<=m;i++){
        for (int j=1;j<n;j++){
            cin >>a[i][j];
        }
    }

    int ans = solve();
    cout << ans << endl;
    printMatrix();
    return 0;
}