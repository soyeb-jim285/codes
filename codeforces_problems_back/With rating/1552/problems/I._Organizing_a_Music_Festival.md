<h1 style='text-align: center;'> I. Organizing a Music Festival</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are the organizer of the famous "Zurich Music Festival". There will be $n$ singers who will perform at the festival, identified by the integers $1$, $2$, $\dots$, $n$. You must choose in which order they are going to perform on stage. 

You have $m$ friends and each of them has a set of favourite singers. More precisely, for each $1\le i\le m$, the $i$-th friend likes singers $s_{i,1}, \, s_{i, 2}, \, \dots, \,s_{i, q_i}$.

A friend of yours is happy if the singers he likes perform consecutively (in an arbitrary order). An ordering of the singers is valid if it makes all your friends happy.

Compute the number of valid orderings modulo $998\,244\,353$.

## Input

The first line contains two integers $n$ and $m$ ($1\le n,\,m\le 100$) — the number of singers and the number of friends correspondingly.

The $i$-th of the next $m$ lines contains the integer $q_i$ ($1\le q_i\le n$) — the number of favorite singers of the $i$-th friend – followed by the $q_i$ integers $s_{i,1}, \, s_{i, 2}, \, \dots, \,s_{i, q_i}$ ($1\le s_{i,1}<s_{i,2}<\cdots<s_{i,q_i}\le n$) — the indexes of his favorite singers.

## Output

Print the number of valid orderings of the singers modulo $998\,244\,353$.

## Examples

## Input


```

3 1
2 1 3

```
## Output


```

4

```
## Input


```

5 5
2 1 2
2 2 3
2 3 4
2 4 5
2 1 5

```
## Output


```

0

```
## Input


```

100 1
1 50

```
## Output


```

35305197

```
## Input


```

5 1
5 1 2 3 4 5

```
## Output


```

120

```
## Input


```

2 5
1 2
1 2
1 2
1 1
1 1

```
## Output


```

2

```
## Input


```

11 4
5 4 5 7 9 11
2 2 10
2 9 11
7 1 2 3 5 8 10 11

```
## Output


```

384

```
## Note

Explanation of the first sample: There are $3$ singers and only $1$ friend. The friend likes the two singers $1$ and $3$. Thus, the $4$ valid orderings are: 

* 1 3 2
* 2 1 3
* 2 3 1
* 3 1 2

Explanation of the second sample: There are $5$ singers and $5$ friends. One can show that no ordering is valid.

Explanation of the third sample: There are $100$ singers and only $1$ friend. The friend likes only singer $50$, hence all the $100!$ possible orderings are valid.

Explanation of the fourth sample: There are $5$ singers and only $1$ friend. The friend likes all the singers, hence all the $5!=120$ possible orderings are valid.



#### tags 

#3400 #dfs_and_similar #math 