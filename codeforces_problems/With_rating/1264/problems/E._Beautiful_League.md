<h1 style='text-align: center;'> E. Beautiful League</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A football league has recently begun in Beautiful land. There are $n$ teams participating in the league. Let's enumerate them with integers from $1$ to $n$.

There will be played exactly $\frac{n(n-1)}{2}$ matches: each team will play against all other teams exactly once. In each match, there is always a winner and loser and there is no draw.

After all matches are played, the organizers will count the number of beautiful triples. Let's call a triple of three teams $(A, B, C)$ beautiful if a team $A$ win against a team $B$, a team $B$ win against a team $C$ and a team $C$ win against a team $A$. We look only to a triples of different teams and the order of teams in the triple is important.

The beauty of the league is the number of beautiful triples.

At the moment, $m$ matches were played and their results are known.

What is the maximum beauty of the league that can be, after playing all remaining matches? Also find a possible results for all remaining $\frac{n(n-1)}{2} - m$ matches, so that the league has this maximum beauty.

#### Input

The first line contains two integers $n, m$ ($3 \leq n \leq 50, 0 \leq m \leq \frac{n(n-1)}{2}$) — the number of teams in the football league and the number of matches that were played.

Each of $m$ following lines contains two integers $u$ and $v$ ($1 \leq u, v \leq n$, $u \neq v$) denoting that the $u$-th team won against the $v$-th team. It is guaranteed that each unordered pair of teams appears at most once.

#### Output

Print $n$ lines, each line having a string of exactly $n$ characters. Each character must be either $0$ or $1$.

Let $a_{ij}$ be the $j$-th number in the $i$-th line. For all $1 \leq i \leq n$ it should be true, that $a_{ii} = 0$. For all pairs of teams $i \neq j$ the number $a_{ij}$ indicates the result of the match between the $i$-th team and the $j$-th team:

* If $a_{ij}$ is $1$, the $i$-th team wins against the $j$-th team;
* Otherwise the $j$-th team wins against the $i$-th team;
* Also, it should be true, that $a_{ij} + a_{ji} = 1$.

Also note that the results of the $m$ matches that were already played cannot be changed in your league.

The beauty of the league in the output should be maximum possible. If there are multiple possible answers with maximum beauty, you can print any of them.

## Examples

#### Input


```text
3 1
1 2
```
#### Output


```text
010
001
100
```
#### Input


```text
4 2
1 2
1 3
```
#### Output


```text
0110
0001
0100
1010
```
## Note

The beauty of league in the first test case is equal to $3$ because there exists three beautiful triples: $(1, 2, 3)$, $(2, 3, 1)$, $(3, 1, 2)$.

The beauty of league in the second test is equal to $6$ because there exists six beautiful triples: $(1, 2, 4)$, $(2, 4, 1)$, $(4, 1, 2)$, $(2, 4, 3)$, $(4, 3, 2)$, $(3, 2, 4)$.



#### Tags 

#2700 #NOT OK #constructive_algorithms #flows #graph_matchings 

## Blogs
- [All Contest Problems](../Codeforces_Round_604_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
