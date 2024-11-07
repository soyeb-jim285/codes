<h1 style='text-align: center;'> C. Freedom of Choice</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let's define the anti-beauty of a multiset $\{b_1, b_2, \ldots, b_{len}\}$ as the number of occurrences of the number $len$ in the multiset.

You are given $m$ multisets, where the $i$-th multiset contains $n_i$ distinct elements, specifically: $c_{i, 1}$ copies of the number $a_{i,1}$, $c_{i, 2}$ copies of the number $a_{i,2}, \ldots, c_{i, n_i}$ copies of the number $a_{i, n_i}$. It is guaranteed that $a_{i, 1} < a_{i, 2} < \ldots < a_{i, n_i}$. You are also given numbers $l_1, l_2, \ldots, l_m$ and $r_1, r_2, \ldots, r_m$ such that $1 \le l_i \le r_i \le c_{i, 1} + \ldots + c_{i, n_i}$.

Let's create a multiset $X$, initially empty. Then, for each $i$ from $1$ to $m$, you must perform the following action exactly once:

1. Choose some $v_i$ such that $l_i \le v_i \le r_i$
2. Choose any $v_i$ numbers from the $i$-th multiset and add them to the multiset $X$.

You need to choose $v_1, \ldots, v_m$ and the added numbers in such a way that the resulting multiset $X$ has the minimum possible anti-beauty.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $m$ ($1 \le m \le 10^5$) — the number of given multisets.

Then, for each $i$ from $1$ to $m$, a data block consisting of three lines is entered.

The first line of each block contains three integers $n_i, l_i, r_i$ ($1 \le n_i \le 10^5, 1 \le l_i \le r_i \le c_{i, 1} + \ldots + c_{i, n_i} \le 10^{17}$) — the number of distinct numbers in the $i$-th multiset and the limits on the number of elements to be added to $X$ from the $i$-th multiset.

The second line of the block contains $n_i$ integers $a_{i, 1}, \ldots, a_{i, n_i}$ ($1 \le a_{i, 1} < \ldots < a_{i, n_i} \le 10^{17}$) — the distinct elements of the $i$-th multiset.

The third line of the block contains $n_i$ integers $c_{i, 1}, \ldots, c_{i, n_i}$ ($1 \le c_{i, j} \le 10^{12}$) — the number of copies of the elements in the $i$-th multiset.

It is guaranteed that the sum of the values of $m$ for all test cases does not exceed $10^5$, and also the sum of $n_i$ for all blocks of all test cases does not exceed $10^5$.

## Output

For each test case, output the minimum possible anti-beauty of the multiset $X$ that you can achieve.

## Example

## Input


```

733 5 610 11 123 3 11 1 31242 4 412 131 517 1000 10061000 1001 1002 1003 1004 1005 1006147 145 143 143 143 143 14212 48 5048 5025 2521 1 1111 1 12111 1 11221 1 1112 1 11 21 124 8 1011 12 13 143 3 3 32 3 411 122 2
```
## Output


```

1
139
0
1
1
0
0

```
## Note

In the first test case, the multisets have the following form:

1. $\{10, 10, 10, 11, 11, 11, 12\}$. From this multiset, you need to select between $5$ and $6$ numbers.
2. $\{12, 12, 12, 12\}$. From this multiset, you need to select between $1$ and $3$ numbers.
3. $\{12, 13, 13, 13, 13, 13\}$. From this multiset, you need to select $4$ numbers.

You can select the elements $\{10, 11, 11, 11, 12\}$ from the first multiset, $\{12\}$ from the second multiset, and $\{13, 13, 13, 13\}$ from the third multiset. Thus, $X = \{10, 11, 11, 11, 12, 12, 13, 13, 13, 13\}$. The size of $X$ is $10$, the number $10$ appears exactly $1$ time in $X$, so the anti-beauty of $X$ is $1$. It can be shown that it is not possible to achieve an anti-beauty less than $1$.



#### tags 

#2000 #brute_force #greedy #implementation 