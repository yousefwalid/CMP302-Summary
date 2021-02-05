# CMP302: Design and Analysis of Algorithms Summary

This repository is a summary for the course, it will contain my own implementation (in C++) for included algorithms, along with pseudocode, important notes and complexity analysis for each algorithm.

# Table of Contents

- [CMP302: Design and Analysis of Algorithms Summary](#cmp302-design-and-analysis-of-algorithms-summary)
- [Table of Contents](#table-of-contents)
- [Dynamic Programming](#dynamic-programming)
  - [Conditions for DP solution satisfaction](#conditions-for-dp-solution-satisfaction)
  - [Types of DP solutions](#types-of-dp-solutions)
  - [Top-down solution steps](#top-down-solution-steps)
  - [Complexity of DP](#complexity-of-dp)
  - [Fibonacci](#fibonacci)
  - [Rod Cutting](#rod-cutting)
    - [Finding optimal cuts](#finding-optimal-cuts)
  - [Matrix Chain Multiplication](#matrix-chain-multiplication)
    - [Naive approach](#naive-approach)
    - [Recursive approach](#recursive-approach)
    - [Top-down approach](#top-down-approach)
    - [Bottom-up approach](#bottom-up-approach)
- [Greedy Algorithms](#greedy-algorithms)
  - [Solution Steps](#solution-steps)
  - [Activity Selection](#activity-selection)
  - [Knapsack Problem](#knapsack-problem)
    - [0-1 Knapsack](#0-1-knapsack)
    - [Fractional Knapsack](#fractional-knapsack)
  - [Huffman Codes](#huffman-codes)
- [Graphs](#graphs)
  - [Graph Representations](#graph-representations)
  - [Breadth First Search (BFS)](#breadth-first-search-bfs)
  - [Depth First Search (DFS)](#depth-first-search-dfs)
  - [Topological Sort](#topological-sort)
  - [Strongly Connected Components (SCC)](#strongly-connected-components-scc)

# Dynamic Programming

A faster technique to solve divide-and-conquer problems, usually decreases running time from **exponential** to **linear**.

## Conditions for DP solution satisfaction
1. Optimal Substructure
    - An optimal solution to the problem can be constructed from the optimal solution of its subproblems.
2. Overlapping Subproblems
    - Subproblems solutions are re-used multiple times.

## Types of DP solutions
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

## Top-down solution steps
Any Top-down solution contains 3 major pillars.
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

- DP complexity = $O(\text{product of state size} * \text{function work})$

Example: 
State = $[1000][5000]$
Complexity = $O(1000*5000*\text{function work})$

## Fibonacci

Fibonacci can be implemented recursively in a **naive** way as follows:
```py
def fib(n):
  if(n == 1 or n == 2)
    return 1
  else
    return fib(n-1) + fib(n-2)
```
However, this implementation is not very well as it is $O(2^n)$.

We can improve this by adding **memoization**:
```py
def fib(n):
  if(n == 1 or n == 2)
    return 1
  
  if(n in memo)
    return memo[n]

  memo[n] = fib[n-1] + fib[n-2]
  return memo[n]
```
This improves the complexity to $O(n)$, however this takes memory space $O(n)$.

This can also be implemented with **tabulation**:
```py
def fib(n):
  fib[0] = 0
  fib[1] = 1
  for i in 2:n
    fib[i] = fib[i-1] + fib[i-2]
  return fib[n]
```

## Rod Cutting

Cut rod of length n to maximize revenue based on a price table.
![](assets/dp/Rod_Cutting_01.png)
![](assets/dp/Rod_Cutting_02.png)

Can be solved naively by:
  1. Cut a piece at the left end of the rod, and sell it.
  2. Find an optimal way to cut the remainder of the rod.
```py
def cut_rod(n, p): # p is array of prices of piece i
  if (n == 0)
    return 0

  q = -inf
  for i in 1:n
    q = max(q, p[i] + cut_rod(p, n - i))

  return q
```

**Runtime:** $O(2^n)$, we can try to optimize this algorithm using dynamic programming, but first we need to check if a DP approach is applicable, by inspecting the recursion tree:

![](assets/dp/Rod_Cutting_03.png)

This tree has $O(2^n)$ leaves which corresponds to the solution complexity, however we can notice a lot of **overlapping subproblems**.

Implementing this with **memoization**:
```py
def cut_rod(n, p):
  if (n == 0)
    return 0

  if (n in memo)
    return memo[n]

  q = -inf
  for i in 1:n
    q = max(q, p[i] + cut_rod(n - i, p))

  memo[n] = q
  return q
```

**Runtime:** $\Theta(n^2)$

*Note the similarities between the memoization solution and the naive solution, they are very similar, the memoization solution is basically the naive solution but with an extra memoization part that checks if a subproblem has been calculated before.*

We can also start from smaller rods and build our answer up to the bigger rods, implementing this with **tabulation**:

```py
def cut_rod(n, p):
  r[0..n] = new array
  r[0] = 0

  for j in 1:n
    q = -inf
    for i in 1:j
      q = max(q, p[i] + r[j - i])
    r[j] = q

  return r[n]
```

**Runtime:** $\Theta(n^2)$

**Explanation:** $r[0..n]$ is an array containing the optimal answers for all cuts at any given iteration, for each rod length $n$ we can define its optimal answer as $max_{i=0}^{i=n}(p[i] + r[n - i])$. 
*We attempt cutting a piece of length $i$ and add it to the optimal answer of $n - i$ for all possible $i$.*


### Finding optimal cuts
We have previously calculated the maximum profit of the rod cutting problem, we have yet to find the optimal way of cutting. We can achieve that by creating a new array and for a given $n$ store the length of the piece cut at the left of the rod.

![](assets/dp/Rod_Cutting_04.png)

```py
def cut_rod_extended(n, p):
  r[0..n], s[0..n] = new array
  r[0] = 0

  for j in 1:n
    q = -inf

    for i in 1:j
      current_price = p[i] + r[j - i]
      if q < r
        s[n] = i
        q = current_price

    r[j] = q

  return r[n], s


def print_cut_rod(n, s):
  while n > 0
    print s[n]
    n = n - s[n]
```

## Matrix Chain Multiplication
When multiplying matrices, the order of multiplication matters, for example, assume we have three matrices $<A_1, A_2, A_3>$ with dimensions $10 \times 100, 100 \times 5, 5 \times 50$ respectively.

If we do the multiplication as $(A_1 A_2) A_3$, we will do $10 * 5 * 50 + 10 * 5 * 50 = 5000 + 2500 = 7500$ operations.
However if we do it as $A_1 (A_2 A_3)$, this will result in $100 * 5 * 50 + 10 * 100 * 50 = 25000 + 50000 = 75000$ operations, which is 10 times faster.

*Note: Number of operations in matrix multiplication of $(n \times m) * (m \times r)$ is $n * m * r$* 

The Matrix Chain Multiplication problem is the problem of parenthesizing the product of matrices in a way that minimizes the number of operations required for multiplication. $A_1 A_2...A_n$

### Naive approach

Applying a naive approach to this problem simply does not work due to the large number of combinations that can be generated, the number of combinations follows the following recurrence relation:

![](assets/dp/Matrix_Chain_01.png)

Which is $\Omega(2^n)$.

### Recursive approach

We can think about solving a general case, multiplying $A_1 A_2...A_n$.
We are required to find a specific $k$ for which we split the multiplication into ($A_1 A_2...A_k$) ($A_{k+1} A_{k+2}...A_n$) such that the cost of multiplication is minimal.
The cost of multiplication in this case is 
$$Cost(A_1 A_2...A_k) + Cost(A_{k+1} A_{k+2}...A_n) + (p_0 * p_k * p_n)$$

or for a more general case ($A_i A_{i+1}...A_k$) ($A_{k+1} A_{k+2}...A_{j}$) it is
$$Cost(A_i A_{i+1}...A_k) + Cost(A_{k+1} A_{k+2}...A_{j}) + (p_{i-1} * p_k * p_j)$$

*where a matrix $A_i$ has dimensions $p_{i-1} \times p_i$*

We can then find a recurrence relation that translates the above:

$m(i, j) = m(i, k) + m(k + 1, j) + p_{i-1}p_{k}p_{j}$

with $m(i, j) = 0$ when $i = j$.

The final form of the reccurence relation:

![](assets/dp/Matrix_Chain_02.png)

This can be implemented with **recursion**:

```py
def mat_chain(i, j):
  if(i == j)
    return 0
  
  q = inf
  
  for k in i:j-1
    q = min(q, mat_chain(i, k) + mat_chain(k+1, j) + (p[i - 1] * p[k] * p[j]))
  
  return q
```

**Runtime is exponential**

### Top-down approach
We can take the previous recursive solution and apply **memoization** to it:

```py
def mat_chain(i, j):
  if(i == j)
    return 0
  
  if((i,j) in memo)
    return memo[i, j]

  q = inf
  
  for k in i:j-1
    q = min(q, mat_chain(i, k) + mat_chain(k+1, j) + (p[i - 1] * p[k] * p[j]))
  
  memo[i, j] = q
  return memo[i, j]
```

**Runtime:** $O(n^3)$

### Bottom-up approach

We can build up the smaller solutions by thinking backwards, computing smaller multiplications first and then bigger ones in sequence, we need to do this in a correct order to solve the problem of dependency in solutions.

Visualizing the table of the DP helps:

![](assets/dp/Matrix_Chain_03.png)

We can notice that we need to start with chains of length 1 and work our way up to the maximum chain length.
We can also compute the ideal position to parenthesis at on our way.

```py
def mat_chain(): 
  n = p.length - 1    # p is sizes of matrices
  m[1..n][1..n], s[1..n][1..n] = new array

  for i in 1:n  
    m[i, i] = 0       # chains with length = 1

  for l in 1:n        # chains with length > 1
    for i in 1:n-l+1  # i = start of chain
      j = i + l - 1   # j = end of chain
      m[i, j] = inf

      for k in i:j-1  # try cutting at k for all k
        q = m[i, k] + m[k+1, j] + p[i-1] * p[k] * p[j]
        if q < m[i, j]
          m[i, j] = q
          s[i, j] = k
  return m[1, n], s
```
**Runtime:** $O(n^3)$

# Greedy Algorithms

- A greedy algorithm always makes the best choice currently.
- Takes the locally optimal solution hoping to reach a globally optimal solution.
- Does not guarantee optimal solutions, but a greedy solution is always at least sub-optimal.
- Proving that a greedy solution is optimal or not is the hard part.
- Much faster than other solutions
- Good for optimization problems

## Solution Steps

1. Interpret the optimization problem as one we make a choice and are left with one smaller subproblem to solve.
2. Prove there is an optimal solution to the original problem that makes the greedy choice.
3. Make sure that combining the optimal solution to the subproblem we have left with the greedy choice we made will leave us with the optimal solution.

## Activity Selection

Find max subset of non-overlapping tasks.

![](assets/greedy/activity_selection_01.png)

A greedy solution may be as follows:
```py
def activity_selection():
  sort tasks by finish time

  k = -inf
  A = []

  for task, i in tasks
    if s[i] >= k
      k = f[i]
      A.insert(task)

  return A
```

**Runtime:** $O(nlogn)$

We sort the tasks on finish times, and count the number of non-overlapping tasks from the least finish time up to the largest finish time.

We can prove that this approach yields an optimal solution, like its dynamic programming counterpart, however, this algorithm is much faster.

## Knapsack Problem

### 0-1 Knapsack

Thief trying to pick maximum value items while maintaining a maximum weight $W$, each item has a value $v_i$ and a weight $w_i$.

0-1 Knapsack problem is always solved with dynamic programming as it guarantees the fastest optimal solution.

There is no optimal greedy algorithm for solving this problem, that is because when making a local choice we cannot guarantee that it is globally optimal.

### Fractional Knapsack

Fractional Knapsack problem is similar to `0-1 Knapsack` but the thief can pick a fraction of the item.

It is easy to find an optimal solution to this problem greedily. Find the item with the highest $value/pound$ and take it.

```py
def FractionalKnapsack(items):
  a = []
  for item in items
    a.insert({ item.v / item.w, w })
  
  sort_descendingly(a)

  ans = 0
  for item in a
    ans += a.value * a.weight

  return ans
```

## Huffman Codes

The problem of huffman encoding is taking a set of symbols with probabilities and assign codes to each symbol, such that the entropy of the alphabet is minimal.

```py
def Huffman(C):
  n = |C|
  Q = C

  for i in 1:n-1
    allocate new node z
    z.left = x = Extract_Min(Q)
    z.right = y = Extract_Min(Q)
    z.freq = x.freq + y.freq
    Q.insert(z)

  return Extract_Min(Q)
```

# Graphs

## Graph Representations

- Adjacency List
  - $\Theta(V + E)$ space
  - Takes less space
  - Takes more time to check if there is an edge between $u$ and $v$
- Adjacency Matrix
  - $\Theta(V^2)$ space
  - Takes more space
  - Faster to check if there is an edge between $u$ and $v$

## Breadth First Search (BFS)

- One of the ways to traverse a graph
- Used for finding unweighted shortest path between a node and all nodes
- Expands from s to surrounding nodes

![](assets/graphs/bfs.gif)

```py
def bfs(G, s):
  for each vertex u in G
    u.color = white # white: unvisited, gray: current, black: visited
    u.dist = inf
    u.parent = nil

  s.color = gray
  s.dist = 0
  s.parent = nil

  Q = new queue
  Q.enqueue(s)

  while Q is not empty
    u = Q.dequeue()
    for each v in adj[u]
      if v.color is white
        v.color = gray
        v.dist = u.dist + 1
        v.parent = u
        Q.enqueue(v)

    u.color = black
```

**Runtime:** $O(V + E)$

## Depth First Search (DFS)

- One of the ways to traverse a graph
- Used as a building block for a lot of algorithms

![](assets/graphs/dfs.gif)

```py
def dfs(G):
  for each vertex u in G 
    u.color = white
    u.parent = pi
  time = 0
  for each vertex u in G
    if u.color is white
      dfs_visit(G, u)

def dfs_visit(G, u):
  time = time + 1
  u.start = time
  u.color = gray

  for each vertex v in adj[u]
    if v.color is white
      v.parent = u
      dfs_visit(G, v)

  u.color = black
  time = time + 1
  u.finish = time
```

**Runtime:** $O(V + E)$

## Topological Sort

- Linear ordering of vertices in graph G such that if there exists edge $(u, v)$ then $u$ appears before $v$
- Must be performed on a DAG (directed acyclic graph)

![](assets/graphs/topological.gif)

```py
def topo(G):
  S = new stack

  for each vertex u in G
    u.color = white
  
  for each vertex u in G
    if u.color is white
      topo_dfs(G, S, u)

  while S is not empty
    print(S.pop())

  return S

def topo_dfs(G, S, u):
  u.color = gray

  for each vertex v in adj[u]
    if v.color is white
      topo_dfs(G, Q, u)

  u.color = black
  S.push(u)
```

**Runtime:** $O(V + E)$

## Strongly Connected Components (SCC)

- Maximal set of vertices $C$ such that every pair of vertices $u$ and $v$ are reachable from each other ($u \rarr v; v \rarr u$)

![](assets/graphs/scc.gif)

```py
def scc(G):
  S = topo(G) # topological order of graph 
              # order of vertices according ot finish time
  
  G_T = transpose(G)

  C = new list

  while S is not empty
    u = S.pop()
    if u.color is white
      c = new list
      scc_dfs(G, c, u)
      C.insert(c)

def scc_dfs(G, c, u):
  c.insert(u)
  for vertex v in adj[u]
    if v.color is white
      dfs_print(G, u)
```