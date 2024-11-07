<h1 style='text-align: center;'> E. Coloring Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Consider an undirected connected graph consisting of $n$ vertices and $m$ edges. Each vertex can be colored with one of three colors: $1$, $2$, or $3$. Initially, all vertices are uncolored.

Alice and Bob are playing a game consisting of $n$ rounds. In each round, the following two-step process happens: 

1. Alice chooses two different colors.
2. Bob chooses an uncolored vertex and colors it with one of the two colors chosen by Alice.

Alice wins if there exists an edge connecting two vertices of the same color. Otherwise, Bob wins.

You are given the graph. Your task is to decide which player you wish to play as and win the game.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$, $m$ ($1 \le n \le 10^4$, $n - 1 \le m \le \min(\frac{n \cdot (n - 1)}{2}, 10^4)$) — the number of vertices and the number of edges in the graph, respectively.

Each of the next $m$ lines of each test case contains two integers $u_i$, $v_i$ ($1 \le u_i, v_i \le n$) — the edges of the graph. It is guaranteed that the graph is connected and there are no multiple edges or self-loops.

It is guaranteed that the sum of $n$ and the sum of $m$ over all test cases does not exceed $10^4$.

## Interaction

For each test case, you need to output a single line containing either "Alice" or "Bob", representing the player you choose.

Then for each of the following $n$ rounds, the following two-step process happens: 

1. Alice (either you or the interactor) will output two integers $a$ and $b$ ($1 \le a, b \le 3$, $a \neq b$) — the colors chosen by Alice.
2. Bob (either you or the interactor) will output two integers $i$ and $c$ ($1 \le i \le n$, $c = a$ or $c = b$) — the vertex and the color chosen by Bob. Vertex $i$ must be a previously uncolored vertex.

If any of your outputs are invalid, the jury will output "-1" and you will receive a Wrong Answer verdict.

At the end of all $n$ turns, if you have lost the game, the jury will output "-1" and you will receive a Wrong Answer verdict.

If your program has received a $-1$ instead of a valid value, it must terminate immediately. Otherwise, you may receive an arbitrary verdict because your solution might be reading from a closed stream.

## Note

 that if you are playing as Alice, and there already exists an edge connected two vertices of the same color, the interactor will not terminate early and you will keep playing all $n$ rounds.

After outputting, do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

In this problem, hacks are disabled.

## Example

## Input


```

2
3 3
1 2
2 3
3 1


3 1

2 2

1 1
4 4
1 2
2 3
3 4
4 1

2 3

1 2

2 1

3 1


```
Output
```






Alice
3 1

1 2

2 1






Bob

1 2

2 1

4 1

3 3

```
## Note

## Note

 that the sample test cases are example games and do not necessarily represent the optimal strategy for both players.

In the first test case, you choose to play as Alice.

1. Alice chooses two colors: $3$ and $1$. Bob chooses vertex $3$ and colors it with color $1$.
2. Alice chooses two colors: $1$ and $2$. Bob chooses vertex $2$ and colors it with color $2$.
3. Alice chooses two colors: $2$ and $1$. Bob chooses vertex $1$ and colors it with color $1$.

Alice wins because the edge $(3, 1)$ connects two vertices of the same color.

In the second test case, you choose to play as Bob.

1. Alice chooses two colors: $2$ and $3$. Bob chooses vertex $1$ and colors it with color $2$.
2. Alice chooses two colors: $1$ and $2$. Bob chooses vertex $2$ and colors it with color $1$.
3. Alice chooses two colors: $2$ and $1$. Bob chooses vertex $4$ and colors it with color $1$.
4. Alice chooses two colors: $3$ and $1$. Bob chooses vertex $3$ and colors it with color $3$.

Bob wins because there are no edges with vertices of the same color.



#### tags 

#constructive_algorithms #dfs_and_similar #games #graphs #greedy #interactive 