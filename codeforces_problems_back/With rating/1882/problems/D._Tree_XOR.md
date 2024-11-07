<h1 style='text-align: center;'> D. Tree XOR</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a tree with $n$ vertices labeled from $1$ to $n$. An integer $a_{i}$ is written on vertex $i$ for $i = 1, 2, \ldots, n$. You want to make all $a_{i}$ equal by performing some (possibly, zero) spells.

Suppose you root the tree at some vertex. On each spell, you can select any vertex $v$ and any non-negative integer $c$. Then for all vertices $i$ in the subtree$^{\dagger}$ of $v$, replace $a_{i}$ with $a_{i} \oplus c$. The cost of this spell is $s \cdot c$, where $s$ is the number of vertices in the subtree. Here $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Let $m_r$ be the minimum possible total cost required to make all $a_i$ equal, if vertex $r$ is chosen as the root of the tree. Find $m_{1}, m_{2}, \ldots, m_{n}$.

$^{\dagger}$ Suppose vertex $r$ is chosen as the root of the tree. Then vertex $i$ belongs to the subtree of $v$ if the simple path from $i$ to $r$ contains $v$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^{4}$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^{5}$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^{20}$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), denoting that there is an edge connecting two vertices $u$ and $v$.

It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^{5}$.

## Output

For each test case, print $m_1, m_2, \ldots, m_n$ on a new line.

## Example

## Input


```

243 2 1 01 22 32 41100
```
## Output


```

8 6 12 10 
0 

```
## Note

In the first test case, to find $m_1$ we root the tree at vertex $1$. 

1. In the first spell, choose $v=2$ and $c=1$. After performing the spell, $a$ will become $[3, 3, 0, 1]$. The cost of this spell is $3$.
2. In the second spell, choose $v=3$ and $c=3$. After performing the spell, $a$ will become $[3, 3, 3, 1]$. The cost of this spell is $3$.
3. In the third spell, choose $v=4$ and $c=2$. After performing the spell, $a$ will become $[3, 3, 3, 3]$. The cost of this spell is $2$.

Now all the values in array $a$ are equal, and the total cost is $3 + 3 + 2 = 8$.

The values $m_2$, $m_3$, $m_4$ can be found analogously.

In the second test case, the goal is already achieved because there is only one vertex.



#### tags 

#1900 #bitmasks #dfs_and_similar #dp #greedy #trees 