<h1 style='text-align: center;'> D. Tokitsukaze and Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tokitsukaze has a permutation $p$. She performed the following operation to $p$ exactly $k$ times: in one operation, for each $i$ from $1$ to $n - 1$ in order, if $p_i$ > $p_{i+1}$, swap $p_i$, $p_{i+1}$. After exactly $k$ times of operations, Tokitsukaze got a new sequence $a$, obviously the sequence $a$ is also a permutation.

After that, Tokitsukaze wrote down the value sequence $v$ of $a$ on paper. Denote the value sequence $v$ of the permutation $a$ of length $n$ as $v_i=\sum_{j=1}^{i-1}[a_i < a_j]$, where the value of $[a_i < a_j]$ define as if $a_i < a_j$, the value is $1$, otherwise is $0$ (in other words, $v_i$ is equal to the number of elements greater than $a_i$ that are to the left of position $i$). Then Tokitsukaze went out to work.

There are three naughty cats in Tokitsukaze's house. When she came home, she found the paper with the value sequence $v$ to be bitten out by the cats, leaving several holes, so that the value of some positions could not be seen clearly. She forgot what the original permutation $p$ was. She wants to know how many different permutations $p$ there are, so that the value sequence $v$ of the new permutation $a$ after exactly $k$ operations is the same as the $v$ written on the paper (not taking into account the unclear positions).

Since the answer may be too large, print it modulo $998\,244\,353$.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. Each test case consists of two lines.

The first line contains two integers $n$ and $k$ ($1 \leq n \leq 10^6$; $0 \leq k \leq n-1$) — the length of the permutation and the exactly number of operations.

The second line contains $n$ integers $v_1, v_2, \dots, v_n$ ($-1 \leq v_i \leq i-1$) — the value sequence $v$. $v_i = -1$ means the $i$-th position of $v$ can't be seen clearly.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, print a single integer — the number of different permutations modulo $998\,244\,353$.

## Example

### Input


```text
35 00 1 2 3 45 2-1 1 2 0 05 20 1 1 0 0
```
### Output

```text

1
6
6

```
## Note

In the first test case, only permutation $p=[5,4,3,2,1]$ satisfies the constraint condition.

In the second test case, there are $6$ permutations satisfying the constraint condition, which are:

* $[3,4,5,2,1]$ $\rightarrow$ $[3,4,2,1,5]$ $\rightarrow$ $[3,2,1,4,5]$
* $[3,5,4,2,1]$ $\rightarrow$ $[3,4,2,1,5]$ $\rightarrow$ $[3,2,1,4,5]$
* $[4,3,5,2,1]$ $\rightarrow$ $[3,4,2,1,5]$ $\rightarrow$ $[3,2,1,4,5]$
* $[4,5,3,2,1]$ $\rightarrow$ $[4,3,2,1,5]$ $\rightarrow$ $[3,2,1,4,5]$
* $[5,3,4,2,1]$ $\rightarrow$ $[3,4,2,1,5]$ $\rightarrow$ $[3,2,1,4,5]$
* $[5,4,3,2,1]$ $\rightarrow$ $[4,3,2,1,5]$ $\rightarrow$ $[3,2,1,4,5]$

So after exactly $2$ times of swap they will all become $a=[3,2,1,4,5]$, whose value sequence is $v=[0,1,2,0,0]$.



#### Tags 

#2500 #NOT OK #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_789_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
