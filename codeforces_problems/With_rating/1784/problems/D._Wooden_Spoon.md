<h1 style='text-align: center;'> D. Wooden Spoon</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

$2^n$ people, numbered with distinct integers from $1$ to $2^n$, are playing in a single elimination tournament. The bracket of the tournament is a full binary tree of height $n$ with $2^n$ leaves.

When two players meet each other in a match, a player with the smaller number always wins. The winner of the tournament is the player who wins all $n$ their matches.

A virtual consolation prize "Wooden Spoon" is awarded to a player who satisfies the following $n$ conditions: 

* they lost their first match;
* the player who beat them lost their second match;
* the player who beat that player lost their third match;
* $\ldots$;
* the player who beat the player from the previous condition lost the final match of the tournament.

It can be shown that there is always exactly one player who satisfies these conditions.

Consider all possible $(2^n)!$ arrangements of players into the tournament bracket. For each player, find the number of these arrangements in which they will be awarded the "Wooden Spoon", and print these numbers modulo $998\,244\,353$.

##### Input

The only line contains a single integer $n$ ($1 \le n \le 20$) — the size of the tournament.

There are $20$ tests in the problem: in the first test, $n = 1$; in the second test, $n = 2$; $\ldots$; in the $20$-th test, $n = 20$.

##### Output

Print $2^n$ integers — the number of arrangements in which the "Wooden Spoon" is awarded to players $1, 2, \ldots, 2^n$, modulo $998\,244\,353$.

## Examples

##### Input


```text
1
```
##### Output


```text
0
2
```
##### Input


```text
2
```
##### Output


```text
0
0
8
16
```
##### Input


```text
3
```
##### Output


```text
0
0
0
1536
4224
7680
11520
15360
```
## Note

In the first example, the "Wooden Spoon" is always awarded to player $2$.

In the second example, there are $8$ arrangements where players $1$ and $4$ meet each other in the first match, and in these cases, the "Wooden Spoon" is awarded to player $3$. In the remaining $16$ arrangements, the "Wooden Spoon" is awarded to player $4$.



#### Tags 

#2400 #NOT OK #combinatorics #dp 

## Blogs
- [All Contest Problems](../VK_Cup_2022_-_Финальный_раунд_(Engine).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
