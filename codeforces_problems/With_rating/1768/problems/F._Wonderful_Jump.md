<h1 style='text-align: center;'> F. Wonderful Jump</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 128 megabytes</h5>

You are given an array of positive integers $a_1,a_2,\ldots,a_n$ of length $n$. 

In one operation you can jump from index $i$ to index $j$ ($1 \le i \le j \le n$) by paying $\min(a_i, a_{i + 1}, \ldots, a_j) \cdot (j - i)^2$ eris.

For all $k$ from $1$ to $n$, find the minimum number of eris needed to get from index $1$ to index $k$.

###### Input

The first line contains a single integer $n$ ($2 \le n \le 4 \cdot 10^5$).

The second line contains $n$ integers $a_1,a_2,\ldots a_n$ ($1 \le a_i \le n$).

###### Output

###### Output

 $n$ integers — the $k$-th integer is the minimum number of eris needed to reach index $k$ if you start from index $1$.

## Examples

###### Input


```text
3
2 1 3
```
###### Output


```text
0 1 2 
```
###### Input


```text
6
1 4 1 6 3 2
```
###### Output


```text
0 1 2 3 6 8 
```
###### Input


```text
2
1 2
```
###### Output


```text
0 1 
```
###### Input


```text
4
1 4 4 4
```
###### Output


```text
0 1 4 8 
```
## Note

In the first example: 

* From $1$ to $1$: the cost is $0$,
* From $1$ to $2$: $1 \rightarrow 2$ — the cost is $\min(2, 1) \cdot (2 - 1) ^ 2=1$,
* From $1$ to $3$: $1 \rightarrow 2 \rightarrow 3$ — the cost is $\min(2, 1) \cdot (2 - 1) ^ 2 + \min(1, 3) \cdot (3 - 2) ^ 2 = 1 + 1 = 2$.

In the fourth example from $1$ to $4$: $1 \rightarrow 3 \rightarrow 4$ — the cost is $\min(1, 4, 4) \cdot (3 - 1) ^ 2 + \min(4, 4) \cdot (4 - 3) ^ 2 = 4 + 4 = 8$.



#### Tags 

#2900 #NOT OK #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_842_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
