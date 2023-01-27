#include <iostream>
#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

int M[1000][20],a[1000],n,pairNum,xPair[1000],yPair[1000];

void process(){
    for (int i=0;i<n;i++){
        M[0][i] = a[i]; //cho cot dau tien la mang nhap vao
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (M[j+1][i] < M[i][j+1]){
                M[i][j] = M[j][i];
            }
            else{
                M[i][j] = M[i][j-1];
            }
        }

    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    process();
    return 0;
}