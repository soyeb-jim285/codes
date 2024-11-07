<h1 style='text-align: center;'> F. Good Graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an undirected graph consisting of $n$ vertices with weighted edges.

A simple cycle is a cycle of the graph without repeated vertices. Let the weight of the cycle be the [XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of weights of edges it consists of.

Let's say the graph is good if all its simple cycles have weight $1$. A graph is bad if it's not good.

Initially, the graph is empty. Then $q$ queries follow. Each query has the next type: 

* $u$ $v$ $x$ — add edge between vertices $u$ and $v$ of weight $x$ if it doesn't make the graph bad.

For each query print, was the edge added or not.

### Input

The first line contains two integers $n$ and $q$ ($3 \le n \le 3 \cdot 10^5$; $1 \le q \le 5 \cdot 10^5$) — the number of vertices and queries.

Next $q$ lines contain queries — one per line. Each query contains three integers $u$, $v$ and $x$ ($1 \le u, v \le n$; $u \neq v$; $0 \le x \le 1$) — the vertices of the edge and its weight.

It's guaranteed that there are no multiple edges in the input.

### Output

For each query, print YES if the edge was added to the graph, or NO otherwise (both case-insensitive).

## Example

### Input


```text
9 12
6 1 0
1 3 1
3 6 0
6 2 0
6 4 1
3 4 1
2 4 0
2 5 0
4 5 0
7 8 1
8 9 1
9 7 0
```
### Output


```text
YES
YES
YES
YES
YES
NO
YES
YES
NO
YES
YES
NO
```


#### Tags 

#2700 #NOT OK #data_structures #dsu #graphs #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_112_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
