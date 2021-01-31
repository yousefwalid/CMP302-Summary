#include <bits/stdc++.h>

int cut_rod_tabulation(int n, const std::vector<int> &p)
{
  if (n == 0)
    return 0;

  std::vector<int> r(n + 1, 0);

  for (int j = 1; j <= n; j++)
  {
    r[j] = INT_MIN;
    for (int i = 1; i <= j; i++)
    {
      r[j] = std::max(r[j], p[i] + r[j - i]);
    }
  }

  return r[n];
}