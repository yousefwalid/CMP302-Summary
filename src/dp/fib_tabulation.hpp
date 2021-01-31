int fib_tabulation(int n)
{
  int x = 1, y = 1, z;
  for (int i = 2; i < n; i++)
  {
    z = x + y; // fib(i) = fib(i-1) + fib(i-2)
    x = y;
    y = z;
  }
  return y;
}