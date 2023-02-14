#include <bits/stdc++.h>
using namespace std;
int n;
int A, B;
int a[51];
int Q = 0;
int main()
{
  cin >> n >> A >> B;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < (1 << n); i++)
  {
    int sum = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j))
        sum += a[j];
    if (sum >= A && sum <= B)
      Q += 1;
  }
  cout << Q;
  return 0;
}