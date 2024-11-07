<h1 style='text-align: center;'> G. Tree LGM</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In TreeWorld, there is a popular two-player game played on a tree with $n$ vertices labelled from $1$ to $n$. In this game, the tournament leaders first choose a vertex to be the root of the tree and choose another vertex (possibly the same vertex as the root) to place a coin on. Then, each player will take turns moving the coin to any child$^\dagger$ of the vertex that the coin is currently on. The first player who is unable to make a move loses.

Alice wants to be a tree LGM, so she spends a lot of time studying the game. She wrote down an $n$ by $n$ matrix $s$, where $s_{i,j} = \mathtt{1}$ if the first player can win with the root of the tree chosen to be vertex $i$, and the coin was initially placed on vertex $j$. Otherwise, $s_{i, j} = \mathtt{0}$. Alice is a perfectionist, so she assumes that both players play perfectly in the game.

However, she accidentally knocked her head on the way to the tournament and forgot what the tree looked like. Determine whether there exists a tree that satisfies the winning and losing states represented by matrix $s$, and if it exists, construct a valid tree.

$^\dagger$ A vertex $c$ is a child of vertex $u$ if there is an edge between $c$ and $u$, and $c$ does not lie on the unique simple path from the root to vertex $u$.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 5000$) — the number of vertices in the tree.

Each of the next $n$ lines contains a string with $n$ characters, the $j$-th character of the $i$-th line representing $s_{i, j}$ ($s_{i, j} \in \{\mathtt{0}, \mathtt{1}\}$) — the winning and losing states of the tree.

#### Output

If there is no tree satisfying the winning and losing states represented by matrix $s$, print a single line containing "NO".

Otherwise, if there exists a tree satisfying matrix $s$, print "YES" on the first line, followed by $n - 1$ lines each containing two integers $u$ and $v$ ($1 \le u, v \le n$) representing that the tree has an edge between vertices $u$ and $v$.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

If there are multiple trees satisfying the winning and losing states represented by matrix $s$, print any of them.

## Examples

#### Input


```text
41100010100110101
```
#### Output

```text

YES
4 1
3 2
2 4

```
#### Input


```text
3001010100
```
#### Output

```text

NO

```
## Note

In the first test case, the line graph $1\!-\!4\!-\!2\!-\!3$ satisfies the winning and losing states represented by matrix $s$. For example, $s_{3,3} = 1$ as the first player can move the coin from $3\rightarrow 2$, then the second player moves the coin from $2\rightarrow 4$, and finally, the first player moves the coin from $4\rightarrow 1$. At this point, $1$ has no children, so the second player is unable to make a move and loses. On the other hand, $s_{1,3} = 0$ as if $1$ is the root, then $3$ has no children so the first player is unable to make the first move and loses.

In the second test case, it is possible to prove that no tree satisfies the winning and losing states represented by matrix $s$.



#### Tags 

#3500 #NOT OK #constructive_algorithms #divide_and_conquer #games #trees 

## Blogs
- [All Contest Problems](../Hello_2024.md)
- [Hello 2024 (en)](../blogs/Hello_2024_(en).md)
- [Editorial for Hello 2024 (en)](../blogs/Editorial_for_Hello_2024_(en).md)
