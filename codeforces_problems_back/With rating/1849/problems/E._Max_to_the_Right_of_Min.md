<h1 style='text-align: center;'> E. Max to the Right of Min</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of length $n$ — an array, consisting of integers from $1$ to $n$, all distinct.

Let $p_{l,r}$ denote a subarray — an array formed by writing down elements from index $l$ to index $r$, inclusive.

Let $\mathit{maxpos}_{l,r}$ denote the index of the maximum element on $p_{l,r}$. Similarly, let $\mathit{minpos}_{l,r}$ denote the index of the minimum element on it.

Calculate the number of subarrays $p_{l,r}$ such that $\mathit{maxpos}_{l,r} > \mathit{minpos}_{l,r}$.

## Input

The first line contains a single integer $n$ ($1 \le n \le 10^6$) — the number of elements in the permutation.

The second line contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \le p_i \le n$). All $p_i$ are distinct.

## Output

Print a single integer — the number of subarrays $p_{l,r}$ such that $\mathit{maxpos}_{l,r} > \mathit{minpos}_{l,r}$.

## Examples

## Input


```

3
1 2 3

```
## Output


```

3

```
## Input


```

6
5 3 6 1 4 2

```
## Output


```

4

```
## Input


```

10
5 1 6 2 8 3 4 10 9 7

```
## Output


```

38

```


#### tags 

#2300 #binary_search #data_structures #divide_and_conquer #dp #dsu #two_pointers 