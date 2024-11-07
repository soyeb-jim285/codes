<h1 style='text-align: center;'> D. Infinite Set</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ distinct positive integers.

Let's consider an infinite integer set $S$ which contains all integers $x$ that satisfy at least one of the following conditions:

1. $x = a_i$ for some $1 \leq i \leq n$.
2. $x = 2y + 1$ and $y$ is in $S$.
3. $x = 4y$ and $y$ is in $S$.

For example, if $a = [1,2]$ then the $10$ smallest elements in $S$ will be $\{1,2,3,4,5,7,8,9,11,12\}$.

Find the number of elements in $S$ that are strictly smaller than $2^p$. Since this number may be too large, print it modulo $10^9 + 7$.

## Input

The first line contains two integers $n$ and $p$ $(1 \leq n, p \leq 2 \cdot 10^5)$.

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ $(1 \leq a_i \leq 10^9)$.

It is guaranteed that all the numbers in $a$ are distinct.

## Output

Print a single integer, the number of elements in $S$ that are strictly smaller than $2^p$. Remember to print it modulo $10^9 + 7$. 

## Examples

## Input


```

2 4
6 1

```
## Output


```

9

```
## Input


```

4 7
20 39 5 200

```
## Output


```

14

```
## Input


```

2 200000
48763 1000000000

```
## Output


```

448201910

```
## Note

In the first example, the elements smaller than $2^4$ are $\{1, 3, 4, 6, 7, 9, 12, 13, 15\}$.

In the second example, the elements smaller than $2^7$ are $\{5,11,20,23,39,41,44,47,79,80,83,89,92,95\}$.



#### tags 

#1800 #bitmasks #dp #math #matrices #number_theory #strings 