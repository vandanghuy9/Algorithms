#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

void init(){
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        a.push_back(temp);
    }
}

int MAX(){
    int b[n][2];
    if (n == 1) {
        return a[0];
    }

    b[0][0] = 0;
    b[0][1] = a[0];

    for (int i = 1; i < n; i++) {
        b[i][1] = b[i - 1][0] + a[i];
        b[i][0] = max(b[i - 1][1], b[i - 1][0]);
    }
    return MAX(b[n - 1][0], b[n - 1][1]);
}

int main(){
    cin >> n;
    init();
    cout << MAX();
}