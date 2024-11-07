<h1 style='text-align: center;'> K. Kingdom of Criticism</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Pak Chanek is visiting a kingdom that earned a nickname "Kingdom of Criticism" because of how often its residents criticise each aspect of the kingdom. One aspect that is often criticised is the heights of the buildings. The kingdom has $N$ buildings. Initially, building $i$ has a height of $A_i$ units.

At any point in time, the residents can give a new criticism, namely they currently do not like buildings with heights between $l$ and $r$ units inclusive for some two integers $l$ and $r$. It is known that $r-l$ is always odd.

In $1$ minute, the kingdom's construction team can increase or decrease the height of any building by $1$ unit as long as the height still becomes a positive number. Each time they receive the current criticism from the residents, the kingdom's construction team makes it so that there are no buildings with heights between $l$ and $r$ units inclusive in the minimum time possible. It can be obtained that there is only one way to do this. 

## Note

 that the construction team only cares about the current criticism from the residents. All previous criticisms are forgotten.

There will be $Q$ queries that you must solve. Each query is one of the three following possibilities: 

* 1 k w: The kingdom's construction team changes the height of building $k$ to be $w$ units ($1 \leq k \leq N$, $1 \leq w \leq 10^9$).
* 2 k: The kingdom's construction team wants you to find the height of building $k$ ($1 \leq k \leq N$).
* 3 l r: The residents currently do not like buildings with heights between $l$ and $r$ units inclusive ($2 \leq l \leq r \leq 10^9-1$, $r-l$ is odd).

## Note

 that each change in height still persists to the next queries.

### Input

The first line contains a single integer $N$ ($1 \leq N \leq 4 \cdot 10^5$) — the number buildings in the kingdom.

The second line contains $N$ integers $A_1, A_2, \ldots, A_N$ ($1 \leq A_i \leq 10^9$) — the initial heights of the buildings.

The next line contains a single integer $Q$ ($1 \leq Q \leq 4 \cdot 10^5$) — the number of queries.

The $j$-th of the next $Q$ lines contains the $j$-th query as described. There is at least one query of type $2$.

### Output

For each query of type $2$, output a line containing an integer representing the height of the building asked.

## Example

### Input


```text
5
2 6 5 6 2
9
1 5 10
2 5
1 1 3
3 3 6
3 8 9
1 2 9
2 3
2 2
2 4
```
### Output


```text
10
7
9
7
```
## Note

After the $1$-st query, the height of each building is $2, 6, 5, 6, 10$.

After the $3$-rd query, the height of each building is $3, 6, 5, 6, 10$.

After the $4$-th query, the height of each building is $2, 7, 7, 7, 10$.

After the $5$-th query, the height of each building is $2, 7, 7, 7, 10$.

After the $6$-th query, the height of each building is $2, 9, 7, 7, 10$.



#### Tags 

#2500 #NOT OK #data_structures #dsu 

## Blogs
- [All Contest Problems](../COMPFEST_14_-_Preliminary_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
