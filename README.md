# CMP302: Design and Analysis of Algorithms Summary

This repository is a summary for the course, it will contain my own implementation (in C++) for included algorithms, along with pseudocode, important notes and complexity analysis for each algorithm.

# Table of Contents

- [Dynamic Programming](#dynamic-programming)
- [Greedy Algorithms]()
- [Graphs]()
  - [placeholder]()
- [NP Completeness]()
- [String Matching]()

# Dynamic Programming

A faster technique to solve divide-and-conquer problems, usually decreases running time from **exponential** to **linear**.

## Conditions for DP solution satisfaction:
1. Optimal Substructure
    - An optimal solution to the problem can be constructed from the optimal solution of its subproblems.
2. Overlapping Subproblems
    - Subproblems solutions are re-used multiple times.

## Types of DP solutions:
A DP solution can be one of the following two types:
1. Top-down approach **(Memoization)**
   - Start from the big problem and work your way down, decomposing the big problem to multiple smaller ones. 
   - Involves recursion which usually takes more memory space than bottom-up solutions.
   - Usually easier to implement than bottom-up solutions.
2. Bottom-up approach **(Tabulation)**
   - Start from the smallest problem and work your way up to the bigger one.
   - Iterative solution (with loops).
   - Saves memory space (no recursion required).
   - Harder to implement

## Bottom-up solution steps
Any bottom-up solution contains 3 major pillars.
1. Base case
    - The recursion termination condition
2. State
    - The base parameters of the recursion method.
    - Must be able to uniquely identify all the states of the recursion.
    - The size of the state impacts the time and memory complexity of the solution.
3. Transition
    - The relation between a problem and its subproblems.
    - The way to construct the bigger problem using its smaller subproblems.

When solving any DP problem we must figure out these 3 things, usually finding out the base case is trivial, we must then think about the state or the transition (whichever is easier).

## Complexity of DP

- DP complexity = O(product of state size)

Example: 
State = $[1000][5000]$
Complexity = $O(1000*5000)$

## Fibonacci

Fibonacci can be implemented recursively in a naive way as follows:
```py
def fib(n):
  if(n == 1 or n == 2)
    return 1
  else
    return fib(n-1) + fib(n-2)
```
However, this implementation is not very well as it is $O(2^n)$.

We can improve this by adding memoization:
```py
def fib(n):
  if(n == 1 or n == 2)
    return 1
  else
    if(n in memo)
      return memo[n]
    else
      memo[n] = fib[n-1] + fib[n-2]
      return memo[n]
```
This improves the complexity to $O(n)$, however this takes memory space $O(N)$ where $N$ is the largest fibonacci number, this also takes a lot of space in the stack as it is a recursive implementation.

This can also be implemented with tabulation:
```py
def fib(n):
  fib[0] = 0
  fib[1] = 1
  for i in 2:n
    fib[i] = fib[i-1] + fib[i-2]
  return fib[n]
```

## Rod Cutting