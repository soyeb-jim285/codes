<h1 style='text-align: center;'> G. Your Loss</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree with $n$ nodes numbered from $1$ to $n$, along with an array of size $n$. The value of $i$-th node is $a_{i}$. There are $q$ queries. In each query, you are given 2 nodes numbered as $x$ and $y$. 

Consider the path from the node numbered as $x$ to the node numbered as $y$. Let the path be represented by $x = p_0, p_1, p_2, \ldots, p_r = y$, where $p_i$ are the intermediate nodes. Compute the sum of $a_{p_i}\oplus i$ for each $i$ such that $0 \le i \le r$ where $\oplus$ is the [XOR](https://en.wikipedia.org/wiki/Exclusive_or) operator. 

More formally, compute $$\sum_{i =0}^{r} a_{p_i}\oplus i$$. 

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Each test case contains several sets of input data.

The first line of each set of input data contains a single integer $n$ ($1 \le n \le 5 \cdot 10^5$) — the number of nodes.

The next $n-1$ lines of each set of input data contain $2$ integers, $u$ and $v$ representing an edge between the node numbered $u$ and the node numbered $v$. It is guaranteed that $u \ne v$ and that the edges form a tree. 

The next line of each set of input data contains $n$ integers, $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 5 \cdot 10^5$) — values of the nodes.

The next line contains a single integer $q$ ($1 \le q \le 10^5$) — the number of queries.

The next $q$ lines describe the queries. The $i$-th query contains $2$ integers $x$ and $y$ ($1 \le x,y \le n$) denoting the starting and the ending node of the path. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$ and sum of $q$ over all test cases does not exceed $10^5$.

## Output

For each query, output a single number — the sum from the problem statement.

## Example

## Input


```

141 22 33 42 3 6 531 43 41 1
```
## Output


```

14
10
2

```


#### tags 

#3000 #bitmasks #brute_force #dp #trees 