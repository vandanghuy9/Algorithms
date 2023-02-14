#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int n;
int a[500000];
int num;
int result[500000];
int chiMuc;
priority_queue<int> q;
void solve(string command)
{
    if (command == "insert")
    {
        q.push(num);
    }
    else if (command == "delete-max")
    {
        int max = q.top();
        result[chiMuc] = max;
        chiMuc++;
        q.pop();
    }
}
void print()
{
    for (int i = 0; i < chiMuc; i++)
    {
        cout << result[i] << endl;
    }
}
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        q.push(a[i]);
    }
    string command;
    while (command != "*")
    {
        cin >> command;
        if (command.find("insert") == 0)
        {
            cin >> num;
        }
        solve(command);
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    chiMuc = 0;
    input();
    print();
    return 0;
}