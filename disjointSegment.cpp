#include<bits/stdc++.h>

using namespace std;

#define maxn 1000000

int n;

pair<int, int> a[maxn];

// sort the segments by second element of pairs
bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        cin >> a[i].first >> a[i].second;
    }
}

void solve(){
    int result = 0;
    int last = -1; //the end point of last segments

    sort(a + 1, a + n + 1, compare);
    for(int i = 1; i <= n; i++){
        if(a[i].first > last){
            result++;
            last = a[i].second;
        }
    }
    cout << result << endl;
}

int main(){
    input();
    solve();
    return 0;
}