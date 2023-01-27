#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;
int k;
void printArray(){
    for (int i=1;i<=n;i++){
        cout << a[i];
    }
    cout << endl;
}
bool check (int y,int k){
    for(int i=1;i<=k-1;i++){
        if (a[i]==y) return false;
    }

    return true;
}
void Try(int k){
    for (int y =0;y<=n;y++){
        if (check(y,k)){
            a[k] = y;
            if (k==n) printArray();
            else Try(k+1);
        }
    }
}
int main(){
    n = 3;
    k =3;
    Try(1);
    return 0;
}