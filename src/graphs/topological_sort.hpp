#include <bits/stdc++.h>

void __topo_dfs(int u, const std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::stack<int> &S)
{
  visited[u] = true;

  for (auto v : adj[u])
    if (!visited[v])
      __topo_dfs(v, adj, visited, S);

  S.push(u);
}

std::stack<int> topological_sort(const std::vector<std::vector<int>> &adj)
{
  std::stack<int> S;
  std::vector<bool> visited(adj.size(), false);

  for (int i = 0; i < adj.size(); i++)
    if (!visited[i])
      __topo_dfs(i, adj, visited, S);

  return S;
}
