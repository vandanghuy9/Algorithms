#include<bits/stdc++.h>

using namespace std;

#define MAX 100

int N; // number of requests (1,2,..,N), request i has picked up  point i and drop-off at point i + N
int cap; // number of places of the bus
int A[MAX * 2 + 1][MAX * 2 + 1]; // 

int x[MAX];
int appear[MAX]; // marking
int load;
int f;
int f_best;
int x_best[MAX];
int cmin;

void input(){
    cin >> N >> cap;
    cmin = 1000000;
    for(int i = 0; i <= 2 * N; i++){
        for(int j = 0; j <= 2 * N; j++){
            cin >> A[i][j];
            if(i != j && cmin > A[i][j] ) cmin = A[i][j];
        }
    }
}

int check(int v, int k){
    if(appear[v] == 1) return 0;
    if(v > N){
        if(!appear[v - N]) return 0;
    }
    else{
        if(load + 1 > cap) return 0;
    }
    return 1;
}

void solution(){
    if(f + A[x[2 * N]][0] < f_best){
        f_best = f + A[x[2 * N]][0];
        for (int i = 0; i < 2 * N; i++)
        {
            x_best[i] = x[i];
        }
    }
}

void TRY(int k){
    for (int i = 1; i <= 2 * N; i++)
    {
        if(check(i, k)){
            x[k] = i;
            f += A[x[k - 1]][x[k]];
            if(i <= N) load += 1;
            else load += -1;
            appear[i] = 1;
            if(k == 2 * N) solution();
            else{
                if(f + (2 * N + 1 - k) * cmin < f_best) TRY(k + 1);
            }
            if(i <= N) load -= 1;
            else load -= -1;
            appear[i] = 0;
            f -= A[x[k - 1]][x[k]];
        }
    }
}    

void solve(){
    load = 0;
    f = 0;
    f_best = 1000000;
    for(int i = 1; i <= 2 * N; i++){
        appear[i] = 0;
    }
    x[0] = 0; // starting point
    TRY(1);
    cout << f_best;
}    

void print(){
    for(int i = 0; i <= 2 * N; i++){
        cout << x_best[i];
    }
}

int main(){
    input();
    solve();
    return 0;
}