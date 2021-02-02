#include <bits/stdc++.h>
#include "activity_selection_iterative.hpp"
using namespace std;

// Activity Selection
vector<pair<int, int>> A = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}};
int F = 4;

void spec_activity_selection_iterative()
{
  vector<pair<int, int>> ans = activity_selection_iterative(A);
  assert(ans.size() == F);
}

int main()
{
  cout << "Starting Greedy Tests" << endl;

  spec_activity_selection_iterative();
  cout << "\t ✅ activity_selection_iterative" << endl;

  cout << "✅ Greedy tests" << endl;
}