#include <bits/stdc++.h>

#define MAX 11

using namespace std;

int n, M, a[MAX];
int f; // current sum
int t[MAX]; // sum from 1 to n
int X[MAX]; // value try at 1 to n
int cnt; // count solution

void initT(){
    for(int i = 1; i <= n; i++){
        t[1] = t[i - 1] + a[i];
    }
}

void checkSolution(){
    if(f == M) cnt++;
}
/*
void printSolution(){
    for (int i = 0; i < cnt; i++)
    {
        cout << X[i] << " " << endl;
    }  
} */

void TRY(int k){
    for (int i = 1; i <= (M - f - (t[n] - t[k])) / a[k]; i++)
    {
        /* code */
        X[k] = i;
        f += a[k] * X[k];
        if(k == n){
            checkSolution();
            //if(k == n) printSolution();
        }
        else TRY(k + 1);
        f -= a[k] * X[k];
    }
}

void input(){
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        cin >> a[i];
    }
}

void solve(){
    initT();
    TRY(1);
    cout << cnt;
}

int main(){
    input();
    solve();
}