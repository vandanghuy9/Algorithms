#include <iterator>
#include <map>
 
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int c[] = {1,5,10,25,100};
int s[5] = {0};

int mem[10][1000] = {-1}; 
// vi op co 2 tham so nen mem 2 chieu
// 1 chieu so luong dong xu di
// 1 chieu so tien phai tra ( mem[i][X])
void Casher(int X,int n){
    for (int i=n-1;i>=0;i--){
        int slg = X / c[i];
        X = X%c[i];
        if (slg > 0){
            s[i] = slg;
        }
    }
}

int opt(int i, int X){
    if (X == 0) return 0;
    if (i == -1) return 9999999;
    if (X < 0) return 9999999;
    if (mem[i][X] != -1) return mem[i][X];
    else{
        int ans = 0;
        ans = min(ans,opt(i-1,X));
        ans = min(ans,1+opt(i,X-c[i]));
        mem[i][X] = ans;
        return ans;
    } 
}

void trace(int i,int X){
    if (i==-1) return;
    if (X <=0) return;
    if (mem[i][X] == 1+opt(i,X-c[i])){
        cout << c[i] <<" ";
        trace(i,X-c[i]);
    }
    else {
        trace(i-1,X);
    }
}
int main(){
    memset(mem,-1,sizeof(mem));
    int n=5,X = 383;
    // Casher(X,n);
    // for (int i=0;i<n;i++){
    //     if (s[i] > 0){
    //         cout << c[i] << ":" << s[i] <<endl;
    //     }
    // }
    cout << "so dong:"<<opt(n-1,X);
    trace(n-1,X);
    return 0;
}