#include <bits/stdc++.h>

int __cut_rod_memoization(int n, const std::vector<int> &p, std::vector<int> &memo)
{
  if (n == 0)
    return 0;

  int &dp = memo[n];
  if (dp != -1)
    return dp;

  int q = INT_MIN;
  for (int i = 1; i <= n; i++)
  {
    q = std::max(q, p[i] + __cut_rod_memoization(n - i, p, memo));
  }

  dp = q;
  return dp;
}

int cut_rod_memoization(int n, const std::vector<int> &p)
{
  std::vector<int> memo(n + 1, -1);
  return __cut_rod_memoization(n, p, memo);
}