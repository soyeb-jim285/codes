<h1 style='text-align: center;'> J. Two Colors</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a tree consisting of $n$ vertices. Some vertices of the tree are red, all other vertices are blue.

Each edge of the tree has a positive weight. Let's define $d(x, y)$ as the distance between the vertices $x$ and $y$, i. e. the sum of weights of edges belonging to the simple path between $x$ and $y$.

For each vertex, you have to choose an integer $v_i$. These integers should meet the following constraint: for every blue vertex $b$ and every red vertex $r$, $d(b, r) \ge v_b + v_r$. 

You have to maximize the value of $\sum \limits_{i=1}^{n} v_i$.

## Note

 that the values of $v_i$ are not necessarily positive.

## Input

The first line contains one integer $n$ ($2 \le n \le 3 \cdot 10^5$).

The second line contains $n$ integers $c_1, c_2, \dots, c_n$ ($0 \le c_i \le 1$). If the $i$-th vertex is red, $c_i = 1$, otherwise $c_i = 0$.

Then $n-1$ lines follow. Each line contains three integers $x_i$, $y_i$ and $w_i$ ($1 \le x_i, y_i \le n$; $1 \le w_i \le 10^6$; $x_i \ne y_i$) denoting an edge between the vertices $x_i$ and $y_i$ which has weight $w_i$. These edges form a tree.

## Output

If the value of $\sum \limits_{i=1}^{n} v_i$ can be as big as possible, print Infinity. Otherwise, print one integer — the maximum possible value of $\sum \limits_{i=1}^{n} v_i$ you can get.

## Examples

## Input


```

4
1 1 0 0
3 4 50
3 2 100
2 1 100

```
## Output


```

350

```
## Input


```

6
0 1 0 1 0 1
1 2 1
1 4 1
1 6 1
6 5 100
6 3 100

```
## Output


```

203

```
## Input


```

3
1 1 1
1 2 100
2 3 100

```
## Output


```

Infinity

```
## Note

In the first example, you can assign $v_1 = 120, v_2 = 20, v_3 = 80, v_4 = 130$.



#### tags 

#2900 #*special 