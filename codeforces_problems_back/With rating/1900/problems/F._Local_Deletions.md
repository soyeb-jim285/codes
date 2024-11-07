<h1 style='text-align: center;'> F. Local Deletions</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For an array $b_1, b_2, \ldots, b_m$, for some $i$ ($1 < i < m$), element $b_i$ is said to be a local minimum if $b_i < b_{i-1}$ and $b_i < b_{i+1}$. Element $b_1$ is said to be a local minimum if $b_1 < b_2$. Element $b_m$ is said to be a local minimum if $b_m < b_{m-1}$.

For an array $b_1, b_2, \ldots, b_m$, for some $i$ ($1 < i < m$), element $b_i$ is said to be a local maximum if $b_i > b_{i-1}$ and $b_i > b_{i+1}$. Element $b_1$ is said to be a local maximum if $b_1 > b_2$. Element $b_m$ is said to be a local maximum if $b_m > b_{m-1}$.

Let $x$ be an array of distinct elements. We define two operations on it:

* $1$ — delete all elements from $x$ that are not local minima.
* $2$ — delete all elements from $x$ that are not local maxima.

Define $f(x)$ as follows. Repeat operations $1, 2, 1, 2, \ldots$ in that order until you get only one element left in the array. Return that element.

For example, take an array $[1,3,2]$. We will first do type $1$ operation and get $[1, 2]$. Then we will perform type $2$ operation and get $[2]$. Therefore, $f([1,3,2]) = 2$.

You are given a permutation$^\dagger$ $a$ of size $n$ and $q$ queries. Each query consists of two integers $l$ and $r$ such that $1 \le l \le r \le n$. The query asks you to compute $f([a_l, a_{l+1}, \ldots, a_r])$. 

$^\dagger$ A permutation of length $n$ is an array of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$, but there is $4$ in the array).

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$) — the length of the permutation $a$ and the number of queries.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — the elements of permutation $a$.

The $i$-th of the next $q$ lines contains two integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le n$) — the description of $i$-th query.

## Output

For each query, output a single integer — the answer to that query.

## Examples

## Input


```

7 5
1 4 3 6 2 7 5
1 1
1 2
2 3
1 4
1 7

```
## Output


```

1
1
3
3
3

```
## Input


```

10 1
1 2 3 4 5 6 7 8 9 10
1 10

```
## Output


```

1

```
## Note

In the first query of the first example, the only number in the subarray is $1$, therefore it is the answer.

In the second query of the first example, our subarray initially looks like $[1, 4]$. After performing type $1$ operation we get $[1]$.

In the third query of the first example, our subarray initially looks like $[4, 3]$. After performing type $1$ operation we get $[3]$.

In the fourth query of the first example, our subarray initially looks like $[1, 4, 3, 6]$. After performing type $1$ operation we get $[1, 3]$. Then we perform type $2$ operation and we get $[3]$.

In the fifth query of the first example, our subarray initially looks like $[1, 4, 3, 6, 2, 7, 5]$. After performing type $1$ operation we get $[1,3,2,5]$. After performing type $2$ operation we get $[3,5]$. Then we perform type $1$ operation and we get $[3]$.

In the first and only query of the second example our subarray initially looks like $[1,2,3,4,5,6,7,8,9,10]$. Here $1$ is the only local minimum, so only it is left after performing type $1$ operation.



#### tags 

#2800 #binary_search #data_structures #implementation 