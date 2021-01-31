#include <bits/stdc++.h>

int __cut_rod_extended_tabulation(int n, const std::vector<int> &p, std::vector<int> &s)
{
  if (n == 0)
    return 0;

  std::vector<int> r(n + 1, 0);

  for (int j = 1; j <= n; j++)
  {
    r[j] = INT_MIN;
    for (int i = 1; i <= j; i++)
    {
      int current_price = p[i] + r[j - i];
      if (current_price > r[j])
      {
        r[j] = current_price;
        s[j] = i;
      }
    }
  }

  return r[n];
}

std::vector<int> __cut_rod_extended_path(int n, const std::vector<int> &s)
{
  std::vector<int> path;
  while (n > 0)
  {
    path.push_back(s[n]);
    n = n - s[n];
  }
  return path;
}

int cut_rod_extended(int n, const std::vector<int> &p, std::vector<int> &path)
{
  std::vector<int> s(n);
  int ans = __cut_rod_extended_tabulation(n, p, s);
  path = __cut_rod_extended_path(n, s);
  return ans;
}