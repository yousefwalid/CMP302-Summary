#include <bits/stdc++.h>
#include "fib_tabulation.hpp"
#include "fib_memoization.hpp"
#include "cut_rod_memoization.hpp"
#include "cut_rod_tabulation.hpp"
#include "cut_rod_extended.hpp"
#include "mat_chain_memoization.hpp"
#include "mat_chain_tabulation.hpp"
using namespace std;

// Fib
int fib_n = 4;
int fib_N[] = {5, 7, 9, 12};
int fib_F[] = {5, 13, 34, 144};

// Cut Rod
int cut_rod_P[] = {0, 1, 5, 8, 9};
int cut_rod_F = 10;
int cut_rod_path_n = 2;
int cut_rod_path_arr[] = {2, 2};

// Mat Chain
int mat_chain_p[] = {30, 35, 15, 5, 10, 20, 25};

void spec_fib_tabulation()
{
  for (int i = 0; i < fib_n; i++)
  {
    assert(fib_tabulation(fib_N[i]) == fib_F[i]);
  }
}

void spec_fib_memoization()
{
  for (int i = 0; i < fib_n; i++)
  {
    assert(fib_memoization(fib_N[i]) == fib_F[i]);
  }
}

void spec_cut_rod_memoization()
{
  int n = sizeof(cut_rod_P) / sizeof(cut_rod_P[0]);
  auto p = vector<int>(cut_rod_P, cut_rod_P + n);
  assert(cut_rod_memoization(4, p) == cut_rod_F);
}

void spec_cut_rod_tabulation()
{
  int n = sizeof(cut_rod_P) / sizeof(cut_rod_P[0]);
  auto p = vector<int>(cut_rod_P, cut_rod_P + n);
  assert(cut_rod_tabulation(4, p) == cut_rod_F);
}

void spec_cut_rod_extended()
{
  int n = sizeof(cut_rod_P) / sizeof(cut_rod_P[0]);
  auto p = vector<int>(cut_rod_P, cut_rod_P + n);

  vector<int> path;

  assert(cut_rod_extended(4, p, path) == cut_rod_F);
  assert(path.size() == cut_rod_path_n);
  for (int i = 0; i < cut_rod_path_n; i++)
    assert(cut_rod_path_arr[i] == path[i]);
}

void spec_mat_chain_memoization()
{
  int n = sizeof(mat_chain_p) / sizeof(mat_chain_p[0]);
  auto p = vector<int>(mat_chain_p, mat_chain_p + n);
  assert(mat_chain_memoization(p) == 15125);
}

void spec_mat_chain_tabulation()
{
  int n = sizeof(mat_chain_p) / sizeof(mat_chain_p[0]);
  auto p = vector<int>(mat_chain_p, mat_chain_p + n);
  assert(mat_chain_tabulation(p) == 15125);
}

int main()
{
  cout << "Starting DP Tests" << endl;

  spec_fib_tabulation();
  cout << "\t ✅ fib_tabulation" << endl;

  spec_fib_memoization();
  cout << "\t ✅ fib_memoization" << endl;

  spec_cut_rod_memoization();
  cout << "\t ✅ cut_rod_memoization" << endl;

  spec_cut_rod_tabulation();
  cout << "\t ✅ cut_rod_tabulation" << endl;

  spec_cut_rod_extended();
  cout << "\t ✅ cut_rod_extended" << endl;

  spec_mat_chain_memoization();
  cout << "\t ✅ mat_chain_memoization" << endl;

  spec_mat_chain_tabulation();
  cout << "\t ✅ mat_chain_tabulation" << endl;

  cout << "✅ DP tests" << endl;
}