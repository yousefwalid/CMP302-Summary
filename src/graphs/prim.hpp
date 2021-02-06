#include <bits/stdc++.h>
#include "util.hpp"

#define f first
#define s second

int prim(const std::vector<std::vector<std::pair<int, int>>> &adj)
{
  std::vector<bool> visited(adj.size(), false);
  std::priority_queue<std::pair<int, int>> pq;

  pq.push({0, 1});

  int MST = 0;

  while (!pq.empty())
  {
    int u = pq.top().s;
    int w = pq.top().f;
    pq.pop();

    if (visited[u])
      continue;

    visited[u] = true;

    MST += w;

    for (auto &e : adj[u])
      if (!visited[e.f])
        pq.push({e.s, e.f});
  }
  return MST;
}