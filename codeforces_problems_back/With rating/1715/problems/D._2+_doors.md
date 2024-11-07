<h1 style='text-align: center;'> D. 2+ doors</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Narrator has an integer array $a$ of length $n$, but he will only tell you the size $n$ and $q$ statements, each of them being three integers $i, j, x$, which means that $a_i \mid a_j = x$, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

Find the lexicographically smallest array $a$ that satisfies all the statements.

An array $a$ is lexicographically smaller than an array $b$ of the same length if and only if the following holds: 

* in the first position where $a$ and $b$ differ, the array $a$ has a smaller element than the corresponding element in $b$.
## Input

In the first line you are given with two integers $n$ and $q$ ($1 \le n \le 10^5$, $0 \le q \le 2 \cdot 10^5$).

In the next $q$ lines you are given with three integers $i$, $j$, and $x$ ($1 \le i, j \le n$, $0 \le x < 2^{30}$) — the statements.

It is guaranteed that all $q$ statements hold for at least one array.

## Output

On a single line print $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^{30}$) — array $a$.

## Examples

## Input


```

4 3
1 2 3
1 3 2
4 1 2

```
## Output


```

0 3 2 2 
```
## Input


```

1 0

```
## Output


```

0 
```
## Input


```

2 1
1 1 1073741823

```
## Output


```

1073741823 0 
```
## Note

In the first sample, these are all the arrays satisfying the statements: 

* $[0, 3, 2, 2]$,
* $[2, 1, 0, 0]$,
* $[2, 1, 0, 2]$,
* $[2, 1, 2, 0]$,
* $[2, 1, 2, 2]$,
* $[2, 3, 0, 0]$,
* $[2, 3, 0, 2]$,
* $[2, 3, 2, 0]$,
* $[2, 3, 2, 2]$.


#### tags 

#1900 #2-sat #bitmasks #graphs #greedy 