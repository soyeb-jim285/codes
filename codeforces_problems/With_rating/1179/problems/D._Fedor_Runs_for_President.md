<h1 style='text-align: center;'> D. Fedor Runs for President</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fedor runs for president of Byteland! In the debates, he will be asked how to solve Byteland's transport problem. It's a really hard problem because of Byteland's transport system is now a tree (connected graph without cycles). Fedor's team has found out in the ministry of transport of Byteland that there is money in the budget only for one additional road. In the debates, he is going to say that he will build this road as a way to maximize the number of distinct simple paths in the country. A simple path is a path which goes through every vertex no more than once. Two simple paths are named distinct if sets of their edges are distinct. 

But Byteland's science is deteriorated, so Fedor's team hasn't succeeded to find any scientists to answer how many distinct simple paths they can achieve after adding exactly one edge on the transport system?

Help Fedor to solve it.

An edge can be added between vertices that are already connected, but it can't be a loop.

In this problem, we consider only simple paths of length at least two.

##### Input

The first line contains one integer $n$ ($2 \leq n \leq 500\ 000$) — number of vertices in Byteland's transport system.

Each of the following $n - 1$ lines contains two integers $v_i$ and $u_i$ ($1 \leq v_i, u_i \leq n$). It's guaranteed that the graph is tree.

##### Output

Print exactly one integer — a maximal number of simple paths that can be achieved after adding one edge.

## Examples

##### Input


```text
2
1 2
```
##### Output


```text
2
```
##### Input


```text
4
1 2
1 3
1 4
```
##### Output


```text
11
```
##### Input


```text
6
1 2
1 3
3 4
3 5
4 6
```
##### Output


```text
29
```


#### Tags 

#2700 #NOT OK #data_structures #dp #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_569_(Div._1).md)
- [Codeforces Round #569](../blogs/Codeforces_Round_569.md)
- [Editorial of Round #569](../blogs/Editorial_of_Round_569.md)
