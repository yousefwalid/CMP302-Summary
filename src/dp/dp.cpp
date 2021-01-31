#include <bits/stdc++.h>
#include "fib_tabulation.hpp"
#include "fib_memoization.hpp"
using namespace std;

// Fib
int fib_n = 4;
int fib_N[] = {5, 7, 9, 12};
int fib_F[] = {5, 13, 34, 144};

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

int main()
{
  cout << "Starting DP Tests" << endl;

  spec_fib_tabulation();
  cout << "\t ✅ fib_tabulation" << endl;

  spec_fib_memoization();
  cout << "\t ✅ fib_memoization" << endl;

  cout << "✅ DP tests" << endl;
}