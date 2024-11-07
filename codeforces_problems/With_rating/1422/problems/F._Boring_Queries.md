<h1 style='text-align: center;'> F. Boring Queries</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Yura owns a quite ordinary and boring array $a$ of length $n$. You think there is nothing more boring than that, but Vladik doesn't agree!

In order to make Yura's array even more boring, Vladik makes $q$ boring queries. Each query consists of two integers $x$ and $y$. Before answering a query, the bounds $l$ and $r$ for this query are calculated: $l = (last + x) \bmod n + 1$, $r = (last + y) \bmod n + 1$, where $last$ is the answer on the previous query (zero initially), and $\bmod$ is the remainder operation. Whenever $l > r$, they are swapped.

After Vladik computes $l$ and $r$ for a query, he is to compute the least common multiple (LCM) on the segment $[l; r]$ of the initial array $a$ modulo $10^9 + 7$. LCM of a multiset of integers is the smallest positive integer that is divisible by all the elements of the multiset. The obtained LCM is the answer for this query.

Help Vladik and compute the answer for each query!

### Input

The first line contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the array.

The second line contains $n$ integers $a_i$ ($1 \le a_i \le 2 \cdot 10^5$) — the elements of the array.

The third line contains a single integer $q$ ($1 \le q \le 10^5$) — the number of queries.

The next $q$ lines contain two integers $x$ and $y$ each ($1 \le x, y \le n$) — the description of the corresponding query.

### Output

Print $q$ integers — the answers for the queries.

## Example

### Input


```text
3
2 3 5
4
1 3
3 3
2 3
2 3
```
### Output


```text
6
2
15
30
```
## Note

Consider the example:

* boundaries for first query are $(0 + 1) \bmod 3 + 1 = 2$ and $(0 + 3) \bmod 3 + 1 = 1$. LCM for segment $[1, 2]$ is equal to $6$;
* boundaries for second query are $(6 + 3) \bmod 3 + 1 = 1$ and $(6 + 3) \bmod 3 + 1 = 1$. LCM for segment $[1, 1]$ is equal to $2$;
* boundaries for third query are $(2 + 2) \bmod 3 + 1 = 2$ and $(2 + 3) \bmod 3 + 1 = 3$. LCM for segment $[2, 3]$ is equal to $15$;
* boundaries for fourth query are $(15 + 2) \bmod 3 + 1 = 3$ and $(15 + 3) \bmod 3 + 1 = 1$. LCM for segment $[1, 3]$ is equal to $30$.


#### Tags 

#2700 #NOT OK #data_structures #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_675_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
