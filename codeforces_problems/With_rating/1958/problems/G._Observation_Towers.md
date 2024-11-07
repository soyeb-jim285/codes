<h1 style='text-align: center;'> G. Observation Towers</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider a segment of an OX axis from $1$ to $n$. There are $k$ observation towers on this segment.

Each tower has two parameters — the coordinate $x_i$ and the height $h_i$. The coordinates of all towers are distinct. From tower $i$, you can see point $j$ if $|x_i - j| \le h_i$ (where $|a|$ is an absolute value of $a$).

You can increase the height of any tower by $1$ for one coin. The height of each tower can be increased any number of times (including zero).

You need to process $q$ independent queries. In the $i$-th query, two different points $l$ and $r$ are given. You need to calculate the minimum number of coins required to be able to see both of these points (from one tower or from different towers).

#### Input

The first line contains two integers $n$ and $k$ ($2 \le n \le 2 \cdot 10^5$; $1 \le k \le n$) — the length of the segment of an OX axis and the number of observation towers.

The second line contains $k$ integers $x_1, x_2, \dots, x_k$ ($1 \le x_i \le n$) — the coordinates of the observation towers. The coordinates of all towers are distinct.

The third line contains $k$ integers $h_1, h_2, \dots, h_k$ ($0 \le h_i \le n$) — the heights of the observation towers.

The fourth line contains a single integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of queries.

Each of the next $q$ lines contains two integers $l$ and $r$ ($1 \le l < r \le n$) — the description of the next query.

#### Output

For each query, output a single integer — the minimum number of coins required to be able to see both points (from one tower or from different towers).

## Examples

#### Input


```text
20 32 15 106 2 031 2010 113 4
```
#### Output

```text

3 1 0

```
#### Input


```text
10 22 91 234 55 61 10
```
#### Output

```text

2 2 0

```


#### Tags 

#2400 #NOT OK #*special 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_10.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
