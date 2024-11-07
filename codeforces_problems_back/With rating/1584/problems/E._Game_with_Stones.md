<h1 style='text-align: center;'> E. Game with Stones</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bob decided to take a break from calculus homework and designed a game for himself. 

The game is played on a sequence of piles of stones, which can be described with a sequence of integers $s_1, \ldots, s_k$, where $s_i$ is the number of stones in the $i$-th pile. On each turn, Bob picks a pair of non-empty adjacent piles $i$ and $i+1$ and takes one stone from each. If a pile becomes empty, its adjacent piles do not become adjacent. The game ends when Bob can't make turns anymore. Bob considers himself a winner if at the end all piles are empty.

We consider a sequence of piles winning if Bob can start with it and win with some sequence of moves.

You are given a sequence $a_1, \ldots, a_n$, count the number of subsegments of $a$ that describe a winning sequence of piles. In other words find the number of segments $[l, r]$ ($1 \leq l \leq r \leq n$), such that the sequence $a_l, a_{l+1}, \ldots, a_r$ is winning.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 3 \cdot 10^5$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 3 \cdot 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

## Output

Print a single integer for each test case — the answer to the problem.

## Example

## Input


```

6
2
2 2
3
1 2 3
4
1 1 1 1
4
1 2 2 1
4
1 2 1 2
8
1 2 1 2 1 2 1 2

```
## Output


```

1
0
4
2
1
3

```
## Note

In the first test case, Bob can't win on subsegments of length $1$, as there is no pair of adjacent piles in an array of length $1$.

In the second test case, every subsegment is not winning.

In the fourth test case, the subsegment $[1, 4]$ is winning, because Bob can make moves with pairs of adjacent piles: $(2, 3)$, $(1, 2)$, $(3, 4)$. Another winning subsegment is $[2, 3]$.



#### tags 

#2300 #binary_search #data_structures #games #greedy 