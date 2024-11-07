<h1 style='text-align: center;'> E. Sum Over Zero</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$ of $n$ integers. Consider $S$ as a set of segments satisfying the following conditions.

* Each element of $S$ should be in form $[x, y]$, where $x$ and $y$ are integers between $1$ and $n$, inclusive, and $x \leq y$.
* No two segments in $S$ intersect with each other. Two segments $[a, b]$ and $[c, d]$ intersect if and only if there exists an integer $x$ such that $a \leq x \leq b$ and $c \leq x \leq d$.
* For each $[x, y]$ in $S$, $a_x+a_{x+1}+ \ldots +a_y \geq 0$.

The length of the segment $[x, y]$ is defined as $y-x+1$. $f(S)$ is defined as the sum of the lengths of every element in $S$. In a formal way, $f(S) = \sum_{[x, y] \in S} (y - x + 1)$. ## Note

 that if $S$ is empty, $f(S)$ is $0$.

What is the maximum $f(S)$ among all possible $S$?

## Input

The first line contains one integer $n$ ($1 \leq n \leq 2 \cdot 10^5$).

The next line is followed by $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \leq a_i \leq 10^9$).

## Output

Print a single integer, the maximum $f(S)$ among every possible $S$.

## Examples

## Input


```

5
3 -3 -2 5 -4

```
## Output


```

4
```
## Input


```

10
5 -2 -4 -6 2 3 -6 5 3 -2

```
## Output


```

9
```
## Input


```

4
-1 -2 -3 -4

```
## Output


```

0
```
## Note

In the first example, $S=\{[1, 2], [4, 5]\}$ can be a possible $S$ because $a_1+a_2=0$ and $a_4+a_5=1$. $S=\{[1, 4]\}$ can also be a possible solution.

Since there does not exist any $S$ that satisfies $f(S) > 4$, the answer is $4$.

In the second example, $S=\{[1, 9]\}$ is the only set that satisfies $f(S)=9$. Since every possible $S$ satisfies $f(S) \leq 9$, the answer is $9$.

In the third example, $S$ can only be an empty set, so the answer is $0$.



#### tags 

#2200 #data_structures #dfs_and_similar #dp 