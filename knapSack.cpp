#include<bits/stdc++.h>

using namespace std;

#define MAX 100

int mem[MAX][MAX];
int S;
int n[MAX];
int v[MAX];
int w[MAX];

void opt(int n, int b){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= S; j++){
            if(i == 0 || b == 0) mem[i][S] = 0;
            if(mem[i][S] != -1) mem[i][S] = mem[i - 1][S];
            if(S < w[i]) mem[i][S] = mem[i -1][S];
            else{
                mem[i][S] = max(v[i] + mem[i - 1][S - w[i]], mem[i - 1][S]);
            }
        }
    }
}

int main(){

}
