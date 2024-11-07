<h1 style='text-align: center;'> C. Circular Mirror</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pak Chanek has a mirror in the shape of a circle. There are $N$ lamps on the circumference numbered from $1$ to $N$ in clockwise order. The length of the arc from lamp $i$ to lamp $i+1$ is $D_i$ for $1 \leq i \leq N-1$. Meanwhile, the length of the arc between lamp $N$ and lamp $1$ is $D_N$.

Pak Chanek wants to colour the lamps with $M$ different colours. Each lamp can be coloured with one of the $M$ colours. However, there cannot be three different lamps such that the colours of the three lamps are the same and the triangle made by considering the three lamps as vertices is a right triangle (triangle with one of its angles being exactly $90$ degrees).

The following are examples of lamp colouring configurations on the circular mirror.

 

|  |  |  |
| --- | --- | --- |
| Figure 1. an example of an incorrect colouring because lamps $1$, $2$, and $3$ form a right triangle | Figure 2. an example of a correct colouring | Figure 3. an example of a correct colouring |

 Before colouring the lamps, Pak Chanek wants to know the number of distinct colouring configurations he can make. Count the number of distinct possible lamp colouring configurations, modulo $998\,244\,353$.

#### Input

The first line contains two integers $N$ and $M$ ($1 \le N \le 3 \cdot 10^5$, $2 \le M \le 3 \cdot 10^5$) — the number of lamps in the mirror and the number of different colours used.

The second line contains $N$ integers $D_1, D_2, \ldots, D_N$ ($1 \le D_i \le 10^9$) — the lengths of the arcs between the lamps in the mirror.

#### Output

An integer representing the number of possible lamp colouring configurations, modulo $998\,244\,353$.

## Examples

#### Input


```text
4 2
10 10 6 14
```
#### Output


```text
10
```
#### Input


```text
1 2
10
```
#### Output


```text
2
```
## Note

In the first example, all correct lamp colouring configurations are $[1, 1, 2, 1]$, $[1, 1, 2, 2]$, $[1, 2, 1, 2]$, $[1, 2, 2, 1]$, $[1, 2, 2, 2]$, $[2, 1, 1, 1]$, $[2, 1, 1, 2]$, $[2, 1, 2, 1]$, $[2, 2, 1, 1]$, and $[2, 2, 1, 2]$.



#### Tags 

#2000 #NOT OK #binary_search #combinatorics #geometry #math #two_pointers 

## Blogs
- [All Contest Problems](../COMPFEST_14_-_Preliminary_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
