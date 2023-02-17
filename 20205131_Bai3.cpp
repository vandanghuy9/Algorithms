#include<bits/stdc++.h>

using namespace std;

int n, k, U, L, M, A, B;
int a[21];
int N[100];
int Count;

void TRY(int i){
    if(i == k){
        U = n - M;
        L = U; 
    }
    else{
        U = n - L - (k - i);
        L = 1;
    }
    for(int j = L; j <=U; j++){
        a[i] = j;
        M = M + j;
        if(i == k) Count++;
        else TRY(i + 1);
        M = M - j;
    }
}

void nghiemNguyen(int k, int n){
    M = 0;
    TRY(1);
}

void solve(int A, int B){
    N[A] = A;
    for(int i = A; i <= B - A + 1; i++){
        N[i+1] = N[i] + 1;
        for(int j = 4; j <= 20; i++){
            nghiemNguyen(j, N[i]);
        }
    }
}

int main(){
    Count = 0;
    cin >> n >> A >> B;
    for(int i = 1; i<= n; i++){
        cin >> a[i];
    }
    solve(A, B);
    cout << Count;
    return 0;
}