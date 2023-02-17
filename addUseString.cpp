#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// cach 1
string Sum1(string firstStr, string secStr){
    while (firstStr.length() < secStr.length())
    {
        /* code */
        firstStr = '0' + firstStr;
    }
    while (firstStr.length() > secStr.length())
    {
        /* code */
        secStr = '0' + secStr;
    }

    string result;
    int sum, nho = 0;
    int sokitu = firstStr.length();
    for(int i = sokitu - 1; i >= 0; i--){
        sum = (firstStr[i] - '0') + (secStr[i] - '0') + nho; // '0' = 48
        nho  = sum / 10;
        //result = char(sum % 10 + '0') + result;
        result.push_back(sum % 10 + '0');
    }
    //if(nho == 1) result = "1" + result;
    if(nho == 1) result.push_back(nho + '0');
    reverse(result.begin(), result.end());
    return result;
}

//cach 2
string Sum2(string a, string b){
    // xau a luon co do dai lon hon xau b
    if(a.length() < b.length()) swap(a, b);
    string kq = "";
    int n1 = a.length(), n2 = b.length();
    // dao nguoc 2 xau
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int nho = 0;
    for(int i = 0; i < n2; i++){
        int sum = ((a[i] - '0') + (b[i] - '0') + nho);
        kq.push_back(sum % 10 + '0');
        nho = sum / 10;
    }
    // them cac chu so con lai cua so lon hon vao ket qua
    for(int i = n2; i< n1; i++){
        int sum = ((a[i] - '0') + nho);
        kq.push_back(sum % 10 + '0');
        nho = sum / 10;
    }
    // cong not nho neu co
    if(nho) kq.push_back(nho + '0');
    // dao nguoc xau ket qua
    reverse(kq.begin(), kq.end());
    return kq;
}


int main(){
    string a, b;
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu 2: ";
    cin >> b;
    //cout << Sum1(a, b);
    cout << Sum2(a, b);
    return 0;
}