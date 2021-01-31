#include <bits/stdc++.h>

int __mat_chain_memoization(int i, int j, const std::vector<int> &p, std::vector<std::vector<int>> &memo)
{
  if (i == j)
    return 0;

  int &dp = memo[i][j];
  if (dp != -1)
    return dp;

  int q = INT_MAX;

  for (int k = i; k < j; k++)
    q = std::min(q, __mat_chain_memoization(i, k, p, memo) + __mat_chain_memoization(k + 1, j, p, memo) + p[i - 1] * p[k] * p[j]);

  dp = q;

  return dp;
}

int mat_chain_memoization(const std::vector<int> &p)
{
  std::vector<std::vector<int>> memo(1000, std::vector<int>(1000, -1));

  int i = 1;
  int j = p.size() - 1;

  return __mat_chain_memoization(i, j, p, memo);
}