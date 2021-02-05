#include <bits/stdc++.h>

void dfs(int u, std::vector<bool> &visited, const std::vector<std::vector<int>> &adj)
{
  visited[u] = true;

  for (auto v : adj[u])
    if (!visited[v])
      dfs(v, visited, adj);
}