<h1 style='text-align: center;'> H. Parallel Swaps Sort</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

[Dubmood - Keygen 8](https://soundcloud.com/penehlopeexd/keygen-8-dubmood)⠀You are given a permutation $p_1, p_2, \dots, p_n$ of $[1, 2, \dots, n]$. You can perform the following operation some (possibly $0$) times:

* choose a subarray $[l, r]$ of even length;
* swap $a_l$, $a_{l+1}$;
* swap $a_{l+2}$, $a_{l+3}$ (if $l+3 \leq r$);
* $\dots$
* swap $a_{r-1}$, $a_r$.

Sort the permutation in at most $10^6$ operations. You do not need to minimize the number of operations.

## Input

The first line contains a single integer $n$ ($2 \le n \le 3 \cdot 10^5$) — the length of the permutation.

The second line contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$, the $p_i$ are distinct) — the permutation before performing the operations.

## Output

## Output

 your operations in the following format.

The first line should contain an integer $k$ ($0 \le k \le 10^6$) — the number of operations.

The next $k$ lines represent the $k$ operations in order. Each of these $k$ lines should contain two integers $l$ and $r$ ($1 \leq l < r \leq n$, $r-l+1$ must be even) — the corresponding operation consists in choosing the subarray $[l, r]$ and swapping its elements according to the problem statement.

After all the operations, $a_i = i$ must be true for each $i$ ($1 \leq i \leq n$).

## Examples

## Input


```

52 5 4 1 3
```
## Output


```

5
1 4
1 2
2 5
1 4
4 5

```
## Input


```

91 2 3 4 5 6 7 8 9
```
## Output


```

0

```
## Input


```

106 4 2 3 8 10 9 1 5 7
```
## Output


```

15
1 8
6 9
1 8
3 10
1 10
1 10
1 6
6 9
6 9
2 7
9 10
5 10
1 6
2 9
1 10

```
## Note

In the first test: 

* At the beginning, $p = [2, 5, 4, 1, 3]$.
* In the first operation, you can choose $[l, r] = [1, 4]$. Then, $(a_1, a_2)$ are swapped and $(a_3, a_4)$ are swapped. The new permutation is $p = [5, 2, 1, 4, 3]$.
* In the second operation, you can choose $[l, r] = [1, 2]$. Then, $(a_1, a_2)$ are swapped. The new permutation is $p = [2, 5, 1, 4, 3]$.
* In the third operation, you can choose $[l, r] = [2, 5]$. Then, $(a_2, a_3)$ are swapped and $(a_4, a_5)$ are swapped. The new permutation is $p = [2, 1, 5, 3, 4]$.
* In the fourth operation, you can choose $[l, r] = [1, 4]$. Then, $(a_1, a_2)$ are swapped and $(a_3, a_4)$ are swapped. The new permutation is $p = [1, 2, 3, 5, 4]$.
* In the fifth operation, you can choose $[l, r] = [4, 5]$. Then, $(a_4, a_5)$ are swapped. The new permutation is $p = [1, 2, 3, 4, 5]$, which is sorted.

In the second test, the permutation is already sorted, so you do not need to perform any operation.



#### tags 

#3500 #constructive_algorithms #data_structures 