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
int a[] = {3, 1, 2, 5, 7};
int n = 5, v;
int row[8];
bool check(int a, int b)
{
    return (a <= b);
}
void swap(int *a, int *b)
{
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
bool UCV(int row, int col)
{
    for (int column = 1; column <= col; column++)
    {
        if (a[column] == row || abs(col - column) == abs(row - a[column]))
        {
            return false;
        }
    }
    return true;
}

void Try(int k)
{
    for (int y = 1; y <= n; y++)
    {
        if (UCV(y, k))
        {
            a[k] = y;
            if (k == n)
                print();
            else
                Try(k + 1);
        }
    }
}
bool checkPlace(int r, int c)
{
    for (int prev = 0; prev < c; prev++)
    {
        if (row[prev] == r || abs(row[prev] - r) == abs(prev - c))
            return false;
    }
    return true;
}
void backtrack(int c)
{
    if (c == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << row[i] + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        for (int r = 0; r < 8; r++)
        {
            if (checkPlace(r, c))
            {
                row[c] = r;
                backtrack(c + 1);
            }
        }
    }
}
void Merge(int l, int m, int r)
{
    int L[10000];
    int R[10000];
    int lengthLeft = m - l + 1;
    int lengthRight = r - m;
    for (int i = 0; i < m - l + 1; i++)
    {
        L[i] = a[l + i];
    }
    for (int i = 0; i < r - m; i++)
    {
        R[i] = a[m + i + 1];
    }
    int startLeft = 0;
    int startRight = 0;
    while (startLeft < lengthLeft && startRight < lengthRight)
    {
        if (L[startLeft] <= R[startRight])
        {
            a[l] = L[startLeft];
            startLeft++;
        }
        else
        {
            a[l] = R[startRight];
            startRight++;
        }
        l++;
    }

    while (startLeft < lengthLeft)
    {
        a[l] = L[startLeft];
        l++;
        startLeft++;
    }
    while (startRight < lengthRight)
    {
        a[l] = R[startRight];
        l++;
        startRight++;
    }
}
void MergeSort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSort(l, m);
        MergeSort(m + 1, r);
        Merge(l, m, r);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    MergeSort(0, n - 1);
    print();
    return 0;
}