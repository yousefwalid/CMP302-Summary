#include <bits/stdc++.h>

std::vector<std::pair<int, std::pair<int, int>>> __get_edges(const std::vector<std::vector<std::pair<int, int>>> &adj)
{
  std::vector<std::pair<int, std::pair<int, int>>> edges;

  for (int u = 0; u < adj.size(); u++)
    for (auto p : adj[u])
      edges.push_back({p.second, {u, p.first}});

  return edges;
}

std::vector<std::vector<int>> __transpose_G(const std::vector<std::vector<int>> &adj)
{
  std::vector<std::vector<int>> adj_T(adj.size());

  for (int i = 0; i < adj.size(); i++)
    for (auto v : adj[i])
      adj_T[v].push_back(i);

  return adj_T;
}