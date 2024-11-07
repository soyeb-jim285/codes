<h1 style='text-align: center;'> E. Monsters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an undirected graph with $n$ vertices and $m$ edges. Initially, for each vertex $i$, there is a monster with danger $a_{i}$ on that vertex. For a monster with danger $a_{i}$, you can defeat it if and only if you have defeated at least $a_{i}$ other monsters before.

Now you want to defeat all the monsters. First, you choose some vertex $s$ and defeat the monster on that vertex (since you haven't defeated any monsters before, $a_{s}$ has to be $0$). Then, you can move through the edges. If you want to move from vertex $u$ to vertex $v$, then the following must hold: either the monster on vertex $v$ has been defeated before, or you can defeat it now. For the second case, you defeat the monster on vertex $v$ and reach vertex $v$.

You can pass the vertices and the edges any number of times. Determine whether you can defeat all the monsters or not.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Their description follows.

The first line of each test case contains two integers $n$, $m$ ($1 \le n, m \le 2 \cdot 10^5$) — the number of vertices and edges in the graph respectively. 

The second line of each test case contains $n$ integers $a_{1}, a_{2}, \ldots, a_{n}$ ($0 \le a_{i} \le n$) — the dangers of monsters on corresponding vertices.

For the following $m$ lines, each line contains two integers $u$, $v$ ($1 \le u, v \le n$), describing an edge connecting vertex $u$ and vertex $v$. It is guaranteed that there are no multi-edges or self-loops in the graph.

It is guaranteed that both the sum of $n$ and the sum of $m$ over all test cases do not exceed $2 \cdot 10^5$.

## Output

For each test case, output "YES" if you can defeat all the monsters, or "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

## Input


```

54 32 1 0 31 22 33 46 60 1 2 3 0 11 22 33 44 54 65 64 30 1 2 01 22 31 34 61 1 1 01 23 24 32 44 11 35 50 1 3 2 01 22 33 44 53 5
```
## Output


```

YES
YES
NO
YES
NO

```
## Note

In the first test case, you can start at vertex $3$ and defeat the monster on it, before you go to vertices $2$, $1$ in this order, defeating the monsters on them as well. Then you return to vertex $3$, and go to vertex $4$, defeating the monster on it.

In the third test case, there is no path to vertex $4$ if you start at vertex $1$. Also, there is no path to vertices $1$, $2$, and $3$ if you start at vertex $4$.



#### tags 

#2100 #brute_force #data_structures #dfs_and_similar #dsu #graphs #greedy 