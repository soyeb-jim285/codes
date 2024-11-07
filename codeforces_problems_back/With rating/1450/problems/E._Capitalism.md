<h1 style='text-align: center;'> E. Capitalism</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A society can be represented by a connected, undirected graph of $n$ vertices and $m$ edges. The vertices represent people, and an edge $(i,j)$ represents a friendship between people $i$ and $j$.

In society, the $i$-th person has an income $a_i$. A person $i$ is envious of person $j$ if $a_j=a_i+1$. That is if person $j$ has exactly $1$ more unit of income than person $i$.

The society is called capitalist if for every pair of friends one is envious of the other. For some friendships, you know which friend is envious of the other. For the remaining friendships, you do not know the direction of envy.

The income inequality of society is defined as $\max\limits_{1 \leq i \leq n} a_i - \min\limits_{1 \leq i \leq n} a_i$.

You only know the friendships and not the incomes. If it is impossible for this society to be capitalist with the given knowledge, you should report about it. Otherwise, you should find an assignment of incomes in which the society is capitalist, and the income inequality is maximized.

## Input

The first line contains two integers $n$, $m$ ($1\le n\le 200$, $n-1\le m\le 2000$) — the number of people and friendships, respectively.

The following $m$ lines describe the friendships. Each friendship is described by three integers $i$, $j$, $b$ ($1\le i, j\le n, i\ne j, 0\le b\le 1$). This denotes that people $i$ and $j$ are friends. If $b=1$, we require that person $i$ is envious of person $j$. If $b=0$, one friend should be envious of the other in either direction.

There is at most one friendship between each pair of people. It is guaranteed that if we consider the friendships as undirected edges, the graph is connected.

## Output

Print "YES" if it is possible that the society is capitalist, or "NO" otherwise. You can print characters in any case (upper or lower).

If the answer is "YES", you should print two additional lines. In the first line, print the maximum possible income inequality. On the next line you should print $n$ integers $a_1,\ldots, a_n$ ($0\le a_i\le 10^6$), where $a_i$ denotes the income of the $i$-th person.

We can prove that if there exists a solution, there exists one where $0\le a_i\le 10^6$ for all $i$.

If there exist multiple solutions, print any.

## Examples

## Input


```

6 6
1 2 0
3 2 0
2 5 0
6 5 1
6 3 0
2 4 1

```
## Output


```

YES
3
3 2 1 3 1 0 

```
## Input


```

4 4
1 2 1
2 3 0
3 4 1
4 1 1

```
## Output


```

NO

```
## Input


```

1 0

```
## Output


```

YES
0
0 

```
## Note

In the first test, we can show that an income inequality greater than $3$ is impossible for the given society. In the given answer with income inequality equal to $3$:

* Person $2$ is envious of person $1$.
* Person $3$ is envious of person $2$.
* Person $5$ is envious of person $2$.
* Person $6$ is envious of person $5$ (the required direction is satisfied).
* Person $6$ is envious of person $3$.
* Person $2$ is envious of person $4$ (the required direction is satisfied).

In the second test, we can show that there is no way to assign incomes to satisfy all requirements.



#### tags 

#2700 #constructive_algorithms #dfs_and_similar #graphs #shortest_paths 