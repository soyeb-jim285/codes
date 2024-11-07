<h1 style='text-align: center;'> E. PermutationForces II</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $a$ of length $n$. Recall that permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order.

You have a strength of $s$ and perform $n$ moves on the permutation $a$. The $i$-th move consists of the following: 

* Pick two integers $x$ and $y$ such that $i \leq x \leq y \leq \min(i+s,n)$, and swap the positions of the integers $x$ and $y$ in the permutation $a$. ## Note

 that you can select $x=y$ in the operation, in which case no swap will occur.

You want to turn $a$ into another permutation $b$ after $n$ moves. However, some elements of $b$ are missing and are replaced with $-1$ instead. Count the number of ways to replace each $-1$ in $b$ with some integer from $1$ to $n$ so that $b$ is a permutation and it is possible to turn $a$ into $b$ with a strength of $s$. 

Since the answer can be large, output it modulo $998\,244\,353$.

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $s$ ($1 \leq n \leq 2 \cdot 10^5$; $1 \leq s \leq n$) — the size of the permutation and your strength, respectively.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — the elements of $a$. All elements of $a$ are distinct.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le n$ or $b_i = -1$) — the elements of $b$. All elements of $b$ that are not equal to $-1$ are distinct.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the number of ways to fill up the permutation $b$ so that it is possible to turn $a$ into $b$ using a strength of $s$, modulo $998\,244\,353$.

## Example

## Input


```

63 12 1 33 -1 -13 22 1 33 -1 -14 11 4 3 24 3 1 26 44 2 6 3 1 56 1 5 -1 3 -17 41 3 6 2 7 4 52 5 -1 -1 -1 4 -114 141 2 3 4 5 6 7 8 9 10 11 12 13 14-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
```
## Output


```

1
2
0
2
12
331032489

```
## Note

In the first test case, $a=[2,1,3]$. There are two possible ways to fill out the $-1$s in $b$ to make it a permutation: $[3,1,2]$ or $[3,2,1]$. We can make $a$ into $[3,1,2]$ with a strength of $1$ as follows: $$[2,1,3] \xrightarrow[x=1,\,y=1]{} [2,1,3] \xrightarrow[x=2,\,y=3]{} [3,1,2] \xrightarrow[x=3,\,y=3]{} [3,1,2].$$ It can be proven that it is impossible to make $[2,1,3]$ into $[3,2,1]$ with a strength of $1$. Thus only one permutation $b$ satisfies the constraints, so the answer is $1$.

In the second test case, $a$ and $b$ the same as the previous test case, but we now have a strength of $2$. We can make $a$ into $[3,2,1]$ with a strength of $2$ as follows: $$[2,1,3] \xrightarrow[x=1,\,y=3]{} [2,3,1] \xrightarrow[x=2,\,y=3]{} [3,2,1] \xrightarrow[x=3,\,y=3]{} [3,2,1].$$ We can still make $a$ into $[3,1,2]$ using a strength of $1$ as shown in the previous test case, so the answer is $2$. 

In the third test case, there is only one permutation $b$. It can be shown that it is impossible to turn $a$ into $b$, so the answer is $0$.



#### tags 

#2300 #brute_force #combinatorics #greedy #sortings #trees #two_pointers 