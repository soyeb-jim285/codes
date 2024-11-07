<h1 style='text-align: center;'> F. Freak Joker Process</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

After the success of the basketball teams formed and trained by Pak Chanek last year (Basketball Together), Pak Chanek wants to measure the performance of each player that is considered as a superstar.

There are $N$ superstar players that have been trained by Pak Chanek. At the end of the season, some calculations will be made on the performance of the $N$ players using an international method. Each player has two values $A_i$ and $B_i$ where each represents the offensive and defensive value of that player.

Define $\text{RankA}(i)$ as the offensive ranking of the $i$-th player, whose value is $c+1$ with $c$ here representing the number of $j$ ($1 \leq j \leq N$) such that $A_j>A_i$. Define $\text{RankB}(i)$ as the defensive ranking of the $i$-th player, whose value is $c+1$ with $c$ here representing the number of $j$ ($1 \leq j \leq N$) such that $B_j>B_i$.

Define $\text{RankOverall}(i)$ as the overall ranking of the $i$-th player, whose value is $c+1$ with $c$ here representing the number of $j$ ($1 \leq j \leq N$) such that $\text{RankA}(j)+\text{RankB}(j)<\text{RankA}(i)+\text{RankB}(i)$.

During the next $Q$ days, exactly one event will happen on each day. Each event is one of the three following possibilities:

* 1 k c – If $c$ is +, then $A_k$ increases by $1$. If $c$ is -, then $A_k$ decreases by $1$. ($1\leq k\leq N$; $c$ is + or -)
* 2 k c – If $c$ is +, then $B_k$ increases by $1$. If $c$ is -, then $B_k$ decreases by $1$. ($1\leq k\leq N$; $c$ is + or -)
* 3 k – Pak Chanek wants to know the value of $\text{RankOverall}(k)$ at that moment. ($1\leq k\leq N$)
### Input

The first line contains a single integer $N$ ($1\leq N\leq10^5$) — the number of superstar players.

The second line contains $N$ integers $A_1, A_2, A_3 \ldots, A_N$ ($1 \leq A_i \leq 10^5$) — the offensive value of each player.

The third line contains $N$ integers $B_1, B_2, B_3 \ldots, B_N$ ($1 \leq B_i \leq 10^5$) — the defensive value of each player.

The fourth line contains a single integer $Q$ ($1\leq Q\leq10^5$) — the number of events.

The $j$-th of the next $Q$ lines contains the $j$-th event as described. At any moment, each value of $A_i$ and $B_i$ is always between $1$ and $10^5$ inclusive. There is at least one event of type $3$.

### Output

For each event of type $3$, output a line containing an integer representing the value of $\text{RankOverall}(k)$ at that moment.

## Example

### Input


```text
5
3 3 1 3 2
3 7 1 3 1
8
3 1
3 2
2 4 +
1 2 -
3 2
3 3
2 2 -
3 1
```
### Output


```text
2
1
2
5
2
```
## Note

At the $8$-th event, $A=[3,2,1,3,2]$ and $B=[3,6,1,4,1]$. It can be obtained that the values of $\text{RankA}$ and $\text{RankB}$ for each player are as follows: 

* $\text{RankA}(1)=1$, $\text{RankB}(1)=3$
* $\text{RankA}(2)=3$, $\text{RankB}(2)=1$
* $\text{RankA}(3)=5$, $\text{RankB}(3)=4$
* $\text{RankA}(4)=1$, $\text{RankB}(4)=2$
* $\text{RankA}(5)=3$, $\text{RankB}(5)=4$

So it can be obtained that $\text{RankOverall}(1)=2$.



#### Tags 

#3100 #NOT OK #binary_search #data_structures #sortings 

## Blogs
- [All Contest Problems](../COMPFEST_15_-_Preliminary_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
