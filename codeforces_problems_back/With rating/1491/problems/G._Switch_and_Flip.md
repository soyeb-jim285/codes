<h1 style='text-align: center;'> G. Switch and Flip</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ coins labeled from $1$ to $n$. Initially, coin $c_i$ is on position $i$ and is facing upwards (($c_1, c_2, \dots, c_n)$ is a permutation of numbers from $1$ to $n$). You can do some operations on these coins. 

In one operation, you can do the following:

* Choose $2$ distinct indices $i$ and $j$.
* Then, swap the coins on positions $i$ and $j$.
* Then, flip both coins on positions $i$ and $j$. (If they are initially faced up, they will be faced down after the operation and vice versa)

Construct a sequence of at most $n+1$ operations such that after performing all these operations the coin $i$ will be on position $i$ at the end, facing up.

## Note

 that you do not need to minimize the number of operations.

## Input

The first line contains an integer $n$ ($3 \leq n \leq 2 \cdot 10^5$) — the number of coins.

The second line contains $n$ integers $c_1,c_2,\dots,c_n$ ($1 \le c_i \le n$, $c_i \neq c_j$ for $i\neq j$).

## Output

In the first line, output an integer $q$ $(0 \leq q \leq n+1)$ — the number of operations you used.

In the following $q$ lines, output two integers $i$ and $j$ $(1 \leq i, j \leq n, i \ne j)$ — the positions you chose for the current operation.

## Examples

## Input


```

3
2 1 3

```
## Output


```

3
1 3
3 2
3 1

```
## Input


```

5
1 2 3 4 5

```
## Output


```

0

```
## Note

Let coin $i$ facing upwards be denoted as $i$ and coin $i$ facing downwards be denoted as $-i$.

The series of moves performed in the first sample changes the coins as such:

* $[~~~2,~~~1,~~~3]$
* $[-3,~~~1,-2]$
* $[-3,~~~2,-1]$
* $[~~~1,~~~2,~~~3]$

In the second sample, the coins are already in their correct positions so there is no need to swap.



#### tags 

#2800 #constructive_algorithms #graphs #math 