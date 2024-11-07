<h1 style='text-align: center;'> I. Desert</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an undirected graph of $N$ nodes and $M$ edges, $E_1, E_2, \dots E_M$.

A connected graph is a cactus if each of it's edges belogs to at most one simple cycle. A graph is a desert if each of it's connected components is a cactus. 

Find the number of pairs $(L, R)$, ($1 \leq L \leq R \leq M$) such that, if we delete all the edges except for $E_L, E_{L+1}, \dots E_R$, the graph is a desert. 

#### Input

The first line contains two integers $N$ and $M$ ($2 \leq N \leq 2.5 \times 10^5$, $1 \leq M \leq 5 \times 10^5$). Each of the next $M$ lines contains two integers. The $i$-th line describes the $i$-th edge. It contains integers $U_i$ and $V_i$, the nodes connected by the $i$-th edge ($E_i=(U_i, V_i)$). It is guaranteed that $1 \leq U_i, V_i \leq N$ and $U_i \neq V_i$. 

#### Output

The output contains one integer number – the answer.

## Examples

#### Input


```text
5 6
1 2
2 3
3 4
4 5
5 1
2 4
```
#### Output


```text
20
```
#### Input

```text

2 3
1 2
1 2
1 2

```
#### Output


```text

5
```
## Note

In the second example: Graphs for pairs $(1, 1)$, $(2, 2)$ and $(3, 3)$ are deserts because they don't have any cycles. Graphs for pairs $(1, 2)$ and $(2, 3)$ have one cycle of length 2 so they are deserts.



#### Tags 

#2700 #NOT OK #data_structures #graphs 

## Blogs
- [All Contest Problems](../Bubble_Cup_14_-_Finals_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred,_Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
