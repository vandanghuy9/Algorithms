#include <bits/stdc++.h>

using namespace std;

#define maxn 1000006

int const Mod = 1e9+7;
int n, a[maxn];
int temp[maxn];

//This function merges 2 sorted array and returns the inversion count

int mergeAndCount(int left, int mid, int right){
    int i = left, j = mid + 1, k = left, inv_count = 0;
    while((i <= mid) && (j <= right)){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else{
            temp[k++] = a[j++];
            inv_count = (inv_count + (mid - i + 1)) % Mod;
        }
    }

    //copy the remaining elements of left arrays it there're ny to temp
    while (i <= mid)
    {
        /* code */
        temp[k++] = a[i++];
    }
    
    //copy the remaining elements of right arrays it there're ny to temp
    while (j <= right)
    {
        /* code */
        temp[k++] = a[j++];
    }

    // copy back the merged elements to original array
    for(i = left; i <= right; i++) a[i] = temp[i];
    return inv_count;
}

//an recursive function that sorts the input array an returns the number of inversion
int mergeSort(int left, int right)
{
    int mid, inv_count = 0;
    if(right > left){
        mid = (right + left) / 2; // devide
        // inversion count will be sum of inversion in leftpart, rightpart and merge
        inv_count = (inv_count + mergeSort(left, mid)) % Mod;
        inv_count = (inv_count + mergeSort(mid + 1, right)) % Mod;
        inv_count = (inv_count + mergeAndCount(left, mid, right)) % Mod;
    }
    return inv_count;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << mergeSort(1, n);
    return 0;
}