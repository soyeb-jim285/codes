<h1 style='text-align: center;'> E. Splittable Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Initially, we had one array, which was a permutation of size $n$ (an array of size $n$ where each integer from $1$ to $n$ appears exactly once).

We performed $q$ operations. During the $i$-th operation, we did the following:

* choose any array we have with at least $2$ elements;
* split it into two non-empty arrays (prefix and suffix);
* write two integers $l_i$ and $r_i$, where $l_i$ is the maximum element in the left part which we get after the split, and $r_i$ is the maximum element in the right part;
* remove the array we've chosen from the pool of arrays we can use, and add the two resulting parts into the pool.

For example, suppose the initial array was $[6, 3, 4, 1, 2, 5]$, and we performed the following operations:

1. choose the array $[6, 3, 4, 1, 2, 5]$ and split it into $[6, 3]$ and $[4, 1, 2, 5]$. Then we write $l_1 = 6$ and $r_1 = 5$, and the arrays we have are $[6, 3]$ and $[4, 1, 2, 5]$;
2. choose the array $[4, 1, 2, 5]$ and split it into $[4, 1, 2]$ and $[5]$. Then we write $l_2 = 4$ and $r_2 = 5$, and the arrays we have are $[6, 3]$, $[4, 1, 2]$ and $[5]$;
3. choose the array $[4, 1, 2]$ and split it into $[4]$ and $[1, 2]$. Then we write $l_3 = 4$ and $r_3 = 2$, and the arrays we have are $[6, 3]$, $[4]$, $[1, 2]$ and $[5]$.

You are given two integers $n$ and $q$, and two sequences $[l_1, l_2, \dots, l_q]$ and $[r_1, r_2, \dots, r_q]$. A permutation of size $n$ is called valid if we can perform $q$ operations and produce the given sequences $[l_1, l_2, \dots, l_q]$ and $[r_1, r_2, \dots, r_q]$.

Calculate the number of valid permutations.

##### Input

The first line contains two integers $n$ and $q$ ($1 \le q < n \le 3 \cdot 10^5$).

The second line contains $q$ integers $l_1, l_2, \dots, l_q$ ($1 \le l_i \le n$).

The third line contains $q$ integers $r_1, r_2, \dots, r_q$ ($1 \le r_i \le n$).

Additional constraint on the input: there exists at least one permutation which can produce the given sequences $[l_1, l_2, \dots, l_q]$ and $[r_1, r_2, \dots, r_q]$.

##### Output

Print one integer — the number of valid permutations, taken modulo $998244353$.

## Examples

##### Input


```text
6 36 4 45 5 2
```
##### Output

```text

30

```
##### Input


```text
10 1109
```
##### Output

```text

1814400

```
##### Input


```text
4 124
```
##### Output

```text

8

```


#### Tags 

#2500 #NOT OK #combinatorics #data_structures #dfs_and_similar #greedy #math #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_166_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
