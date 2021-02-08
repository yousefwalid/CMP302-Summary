#include <bits/stdc++.h>

using namespace std;

bool ford(int s, vector<int> &sp, const vector<vector<pair<int, int>>> &adj)
{
  bool updated = true;
  int n = adj.size(), u, v, c;

  sp = vector<int>(n, INT_MAX);

  for (int k = 0; k < n && updated; k++)
  {
    updated = false;
    for (u = 0; u < n; u++)
    {
      for (auto &e : adj[u])
      {
        v = e.first;
        c = e.second;

        if (sp[v] > sp[u] + c * 1LL)
        {
          sp[v] = sp[u] + c;
          updated = true;
        }
      }
    }
  }

  return updated;
}