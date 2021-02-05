#include <bits/stdc++.h>

#define NOT_VISITED -1

void bfs(int s, std::vector<int> &sp, const std::vector<std::vector<int>> &adj)
{
  sp.resize(adj.size());
  std::fill(sp.begin(), sp.end(), NOT_VISITED);

  sp[s] = 0;
  std::queue<int> Q;
  Q.push(s);

  while (!Q.empty())
  {
    auto u = Q.front();
    Q.pop();

    for (auto v : adj[u])
      if (sp[v] == NOT_VISITED)
      {
        sp[v] = sp[u] + 1;
        Q.push(v);
      }
  }
}