<h1 style='text-align: center;'> B. Xor of 3</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence $a$ of length $n$ consisting of $0$s and $1$s.

You can perform the following operation on this sequence: 

* Pick an index $i$ from $1$ to $n-2$ (inclusive).
* Change all of $a_{i}$, $a_{i+1}$, $a_{i+2}$ to $a_{i} \oplus a_{i+1} \oplus a_{i+2}$ simultaneously, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR)

 Find a sequence of at most $n$ operations that changes all elements of $a$ to $0$s or report that it's impossible.We can prove that if there exists a sequence of operations of any length that changes all elements of $a$ to $0$s, then there is also such a sequence of length not greater than $n$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$).

The first line of each test case contains a single integer $n$ ($3 \le n \le 2\cdot10^5$) — the length of $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($a_i = 0$ or $a_i = 1$) — elements of $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot10^5$.

### Output

For each test case, do the following: 

* if there is no way of making all the elements of $a$ equal to $0$ after performing the above operation some number of times, print "NO".
* otherwise, in the first line print "YES", in the second line print $k$ ($0 \le k \le n$) — the number of operations that you want to perform on $a$, and in the third line print a sequence $b_1, b_2, \dots, b_k$ ($1 \le b_i \le n - 2$) — the indices on which the operation should be applied.

If there are multiple solutions, you may print any.

## Example

### Input


```text
3
3
0 0 0
5
1 1 1 1 0
4
1 0 0 1
```
### Output


```text
YES
0
YES
2
3 1
NO
```
## Note

In the first example, the sequence contains only $0$s so we don't need to change anything.

In the second example, we can transform $[1, 1, 1, 1, 0]$ to $[1, 1, 0, 0, 0]$ and then to $[0, 0, 0, 0, 0]$ by performing the operation on the third element of $a$ and then on the first element of $a$.

In the third example, no matter whether we first perform the operation on the first or on the second element of $a$ we will get $[1, 1, 1, 1]$, which cannot be transformed to $[0, 0, 0, 0]$.



#### Tags 

#2500 #NOT OK #brute_force #constructive_algorithms #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_743_(Div._1).md)
- [Codeforces Round #743 (en)](../blogs/Codeforces_Round_743_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
