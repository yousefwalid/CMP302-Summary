#include <bits/stdc++.h>

using namespace std;

int __find_path(int s, int t, vector<int> &par, const vector<vector<pair<int, int>>> &adj, const vector<vector<int>> &capacity)
{
  fill(par.begin(), par.end(), -1);

  par[s] = -2;

  queue<pair<int, int>> q;
  q.push({s, INT_MAX});

  int u,   // current node
      v,   // new node
      u_f, // flow of u
      v_f; // flow of v
  while (!q.empty())
  {
    u = q.front().first;
    u_f = q.front().second;
    q.pop();

    for (auto &e : adj[u])
    {
      v = q.front().first;
      v_f = capacity[u][v];
      if (par[v] == -1 && v_f > 0) // new edge with flow > 0
      {
        par[v] = u;
        int new_flow = min(u_f, v_f);
        if (v == t)
          return new_flow;

        q.push({v, new_flow});
      }
    }
  }

  return 0;
}

int edmonds_karp(int s, int t, const vector<vector<pair<int, int>>> &adj)
{
  int flow = 0, new_flow, n = adj.size();
  vector<int> par(n);
  vector<vector<int>> capacity(n, vector<int>(n, 0));

  for (int u = 0; u < n; u++)
    for (auto &e : adj[u])
      capacity[u][e.first] = e.second;

  while (new_flow = __find_path(s, t, par, adj, capacity))
  {
    flow += new_flow;
    int current = t;
    int previous;
    while (current != s) // Move on path from sink to source and update the edge values with the newly found path
    {
      previous = par[current];
      capacity[previous][current] -= new_flow;
      capacity[current][previous] += new_flow;
      current = previous;
    }
  }

  return flow;
}