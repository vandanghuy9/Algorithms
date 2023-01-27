#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int time[100];
int n,t;
int sum[100];
int binary_search(int low, int high, int target){
    while (low <= high){
        int mid = (high+low)/2;
        if (sum[mid] == target) return mid;
        else if (sum[mid] < target) low = mid +1;
        else high = mid -1; 
    }
    return high;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;
    for (int i=1;i<=n;i++){
        cin >> time[i];
        sum[i] = sum[i-1] + time[i];
    }
    int result = 0;
    for (int i=1;i<=n;i++){
        int j = binary_search(i,n,t+sum[i]-time[i]);
        result = max(result,j-i+1);
    }
    cout << endl;
    cout << result << endl;
    return 0;
}