#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[100];
int Count;

int ghiNhan(){
    Count++;
    cout << "hoan vi " << Count << ": ";
    for(int i = 1; i<= n; i++) cout << a[i] << " ";
    cout << endl; 
}

bool UCV(int y, int k){
    for(int i = 1; i <= k - 1; i++) if(y == a[i]) return false;
    return true;
}

void TRY(int k){
    for(int y = 1; y <= n; y++){
        if(UCV(y, k)){
            a[k] = y;
            if(k == n) ghiNhan();
            else TRY(k + 1);
        }
    }
}

int main(){
    cout << "Nhap n: ";
    cin >> n;
    Count = 0;
    TRY(1);
    cout << "So hoan vi = " << Count;
    return 0;
}