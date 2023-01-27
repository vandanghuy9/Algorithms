#include <iterator>
#include <map>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int mem[100][100];
int a[] = {5, 3, 2, 4};
int c[] = {10, 5, 3, 6};
int n, b;
int s;
void opt()
{
    for (int i = 0; i < n; i++)
    {
        for (s = 0; s < b; s++)
        {
            if (i == 0 || s == 0)
                mem[i][s] = 0;
            else if (s < a[i])
            {
                mem[i][s] = mem[i - 1][s];
            }
            else
                mem[i][s] = max(c[i] + mem[i - 1][s - a[i]], mem[i - 1][s]);
        }
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b; j++)
        {
            mem[i][j] = -1;
        }
    }
    printf("%d\n", mem[0][0]);
    n = 4;
    b = 8;
    opt();
    cout << mem[n - 1][b - 1] << endl;
    return 0;
}