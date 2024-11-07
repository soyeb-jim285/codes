<h1 style='text-align: center;'> D. Two Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Sam changed his school and on the first biology lesson he got a very interesting task about genes.

You are given $n$ arrays, the $i$-th of them contains $m$ different integers — $a_{i,1}, a_{i,2},\ldots,a_{i,m}$. Also you are given an array of integers $w$ of length $n$.

Find the minimum value of $w_i + w_j$ among all pairs of integers $(i, j)$ ($1 \le i, j \le n$), such that the numbers $a_{i,1}, a_{i,2},\ldots,a_{i,m}, a_{j,1}, a_{j,2},\ldots,a_{j,m}$ are distinct.

#### Input

The first line contains two integers $n$, $m$ ($2 \leq n \leq 10^5$, $1 \le m \le 5$).

The $i$-th of the next $n$ lines starts with $m$ distinct integers $a_{i,1}, a_{i,2}, \ldots, a_{i,m}$ and then $w_i$ follows ($1\leq a_{i,j} \leq 10^9$, $1 \leq w_{i} \leq 10^9$).

#### Output

Print a single number — the answer to the problem. 

If there are no suitable pairs $(i, j)$, print $-1$.

## Examples

#### Input


```text
4 2
1 2 5
4 3 1
2 3 2
4 5 3
```
#### Output


```text
5
```
#### Input


```text
4 3
1 2 3 5
2 3 4 2
3 4 5 3
1 3 10 10
```
#### Output


```text
-1
```
## Note

In the first test the minimum value is $5 = w_3 + w_4$, because numbers $\{2, 3, 4, 5\}$ are distinct.

In the second test case, there are no suitable pair $(i, j)$.



#### Tags 

#2700 #NOT OK #bitmasks #brute_force #combinatorics #greedy #hashing #math #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_773_(Div._1).md)
- [Codeforces Round #773](../blogs/Codeforces_Round_773.md)
- [Tutorial](../blogs/Tutorial.md)
