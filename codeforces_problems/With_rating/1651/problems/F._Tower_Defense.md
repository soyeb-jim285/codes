<h1 style='text-align: center;'> F. Tower Defense</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp is playing a tower defense game. A level in the game can be represented as an OX axis, where each lattice point from $1$ to $n$ contains a tower in it.

The tower in the $i$-th point has $c_i$ mana capacity and $r_i$ mana regeneration rate. In the beginning, before the $0$-th second, each tower has full mana. If, at the end of some second, the $i$-th tower has $x$ mana, then it becomes $\mathit{min}(x + r_i, c_i)$ mana for the next second.

There are $q$ monsters spawning on a level. The $j$-th monster spawns at point $1$ at the beginning of $t_j$-th second, and it has $h_j$ health. Every monster is moving $1$ point per second in the direction of increasing coordinate.

When a monster passes the tower, the tower deals $\mathit{min}(H, M)$ damage to it, where $H$ is the current health of the monster and $M$ is the current mana amount of the tower. This amount gets subtracted from both monster's health and tower's mana.

Unfortunately, sometimes some monsters can pass all $n$ towers and remain alive. Monocarp wants to know what will be the total health of the monsters after they pass all towers.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of towers.

The $i$-th of the next $n$ lines contains two integers $c_i$ and $r_i$ ($1 \le r_i \le c_i \le 10^9$) — the mana capacity and the mana regeneration rate of the $i$-th tower.

The next line contains a single integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of monsters.

The $j$-th of the next $q$ lines contains two integers $t_j$ and $h_j$ ($0 \le t_j \le 2 \cdot 10^5$; $1 \le h_j \le 10^{12}$) — the time the $j$-th monster spawns and its health.

The monsters are listed in the increasing order of their spawn time, so $t_j < t_{j+1}$ for all $1 \le j \le q-1$.

#### Output

Print a single integer — the total health of all monsters after they pass all towers.

## Examples

#### Input


```text
3
5 1
7 4
4 2
4
0 14
1 10
3 16
10 16
```
#### Output


```text
4
```
#### Input


```text
5
2 1
4 1
5 4
7 5
8 3
9
1 21
2 18
3 14
4 24
5 8
6 25
7 19
8 24
9 24
```
#### Output


```text
40
```


#### Tags 

#3000 #NOT OK #binary_search #brute_force #data_structures 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_124_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
