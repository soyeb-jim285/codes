<h1 style='text-align: center;'> C. Perfect Triples</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider the infinite sequence $s$ of positive integers, created by repeating the following steps:

1. Find the lexicographically smallest triple of positive integers $(a, b, c)$ such that
	* $a \oplus b \oplus c = 0$, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).
	* $a$, $b$, $c$ are not in $s$. Here triple of integers $(a_1, b_1, c_1)$ is considered to be lexicographically smaller than triple $(a_2, b_2, c_2)$ if sequence $[a_1, b_1, c_1]$ is lexicographically smaller than sequence $[a_2, b_2, c_2]$.
2. Append $a$, $b$, $c$ to $s$ in this order.
3. Go back to the first step.

You have integer $n$. Find the $n$-th element of $s$.

You have to answer $t$ independent test cases.

A sequence $a$ is lexicographically smaller than a sequence $b$ if in the first position where $a$ and $b$ differ, the sequence $a$ has a smaller element than the corresponding element in $b$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases.

Each of the next $t$ lines contains a single integer $n$ ($1\le n \le 10^{16}$) — the position of the element you want to know.

### Output

In each of the $t$ lines, output the answer to the corresponding test case.

## Example

### Input


```text
9
1
2
3
4
5
6
7
8
9
```
### Output


```text
1
2
3
4
8
12
5
10
15
```
## Note

The first elements of $s$ are $1, 2, 3, 4, 8, 12, 5, 10, 15, \dots $



#### Tags 

#2200 #NOT OK #bitmasks #brute_force #constructive_algorithms #divide_and_conquer #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_633_(Div._1).md)
- [Codeforces Round #633 (en)](../blogs/Codeforces_Round_633_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
