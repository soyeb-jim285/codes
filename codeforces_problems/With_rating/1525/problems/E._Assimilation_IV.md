<h1 style='text-align: center;'> E. Assimilation IV</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing a game "Assimilation IV". In this game he manages a great empire: builds cities and conquers new lands.

Monocarp's empire has $n$ cities. In order to conquer new lands he plans to build one Monument in each city. The game is turn-based and, since Monocarp is still amateur, he builds exactly one Monument per turn.

Monocarp has $m$ points on the map he'd like to control using the constructed Monuments. For each point he knows the distance between it and each city. Monuments work in the following way: when built in some city, a Monument controls all points at distance at most $1$ to this city. Next turn, the Monument controls all points at distance at most $2$, the turn after — at distance at most $3$, and so on. Monocarp will build $n$ Monuments in $n$ turns and his empire will conquer all points that are controlled by at least one Monument.

Monocarp can't figure out any strategy, so during each turn he will choose a city for a Monument randomly among all remaining cities (cities without Monuments). Monocarp wants to know how many points (among $m$ of them) he will conquer at the end of turn number $n$. Help him to calculate the expected number of conquered points!

### Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 20$; $1 \le m \le 5 \cdot 10^4$) — the number of cities and the number of points.

Next $n$ lines contains $m$ integers each: the $j$-th integer of the $i$-th line $d_{i, j}$ ($1 \le d_{i, j} \le n + 1$) is the distance between the $i$-th city and the $j$-th point.

### Output

It can be shown that the expected number of points Monocarp conquers at the end of the $n$-th turn can be represented as an irreducible fraction $\frac{x}{y}$. Print this fraction modulo $998\,244\,353$, i. e. value $x \cdot y^{-1} \bmod 998244353$ where $y^{-1}$ is such number that $y \cdot y^{-1} \bmod 998244353 = 1$.

## Example

### Input


```text
3 5
1 4 4 3 4
1 4 1 4 2
1 4 4 4 3
```
### Output


```text
166374062
```
## Note

Let's look at all possible orders of cities Monuments will be build in: 

* $[1, 2, 3]$:
	+ the first city controls all points at distance at most $3$, in other words, points $1$ and $4$;
	+ the second city controls all points at distance at most $2$, or points $1$, $3$ and $5$;
	+ the third city controls all points at distance at most $1$, or point $1$. In total, $4$ points are controlled.
* $[1, 3, 2]$: the first city controls points $1$ and $4$; the second city — points $1$ and $3$; the third city — point $1$. In total, $3$ points.
* $[2, 1, 3]$: the first city controls point $1$; the second city — points $1$, $3$ and $5$; the third city — point $1$. In total, $3$ points.
* $[2, 3, 1]$: the first city controls point $1$; the second city — points $1$, $3$ and $5$; the third city — point $1$. In total, $3$ points.
* $[3, 1, 2]$: the first city controls point $1$; the second city — points $1$ and $3$; the third city — points $1$ and $5$. In total, $3$ points.
* $[3, 2, 1]$: the first city controls point $1$; the second city — points $1$, $3$ and $5$; the third city — points $1$ and $5$. In total, $3$ points.

 The expected number of controlled points is $\frac{4 + 3 + 3 + 3 + 3 + 3}{6}$ $=$ $\frac{19}{6}$ or $19 \cdot 6^{-1}$ $\equiv$ $19 \cdot 166374059$ $\equiv$ $166374062$ $\pmod{998244353}$

#### Tags 

#2100 #NOT OK #combinatorics #dp #math #probabilities #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_109_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
