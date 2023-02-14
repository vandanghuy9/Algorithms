#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int a[500000];
int n, A, B;
int result;
void input()
{
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            if (sum + a[j] >= A && sum + a[j] <= B)
            {
                sum += a[j];
            }
        }
        if (sum <= B && sum >= A)
        {
            result++;
        }
    }
    cout << result << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    result = 0;
    input();
    solve();
    return 0;
}