<h1 style='text-align: center;'> A. Planets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day, Vogons wanted to build a new hyperspace highway through a distant system with $n$ planets. The $i$-th planet is on the orbit $a_i$, there could be multiple planets on the same orbit. It's a pity that all the planets are on the way and need to be destructed.

Vogons have two machines to do that.

* The first machine in one operation can destroy any planet at cost of $1$ Triganic Pu.
* The second machine in one operation can destroy all planets on a single orbit in this system at the cost of $c$ Triganic Pus.

Vogons can use each machine as many times as they want.

Vogons are very greedy, so they want to destroy all planets with minimum amount of money spent. Can you help them to know the minimum cost of this project?

#### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Then the test cases follow.

Each test case consists of two lines.

The first line contains two integers $n$ and $c$ ($1 \le n, c \le 100$) — the number of planets and the cost of the second machine usage.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 100$), where $a_i$ is the orbit of the $i$-th planet.

#### Output

For each test case print a single integer — the minimum cost of destroying all planets.

## Examples

#### Input


```text
410 12 1 4 5 2 4 5 5 1 25 23 2 1 2 22 21 12 21 2
```
#### Output

```text

4
4
2
2

```
#### Input


```text
11 1001
```
#### Output

```text

1

```
## Note

In the first test case, the cost of using both machines is the same, so you can always use the second one and destroy all planets in orbit $1$, all planets in orbit $2$, all planets in orbit $4$, all planets in orbit $5$.

In the second test case, it is advantageous to use the second machine for $2$ Triganic Pus to destroy all the planets in orbit $2$, then destroy the remaining two planets using the first machine.

In the third test case, you can use the first machine twice or the second machine once.

In the fourth test case, it is advantageous to use the first machine twice.



#### Tags 

#800 #NOT OK #data_structures #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_823_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
