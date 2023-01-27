#include <iterator>
#include <map>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int a[1000000];
int test_num;
int N;
int C;
bool compare (int a,int b){
    return a < b;
}

bool check(int distance){
    int quantity = 1; // so luong phan tu chon duoc de co khoang cach >= distance
    int i=0,j=1;
    while (i<N-1){
        while (j < N && a[j] - a[i]< distance ){
            j++;
        }
        if (j<N){
            quantity ++;
        }
        if (quantity >= C) return true;
        i=j;
        j++;
    }
    return false;
}

int findMaxDis(){
    int l =0;
    int r = a[N-1] - a[0];
    int res=0;
    while (l < r){
        int mid = (r+l)/2;
        if (check(mid)){
            l = mid +1;
        }
        else{
            r = mid -1;
        }
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> test_num;
    for (int i=0;i<test_num;i++){
        cin >> N >> C;
        for (int j=0;j<N;j++){
            cin >> a[j];
        }
        sort(a,a+N,compare);
        int res = findMaxDis();
        cout << res << endl;
    }
    return 0;
}