<h1 style='text-align: center;'> F. Pairwise Modulo</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ consisting of $n$ distinct positive integers, numbered from $1$ to $n$. Define $p_k$ as $$p_k = \sum_{1 \le i, j \le k} a_i \bmod a_j,$$ where $x \bmod y$ denotes the remainder when $x$ is divided by $y$. You have to find and print $p_1, p_2, \ldots, p_n$. 

## Input

The first line contains $n$ — the length of the array ($2 \le n \le 2 \cdot 10^5$).

The second line contains $n$ space-separated distinct integers $a_1, \ldots, a_n$ ($1 \le a_i \le 3 \cdot 10^5$, $a_i \neq a_j$ if $i \neq j$). 

## Output

Print $n$ integers $p_1, p_2, \ldots, p_n$. 

## Examples

## Input


```

4
6 2 7 3

```
## Output


```

0 2 12 22

```
## Input


```

3
3 2 1

```
## Output


```

0 3 5

```


#### tags 

#2300 #data_structures #math 