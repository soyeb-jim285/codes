<h1 style='text-align: center;'> G. Jellyfish and Inscryption</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Jellyfish loves playing a game called "Inscryption" which is played on a directed acyclic graph with $n$ vertices and $m$ edges. All edges $a \to b$ satisfy $a < b$.

You need to move from vertex $1$ to vertex $n$ along the directed edges, and then fight with the final boss.

You will collect cards and props in the process.

Each card has two attributes: HP and damage. If a card's HP is $a$ and its damage is $b$, then the power of the card is $a \times b$.

Each prop has only one attribute: power.

In addition to vertex $1$ and vertex $n$, there are some vertices that trigger special events. The special events are:

1. You will get a card with $a$ HP, and $b$ damage.
2. If you have at least one card, choose one of your cards and increase its HP by $x$.
3. If you have at least one card, choose one of your cards and increase its damage by $y$.
4. You will get a prop with $w$ power.

When you get to vertex $n$, you can choose at most one of your cards and multiply its damage by $10^9$.

The final boss is very strong, so you want to maximize the sum of the power of all your cards and props. Find the maximum possible sum of power of all your cards and props if you play the game optimally.

######## Input

The first line contains two integers $n$ and $m$ ($2 \leq n \leq 200$, $n - 1\leq m \leq \min(\frac{n(n-1)}2, 2000)$) — the number of the vertices and the number of the edges.

In the following $n$ lines, the $i$-th $(1 \leq i \leq n)$ line describes the special event that will trigger on vertex $i$:

* 0 — no special events.
* 1 a b ($1 \leq a, b \leq 200$) — you will get a card with $a$ HP, and $b$ damage.
* 2 x ($1 \leq x \leq 200$) — if you have at least one card, choose one of your cards and increase its HP by $x$.
* 3 y ($1 \leq y \leq 200$) — if you have at least one card, choose one of your cards and increase its damage by $y$.
* 4 w ($1 \leq w \leq 10^6$) — you will get a prop with $w$ power.

In the following $m$ lines, each line contains two integers $u$ and $v$ ($1 \leq u < v \leq n$) representing a directed edge from vertex $u$ to vertex $v$.

It is guaranteed that every edge $(u,v)$ appears at most once.

It is guaranteed that there are no special events on vertex $1$ and vertex $n$.

It is guaranteed that for all $i$, there exists a path from vertex $1$ to vertex $n$ that passes through vertex $i$.

######## Output

######## Output

 a single integer — the maximum sum of the power of all your cards and props.

## Examples

######## Input


```text
6 8
0
1 2 10
1 6 6
2 8
3 10
0
1 2
1 3
2 4
2 5
3 4
3 5
4 6
5 6
```
######## Output


```text
100000000000
```
######## Input

```text

4 3
0
4 1000000
4 1000000
0
1 2
2 3
3 4

```
######## Output


```text
2000000
```
######## Input

```text

16 15
0
1 1 10
1 10 1
2 4
3 4
1 20 20
2 30
3 20
1 1 100
2 9
1 1 200
2 9
3 10
1 190 100
2 10
0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16

```
######## Output


```text
20000000005600
```
######## Input

```text

9 9
0
1 1 200
3 200
3 200
3 200
3 200
1 200 200
3 200
0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
1 9

```
######## Output


```text
80000000001000
```
######## Input

```text

9 8
0
1 20 200
3 200
3 200
2 5
1 100 200
3 200
3 200
0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9

```
######## Output


```text
60000000015000
```
######## Input

```text

16 34
0
0
0
2 6
3 1
4 27
4 40
3 9
0
2 6
1 8 1
0
2 2
1 10 7
2 9
0
2 4
3 10
2 11
2 7
13 15
3 15
2 3
6 14
4 12
10 12
9 10
7 8
4 13
11 12
4 6
11 16
14 15
2 5
5 15
9 13
8 14
1 3
2 15
12 16
7 10
4 5
1 2
4 11
4 9
4 16
3 6
6 8
7 11
15 16

```
######## Output


```text

133000000040
```
## Note

In the first example, we will play the game in the following order:

* move from vertex $1$ to vertex $2$, get a card with $2$ HP, and $10$ damage.
* move from vertex $2$ to vertex $4$, choose the card we get from vertex $2$ and increase its HP by $8$.
* move from vertex $4$ to vertex $6$, choose the card we get from vertex $2$ and multiply its damage by $10^9$.

In the end, we will have a card with $(2+8)=10$ HP and $10 \times 10^9=10^{10}$ damage, It's power is $10 \times 10^{10}=10^{11}$. Because we only have the card we get from vertex $2$, so the sum of power of all your cards and props is $10^{11}$.



#### Tags 

#3500 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_901_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
