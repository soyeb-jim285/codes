<h1 style='text-align: center;'> F. XOR, Tree, and Queries</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree of $n$ vertices. The vertices are numbered from $1$ to $n$.

You will need to assign a weight to each edge. Let the weight of the $i$-th edge be $a_i$ ($1 \leq i \leq n-1$). The weight of each edge should be an integer between $0$ and $2^{30}-1$, inclusive.

You are given $q$ conditions. Each condition consists of three integers $u$, $v$, and $x$. This means that the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all edges on the shortest path from $u$ to $v$ should be $x$.

Find out if there exist $a_1, a_2, \ldots, a_{n-1}$ that satisfy the given conditions. If yes, print a solution such that $a_1 \oplus a_2 \oplus \ldots \oplus a_{n-1}$ is the smallest. Here, $\oplus$ denotes the bitwise XOR operation.

If there are multiple solutions such that $a_1 \oplus a_2 \oplus \ldots \oplus a_{n-1}$ is the smallest, print any.

## Input

The first line contains two integers $n$ and $q$ ($2 \le n \le 2.5 \cdot 10^5$, $0 \le q \le 2.5 \cdot 10^5$).

The $i$-th of the following $n-1$ lines contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le n$, $x_i \neq y_i$), meaning that the $i$-th edge connects vertices $x_i$ and $y_i$ in the tree.

It is guaranteed that the given edges form a tree.

The following $q$ lines contain information about conditions.

Each line contains three integers $u$, $v$, $x$ ($1 \le u, v \le n$, $u \neq v$, $0 \le x \le 2^{30}-1$), meaning that the bitwise XOR of all edges on the shortest path from $u$ to $v$ should be $x$.

## Output

If there do not exist $a_1$, $a_2$, ..., $a_{n-1}$ that satisfy the given conditions, print "No".

Otherwise, print "Yes" in the first line.

Then print $n-1$ integers on the next line, where the $i$-th integer is the weight of the $i$-th edge. If there are multiple solutions that satisfy the given conditions, print a solution such that $a_1 \oplus a_2 \oplus \ldots \oplus a_{n-1}$ is the smallest.

If there are multiple solutions such that $a_1 \oplus a_2 \oplus \ldots \oplus a_{n-1}$ is the smallest, print any.

When printing "Yes" or "No", you can print each letter in any case (either upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Examples

## Input


```

4 4
1 2
2 3
3 4
1 4 3
2 4 2
1 3 1
2 3 1

```
## Output


```

No
```
## Input


```

6 2
1 2
2 3
3 4
2 5
5 6
1 4 2
2 6 7

```
## Output


```

Yes
4 2 4 1 6
```
## Input


```

6 2
1 2
2 3
3 4
2 5
5 6
1 4 3
1 6 5

```
## Output


```

Yes
6 1 4 3 0
```
## Note

For the first example, there does not exist a set of edge weights that satisfies the given conditions.

For the second example, the two given conditions are $a_1 \oplus a_2 \oplus a_3=2$ and $a_4 \oplus a_5=7$. There can be multiple solutions, for example, $(a_1, a_2, a_3, a_4, a_5)=(1, 2, 1, 4, 3)$.

For the third example, the two given conditions are $a_1 \oplus a_2 \oplus a_3=3$ and $a_1 \oplus a_4 \oplus a_5=5$. There are multiple solutions that satisfy the given conditions. 

$(a_1, a_2, a_3, a_4, a_5)=(1, 1, 3, 4, 0)$ satisfies the given conditions, but the bitwise XOR of all edge weights is $7$, which does not have the smallest $a_1 \oplus a_2 \oplus \ldots \oplus a_{n-1}$, so it cannot be the answer.



#### tags 

#2500 #bitmasks #constructive_algorithms #dfs_and_similar #dsu #graphs #greedy #implementation #trees 