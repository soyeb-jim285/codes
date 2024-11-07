<h1 style='text-align: center;'> G. Segment Covering</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

ChthollyNotaSeniorious gives DataStructures a number axis with $m$ distinct segments on it. Let $f(l,r)$ be the number of ways to choose an even number of segments such that the union of them is exactly $[l,r]$, and $g(l,r)$ be the number of ways to choose an odd number of segments such that the union of them is exactly $[l,r]$.

ChthollyNotaSeniorious asked DataStructures $q$ questions. In each query, ChthollyNotaSeniorious will give DataStructures two numbers $l, r$, and now he wishes that you can help him find the value $f(l,r)-g(l,r)$ modulo $998\,244\,353$ so that he wouldn't let her down. 

### Input

The first line of input contains two integers $m$ ($1 \leq m \leq 2 \cdot 10^5$) and $q$ ($1 \leq q \leq 2 \cdot 10^5$)  — the number of segments and queries, correspondingly.

The $i$-th of the next $m$ lines contains two integers $x_i$ and $y_i$ ($1 \leq x_i < y_i \leq 10^9$), denoting a segment $[x_i, y_i]$. 

It is guaranteed that all segments are distinct. More formally, there do not exist two numbers $i, j$ with $1 \le i < j \le m$ such that $x_i = x_j$ and $y_i = y_j$.

The $i$-th of the next $q$ lines contains two integers $l_i$ and $r_i$ ($1 \leq l_i < r_i \leq 10^9$), describing a query.

### Output

For each query, output a single integer  — $f(l_i,r_i)-g(l_i,r_i)$ modulo $998\,244\,353$.

## Example

### Input


```text
4 2
1 3
4 6
2 4
3 5
1 4
1 5
```
### Output


```text
1
0
```
## Note

In the first query, we have to find $f(1, 4) - g(1, 4)$. The only subset of segments with union $[1, 4]$ is $\{[1, 3], [2, 4]\}$, so $f(1, 4) = 1, g(1, 4) = 0$.

In the second query, we have to find $f(1, 5) - g(1, 5)$. The only subsets of segments with union $[1, 5]$ are $\{[1, 3], [2, 4], [3, 5]\}$ and $\{[1, 3], [3, 5]\}$, so $f(1, 5) = 1, g(1, 5) = 1$.



#### Tags 

#3200 #NOT OK #brute_force #combinatorics #constructive_algorithms #data_structures #dp #trees 

## Blogs
- [All Contest Problems](../Polynomial_Round_2022_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
