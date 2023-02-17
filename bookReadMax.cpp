#include<bits/stdc++.h>

using namespace std;

#define maxn 100000

int n, t, Time[maxn], sum[maxn];

int binarySearch(int sum[], int low, int high, int target){
    while (low <= high)
    {
        /* code */
        int mid = (low + high) / 2;
        if(sum[mid] == target) return mid;
        else if(sum[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

void printResult(){
    int result = INT_MIN;
    for(int i = 1; i <= n; i++){
        int j = binarySearch(sum, i, n, t + sum[i] - Time[i]);
        result = max(result, j - i + 1);
    }
    cout << "The max book can read: " << result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        cin >> Time[i];
    }
    sum[1] = Time[1];
    for(int i = 2; i <= n; i++){
        sum[i] += sum[i - 1] + Time[i];
    }
    printResult();
    return 0;
}