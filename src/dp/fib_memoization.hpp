#include <bits/stdc++.h>

int __rec_fib_memoization(int n, std::vector<int> &memo)
{
  if (n == 2 || n == 1)
    return 1;

  int &dp = memo[n];
  if (dp != -1)
    return memo[n];

  dp = __rec_fib_memoization(n - 1, memo) + __rec_fib_memoization(n - 2, memo);
  return dp;
}

int fib_memoization(int n)
{
  std::vector<int> memo(n + 1, -1);

  return __rec_fib_memoization(n, memo);
}