#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int height[100];
int n,t;
int sum[100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;
    for (int i=1;i<=n;i++){
        cin >> height[i];
        sum[i] = sum[i-1] + height[i];
    }
}