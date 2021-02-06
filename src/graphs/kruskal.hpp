#include <bits/stdc++.h>
#include "dsu.hpp"
#include "util.hpp"
#define f first
#define s second

int kruskal(const std::vector<std::vector<std::pair<int, int>>> &adj)
{
  int MST = 0;

  std::vector<std::pair<int, std::pair<int, int>>> edges = __get_edges(adj);
  sort(edges.begin(), edges.end());

  auto dsu_par = dsu_init(adj.size());

  for (auto e : edges)
  {
    int u = e.s.f;
    int v = e.s.s;
    if (dsu_find_set(u, dsu_par) != dsu_find_set(v, dsu_par))
    {
      dsu_union(u, v, dsu_par);
      MST += e.f;
    }
  }

  return MST;
}