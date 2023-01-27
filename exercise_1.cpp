#include <iterator>
#include <map>

#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[10000000];
int U, M, L;
void print()
{
    for (int i = 0; i < k; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void Try(int i)
{
    if (i == k - 1)
    {
        U = n - M;
        L = U;
    }
    else
    {
        U = n - M - (k - i);
        L = 1;
    }

    for (int j = L; j <= U; j++)
    {
        a[i] = j;
        M = M + j;
        if (i == k - 1)
            print();
        else
            Try(i + 1);
        M = M - j;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    n = 10, k = 5;
    M = 0;
    Try(0);
    return 0;
}