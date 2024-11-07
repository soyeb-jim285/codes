![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Graph Paths I

  * Task
  * Statistics

CSES - Graph Paths I

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Consider a directed graph that has $n$ nodes and $m$ edges. Your task is to
count the number of paths from node $1$ to node $n$ with exactly $k$ edges.

# Input

The first input line contains three integers $n$, $m$ and $k$: the number of
nodes and edges, and the length of the path. The nodes are numbered
$1,2,\dots,n$.

Then, there are $m$ lines describing the edges. Each line contains two
integers $a$ and $b$: there is an edge from node $a$ to node $b$.

# Output

Print the number of paths modulo $10^9+7$.

# Constraints

  * $1 \le n \le 100$
  * $1 \le m \le n(n-1)$
  * $1 \le k \le 10^9$
  * $1 \le a,b \le n$

# Example

Input:

``` 3 4 8 1 2 2 3 3 1 3 2 ```

Output:

``` 2 ```

Explanation: The paths are $1 \rightarrow 2 \rightarrow 3 \rightarrow 1
\rightarrow 2 \rightarrow 3 \rightarrow 1 \rightarrow 2 \rightarrow 3$ and $1
\rightarrow 2 \rightarrow 3 \rightarrow 2 \rightarrow 3 \rightarrow 2
\rightarrow 3 \rightarrow 2 \rightarrow 3$.

#### Mathematics

... Counting GridsFibonacci NumbersThrowing DiceGraph Paths IGraph Paths
IIDice ProbabilityMoving RobotsCandy Lottery...

* * *

