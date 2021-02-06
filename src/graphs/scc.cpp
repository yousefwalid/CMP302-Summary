#include <bits/stdc++.h>
#include "topological_sort.hpp"
#include "util.hpp"

void __scc_dfs(int u, const std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::vector<int> &c)
{
  visited[u] = true;
  c.push_back(u);
  for (auto v : adj[u])
    if (!visited[v])
      __scc_dfs(v, adj, visited, c);
}

std::vector<std::vector<int>> scc(const std::vector<std::vector<int>> &adj)
{
  auto S = topological_sort(adj);

  auto adj_T = __transpose_G(adj);

  std::vector<bool> visited(adj.size(), false);
  std::vector<std::vector<int>> sccs;

  while (!S.empty())
  {
    auto u = S.top();
    S.pop();
    if (!visited[u])
    {
      std::vector<int> c;
      __scc_dfs(u, adj_T, visited, c);
      sccs.push_back(c);
    }
  }

  return sccs;
}