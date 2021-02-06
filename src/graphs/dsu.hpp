#include <bits/stdc++.h>

std::vector<int> dsu_init(int n)
{
  std::vector<int> par(n);
  iota(par.begin(), par.end(), 0);
  return par;
}

int dsu_find_set(int x, std::vector<int> &par)
{
  if (x == par[x])
    return x;

  return par[x] = dsu_find_set(par[x], par);
}

bool dsu_union(int x, int y, std::vector<int> &par)
{
  int a = dsu_find_set(x, par);
  int b = dsu_find_set(y, par);

  if (a == b)
    return false;

  par[a] = b;

  return true;
}