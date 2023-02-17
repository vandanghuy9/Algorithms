#include<bits/stdc++.h>

using namespace std;

#define MAX 100000

int n, k;
long long m;
int Count;
int a[MAX];



void solve(){
    for(int i = 1; i <= n; i++){
        long long weight = 0;
        for(int j = i; j <= i + k - 1; j++){
            weight += a[j];
            // cout << weight << " ";      
        }
        if(weight == m) Count++;
    }
}

int main(){
    Count = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    solve();
    cout << Count;
    return 0;
}