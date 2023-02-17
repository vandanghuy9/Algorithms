#include<stdio.h>
#include<iostream>

using namespace std;

int n;
int x[100], xopt[100];
int c[100][100];
bool visited[100];
int f = 0;
int fopt = INT_MAX;

void Try(int k){
    // Sk = {2, 3, ..., n} \ {x[1], x[2], ...x[k - 1]}
    for (int y = 2; y <= n; y++)
    {
        /* code */
        if(visited[y] == 0){
            x[k] = y;
            visited[y] = 1;
            f = f + c[x[k - 1]][x[k]];
            if(k == n){
                int f1 = f + c[x[n]][1];
                if(f1 < fopt){
                    fopt = f1;
                    for(int j = 1; j <= n; j++){
                        xopt[j] = x[j];
                    }
                }            
            }
            else // if di tiep cho loi giai tot hon fopt
                // cmin = min(c[i][j] : 1<= i, j <= n);
                if (f + cmin * (n - k + 1) < fopt) Try(k + 1);
            visited[y] = 0;
            f -= c[x[k - 1]][x[k]];
        }
    }
    
}

int main(){
    int n = 5;
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    } */
    c[n][n] = {{0, 3, 14, 18, 15}, {3, 0, 4, 22, 20}, {17, 9, 0, 16, 4}, {9, 20, 7, 0, 18}, {9, 15, 11, 5, 0}};
    x[1] = 1;
    Try(2);
    cout << "Distance min: " << fopt << endl;
    cout << "Travel: " ;
    for(int i = 1; i <= n; i++){
        cout << x[i] << "--> ";
    }
    cout << x[1] << endl;
}