<h1 style='text-align: center;'> F. Bicolored Segments</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ segments $[l_1, r_1], [l_2, r_2], \dots, [l_n, r_n]$. Each segment has one of two colors: the $i$-th segment's color is $t_i$.

Let's call a pair of segments $i$ and $j$ bad if the following two conditions are met:

* $t_i \ne t_j$;
* the segments $[l_i, r_i]$ and $[l_j, r_j]$ intersect, embed or touch, i. e. there exists an integer $x$ such that $x \in [l_i, r_i]$ and $x \in [l_j, r_j]$.

Calculate the maximum number of segments that can be selected from the given ones, so that there is no bad pair among the selected ones.

## Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — number of segments.

The next $n$ lines contains three integers $l_i, r_i, t_i$ ($1 \le l_i \le r_i \le 10^9; t_i \in \{1, 2\}$) — description of the $i$-th segment.

## Output

Print the maximum number of segments that can be selected, so that there is no bad pair among the selected segments.

## Examples

## Input


```

3
1 3 1
4 6 2
2 5 1

```
## Output


```

2

```
## Input


```

5
5 8 1
1 3 2
3 4 2
6 6 1
2 10 2

```
## Output


```

4

```
## Input


```

7
19 20 1
13 15 2
6 11 2
4 10 1
14 17 1
13 13 2
5 9 1

```
## Output


```

5

```


#### tags 

#2600 #data_structures #dp #graph_matchings #sortings 