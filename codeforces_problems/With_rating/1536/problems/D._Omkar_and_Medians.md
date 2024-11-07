<h1 style='text-align: center;'> D. Omkar and Medians</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Uh oh! Ray lost his array yet again! However, Omkar might be able to help because he thinks he has found the OmkArray of Ray's array. The OmkArray of an array $a$ with elements $a_1, a_2, \ldots, a_{2k-1}$, is the array $b$ with elements $b_1, b_2, \ldots, b_{k}$ such that $b_i$ is equal to the median of $a_1, a_2, \ldots, a_{2i-1}$ for all $i$. Omkar has found an array $b$ of size $n$ ($1 \leq n \leq 2 \cdot 10^5$, $-10^9 \leq b_i \leq 10^9$). Given this array $b$, Ray wants to test Omkar's claim and see if $b$ actually is an OmkArray of some array $a$. Can you help Ray?

The median of a set of numbers $a_1, a_2, \ldots, a_{2i-1}$ is the number $c_{i}$ where $c_{1}, c_{2}, \ldots, c_{2i-1}$ represents $a_1, a_2, \ldots, a_{2i-1}$ sorted in nondecreasing order. 

#### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of the array $b$.

The second line contains $n$ integers $b_1, b_2, \ldots, b_n$ ($-10^9 \leq b_i \leq 10^9$) — the elements of $b$.

It is guaranteed the sum of $n$ across all test cases does not exceed $2 \cdot 10^5$. 

#### Output

For each test case, output one line containing YES if there exists an array $a$ such that $b_i$ is the median of $a_1, a_2, \dots, a_{2i-1}$ for all $i$, and NO otherwise. The case of letters in YES and NO do not matter (so yEs and No will also be accepted).

## Examples

#### Input


```text
5
4
6 2 1 3
1
4
5
4 -8 5 6 -7
2
3 3
4
2 1 2 3
```
#### Output


```text
NO
YES
NO
YES
YES
```
#### Input


```text
5
8
-8 2 -6 -5 -4 3 3 2
7
1 1 3 1 0 -2 -1
7
6 12 8 6 2 6 10
6
5 1 2 3 6 7
5
1 3 4 3 0
```
#### Output


```text
NO
YES
NO
NO
NO
```
## Note

In the second case of the first sample, the array $[4]$ will generate an OmkArray of $[4]$, as the median of the first element is $4$.

In the fourth case of the first sample, the array $[3, 2, 5]$ will generate an OmkArray of $[3, 3]$, as the median of $3$ is $3$ and the median of $2, 3, 5$ is $3$.

In the fifth case of the first sample, the array $[2, 1, 0, 3, 4, 4, 3]$ will generate an OmkArray of $[2, 1, 2, 3]$ as 

* the median of $2$ is $2$
* the median of $0, 1, 2$ is $1$
* the median of $0, 1, 2, 3, 4$ is $2$
* and the median of $0, 1, 2, 3, 3, 4, 4$ is $3$.

In the second case of the second sample, the array $[1, 0, 4, 3, 5, -2, -2, -2, -4, -3, -4, -1, 5]$ will generate an OmkArray of $[1, 1, 3, 1, 0, -2, -1]$, as 

* the median of $1$ is $1$
* the median of $0, 1, 4$ is $1$
* the median of $0, 1, 3, 4, 5$ is $3$
* the median of $-2, -2, 0, 1, 3, 4, 5$ is $1$
* the median of $-4, -2, -2, -2, 0, 1, 3, 4, 5$ is $0$
* the median of $-4, -4, -3, -2, -2, -2, 0, 1, 3, 4, 5$ is $-2$
* and the median of $-4, -4, -3, -2, -2, -2, -1, 0, 1, 3, 4, 5, 5$ is $-1$

For all cases where the answer is NO, it can be proven that it is impossible to find an array $a$ such that $b$ is the OmkArray of $a$.



#### Tags 

#2000 #NOT OK #data_structures #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_724_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
