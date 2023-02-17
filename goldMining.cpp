#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int a[N], S[N];
int n, L1, L2, result;

void solve(){
    deque<int> d; // luu chi so cac ung cu vien j tham gia xac dinh bai toan con S(j)
    result = 0;
    for(int i = 1; i <= n; i++){
        while(!d.empty() && d.front() < i - L2) d.pop_front();
        int j = i - L1;
        if(j >= 1){
            while(!d.empty() && S[d.back()] < S[j]) d.pop_back();
            d.push_back(j);
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
        result = max(result, S[i]);
    }
    cout << result;
}

void intput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int main(){
    intput();
    solve();
    return 0;
}