![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Subtree Queries

  * Task
  * Statistics

CSES - Subtree Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a rooted tree consisting of $n$ nodes. The nodes are numbered
$1,2,\ldots,n$, and node $1$ is the root. Each node has a value.

Your task is to process following types of queries:

  1. change the value of node $s$ to $x$
  2. calculate the sum of values in the subtree of node $s$

# Input

The first input line contains two integers $n$ and $q$: the number of nodes
and queries. The nodes are numbered $1,2,\ldots,n$.

The next line has $n$ integers $v_1,v_2,\ldots,v_n$: the value of each node.

Then there are $n-1$ lines describing the edges. Each line contans two
integers $a$ and $b$: there is an edge between nodes $a$ and $b$.

Finally, there are $q$ lines describing the queries. Each query is either of
the form "1 $s$ $x$" or "2 $s$".

# Output

Print the answer to each query of type 2.

# Constraints

  * $1 \le n, q \le 2 \cdot 10^5$
  * $1 \le a,b, s \le n$
  * $1 \le v_i, x \le 10^9$

# Example

Input:

``` 5 3 4 2 5 2 1 1 2 1 3 3 4 3 5 2 3 1 5 3 2 3 ```

Output:

``` 8 10 ```

#### Tree Algorithms

... Company Queries IIDistance QueriesCounting PathsSubtree QueriesPath
QueriesPath Queries IIDistinct ColorsFinding a Centroid...

* * *

