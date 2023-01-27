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
typedef pair<int, int> ii;
ii a[1000000];
int n;
ii s[1000000];
int last;
bool check(ii b, ii c)
{
    return b.second < c.second;
}

int Greedy2()
{
    int i = 0;
    for (int k = 0; k < n; k++)
    {
        if (last <= a[k].first)
        {
            s[i] = a[k];
            i++;
            last = a[k].second;
        }
    }
    return i;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, check);
    last = -9999999;
    int meetNum = Greedy2();
    for (int i = 0; i < meetNum; i++)
    {
        cout << s[i].first << " " << s[i].second << endl;
    }
    return 0;
}