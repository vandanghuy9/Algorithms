/*
Liet ke nghiem nguyen cua phuong trinh x1 + x2 + ... + xk = n
x1, x2, x3, .. xk > 0
Gia su xay dung duoc loi giai bo phan (x1, x2, .., xk-1)
Ta tiep tuc xay dung thanh phan thu i cua loi giai: tuc la can tim gia tri
cho bien xi:
    tong cua (i - 1) bien dau tien M = x1 + x2 +.. + xi-1
    tong (k - 1) cac bien xi+1 , ... , xk it nhat phai bang k - i
    gia tri lon nhat xi co the nhan la U = n - M - (k - i)
    => xi thuoc [1; U]
*/

#include<bits/stdc++.h>

using namespace std;

int n, k, U, L, M;
int x[20];

void GhiNhan(){
    cout << "Nghiem nguyen: ";
    for(int i = 1; i <= k; i++) cout << x[i] << " ";
    cout << endl;
}

void TRY(int i){
    if(i == k){
        U = n - M;
        L = U; 
    }
    else{
        U = n - L - (k - i);
        L = 1;
    }
    for(int j = L; j <=U; j++){
        x[i] = j;
        M = M + j;
        if(i == k) GhiNhan();
        else TRY(i + 1);
        M = M - j;
    }
}

void nghiemNguyen(int k, int n){
    M = 0;
    TRY(1);
}

int main(){
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;
    nghiemNguyen(k, n);
    return 0;
}