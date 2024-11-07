<h1 style='text-align: center;'> G. Yasya and the Mysterious Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Yasya was walking in the forest and accidentally found a tree with $n$ vertices. A tree is a connected undirected graph with no cycles.

Next to the tree, the girl found an ancient manuscript with $m$ queries written on it. The queries can be of two types.

The first type of query is described by the integer $y$. The weight of each edge in the tree is replaced by the [bitwise exclusive OR](http://tiny.cc/xor_wiki_eng) of the weight of that edge and the integer $y$.

The second type is described by the vertex $v$ and the integer $x$. Yasya chooses a vertex $u$ ($1 \le u \le n$, $u \neq v$) and mentally draws a bidirectional edge of weight $x$ from $v$ to $u$ in the tree.

Then Yasya finds a simple cycle in the resulting graph and calculates the [bitwise exclusive OR](http://tiny.cc/xor_wiki_eng) of all the edges in it. She wants to choose a vertex $u$ such that the calculated value is maximum. This calculated value will be the answer to the query. It can be shown that such a cycle exists and is unique under the given constraints (independent of the choice of $u$). If an edge between $v$ and $u$ already existed, a simple cycle is the path $v \to u \to v$.

Note that the second type of query is performed mentally, meaning the tree does not change in any way after it.

Help Yasya answer all the queries.

## Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The descriptions of the test cases follow.

The first line of each test case contains two integers $n$, $m$ ($2 \le n \le 2 \cdot 10^5$, $1 \le m \le 2 \cdot 10^5$) — the number of vertices in the tree and the number of queries.

The next $n - 1$ lines of each test case contain three integers $v$, $u$, $w$ ($1 \le v, u \le n$, $1 \le w \le 10^9$) — the ends of some edge in the tree and its weight.

It is guaranteed that the given set of edges forms a tree.

The next $m$ lines of each test case describe the queries: 

* ^ $y$ ($1 \le y \le 10^9$) — parameter of the first type query;
* ? $v$ $x$ ($1 \le v \le n$, $1 \le x \le 10^9$) — parameters of the second type query.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. The same is guaranteed for $m$.

## Output

For each test case, output the answers to the queries of the second type.

## Examples

## Input


```

23 71 2 13 1 8^ 5? 2 9^ 1? 1 10^ 6? 3 1? 2 95 61 2 7773 2 28124 1 165 3 1000000000^ 4? 3 123? 5 1000000000^ 1000000000? 1 908070? 2 1
```
## Output


```

13 15 11 10 
1000000127 2812 999756331 999999756 

```
## Input


```

38 48 6 36 3 42 5 47 6 27 1 104 1 45 1 2^ 4^ 7? 7 8? 4 105 63 1 42 3 94 3 65 2 10? 5 7^ 1^ 8? 4 10? 1 9? 3 64 22 1 44 3 52 3 4^ 13? 1 10
```
## Output


```

14 13 
13 8 11 11 
10 

```


#### tags 

#2300 #bitmasks #data_structures #dfs_and_similar #graphs #greedy #strings #trees 