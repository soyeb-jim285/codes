<h1 style='text-align: center;'> B. Mark the Dust Sweeper</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mark is cleaning a row of $n$ rooms. The $i$-th room has a nonnegative dust level $a_i$. He has a magical cleaning machine that can do the following three-step operation. 

* Select two indices $i<j$ such that the dust levels $a_i$, $a_{i+1}$, $\dots$, $a_{j-1}$ are all strictly greater than $0$.
* Set $a_i$ to $a_i-1$.
* Set $a_j$ to $a_j+1$.

 Mark's goal is to make $a_1 = a_2 = \ldots = a_{n-1} = 0$ so that he can nicely sweep the $n$-th room. Determine the minimum number of operations needed to reach his goal.## Input

The first line contains a single integer $t$ ($1\leq t\leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2\leq n\leq 2\cdot 10^5$) — the number of rooms.

The second line of each test case contains $n$ integers $a_1$, $a_2$, ..., $a_n$ ($0\leq a_i\leq 10^9$) — the dust level of each room.

It is guaranteed that the sum of $n$ across all test cases does not exceed $2\cdot 10^5$.

## Output

For each test case, print a line containing a single integer — the minimum number of operations. It can be proven that there is a sequence of operations that meets the goal.

## Example

## Input


```

432 0 050 2 0 2 062 0 3 0 4 640 0 0 10
```
## Output


```

3
5
11
0

```
## Note

In the first case, one possible sequence of operations is as follows. 

* Choose $i=1$ and $j=2$, yielding the array $[1,1,0]$.
* Choose $i=1$ and $j=3$, yielding the array $[0,1,1]$.
* Choose $i=2$ and $j=3$, yielding the array $[0,0,2]$.

 At this point, $a_1=a_2=0$, completing the process.In the second case, one possible sequence of operations is as follows. 

* Choose $i=4$ and $j=5$, yielding the array $[0,2,0,1,1]$.
* Choose $i=2$ and $j=3$, yielding the array $[0,1,1,1,1]$.
* Choose $i=2$ and $j=5$, yielding the array $[0,0,1,1,2]$.
* Choose $i=3$ and $j=5$, yielding the array $[0,0,0,1,3]$.
* Choose $i=4$ and $j=5$, yielding the array $[0,0,0,0,4]$.

In the last case, the array already satisfies the condition.



#### tags 

#900 #constructive_algorithms #greedy #implementation 