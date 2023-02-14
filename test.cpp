#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int n;
int a[500000];
priority_queue<int> q;
void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        q.push(a[i]);
    }
    string command;
    while (command != "*")
    {
        cin >> command;
        solve(command);
    }
}
void solve(string command)
{
    if (command.find("insert") == 0)
    {
        string insert = "insert";
        string numStr = command.substr(insert.length() + 1);
        int num = stoi(numStr);
        q.push(num);
    }
    else if (command.find("delete_max") == 0)
    {
        int max = q.top();
        cout << max << endl;
        q.pop();
    }
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    return 0;
}