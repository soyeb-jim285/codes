<h1 style='text-align: center;'> A. Constructive Problems</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gridlandia has been hit by flooding and now has to reconstruct all of it's cities. Gridlandia can be described by an $n \times m$ matrix.

Initially, all of its cities are in economic collapse. The government can choose to rebuild certain cities. Additionally, any collapsed city which has at least one vertically neighboring rebuilt city and at least one horizontally neighboring rebuilt city can ask for aid from them and become rebuilt without help from the government. More formally, collapsed city positioned in $(i, j)$ can become rebuilt if both of the following conditions are satisfied:

* At least one of cities with positions $(i + 1, j)$ and $(i - 1, j)$ is rebuilt;
* At least one of cities with positions $(i, j + 1)$ and $(i, j - 1)$ is rebuilt.

If the city is located on the border of the matrix and has only one horizontally or vertically neighbouring city, then we consider only that city.

 

|  |
| --- |

  Illustration of two possible ways cities can be rebuilt by adjacent aid. White cells are collapsed cities, yellow cells are initially rebuilt cities (either by the government or adjacent aid), and orange cells are rebuilt cities after adjacent aid. The government wants to know the minimum number of cities it has to rebuild such that after some time all the cities can be rebuild.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $n$ and $m$ ($2 \le n, m \le 100$) — the sizes of Gridlandia.

### Output

For each test case, output a single integer — the minimum number of cities the government needs to rebuild.

## Example

### Input


```text
32 25 73 2
```
### Output

```text

2
7
3

```
## Note

In the first test case, it's enough for the government to rebuild cities $(1, 2)$ and $(2, 1)$.

In the second test case, it's enough for the government to rebuild cities $(1, 4)$, $(2, 2)$, $(3, 1)$, $(3, 6)$, $(4, 3)$, $(5, 5)$, $(5, 7)$.



#### Tags 

#800 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_915_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
