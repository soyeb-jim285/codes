<h1 style='text-align: center;'> E. Matrix Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a matrix $a$, consisting of $n$ rows by $m$ columns. Each element of the matrix is equal to $0$ or $1$.

You can perform the following operation any number of times (possibly zero): choose an element of the matrix and replace it with either $0$ or $1$.

You are also given two arrays $A$ and $B$ (of length $n$ and $m$ respectively). After you perform the operations, the matrix should satisfy the following conditions:

1. the number of ones in the $i$-th row of the matrix should be exactly $A_i$ for every $i \in [1, n]$.
2. the number of ones in the $j$-th column of the matrix should be exactly $B_j$ for every $j \in [1, m]$.

Calculate the minimum number of operations you have to perform.

## Input

The first line contains two integers $n$ and $m$ ($2 \le n, m \le 50$).

Then $n$ lines follow. The $i$-th of them contains $m$ integers $a_{i,1}, a_{i,2}, \dots, a_{i,m}$ ($0 \le a_{i,j} \le 1$).

The next line contains $n$ integers $A_1, A_2, \dots, A_n$ ($0\le A_i\le m$).

The next line contains $m$ integers $B_1, B_2, \dots, B_m$ ($0\le B_i\le n$).

## Output

Print one integer — the minimum number of operations you have to perform, or -1 if it is impossible.

## Examples

## Input


```

3 30 0 00 0 00 0 01 1 11 1 1
```
## Output


```

3
```
## Input


```

3 31 1 11 1 11 1 13 2 11 2 3
```
## Output


```

3
```
## Input


```

2 20 00 01 20 1
```
## Output


```

-1
```


#### tags 

#2400 #flows #graphs 