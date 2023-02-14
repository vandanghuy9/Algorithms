
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
queue<int> hanhLang;
stack<int> chuong;
int c[10000000];
int n;
void checkSignal(string signal)
{
    for (int i = 0; i < signal.size(); i++)
    {
        if (signal[i] == 'C')
        {
            if (!chuong.empty())
            {
                int num = chuong.top();
                chuong.pop();
                hanhLang.push(num);
            }
        }
        else if (signal[i] == 'H')
        {
            if (!hanhLang.empty())
            {
                int num = hanhLang.front();
                hanhLang.pop();
                chuong.push(num);
            }
        }
    }
    while (!hanhLang.empty())
    {
        {
            int num = hanhLang.front();
            hanhLang.pop();
            chuong.push(num);
        }
    }
}
void print()
{
    while (!chuong.empty())
    {
        int num = chuong.top();
        cout << num << " ";
        chuong.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    while (test <= 1)
    {
        scanf("%d", &n);
        int p;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &c[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            chuong.push(c[i]);
        }
        string signal;
        cin >> signal;
        checkSignal(signal);
        print();
        test++;
    }
}