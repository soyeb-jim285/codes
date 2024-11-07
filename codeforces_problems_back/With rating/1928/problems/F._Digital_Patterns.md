<h1 style='text-align: center;'> F. Digital Patterns</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Anya is engaged in needlework. Today she decided to knit a scarf from semi-transparent threads. Each thread is characterized by a single integer — the transparency coefficient.

The scarf is made according to the following scheme: horizontal threads with transparency coefficients $a_1, a_2, \ldots, a_n$ and vertical threads with transparency coefficients $b_1, b_2, \ldots, b_m$ are selected. Then they are interwoven as shown in the picture below, forming a piece of fabric of size $n \times m$, consisting of exactly $nm$ nodes:

 ![](images/32013a15179bef04a140e1801c28b2767028bd0d.png) Example of a piece of fabric for $n = m = 4$. After the interweaving tightens and there are no gaps between the threads, each node formed by a horizontal thread with number $i$ and a vertical thread with number $j$ will turn into a cell, which we will denote as $(i, j)$. Cell $(i, j)$ will have a transparency coefficient of $a_i + b_j$.

The interestingness of the resulting scarf will be the number of its sub-squares$^{\dagger}$ in which there are no pairs of neighboring$^{\dagger \dagger}$ cells with the same transparency coefficients.

Anya has not yet decided which threads to use for the scarf, so you will also be given $q$ queries to increase/decrease the coefficients for the threads on some ranges. After each query of which you need to output the interestingness of the resulting scarf.

$^{\dagger}$A sub-square of a piece of fabric is defined as the set of all its cells $(i, j)$, such that $x_0 \le i \le x_0 + d$ and $y_0 \le j \le y_0 + d$ for some integers $x_0$, $y_0$, and $d$ ($1 \le x_0 \le n - d$, $1 \le y_0 \le m - d$, $d \ge 0$).

$^{\dagger \dagger}$. Cells $(i_1, j_1)$ and $(i_2, j_2)$ are neighboring if and only if $|i_1 - i_2| + |j_1 - j_2| = 1$.

## Input

The first line contains three integers $n$, $m$, and $q$ ($1 \le n, m \le 3 \cdot 10^5$, $0 \le q \le 3 \cdot 10^5$) — the number of horizontal threads, the number of vertical threads, and the number of change requests.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$) — the transparency coefficients for the horizontal threads, with the threads numbered from top to bottom.

The third line contains $m$ integers $b_1, b_2, \ldots, b_m$ ($-10^9 \le b_i \le 10^9$) — the transparency coefficients for the vertical threads, with the threads numbered from left to right.

The next $q$ lines specify the change requests. Each request is described by a quadruple of integers $t$, $l$, $r$, and $x$ ($1 \le t \le 2$, $l \le r$, $-10^9 \le x \le 10^9$). Depending on the parameter $t$ in the request, the following actions are required:

* $t=1$. The transparency coefficients for the horizontal threads in the range $[l, r]$ are increased by $x$ (in other words, for all integers $l \le i \le r$, the value of $a_i$ is increased by $x$);
* $t=2$. The transparency coefficients for the vertical threads in the range $[l, r]$ are increased by $x$ (in other words, for all integers $l \le i \le r$, the value of $b_i$ is increased by $x$).
## Output

## Output

 $(q+1)$ lines. In the $(i + 1)$-th line ($0 \le i \le q$), output a single integer — the interestingness of the scarf after applying the first $i$ requests.

## Examples

## Input


```

4 4 01 1 2 31 2 2 3
```
## Output


```

20

```
## Input


```

3 3 21 1 12 2 81 2 3 12 2 3 -6
```
## Output


```

9
10
11

```
## Input


```

3 2 2-1000000000 0 1000000000-1000000000 10000000001 1 1 10000000002 2 2 -1000000000
```
## Output


```

8
7
7

```
## Note

In the first example, the transparency coefficients of the cells in the resulting plate are as follows:

 

| 2 | 3 | 3 | 4 |
| --- | --- | --- | --- |
| 2 | 3 | 3 | 4 |
| 3 | 4 | 4 | 5 |
| 4 | 5 | 5 | 6 |

 Then there are the following sub-squares that do not contain two neighboring cells with the same transparency coefficient:

* Each of the $16$ cells separately;
* A sub-square with the upper left corner at cell $(3, 1)$ and the lower right corner at cell $(4, 2)$;
* A sub-square with the upper left corner at cell $(2, 3)$ and the lower right corner at cell $(3, 4)$;
* A sub-square with the upper left corner at cell $(2, 1)$ and the lower right corner at cell $(3, 2)$;
* A sub-square with the upper left corner at cell $(3, 3)$ and the lower right corner at cell $(4, 4)$.

In the second example, after the first query, the transparency coefficients of the horizontal threads are $[1, 2, 2]$. After the second query, the transparency coefficients of the vertical threads are $[2, -4, 2]$.



#### tags 

#2900 #combinatorics #data_structures #implementation #math 