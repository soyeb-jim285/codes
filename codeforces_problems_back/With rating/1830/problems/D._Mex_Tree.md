<h1 style='text-align: center;'> D. Mex Tree</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree with $n$ nodes. For each node, you either color it in $0$ or $1$.

The value of a path $(u,v)$ is equal to the MEX$^\dagger$ of the colors of the nodes from the shortest path between $u$ and $v$.

The value of a coloring is equal to the sum of values of all paths $(u,v)$ such that $1 \leq u \leq v \leq n$.

What is the maximum possible value of any coloring of the tree?

$^{\dagger}$ The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance:

* The MEX of $[2,2,1]$ is $0$, because $0$ does not belong to the array.
* The MEX of $[3,1,0,1]$ is $2$, because $0$ and $1$ belong to the array, but $2$ does not.
* The MEX of $[0,3,1,2]$ is $4$ because $0$, $1$, $2$, and $3$ belong to the array, but $4$ does not.
## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of nodes in the tree.

The following $n-1$ lines of each test case contains $2$ integers $a_i$ and $b_i$ ($1 \leq a_i, b_i \leq n, a_i \neq b_i$) — indicating an edge between vertices $a_i$ and $b_i$. It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of $n$ across all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print the maximum possible value of any coloring of the tree.

## Example

## Input


```

431 22 341 21 31 4101 21 33 43 51 65 72 86 96 101
```
## Output


```

8
15
96
1

```
## Note

In the first sample, we will color vertex $2$ in $1$ and vertices $1,3$ in $0$. After this, we consider all paths: 

* $(1,1)$ with value $1$
* $(1,2)$ with value $2$
* $(1,3)$ with value $2$
* $(2,2)$ with value $0$
* $(2,3)$ with value $2$
* $(3,3)$ with value $1$

We notice the sum of values is $8$ which is the maximum possible.



#### tags 

#2800 #brute_force #dp #trees 