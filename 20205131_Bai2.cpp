#include<bits/stdc++.h>

using namespace std;

#define MAX 100000

vector <int> a;
int n, max;

void insert(int x){
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(a[i] <= x){
            for(int j = *a.end() - 1; j > i; j--){
                a[j+1] = a[j];
            }
            a[i + 1] = x;
        }
    }
}

void delete_max(vector<int> a, int *index){
    int max_pos = 0;
    int max = a[0];
    for(int i = 1; i < *index; i++)
    {
        if(max < a[i])
        {
            max = a[i];
            max_pos = i;
        }
    }
    for(int i = max_pos; i < *index; i++)
    {
        a[i] = a[i+1];
    }
    (*index)--;
}

int main(){
    
}