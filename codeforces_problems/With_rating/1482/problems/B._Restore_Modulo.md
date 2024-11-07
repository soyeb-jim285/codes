<h1 style='text-align: center;'> B. Restore Modulo</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For the first place at the competition, Alex won many arrays of integers and was assured that these arrays are very expensive. After the award ceremony Alex decided to sell them. There is a rule in arrays pawnshop: you can sell array only if it can be compressed to a generator.

This generator takes four non-negative numbers $n$, $m$, $c$, $s$. $n$ and $m$ must be positive, $s$ non-negative and for $c$ it must be true that $0 \leq c < m$. The array $a$ of length $n$ is created according to the following rules: 

* $a_1 = s \bmod m$, here $x \bmod y$ denotes remainder of the division of $x$ by $y$;
* $a_i = (a_{i-1} + c) \bmod m$ for all $i$ such that $1 < i \le n$.

For example, if $n = 5$, $m = 7$, $c = 4$, and $s = 10$, then $a = [3, 0, 4, 1, 5]$.

Price of such an array is the value of $m$ in this generator.

Alex has a question: how much money he can get for each of the arrays. Please, help him to understand for every array whether there exist four numbers $n$, $m$, $c$, $s$ that generate this array. If yes, then maximize $m$.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of arrays.

The first line of array description contains a single integer $n$ ($1 \leq n \leq 10^5$) — the size of this array.

The second line of array description contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^9$ ) — elements of the array. 

It is guaranteed that the sum of array sizes does not exceed $10^5$.

### Output

For every array print: 

* $-1$, if there are no such four numbers that generate this array;
* $0$, if $m$ can be arbitrary large;
* the maximum value $m$ and any appropriate $c$ ($0 \leq c < m$) in other cases.
## Example

### Input


```text
6
6
1 9 17 6 14 3
3
4 2 2
3
7 3 4
3
2 2 4
5
0 1000000000 0 1000000000 0
2
1 1
```
### Output


```text
19 8
-1
-1
-1
2000000000 1000000000
0
```


#### Tags 

#1500 #NOT OK #implementation #math 

## Blogs
- [All Contest Problems](../Технокубок_2021_-_Финал.md)
- [Tutorial](../blogs/Tutorial.md)
