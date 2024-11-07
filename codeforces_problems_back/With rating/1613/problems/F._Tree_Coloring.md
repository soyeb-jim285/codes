<h1 style='text-align: center;'> F. Tree Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 4.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a rooted tree consisting of $n$ vertices numbered from $1$ to $n$. The root of the tree is the vertex $1$.

You have to color all vertices of the tree into $n$ colors (also numbered from $1$ to $n$) so that there is exactly one vertex for each color. Let $c_i$ be the color of vertex $i$, and $p_i$ be the parent of vertex $i$ in the rooted tree. The coloring is considered beautiful if there is no vertex $k$ ($k > 1$) such that $c_k = c_{p_k} - 1$, i. e. no vertex such that its color is less than the color of its parent by exactly $1$.

Calculate the number of beautiful colorings, and print it modulo $998244353$.

## Input

The first line contains one integer $n$ ($2 \le n \le 250000$) — the number of vertices in the tree.

Then $n-1$ lines follow, the $i$-th line contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le n$; $x_i \ne y_i$) denoting an edge between the vertex $x_i$ and the vertex $y_i$. These edges form a tree.

## Output

Print one integer — the number of beautiful colorings, taken modulo $998244353$.

## Examples

## Input


```

5
1 2
3 2
4 2
2 5

```
## Output


```

42

```
## Input


```

5
1 2
2 3
3 4
4 5

```
## Output


```

53

```
## Input


```

20
20 19
20 4
12 4
5 8
1 2
20 7
3 10
7 18
11 8
9 10
17 10
1 15
11 16
14 11
18 10
10 1
14 2
13 17
20 6

```
## Output


```

955085064

```


#### tags 

#2600 #combinatorics #divide_and_conquer #fft 