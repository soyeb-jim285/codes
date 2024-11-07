<h1 style='text-align: center;'> A. Ropewalkers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp decided to relax on his weekend and visited to the performance of famous ropewalkers: Agafon, Boniface and Konrad.

The rope is straight and infinite in both directions. At the beginning of the performance, Agafon, Boniface and Konrad are located in positions $a$, $b$ and $c$ respectively. At the end of the performance, the distance between each pair of ropewalkers was at least $d$.

Ropewalkers can walk on the rope. In one second, only one ropewalker can change his position. Every ropewalker can change his position exactly by $1$ (i. e. shift by $1$ to the left or right direction on the rope). Agafon, Boniface and Konrad can not move at the same time (Only one of them can move at each moment). Ropewalkers can be at the same positions at the same time and can "walk past each other".

You should find the minimum duration (in seconds) of the performance. In other words, find the minimum number of seconds needed so that the distance between each pair of ropewalkers can be greater or equal to $d$.

Ropewalkers can walk to negative coordinates, due to the rope is infinite to both sides.

###### Input

The only line of the input contains four integers $a$, $b$, $c$, $d$ ($1 \le a, b, c, d \le 10^9$). It is possible that any two (or all three) ropewalkers are in the same position at the beginning of the performance.

###### Output

###### Output

 one integer — the minimum duration (in seconds) of the performance.

## Examples

###### Input


```text
5 2 6 3
```
###### Output


```text
2
```
###### Input


```text
3 1 5 6
```
###### Output


```text
8
```
###### Input


```text
8 3 3 2
```
###### Output


```text
2
```
###### Input


```text
2 3 10 4
```
###### Output


```text
3
```
## Note

In the first example: in the first two seconds Konrad moves for 2 positions to the right (to the position $8$), while Agafon and Boniface stay at their positions. Thus, the distance between Agafon and Boniface will be $|5 - 2| = 3$, the distance between Boniface and Konrad will be $|2 - 8| = 6$ and the distance between Agafon and Konrad will be $|5 - 8| = 3$. Therefore, all three pairwise distances will be at least $d=3$, so the performance could be finished within 2 seconds.



#### Tags 

#800 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_568_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
