<h1 style='text-align: center;'> E. Replace the Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array of integers (initially empty).

You have to perform $q$ queries. Each query is of one of two types: 

* "$1$ $x$" — add the element $x$ to the end of the array;
* "$2$ $x$ $y$" — replace all occurrences of $x$ in the array with $y$.

Find the resulting array after performing all the queries.

## Input

The first line contains a single integer $q$ ($1 \le q \le 5 \cdot 10^5$) — the number of queries.

Next $q$ lines contain queries (one per line). Each query is of one of two types: 

* "$1$ $x$" ($1 \le x \le 5 \cdot 10^5$);
* "$2$ $x$ $y$" ($1 \le x, y \le 5 \cdot 10^5$).

It's guaranteed that there is at least one query of the first type.

## Output

In a single line, print $k$ integers — the resulting array after performing all the queries, where $k$ is the number of queries of the first type.

## Examples

## Input


```

7
1 3
1 1
2 1 2
1 2
1 1
1 2
2 1 3

```
## Output


```

3 2 2 3 2 
```
## Input


```

4
1 1
1 2
1 1
2 2 2

```
## Output


```

1 2 1 
```
## Input


```

8
2 1 4
1 1
1 4
1 2
2 2 4
2 4 3
1 2
2 2 7

```
## Output


```

1 3 3 7 
```
## Note

In the first example, the array changes as follows:

$[]$ $\rightarrow$ $[3]$ $\rightarrow$ $[3, 1]$ $\rightarrow$ $[3, 2]$ $\rightarrow$ $[3, 2, 2]$ $\rightarrow$ $[3, 2, 2, 1]$ $\rightarrow$ $[3, 2, 2, 1, 2]$ $\rightarrow$ $[3, 2, 2, 3, 2]$.

In the second example, the array changes as follows:

$[]$ $\rightarrow$ $[1]$ $\rightarrow$ $[1, 2]$ $\rightarrow$ $[1, 2, 1]$ $\rightarrow$ $[1, 2, 1]$.

In the third example, the array changes as follows:

$[]$ $\rightarrow$ $[]$ $\rightarrow$ $[1]$ $\rightarrow$ $[1, 4]$ $\rightarrow$ $[1, 4, 2]$ $\rightarrow$ $[1, 4, 4]$ $\rightarrow$ $[1, 3, 3]$ $\rightarrow$ $[1, 3, 3, 2]$ $\rightarrow$ $[1, 3, 3, 7]$.



#### tags 

#1900 #constructive_algorithms #data_structures #dsu #implementation 