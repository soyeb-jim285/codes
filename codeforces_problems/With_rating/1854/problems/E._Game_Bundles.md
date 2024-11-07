<h1 style='text-align: center;'> E. Game Bundles</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Rishi is developing games in the 2D metaverse and wants to offer game bundles to his customers. Each game has an associated enjoyment value. A game bundle consists of a subset of games whose total enjoyment value adds up to $60$.

Your task is to choose $k$ games, where $1 \leq k \leq 60$, along with their respective enjoyment values $a_1, a_2, \dots, a_k$, in such a way that exactly $m$ distinct game bundles can be formed.

##### Input

The input is a single integer $m$ ($1 \le m \le 10^{10}$) — the desired number of game bundles.

##### Output

The first line should contain an integer $k$ ($1 \le k \le 60$) — the number of games.

The second line should contain $k$ integers, $a_1, a_2, \dots, a_k$ ($1 \le a_1, a_2, \dots, a_k \le 60$) — the enjoyment values of the $k$ games.

## Examples

##### Input


```text
4
```
##### Output


```text
4
20 20 20 20
```
##### Input


```text
722
```
##### Output


```text
15
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
```
##### Input

```text

1

```
##### Output


```text
1
60
```
## Note

In the first sample, any subset of size $3$ is a game bundle. There are $4$ such subsets.



#### Tags 

#3000 #NOT OK #brute_force #constructive_algorithms #dp #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_889_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
