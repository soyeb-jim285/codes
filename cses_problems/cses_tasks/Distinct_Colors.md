![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Distinct Colors

  * Task
  * Statistics

CSES - Distinct Colors

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a rooted tree consisting of $n$ nodes. The nodes are numbered
$1,2,\ldots,n$, and node $1$ is the root. Each node has a color.

Your task is to determine for each node the number of distinct colors in the
subtree of the node.

# Input

The first input line contains an integer $n$: the number of nodes. The nodes
are numbered $1,2,\ldots,n$.

The next line consists of $n$ integers $c_1,c_2,\ldots,c_n$: the color of each
node.

Then there are $n-1$ lines describing the edges. Each line contains two
integers $a$ and $b$: there is an edge between nodes $a$ and $b$.

# Output

Print $n$ integers: for each node $1,2,\ldots,n$, the number of distinct
colors.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le a,b \le n$
  * $1 \le c_i \le 10^9$

# Example

Input:

``` 5 2 3 2 2 1 1 2 1 3 3 4 3 5 ```

Output:

``` 3 1 2 1 1 ```

#### Tree Algorithms

... Counting PathsSubtree QueriesPath QueriesPath Queries IIDistinct
ColorsFinding a CentroidFixed-Length Paths IFixed-Length Paths II

* * *

