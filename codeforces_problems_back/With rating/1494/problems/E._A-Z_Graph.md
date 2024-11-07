<h1 style='text-align: center;'> E. A-Z Graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a directed graph consisting of $n$ vertices. Each directed edge (or arc) labeled with a single character. Initially, the graph is empty.

You should process $m$ queries with it. Each query is one of three types: 

* "$+$ $u$ $v$ $c$" — add arc from $u$ to $v$ with label $c$. It's guaranteed that there is no arc $(u, v)$ in the graph at this moment;
* "$-$ $u$ $v$" — erase arc from $u$ to $v$. It's guaranteed that the graph contains arc $(u, v)$ at this moment;
* "$?$ $k$" — find the sequence of $k$ vertices $v_1, v_2, \dots, v_k$ such that there exist both routes $v_1 \to v_2 \to \dots \to v_k$ and $v_k \to v_{k - 1} \to \dots \to v_1$ and if you write down characters along both routes you'll get the same string. You can visit the same vertices any number of times.
## Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 2 \cdot 10^5$; $1 \le m \le 2 \cdot 10^5$) — the number of vertices in the graph and the number of queries.

The next $m$ lines contain queries — one per line. Each query is one of three types: 

* "$+$ $u$ $v$ $c$" ($1 \le u, v \le n$; $u \neq v$; $c$ is a lowercase Latin letter);
* "$-$ $u$ $v$" ($1 \le u, v \le n$; $u \neq v$);
* "$?$ $k$" ($2 \le k \le 10^5$).

It's guaranteed that you don't add multiple edges and erase only existing edges. Also, there is at least one query of the third type.

## Output

For each query of the third type, print YES if there exist the sequence $v_1, v_2, \dots, v_k$ described above, or NO otherwise.

## Example

## Input


```

3 11
+ 1 2 a
+ 2 3 b
+ 3 2 a
+ 2 1 b
? 3
? 2
- 2 1
- 3 2
+ 2 1 c
+ 3 2 d
? 5

```
## Output


```

YES
NO
YES

```
## Note

In the first query of the third type $k = 3$, we can, for example, choose a sequence $[1, 2, 3]$, since $1 \xrightarrow{\text{a}} 2 \xrightarrow{\text{b}} 3$ and $3 \xrightarrow{\text{a}} 2 \xrightarrow{\text{b}} 1$.

In the second query of the third type $k = 2$, and we can't find sequence $p_1, p_2$ such that arcs $(p_1, p_2)$ and $(p_2, p_1)$ have the same characters.

In the third query of the third type, we can, for example, choose a sequence $[1, 2, 3, 2, 1]$, where $1 \xrightarrow{\text{a}} 2 \xrightarrow{\text{b}} 3 \xrightarrow{\text{d}} 2 \xrightarrow{\text{c}} 1$.



#### tags 

#2400 #constructive_algorithms #data_structures #graphs #hashing 