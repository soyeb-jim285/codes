<h1 style='text-align: center;'> F. Exotic Queries</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

AquaMoon gives RiverHamster a sequence of integers $a_1,a_2,\dots,a_n$, and RiverHamster gives you $q$ queries. Each query is expressed by two integers $l$ and $r$. 

For each query independently, you can take any continuous segment of the sequence and subtract an identical non-negative value from all the numbers of this segment. You can do so multiple (possibly, zero) times. However, you may not choose two intersecting segments which are not included in one another. Your goal is to convert to $0$ all numbers whose initial value was within the range $[l, r]$. You must do so in the minimum number of operations.

Please note that the queries are independent, the numbers in the array are restored to their initial values between the queries.

Formally, for each query, you are to find the smallest $m$ such that there exists a sequence $\{(x_j,y_j,z_j)\}_{j=1}^{m}$ satisfying the following conditions:

* for any $1 \le j \leq m$, $z_j \ge 0$ and $1 \le x_j \le y_j \leq n$ (here $[x_j, y_j]$ correspond to the segment of the sequence);
* for any $1 \le j < k \le m$, it is true that $[x_j,y_j]\subseteq[x_{k},y_{k}]$, or $[x_k,y_k]\subseteq[x_{j},y_{j}]$, or $[x_j,y_j]\cap[x_{k},y_{k}]=\varnothing$;
* for any $1 \le i \le n$, such that $l \le a_i \leq r$, it is true that $${\large a_i = \sum\limits_{\substack {1 \le j \le m \\\ x_j \le i \le y_j}} z_j. }$$
## Input

The first line contains two integers $n$ and $q$ ($1\le n,q\le 10^6$).

The second line contains $n$ integers integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$).

Each of the next $q$ lines contains two integers $l$ and $r$ ($1\le l\le r\le n$), representing a query.

## Output

For each query, output the answer for this query on a separate line.

## Examples

## Input


```

10 8
1 6 2 3 2 6 3 10 1 2
1 10
2 2
3 3
2 3
1 3
3 6
4 6
5 5

```
## Output


```

8
1
1
3
5
3
1
0

```
## Input


```

3 1
1 3 2
1 3

```
## Output


```

3

```
## Note

In the first test case, consider the second query, when $l = 2$, $r = 2$. The elements to be manipulated are $[a_3, a_5, a_{10}] = [2, 2, 2]$. It is sufficient to apply the operation sequence $\{(2, 10, 2)\}$.

Consider the fourth query, when $l = 2$, $r = 3$. The elements to be manipulated are $[a_3, a_4, a_5, a_7, a_{10}] = [2, 3, 2, 3, 2]$. It is sufficient to apply the operation sequence $\{(1, 10, 2), (4, 4, 1), (7, 7, 1)\}$.

In the second test case, note that the operation sequence $\{(1, 2, 1), (2, 3, 2)\}$ is invalid because the two segments intersect but neither is contained inside the other.



#### tags 

#2300 #data_structures #implementation #sortings 