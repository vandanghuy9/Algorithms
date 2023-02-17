#include<bits/stdc++.h>

#define maxn 100005

using namespace std;

int t;
int n, c;
int a[maxn];

bool check(int distance){
    int sl = 1;
    int i = 1, j = 2;
    while(i < n){
        while(j <= n && a[j] - a[i] < distance) ++j;
        if(j <= n) sl++;
        if(sl >= c) return true; // co the lay du c phan tu
        i = j;
        j++; 
    }
    return false;
}


int maxDistance(){
    int l = 0, r = a[n] - a[1];
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid + 1; // continue find in the right
        else r = mid - 1; // find int the left
    } 
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << maxDistance() << endl;
    }
}