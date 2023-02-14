#include <iterator>
#include <map>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string combination[] = {"BCG", "BGC", "CBG", "CGB", "GCB", "GBC"};
int sum = 0;
int a[9];
int n;
int index = 0;
int numOfMovement(string tryCom)
{
    int start = 0;
    int end = 2;
    int i = 0;
    int combinationSum = 0;
    while (end < 9)
    {
        char c = tryCom.at(i);
        if (c == 'B')
        {
            combinationSum += a[start];
        }
        else if (c == 'C')
        {
            combinationSum += a[end];
        }
        else if (c == 'G')
        {
            combinationSum += a[(end + start) / 2];
        }
        end = end + 3;
        start = start + 3;
        i++;
    }
    return (sum - combinationSum);
}

int countMinimum()
{
    int minimumMovement = 9999999;
    for (int i = 0; i < 6; i++)
    {
        int num = numOfMovement(combination[i]);
        cout << combination[i] << " " << num << endl;
        if (minimumMovement > num)
        {
            minimumMovement = num;
            index = i;
        }
    }
    return minimumMovement;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[j];
            sum += a[j];
        }
        int minimum = countMinimum();
        cout << combination[index] << " " << minimum << endl;
        sum = 0;
    }
    return 0;
}