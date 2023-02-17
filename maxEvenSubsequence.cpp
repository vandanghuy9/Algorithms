#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int n;
long long a[N];
long long s0[N];
long long s1[N];
bool B0[N];
bool B1[N];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    if(a[1] % 2 == 0){
        s0[1] = a[1];
        B0[1] = true;
        B1[1] = false;
    }
    else{
        s1[1] = a[1]; 
        B1[1] = true;
        B0[1] = false;
    }
    
    for(int i = 2; i <= n; i++){
        if(a[i] % 2 == 0){
            if(a[i] % 2 == 0){
                if(B0[i - 1]){
                    if(s0[i - 1] > 0) s0[i] = s0[i - 1] + a[i];
                    else s0[i] = a[i];
                    B0[i] = true;
                }
            }
            else{
                s0[i] = a[i];
                B0[i] = true;
            }
            if(B1[i - 1]){
                s1[i] = s1[i - 1] + a[i];
                B1[i] = true;
            }
            else{
                B1[i] = false;
            }
        }
        else{
            if(B1[i - 1]){
                s0[i] = s1[i -1] + a[i];
                B0[i] = true;
            }
            else {
                B0[i] = false;
            }
            if(B0[i - 1]){
                if(s0[i - 1] > 0){
                    s1[i] = s0[i - 1] + a[i];
                }
                else{
                    s1[i] = a[i];
                }
                B1[i] = true;
            }
            else{
                s1[i] = a[i];
                B1[i] = true;
            }
        }
    }
    long long ans = -1e18;
    for(int i = 1; i <= n; i++){
        if(B0[i] && ans < s0[i]) ans = s0[i];
    }
    
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}