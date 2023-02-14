
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1e6 + 1;
int n;
long a[N];
long S0[N], S1[N];
bool B0[N], B1[N];
void solve()
{
    if (a[1] % 2 == 0)
    {
        S0[1] = a[1];
        B0[1] = true;
        B1[1] = false;
    }
    else
    {
        S1[1] = a[1];
        B1[1] = true;
        B0[1] = false;
    }

    for (int i = 2; i <= n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (B0[i - 1])
            {
                if (S0[i - 1] > 0)
                {
                    S0[i] = a[i] + S0[i - 1];
                    B0[i] = true;
                }
                else
                {
                    S0[i] = a[i];
                    B0[i] = true;
                }
            }
            else
            {
                S0[i] = a[i];
                B0[i] = true;
            }
            if (B1[i - 1])
            {
                if (S1[i - 1] > 0)
                {
                    S1[i] = a[i] + S1[i - 1];
                    B1[i] = true;
                }
                else
                {
                    S1[i] = S1[i - 1];
                    B1[i] = true;
                }
            }
            else
            {
                B1[i] = false;
            }
        }
        else
        {
            if (B1[i - 1])
            {
                S0[i] = S1[i - 1] + a[i];
                B0[i] = true;
            }
            else
            {
                B0[i] = false;
            }
            if (B0[i - 1])
            {
                if (S0[i - 1] > 0)
                {
                    S1[i] = S0[i - 1] + a[i];
                    B1[i] = true;
                }
                else
                {
                    S1[i] = a[i];
                    B1[i] = true;
                }
            }
            else
            {
                S1[i] = S1[i - 1];
                B1[i] = true;
            }
        }
    }
    int ans = -1e6;
    for (int i = 1; i <= n; i++)
    {
        // cout << S0[i] << " ";
        if (B0[i] && ans < S0[i])
        {
            ans = S0[i];
        }
    }

    cout << ans << endl;
}
int main()
{
    B0[1] = false;
    B1[1] = true;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve();
}
