<h1 style='text-align: center;'> B. Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Toad Ivan has $m$ pairs of integers, each integer is between $1$ and $n$, inclusive. The pairs are $(a_1, b_1), (a_2, b_2), \ldots, (a_m, b_m)$. 

He asks you to check if there exist two integers $x$ and $y$ ($1 \leq x < y \leq n$) such that in each given pair at least one integer is equal to $x$ or $y$.

##### Input

The first line contains two space-separated integers $n$ and $m$ ($2 \leq n \leq 300\,000$, $1 \leq m \leq 300\,000$) — the upper bound on the values of integers in the pairs, and the number of given pairs.

The next $m$ lines contain two integers each, the $i$-th of them contains two space-separated integers $a_i$ and $b_i$ ($1 \leq a_i, b_i \leq n, a_i \neq b_i$) — the integers in the $i$-th pair.

##### Output

##### Output

 "YES" if there exist two integers $x$ and $y$ ($1 \leq x < y \leq n$) such that in each given pair at least one integer is equal to $x$ or $y$. Otherwise, print "NO". You can print each letter in any case (upper or lower).

## Examples

##### Input


```text
4 6
1 2
1 3
1 4
2 3
2 4
3 4
```
##### Output


```text
NO
```
##### Input


```text
5 4
1 2
2 3
3 4
4 5
```
##### Output


```text
YES
```
##### Input


```text
300000 5
1 2
1 2
1 2
1 2
1 2
```
##### Output


```text
YES
```
## Note

In the first example, you can't choose any $x$, $y$ because for each such pair you can find a given pair where both numbers are different from chosen integers.

In the second example, you can choose $x=2$ and $y=4$.

In the third example, you can choose $x=1$ and $y=2$.



#### Tags 

#1500 #NOT OK #graphs #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_562_(Div._2).md)
- [Codeforces Round #562](../blogs/Codeforces_Round_562.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
