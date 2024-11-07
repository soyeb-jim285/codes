<h1 style='text-align: center;'> H. Permutation and Queries</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of $n$ elements. A permutation of $n$ elements is an array of length $n$ containing each integer from $1$ to $n$ exactly once. For example, $[1, 2, 3]$ and $[4, 3, 5, 1, 2]$ are permutations, but $[1, 2, 4]$ and $[4, 3, 2, 1, 2]$ are not permutations. You should perform $q$ queries.

There are two types of queries:

* $1$ $x$ $y$ — swap $p_x$ and $p_y$.
* $2$ $i$ $k$ — print the number that $i$ will become if we assign $i = p_i$ $k$ times.
## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$).

The second line contains $n$ integers $p_1, p_2, \dots, p_n$.

Each of the next $q$ lines contains three integers. The first integer is $t$ ($1 \le t \le 2$) — type of query. If $t = 1$, then the next two integers are $x$ and $y$ ($1 \le x, y \le n$; $x \ne y$) — first-type query. If $t = 2$, then the next two integers are $i$ and $k$ ($1 \le i, k \le n$) — second-type query.

It is guaranteed that there is at least one second-type query.

## Output

For every second-type query, print one integer in a new line — answer to this query.

## Examples

## Input


```

5 4
5 3 4 2 1
2 3 1
2 1 2
1 1 3
2 1 2

```
## Output


```

4
1
2

```
## Input


```

5 9
2 3 5 1 4
2 3 5
2 5 5
2 5 1
2 5 3
2 5 4
1 5 4
2 5 3
2 2 5
2 5 1

```
## Output


```

3
5
4
2
3
3
3
1

```
## Note

In the first example $p = \{5, 3, 4, 2, 1\}$. 

The first query is to print $p_3$. The answer is $4$.

The second query is to print $p_{p_1}$. The answer is $1$.

The third query is to swap $p_1$ and $p_3$. Now $p = \{4, 3, 5, 2, 1\}$.

The fourth query is to print $p_{p_1}$. The answer is $2$.



#### tags 

#2400 #brute_force #data_structures #divide_and_conquer #two_pointers 