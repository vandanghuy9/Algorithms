#include<bits/stdc++.h>

using namespace std;

// greedy algorithms
void cashier(int X, int c[], int S[], int n){
    for(int i = n - 1; i >= 0; i--){
        int soluong = X / c[i];
        if(soluong > 0) S[i] = soluong;
        X %= c[i];
    }
}

//dynamic
int INF = 100000;
int d[10] = {1, 5, 10, 25, 100};
int mem[10][10000];
memset(mem, -1, sizeof(mem));

int opt(int i, int x){
    if(x < 0) return INF;
    if(x = 0) return 0; // k can tra cho khach hang
    if(x == -1) return INF;

    if(mem[i][x] != -1) return mem[i][x];

    int res = INF;
    res = min(res, 1 + opt(i, x - d[i]));
    res = min(res, opt(i - 1, x));

    mem[i][x] = res;
    return res;
}

void trace(int i, int x){
    if(x < 0) return;
    if(x == 0) return;
    if(i == -1) return;

    int res = INF;
    if(mem[i][x] == 1 + mem[i][x - d[i]]){
        printf("%d ", d[i]);
        trace(i, x - d[i]);
    }
    else{
        trace(i - 1, x);
    }
}



int main(){
    int c[] = {1, 5, 10, 25, 100};
    int S[5] = {0};
    int n = 5, X = 383;
    cashier(X, c, S, n);
    cout << "Cach doi " << X << " cent: " << endl;
    for(int i = 0; i < n; i++){
        if(S[i] > 0) cout << S[i] << " dong xu menh gia " << c[i] << endl;
    }
    

    // dynamic
    cout << "so luong dong xu it nhat can su dung: " << opt(n - 1, X) << endl;
    return 0;
}