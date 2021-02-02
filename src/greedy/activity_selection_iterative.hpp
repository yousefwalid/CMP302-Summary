#include <bits/stdc++.h>

typedef std::vector<std::pair<int, int>> vpii;

bool __sort_by_second_asc(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
  return a.second < b.second;
}

vpii activity_selection_iterative(const vpii &tasks)
{
  auto sorted_tasks = vpii(tasks);
  sort(sorted_tasks.begin(), sorted_tasks.end(), __sort_by_second_asc);

  int k = INT_MIN;
  vpii A;

  for (int i = 0; i < sorted_tasks.size(); i++)
  {
    if (tasks[i].first >= k)
    {
      k = tasks[i].second;
      A.push_back(tasks[i]);
    }
  }
  return A;
}