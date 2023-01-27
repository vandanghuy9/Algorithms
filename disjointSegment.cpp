#include <stdio.h>
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
int n;
pair<int,int> segment[10000];
bool compare(pair<int,int> a, pair<int,int>b){
    return a.second < b.second;
}
int greedy(){
    int res = 0;
    int last = -1;
    for (int i=0;i<n;i++){
        if (segment[i].first > last ){
            res ++;
            last = segment[i].second;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int x,y;
    for (int i=0;i<n;i++){
        cin >> x >> y;
        segment[i].first = x;
        segment[i].second = y;
    }
    sort(segment,segment+n,compare);
    // for (int i=0;i<n;i++){
    //     cout << segment[i].first << " " << segment[i].second << endl;
    // }
    int res = greedy();
    cout << "so doan khong trung: " << res << endl;
    
    return 0;
}