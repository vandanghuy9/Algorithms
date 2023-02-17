#include <bits/stdc++.h>

using namespace std;

#define N 50

vector<int> T[N]; // T[i]: the list of teachers that can be assigned course i
int m, n;
bool conflict[N][N];
int x[N];
int load[N];
int res;

void input(){
    cin >> m >> n;
    for (int i = 1 ; i <= m; i++)
    {
        /* code */
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int c;
            cin >> c;
            T[c].push_back(i);
        }
    }
    int K;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        for(int j = 1; j <= n; j++){
            conflict[i][j] = false;
        }
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        /* code */
        int j, h;
        cin >> j >> h;
        conflict[j][h] = true;
        conflict[h][j] = true;
    }   
}

bool check(int t, int k){
    for(int i = 1; i <= k - 1; i++){
        if(conflict[i][k] && x[i] == t) return false;
    }
    return true;
}

void solution(){
    int maxLoad = 0;
    for (int i = 1; i <= m; i++)
    {
        /* code */
        maxLoad = max(maxLoad, load[i]);
    }
    if(maxLoad < res) res = maxLoad;   
}

void TRY(int k){
    for(int i = 0; i < T[k].size(); i++){
        int t = T[k][i];
        if(check(t, k)){
            x[k] = t; // assign course k to teacher t
            load[t] += 1;
            if(k == n) solution();
            else{
                if(load[t] < res){
                    TRY(k + 1);
                }
            }
            load [t] = -1;
        }
    }
}

int main(){
    input();
    for (int i = 0; i <= m; i++){
        load[i] = 0;
    }
    res = 1e9;
    TRY(1);
    cout << res;
    return 0;
}