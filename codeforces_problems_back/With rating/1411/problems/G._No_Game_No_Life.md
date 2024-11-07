<h1 style='text-align: center;'> G. No Game No Life</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's consider the following game of Alice and Bob on a directed acyclic graph. Each vertex may contain an arbitrary number of chips. Alice and Bob make turns alternating. Alice goes first. In one turn player can move exactly one chip along any edge outgoing from the vertex that contains this chip to the end of this edge. The one who cannot make a turn loses. Both players play optimally.

Consider the following process that takes place every second on a given graph with $n$ vertices: 

1. An integer $v$ is chosen equiprobably from $[1, n + 1]$.
2. If $v \leq n$, we add a chip to the $v$-th vertex and go back to step 1.
3. If $v = n + 1$, Alice and Bob play the game with the current arrangement of chips and the winner is determined. After that, the process is terminated.

Find the probability that Alice will win the game. It can be shown that the answer can be represented as $\frac{P}{Q}$, where $P$ and $Q$ are coprime integers and $Q \not\equiv 0 \pmod{998\,244\,353}$. Print the value of $P \cdot Q^{-1} \bmod 998\,244\,353$.

## Input

The first line contains two integers $n$ and $m$ — the number of vertices and edges of the graph ($1 \leq n \leq 10^5$, $0 \leq m \leq 10^5$).

The following $m$ lines contain edges description. The $i$-th of them contains two integers $u_i$ and $v_i$ — the beginning and the end vertices of the $i$-th edge ($1 \leq u_i, v_i \leq n$). It's guaranteed that the graph is acyclic.

## Output

## Output

 a single integer — the probability of Alice victory modulo $998\,244\,353$.

## Examples

## Input


```

1 0

```
## Output


```

0

```
## Input


```

2 1
1 2

```
## Output


```

332748118

```
## Input


```

5 5
1 4
5 2
4 3
1 5
5 4

```
## Output


```

931694730

```


#### tags 

#2700 #bitmasks #games #math #matrices 