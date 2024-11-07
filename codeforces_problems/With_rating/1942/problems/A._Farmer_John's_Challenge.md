<h1 style='text-align: center;'> A. Farmer John's Challenge</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Trade Winds - Patrick Deng](https://soundcloud.com/patrick-deng-392681004/trade-winds-ft-alex-zhu)⠀Let's call an array $a$ sorted if $a_1 \leq a_2 \leq \ldots \leq a_{n - 1} \leq a_{n}$.

You are given two of Farmer John's favorite integers, $n$ and $k$. He challenges you to find any array $a_1, a_2, \ldots, a_{n}$ satisfying the following requirements:

* $1 \leq a_i \leq 10^9$ for each $1 \leq i \leq n$;
* Out of the $n$ total cyclic shifts of $a$, exactly $k$ of them are sorted.$^\dagger$

If there is no such array $a$, output $-1$.

$^\dagger$The $x$-th ($1 \leq x \leq n$) cyclic shift of the array $a$ is $a_x, a_{x+1} \ldots a_n, a_1, a_2 \ldots a_{x - 1}$. If $c_{x, i}$ denotes the $i$'th element of the $x$'th cyclic shift of $a$, exactly $k$ such $x$ should satisfy $c_{x,1} \leq c_{x,2} \leq \ldots \leq c_{x, n - 1} \leq c_{x, n}$.

For example, the cyclic shifts for $a = [1, 2, 3, 3]$ are the following:

* $x = 1$: $[1, 2, 3, 3]$ (sorted);
* $x = 2$: $[2, 3, 3, 1]$ (not sorted);
* $x = 3$: $[3, 3, 1, 2]$ (not sorted);
* $x = 4$: $[3, 1, 2, 3]$ (not sorted).
### Input

The first line contains $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

Each test case contains two integers $n$ and $k$ ($1 \leq k \leq n \leq 10^3$) — the length of $a$ and the number of sorted cyclic shifts $a$ must have.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^3$.

### Output

For each test case, print a single line: 

* if there is a valid array $a$, output $n$ integers, representing $a_1, a_2, \ldots, a_{n}$;
* otherwise, output $-1$.

If there are multiple solutions, print any of them.

## Example

### Input


```text
32 23 13 2
```
### Output

```text

1 1
69420 69 420
-1

```
## Note

In the first testcase, $a = [1, 1]$ satisfies $n = 2, k = 2$:

The two cyclic shifts of $a$ are $[a_1, a_2]$ and $[a_2, a_1]$, which are both $[1, 1]$ and are sorted.

In the second testcase, $a = [69\,420, 69, 420]$ satisfies $n = 3, k = 1$:

The three cyclic shifts of $a$ are $[a_1, a_2, a_3]$, $[a_2, a_3, a_1]$, $[a_3, a_1, a_2]$, which are $[69\,420, 69, 420]$, $[69, 420, 69\,420]$, and $[420, 69\,420, 69]$, respectively. 

Only $[69, 420, 69\,420]$ is sorted.



#### Tags 

#800 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../CodeTON_Round_8_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
