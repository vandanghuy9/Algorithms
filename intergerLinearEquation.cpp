#include <iostream>
#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
int n,M,a[100],t[100],x[100],f,result;
int calSum(int k){
    int sum =0;
    for (int i=0;i<=k;i++){
        sum += a[i];
    }
    return sum;
}

void check(){
    if (f == M) {
        result ++;
    }
}
void Try(int k){
    int maxValue = (M-f-(t[n-1]-t[k]))/a[k];
    for (int v=1;v<=maxValue;v++){
        x[k] = v;
        f += a[k]*x[k];
        if (k == n-1){
            check();
        }
        else{
            Try(k+1);
        }
        f -= a[k]*x[k];
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> M;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    
    result = 0;
    f=0;
    for (int i=0;i<n;i++){
        t[i] = calSum(i);
    }
    
    Try(0);
    cout << result;
    return 0;
}