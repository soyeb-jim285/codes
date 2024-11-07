![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Path Queries II

  * Task
  * Statistics

CSES - Path Queries II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a tree consisting of $n$ nodes. The nodes are numbered
$1,2,\ldots,n$. Each node has a value.

Your task is to process following types of queries:

  1. change the value of node $s$ to $x$
  2. find the maximum value on the path between nodes $a$ and $b$.

# Input

The first input line contains two integers $n$ and $q$: the number of nodes
and queries. The nodes are numbered $1,2,\ldots,n$.

The next line has $n$ integers $v_1,v_2,\ldots,v_n$: the value of each node.

Then there are $n-1$ lines describing the edges. Each line contains two
integers $a$ and $b$: there is an edge between nodes $a$ and $b$.

Finally, there are $q$ lines describing the queries. Each query is either of
the form "1 $s$ $x$" or "2 $a$ $b$".

# Output

Print the answer to each query of type 2.

# Constraints

  * $1 \le n, q \le 2 \cdot 10^5$
  * $1 \le a,b, s \le n$
  * $1 \le v_i, x \le 10^9$

# Example

Input:

``` 5 3 2 4 1 3 3 1 2 1 3 2 4 2 5 2 3 5 1 2 2 2 3 5 ```

Output:

``` 4 3 ```

#### Tree Algorithms

... Counting PathsSubtree QueriesPath QueriesPath Queries IIDistinct
ColorsFinding a CentroidFixed-Length Paths IFixed-Length Paths II

* * *

