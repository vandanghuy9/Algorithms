#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n, k, m;
int a[500000];

void input()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void solve(int Tcount)
{
    int count = Tcount;
    for (int i = 1; i <= n - k + 1; i++)
    {
        int sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += a[j];
        }
        if (sum == m)
        {
            count++;
        }
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 0;
    input();
    solve(0);
}