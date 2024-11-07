<h1 style='text-align: center;'> G. Moving Platforms</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a game where you need to move through a labyrinth. The labyrinth consists of $n$ platforms, connected by $m$ passages. 

Each platform is at some level $l_i$, an integer number from $0$ to $H - 1$. In a single step, if you are currently on platform $i$, you can stay on it, or move to another platform $j$. To move to platform $j$ they have to be connected by the passage, and their levels have to be the same, namely $l_i = l_j$.

After each step, the levels of all platforms change. The new level of platform $i$ is calculated as $l'_i = (l_i + s_i) \bmod H$, for all $i$. 

You start on platform $1$. Find the minimum number of steps you need to get to platform $n$.

## Input

The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains three integers $n$, $m$, and $H$ ($2 \le n \le 10^5$, $1 \le m \le 10^5$, $1 \le H \le 10^9$).

The second line contains $n$ integers $l_i$, the initial level of each platform ($0 \le l_i \le H-1$). 

The third line contains $n$ integers $s_i$, the change of level for each platform ($0 \le s_i \le H-1$).

Next $m$ lines contain a description of the passages. Each passage is described as a pair of integers — the platforms, connected by the passage. There is at most one passage connecting each pair of platforms, and there is no passage connecting a platform to itself.

The sum of $n$ for all tests does not exceed $10^5$, the sum of $m$ for all tests does not exceed $10^5$.

## Output

For each test case, print a single integer, the minimum number of steps needed to get from platform $1$ to platform $n$.

If it is impossible to get to platform $n$, print $-1$.

## Example

## Input


```

33 3 101 9 42 3 01 23 21 32 1 101 24 61 28 7 2522 14 5 3 10 14 11 19 5 4 10 7 16 18 182 86 33 57 52 61 44 7
```
## Output


```

6
-1
52

```
## Note

This is how levels of the platforms change, and what actions we need to perform in the first example.



|  | Platform 1 | Platform 2 | Platform 3 | Action |
| --- | --- | --- | --- | --- |
| Step 1 | 1 | 9 | 4 | Stay on the platform 1 |
| Step 2 | 3 | 2 | 4 | Stay on the platform 1 |
| Step 3 | 5 | 5 | 4 | Move to the platform 2 |
| Step 4 | 7 | 8 | 4 | Stay on the platform 2 |
| Step 5 | 9 | 1 | 4 | Stay on the platform 2 |
| Step 6 | 1 | 4 | 4 | Move to the platform 3 |





#### tags 

#2300 #graphs #math #number_theory #shortest_paths 