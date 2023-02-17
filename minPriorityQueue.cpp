/*
    Can thuc hien n cong viec: moi cong viec i co
    - pi la luog thoi gian can de hoan thah cong viec i
    - ri la thoi diem som nhan co the bat dau thuc hien cong viec i
    ci la thoi diem cong viec i se hoan thanh. 
    xac dinh trinh tu cong viec cho thoi gian hoan thanh trung binh
    n cong viec la nho nhat: min (1/n)(xich ma i = 1 ->n)ci
    Input: n: so luong cong viec
        dong tiep theo, n nhom so nguye nduong, moi nhom gom 2 so nguyen duong pi va ri
    Output:
        dong 1: tg trung binh nho nhat
        day k(k >= n) cac nhom so nguyen duong ghi lai nhat ki lam viec
        moi nhom gom 3 so i t t'(bat dau, thoi diem bat dau/tiep tuc, tam dung/hoan thanh)
    vd: 2           out 8.5
        3 3 6 2         2 2 3 1 3 6 2 6 11
*/

#include<bits/stdc++.h>

using namespace std;

int n;
vector <pair<int, int> > a;

int main(){
    cin >> n;
    long long p, r;
    for(int i = 0; i < n; i++){
        cin >> p;
        cin >> r;
        a.push_back(make_pair(r, p));
    }
    /*sap xep theo thu tu tang dan cua thanh phan thu nhat cua vecto a
    (tuc la theo gia tri r tang dan cua cac cong viec)*/
    sort(a.begin(), a.end());
    /*khai bao hang doi uu tien Q chua cac so nguyen la luong thoi gian
    con lai de hoan thanh cac cong viec dang duoc thuc hien*/
    priority_queue<int, vector<int>, greater<int> > Q;
    int t = 0; //thoi diem hien tai
    int i = 0;
    int result = 0;
    while(i < n || !Q.empty()){
        if(Q.empty()){
            t = a[i].first;
            Q.push(a[i].second);
            i++;
        }
        else{
            if(i < n){
                /* tinh luong thoi gian tinh tu toi diem hien tai t den khi co the bat dau
                thuc hien cong viec i*/
                int remain = a[i].first - t;
                if(remain < Q.top()){
                    //thuc hien tiep cong viec hien tai cho den thoi diem co the bat dau thuc hien cong viec i
                    int u = Q.top();
                    Q.pop();
                    Q.push(u - remain); //cap nhat lai luong thoi gian con lai de hoan thanh cv hien tai
                    Q.push(a[i].second); // bo sung luong thoi gian thuc hien cong viec i vao Q
                    t = a[i] .first;
                    i++;
                }
                else{
                    t += Q.top(); // thuc hien not cv hien tai cho den khi hoan thanh no
                    result += t;
                    Q.pop();
                }
            }
            else{
                t += Q.top();
                result += t;
                cout << result << endl;
                Q.pop();
            }
        }
    }
    printf("%.2f", 1.0 *result/n); // 2 1 3 2 4 1
    return 0;
}