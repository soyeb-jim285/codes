<h1 style='text-align: center;'> E. Pairs of Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a simple and connected undirected graph consisting of $n$ nodes and $m$ edges.

Consider any way to pair some subset of these $n$ nodes such that no node is present in more than one pair. 

This pairing is valid if for every pair of pairs, the induced subgraph containing all $4$ nodes, two from each pair, has at most $2$ edges (out of the $6$ possible edges). More formally, for any two pairs, $(a,b)$ and $(c,d)$, the induced subgraph with nodes $\{a,b,c,d\}$ should have at most $2$ edges. 

Please note that the subgraph induced by a set of nodes contains nodes only from this set and edges which have both of its end points in this set.

Now, do one of the following: 

* Find a simple path consisting of at least $\lceil \frac{n}{2} \rceil$ nodes. Here, a path is called simple if it does not visit any node multiple times.
* Find a valid pairing in which at least $\lceil \frac{n}{2} \rceil$ nodes are paired.

It can be shown that it is possible to find at least one of the two in every graph satisfying constraints from the statement. 

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

The first line of each test case contains $2$ integers $n, m$ ($2 \le n \le 5\cdot 10^5$, $1 \le m \le 10^6$), denoting the number of nodes and edges, respectively. 

The next $m$ lines each contain $2$ integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), denoting that there is an undirected edge between nodes $u$ and $v$ in the given graph.

It is guaranteed that the given graph is connected, and simple  — it does not contain multiple edges between the same pair of nodes, nor does it have any self-loops. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $5\cdot 10^5$.

It is guaranteed that the sum of $m$ over all test cases does not exceed $10^6$.

## Output

For each test case, the output format is as follows. 

If you have found a pairing, in the first line output "PAIRING" (without quotes). 

* Then, output $k$ ($\lceil \frac{n}{2} \rceil \le 2\cdot k \le n$), the number of pairs in your pairing.
* Then, in each of the next $k$ lines, output $2$ integers $a$ and $b$  — denoting that $a$ and $b$ are paired with each other. ## Note

 that the graph does not have to have an edge between $a$ and $b$!
* This pairing has to be valid, and every node has to be a part of at most $1$ pair.

Otherwise, in the first line output "PATH" (without quotes). 

* Then, output $k$ ($\lceil \frac{n}{2} \rceil \le k \le n$), the number of nodes in your path.
* Then, in the second line, output $k$ integers, $v_1, v_2, \ldots, v_k$, in the order in which they appear on the path. Formally, $v_i$ and $v_{i+1}$ should have an edge between them for every $i$ ($1 \le i < k$).
* This path has to be simple, meaning no node should appear more than once.
## Example

## Input


```

4
6 5
1 4
2 5
3 6
1 5
3 5
6 5
1 4
2 5
3 6
1 5
3 5
12 14
1 2
2 3
3 4
4 1
1 5
1 12
2 6
2 7
3 8
3 9
4 10
4 11
2 4
1 3
12 14
1 2
2 3
3 4
4 1
1 5
1 12
2 6
2 7
3 8
3 9
4 10
4 11
2 4
1 3

```
## Output


```

PATH
4 
1 5 3 6
PAIRING
2
1 6
2 4
PAIRING
3
1 8
2 5
4 10
PAIRING
4
1 7
2 9
3 11
4 5

```
## Note

The path outputted in the first case is the following. 

 ![](images/1d4c7b8d4a4ae14de9052f6247a2c6dabc66fd5a.png) The pairing outputted in the second case is the following. 

 ![](images/3cbf482f3c60ece0b60acdaf139e30183322f5e1.png) Here is an invalid pairing for the same graph  — the subgraph $\{1,3,4,5\}$ has $3$ edges. 

 ![](images/c9e2ef34cd76f35960be2989a07458b0b35dd34b.png) Here is the pairing outputted in the third case. 

 ![](images/361c9659091dd0ab87d737e166e090bf7f9dfa9c.png) It's valid because — 

* The subgraph $\{1,8,2,5\}$ has edges ($1$,$2$) and ($1$,$5$).
* The subgraph $\{1,8,4,10\}$ has edges ($1$,$4$) and ($4$,$10$).
* The subgraph $\{4,10,2,5\}$ has edges ($2$,$4$) and ($4$,$10$).

Here is the pairing outputted in the fourth case. 

 ![](images/9879845d9100ec68ef3c88a3f9d849e7d66d6a40.png) 

#### tags 

#2600 #constructive_algorithms #dfs_and_similar #graphs #greedy #trees 