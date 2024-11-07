<h1 style='text-align: center;'> E. Computing Machine</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sasha has two binary strings $s$ and $t$ of the same length $n$, consisting of the characters 0 and 1.

There is also a computing machine that can perform two types of operations on binary strings $a$ and $b$ of the same length $k$:

1. If $a_{i} = a_{i + 2} =$ 0, then you can assign $b_{i + 1} :=$ 1 ($1 \le i \le k - 2$).
2. If $b_{i} = b_{i + 2} =$ 1, then you can assign $a_{i + 1} :=$ 1 ($1 \le i \le k - 2$).

Sasha became interested in the following: if we consider the string $a=s_ls_{l+1}\ldots s_r$ and the string $b=t_lt_{l+1}\ldots t_r$, what is the maximum number of 1 characters in the string $a$ that can be obtained using the computing machine. Since Sasha is very curious but lazy, it is up to you to answer this question for several pairs $(l_i, r_i)$ that interest him.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^{4}$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the strings $s$ and $t$.

The second line of each test case contains a binary string $s$ of length $n$, consisting of the characters 0 and 1.

The third line of each test case contains a binary string $t$ of length $n$, consisting of the characters 0 and 1.

The fourth line of each test case contains a single integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of queries.

The $i$-th of the following lines contains two integers $l_{i}$ and $r_{i}$ ($1 \le l_{i} \le r_{i} \le n$) — the boundaries of the $i$-th pair of substrings that interest Sasha.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$ and the sum of $q$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output $q$ integers — the answers to all queries.

## Example

### Input


```text
341111000021 22 441010110121 31 4601010101101052 31 62 54 43 6
```
### Output

```text

2
3
2
3
1
4
3
1
2

```
## Note

In the first test case: 

* In the first query, $a =$ 11, so the maximum number of 1 characters is $2$.
* In the second query, $a =$ 111, so the maximum number of 1 characters is $3$.

In the second test case: 

* In the first query, $a =$ 101 and $b =$ 110. No operations can be performed, so the maximum number of 1 characters is $2$.
* In the second query, $a =$ 1010 and $b =$ 1101. Since $a_2 = a_4 =$ 0, we can assign $b_3 :=$ 1. Now $b_1 = b_3 =$ 1, so we can assign $a_2 :=$ 1. The string $a$ becomes 1110, so the maximum number of 1 characters is $3$.


#### Tags 

#2000 #NOT OK #brute_force #data_structures #dp #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_953_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
