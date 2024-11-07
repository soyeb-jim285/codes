<h1 style='text-align: center;'> D. Yet Another Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers $a_1, a_2, a_3, \ldots, a_n$.

You have to answer $q$ independent queries, each consisting of two integers $l$ and $r$. 

* Consider the subarray $a[l:r]$ $=$ $[a_l, a_{l+1}, \ldots, a_r]$. You can apply the following operation to the subarray any number of times (possibly zero)-
	1. Choose two integers $L$, $R$ such that $l \le L \le R \le r$ and $R - L + 1$ is odd.
	2. Replace each element in the subarray from $L$ to $R$ with the XOR of the elements in the subarray $[L, R]$.
* The answer to the query is the minimum number of operations required to make all elements of the subarray $a[l:r]$ equal to $0$ or $-1$ if it is impossible to make all of them equal to $0$.

You can find more details about XOR operation [here](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

## Input

The first line contains two integers $n$ and $q$ $(1 \le n, q \le 2 \cdot 10^5)$  — the length of the array $a$ and the number of queries.

The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ $(0 \le a_i \lt 2^{30})$  — the elements of the array $a$.

The $i$-th of the next $q$ lines contains two integers $l_i$ and $r_i$ $(1 \le l_i \le r_i \le n)$  — the description of the $i$-th query.

## Output

For each query, output a single integer  — the answer to that query.

## Example

## Input


```

7 6
3 0 3 3 1 2 3
3 4
4 6
3 7
5 6
1 6
2 2

```
## Output


```

-1
1
1
-1
2
0

```
## Note

In the first query, $l = 3, r = 4$, subarray = $[3, 3]$. We can apply operation only to the subarrays of length $1$, which won't change the array; hence it is impossible to make all elements equal to $0$.

In the second query, $l = 4, r = 6$, subarray = $[3, 1, 2]$. We can choose the whole subarray $(L = 4, R = 6)$ and replace all elements by their XOR $(3 \oplus 1 \oplus 2) = 0$, making the subarray $[0, 0, 0]$.

In the fifth query, $l = 1, r = 6$, subarray = $[3, 0, 3, 3, 1, 2]$. We can make the operations as follows: 

1. Choose $L = 4, R = 6$, making the subarray $[3, 0, 3, 0, 0, 0]$.
2. Choose $L = 1, R = 5$, making the subarray $[0, 0, 0, 0, 0, 0]$.


#### tags 

#1900 #binary_search #bitmasks #constructive_algorithms #data_structures 