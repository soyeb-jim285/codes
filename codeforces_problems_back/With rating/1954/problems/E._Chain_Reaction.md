<h1 style='text-align: center;'> E. Chain Reaction</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are $n$ monsters standing in a row. The $i$-th monster has $a_i$ health points.

Every second, you can choose one alive monster and launch a chain lightning at it. The lightning deals $k$ damage to it, and also spreads to the left (towards decreasing $i$) and to the right (towards increasing $i$) to alive monsters, dealing $k$ damage to each. When the lightning reaches a dead monster or the beginning/end of the row, it stops. A monster is considered alive if its health points are strictly greater than $0$.

For example, consider the following scenario: there are three monsters with health equal to $[5, 2, 7]$, and $k = 3$. You can kill them all in $4$ seconds:

* launch a chain lightning at the $3$-rd monster, then their health values are $[2, -1, 4]$;
* launch a chain lightning at the $1$-st monster, then their health values are $[-1, -1, 4]$;
* launch a chain lightning at the $3$-rd monster, then their health values are $[-1, -1, 1]$;
* launch a chain lightning at the $3$-th monster, then their health values are $[-1, -1, -2]$.

For each $k$ from $1$ to $\max(a_1, a_2, \dots, a_n)$, calculate the minimum number of seconds it takes to kill all the monsters.

## Input

The first line contains a single integer $n$ ($1 \le n \le 10^5$) — the number of monsters.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^5$) — the health points of the $i$-th monster.

## Output

For each $k$ from $1$ to $\max(a_1, a_2, \dots, a_n)$, output the minimum number of seconds it takes to kill all the monsters.

## Examples

## Input


```

35 2 7
```
## Output


```

10 6 4 3 2 2 1 

```
## Input


```

47 7 7 7
```
## Output


```

7 4 3 2 2 2 1 

```
## Input


```

101 9 7 6 2 4 7 8 1 3
```
## Output


```

17 9 5 4 3 3 3 2 1 

```


#### tags 

#2200 #binary_search #data_structures #dsu #greedy #implementation #math #number_theory 