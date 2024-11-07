<h1 style='text-align: center;'> F. Too Many Constraints</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are asked to build an array $a$, consisting of $n$ integers, each element should be from $1$ to $k$.

The array should be non-decreasing ($a_i \le a_{i+1}$ for all $i$ from $1$ to $n-1$). 

You are also given additional constraints on it. Each constraint is of one of three following types: 

* $1~i~x$: $a_i$ should not be equal to $x$;
* $2~i~j~x$: $a_i + a_j$ should be less than or equal to $x$;
* $3~i~j~x$: $a_i + a_j$ should be greater than or equal to $x$.

Build any non-decreasing array that satisfies all constraints or report that no such array exists.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains three integers $n, m$ and $k$ ($2 \le n \le 2 \cdot 10^4$; $0 \le m \le 2 \cdot 10^4$; $2 \le k \le 10$).

The $i$-th of the next $m$ lines contains a description of a constraint. Each constraint is of one of three following types: 

* $1~i~x$ ($1 \le i \le n$; $1 \le x \le k$): $a_i$ should not be equal to $x$;
* $2~i~j~x$ ($1 \le i < j \le n$; $2 \le x \le 2 \cdot k$): $a_i + a_j$ should be less than or equal to $x$;
* $3~i~j~x$ ($1 \le i < j \le n$; $2 \le x \le 2 \cdot k$): $a_i + a_j$ should be greater than or equal to $x$.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^4$. The sum of $m$ over all testcases doesn't exceed $2 \cdot 10^4$.

### Output

For each testcase, determine if there exists a non-decreasing array that satisfies all conditions. If there is no such array, then print -1. Otherwise, print any valid array — $n$ integers from $1$ to $k$.

## Example

### Input


```text
44 0 42 2 33 1 2 31 2 23 3 21 1 12 2 3 23 2 3 25 5 53 2 5 72 4 5 103 4 5 63 3 4 72 1 5 7
```
### Output

```text

1 2 3 4
1 3
-1
1 2 2 5 5

```


#### Tags 

#2800 #NOT OK #2-sat #constructive_algorithms #graphs #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_130_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
