#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> floyd(const vector<vector<pair<int, int>>> &adj)
{
  int n = adj.size(), u, v, c;

  vector<vector<int>> sp(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < n; i++)
    sp[i][i] = 0;

  for (int u = 0; u < n; u++)
    for (auto &e : adj[u])
    {
      v = e.first;
      c = e.second;
      sp[u][v] = c;
    }

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (sp[i][j] > sp[i][k] + sp[k][j])
          sp[i][j] = sp[i][k] + sp[k][j];

  return sp;
}