// tim so chuoi con co A<=sum<=B
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int arr[500000];
int n, A, B;
int result;
int sum;
void input()
{
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void countSub(int k)
{
    for (int i = k; i < n; i++)
    {
        if (sum + arr[i] <= B && k < n)
        {
            sum += arr[i];
            if (sum >= A)
            {
                result++;
                countSub(i + 1);
            }
            else
            {
                countSub(i + 1);
            }
            sum -= arr[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    sum = 0;
    result = 0;
    input();
    countSub(0);
    cout << result << endl;
    return 0;
}