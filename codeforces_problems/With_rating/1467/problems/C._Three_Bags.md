<h1 style='text-align: center;'> C. Three Bags</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three bags. Each bag contains a non-empty multiset of numbers. You can perform a number of operations on these bags. In one operation, you can choose any two non-empty bags, and choose one number from each of the bags. Let's say that you choose number $a$ from the first bag and number $b$ from the second bag. Then, you remove $b$ from the second bag and replace $a$ with $a-b$ in the first bag. 
## Note

 that if there are multiple occurrences of these numbers, then you shall only remove/replace exactly one occurrence.

You have to perform these operations in such a way that you have exactly one number remaining in exactly one of the bags (the other two bags being empty). It can be shown that you can always apply these operations to receive such a configuration in the end. Among all these configurations, find the one which has the maximum number left in the end.

#### Input

The first line of the input contains three space-separated integers $n_1$, $n_2$ and $n_3$ ($1 \le n_1, n_2, n_3 \le 3\cdot10^5$, $1 \le n_1+n_2+n_3 \le 3\cdot10^5$) — the number of numbers in the three bags.

The $i$-th of the next three lines contain $n_i$ space-separated integers $a_{{i,1}}$, $a_{{i,2}}$, ..., $a_{{i,{{n_i}}}}$ ($1 \le a_{{i,j}} \le 10^9$) — the numbers in the $i$-th bag.

#### Output

Print a single integer — the maximum number which you can achieve in the end.

## Examples

#### Input


```text
2 4 1
1 2
6 3 4 5
5
```
#### Output


```text
20
```
#### Input

```text

3 2 2
7 5 4
2 9
7 1

```
#### Output


```text

29
```
## Note

In the first example input, let us perform the following operations:

$[1, 2], [6, 3, 4, 5], [5]$

$[-5, 2], [3, 4, 5], [5]$ (Applying an operation to $(1, 6)$)

$[-10, 2], [3, 4], [5]$ (Applying an operation to $(-5, 5)$)

$[2], [3, 4], [15]$ (Applying an operation to $(5, -10)$)

$[-1], [4], [15]$ (Applying an operation to $(2, 3)$)

$[-5], [], [15]$ (Applying an operation to $(-1, 4)$)

$[], [], [20]$ (Applying an operation to $(15, -5)$)

You can verify that you cannot achieve a bigger number. Hence, the answer is $20$.



#### Tags 

#1900 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_695_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
