<h1 style='text-align: center;'> C. Number of Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers. Find the number of pairs $(i, j)$ ($1 \le i < j \le n$) where the sum of $a_i + a_j$ is greater than or equal to $l$ and less than or equal to $r$ (that is, $l \le a_i + a_j \le r$).

For example, if $n = 3$, $a = [5, 1, 2]$, $l = 4$ and $r = 7$, then two pairs are suitable: 

* $i=1$ and $j=2$ ($4 \le 5 + 1 \le 7$);
* $i=1$ and $j=3$ ($4 \le 5 + 2 \le 7$).
## Input

The first line contains an integer $t$ ($1 \le t \le 10^4$). Then $t$ test cases follow.

The first line of each test case contains three integers $n, l, r$ ($1 \le n \le 2 \cdot 10^5$, $1 \le l \le r \le 10^9$) — the length of the array and the limits on the sum in the pair.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ overall test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the number of index pairs $(i, j)$ ($i < j$), such that $l \le a_i + a_j \le r$.

## Example

## Input


```

4
3 4 7
5 1 2
5 5 8
5 1 2 4 3
4 100 1000
1 1 1 1
5 9 13
2 5 5 1 1

```
## Output


```

2
7
0
1

```


#### tags 

#1300 #binary_search #data_structures #math #two_pointers 