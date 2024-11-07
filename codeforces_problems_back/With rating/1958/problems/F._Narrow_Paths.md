<h1 style='text-align: center;'> F. Narrow Paths</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is wandering through a matrix consisting of $2$ rows and $n$ columns. Let's denote the cell in the $i$-th row and $j$-th column as $(i, j)$. Monocarp starts at cell $(1, 1)$ and wants to reach cell $(2, n)$.

In one move, Monocarp can move in one of two directions: 

* right — from cell $(i, j)$ to cell $(i, j + 1)$;
* down — from cell $(i, j)$ to cell $(i + 1, j)$.

Monocarp can't go outside the matrix.

Polycarp wants to prevent Monocarp from freely wandering through the matrix. To do this, he wants to choose exactly $k$ different cells in the matrix and block them. He cannot choose cells $(1, 1)$ and $(2, n)$.

For each $i$ from $0$ to $n$, Polycarp wants to know how many ways he can block exactly $k$ cells, so that Monocarp has exactly $i$ different paths from $(1, 1)$ to $(2, n)$. Two paths are considered different if there exists a cell that Monocarp visits in one path but not in the other.

As the number of ways can be quite large, output it modulo $10^9 + 7$.

## Input

The only line contains two integers $n$ and $k$ ($2 \le n \le 2 \cdot 10^5$; $2 \le k \le 2 \cdot n - 2$) — the number of columns in the matrix and the number of cells Polycarp wants to block.

## Output

## Output

 $n + 1$ integers: for each $i$ from $0$ to $n$, the number of ways to block exactly $k$ cells, so that Monocarp has exactly $i$ different paths from $(1, 1)$ to $(2, n)$. ## Output

 all answers modulo $10^9 + 7$.

## Examples

## Input


```

2 2
```
## Output


```

1 0 0

```
## Input


```

10 2
```
## Output


```

45 24 21 18 15 12 9 6 3 0 0

```
## Input


```

10 5
```
## Output


```

7812 420 210 90 30 6 0 0 0 0 0

```
## Input


```

22 10
```
## Output


```

467563090 1847560 1016158 534820 267410 125840 55055 22022 7865 2420 605 110 11 0 0 0 0 0 0 0 0 0 0

```


#### tags 

#2000 #*special #combinatorics 