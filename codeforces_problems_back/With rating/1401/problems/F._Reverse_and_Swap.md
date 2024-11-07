<h1 style='text-align: center;'> F. Reverse and Swap</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $2^n$. You should process $q$ queries on it. Each query has one of the following $4$ types: 

1. $Replace(x, k)$ — change $a_x$ to $k$;
2. $Reverse(k)$ — reverse each subarray $[(i-1) \cdot 2^k+1, i \cdot 2^k]$ for all $i$ ($i \ge 1$);
3. $Swap(k)$ — swap subarrays $[(2i-2) \cdot 2^k+1, (2i-1) \cdot 2^k]$ and $[(2i-1) \cdot 2^k+1, 2i \cdot 2^k]$ for all $i$ ($i \ge 1$);
4. $Sum(l, r)$ — print the sum of the elements of subarray $[l, r]$.

Write a program that can quickly process given queries.

## Input

The first line contains two integers $n$, $q$ ($0 \le n \le 18$; $1 \le q \le 10^5$) — the length of array $a$ and the number of queries.

The second line contains $2^n$ integers $a_1, a_2, \ldots, a_{2^n}$ ($0 \le a_i \le 10^9$).

Next $q$ lines contains queries — one per line. Each query has one of $4$ types: 

* "$1$ $x$ $k$" ($1 \le x \le 2^n$; $0 \le k \le 10^9$) — $Replace(x, k)$;
* "$2$ $k$" ($0 \le k \le n$) — $Reverse(k)$;
* "$3$ $k$" ($0 \le k < n$) — $Swap(k)$;
* "$4$ $l$ $r$" ($1 \le l \le r \le 2^n$) — $Sum(l, r)$.

It is guaranteed that there is at least one $Sum$ query.

## Output

Print the answer for each $Sum$ query.

## Examples

## Input


```

2 3
7 4 9 9
1 2 8
3 1
4 2 4

```
## Output


```

24

```
## Input


```

3 8
7 0 8 8 7 1 5 2
4 3 7
2 1
3 2
4 1 6
2 3
1 5 16
4 8 8
3 0

```
## Output


```

29
22
1

```
## Note

In the first sample, initially, the array $a$ is equal to $\{7,4,9,9\}$.

After processing the first query. the array $a$ becomes $\{7,8,9,9\}$.

After processing the second query, the array $a_i$ becomes $\{9,9,7,8\}$

Therefore, the answer to the third query is $9+7+8=24$.

In the second sample, initially, the array $a$ is equal to $\{7,0,8,8,7,1,5,2\}$. What happens next is: 

1. $Sum(3, 7)$ $\to$ $8 + 8 + 7 + 1 + 5 = 29$;
2. $Reverse(1)$ $\to$ $\{0,7,8,8,1,7,2,5\}$;
3. $Swap(2)$ $\to$ $\{1,7,2,5,0,7,8,8\}$;
4. $Sum(1, 6)$ $\to$ $1 + 7 + 2 + 5 + 0 + 7 = 22$;
5. $Reverse(3)$ $\to$ $\{8,8,7,0,5,2,7,1\}$;
6. $Replace(5, 16)$ $\to$ $\{8,8,7,0,16,2,7,1\}$;
7. $Sum(8, 8)$ $\to$ $1$;
8. $Swap(0)$ $\to$ $\{8,8,0,7,2,16,1,7\}$.


#### tags 

#2400 #binary_search #bitmasks #data_structures 