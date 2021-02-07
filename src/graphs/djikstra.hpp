#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

vector<int> djikstra(const vector<vector<pair<int, int>>> &adj, int s)
{
  vector<int> sp(adj.size(), INT_MAX);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({0, s});
  sp[s] = 0;

  int u, v;
  long long c, cost;
  while (!pq.empty())
  {
    u = pq.top().s;
    c = pq.top().f;
    pq.pop();

    if (sp[u] < c)
      continue;

    for (auto &e : adj[u])
    {
      v = e.f;
      cost = e.s;

      if (c + cost < sp[v])
      {
        sp[v] = c + cost;
        pq.push({sp[v], v});
      }
    }
  }

  return sp;
}