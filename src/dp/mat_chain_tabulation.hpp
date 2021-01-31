#include <bits/stdc++.h>

int mat_chain_tabulation(const std::vector<int> &p)
{
  int n = p.size() - 1;

  std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++)
    m[i][i] = 0;

  for (int l = 2; l <= n; l++)
  {
    for (int i = 1; i <= n - l + 1; i++)
    {
      int j = i + l - 1;
      m[i][j] = INT_MAX;

      for (int k = i; k < j; k++)
      {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
        {
          m[i][j] = q;
        }
      }
    }
  }

  return m[1][n];
}