<h1 style='text-align: center;'> G. SlavicG's Favorite Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a weighted tree with $n$ vertices. Recall that a tree is a connected graph without any cycles. A weighted tree is a tree in which each edge has a certain weight. The tree is undirected, it doesn't have a root.

Since trees bore you, you decided to challenge yourself and play a game on the given tree.

In a move, you can travel from a node to one of its neighbors (another node it has a direct edge with).

You start with a variable $x$ which is initially equal to $0$. When you pass through edge $i$, $x$ changes its value to $x ~\mathsf{XOR}~ w_i$ (where $w_i$ is the weight of the $i$-th edge). 

Your task is to go from vertex $a$ to vertex $b$, but you are allowed to enter node $b$ if and only if after traveling to it, the value of $x$ will become $0$. In other words, you can travel to node $b$ only by using an edge $i$ such that $x ~\mathsf{XOR}~ w_i = 0$. Once you enter node $b$ the game ends and you win.

Additionally, you can teleport at most once at any point in time to any vertex except vertex $b$. You can teleport from any vertex, even from $a$.

Answer with "YES" if you can reach vertex $b$ from $a$, and "NO" otherwise.

## Note

 that $\mathsf{XOR}$ represents the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains three integers $n$, $a$, and $b$ ($2 \leq n \leq 10^5$), ($1 \leq a, b \leq n; a \ne b$) — the number of vertices, and the starting and desired ending node respectively.

Each of the next $n-1$ lines denotes an edge of the tree. Edge $i$ is denoted by three integers $u_i$, $v_i$ and $w_i$  — the labels of vertices it connects ($1 \leq u_i, v_i \leq n; u_i \ne v_i; 1 \leq w_i \leq 10^9$) and the weight of the respective edge.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case output "YES" if you can reach vertex $b$, and "NO" otherwise.

## Example

### Input


```text
35 1 41 3 12 3 24 3 33 5 12 1 21 2 26 2 31 2 12 3 13 4 14 5 35 6 5
```
### Output

```text

YES
NO
YES

```
## Note

For the first test case, we can travel from node $1$ to node $3$, $x$ changing from $0$ to $1$, then we travel from node $3$ to node $2$, $x$ becoming equal to $3$. Now, we can teleport to node $3$ and travel from node $3$ to node $4$, reaching node $b$, since $x$ became equal to $0$ in the end, so we should answer "YES".

For the second test case, we have no moves, since we can't teleport to node $b$ and the only move we have is to travel to node $2$ which is impossible since $x$ wouldn't be equal to $0$ when reaching it, so we should answer "NO".



#### Tags 

#1700 #NOT OK #bitmasks #dfs_and_similar #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_835_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
