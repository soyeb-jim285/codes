<h1 style='text-align: center;'> F. LIS?</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Entering senior high school life, Tom is attracted by LIS problems, not only the Longest Increasing Subsequence problem, but also the Largest Interval Sum problem. Now he gets a really interesting problem from his friend Daniel. However, it seems too hard for him to solve it, so he asks you for help.

Given an array $a$ consisting of $n$ integers.

In one operation, you do the following: 

* Select an interval $[l,r]$ ($1\le l\le r\le n$), such that the sum of the interval is the largest among all intervals in the array $a$. More formally, $\displaystyle\sum_{i=l}^r a_i=\max_{1\le l'\le r'\le n}\sum_{i=l'}^{r'} a_i$.
* Then subtract $1$ from all elements $a_l,a_{l+1},\ldots,a_r$.

Find the minimum number of operations you need to perform to make $a_i<0$ for every $1\le i\le n$.

## Input

The first line of input contains a single integer $n$ ($1 \le n \le 5 \cdot 10^5$) — the length of the array $a$.

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($-10^6\le a_i\le 10^6$) — the elements of the array $a$.

## Output

Print a single integer — the minimum number of operations.

## Examples

## Input


```

5
1 2 3 4 5

```
## Output


```

6

```
## Input


```

6
-1 -5 -4 -1 -4 -7

```
## Output


```

0

```
## Input


```

11
0 1000000 1 -50000 2 998353 3 -100007 4 200943 0

```
## Output


```

1936973

```
## Note

In the first example, you can do operations on intervals $[1,5],[1,5],[2,5],[3,5],[4,5],[5,5]$ in such order. You may also do operations on intervals $[1,5],[2,5],[3,5],[4,5],[5,5],[1,5]$ in such order.

In the second example, it's already satisfied that $a_i<0$ for every $1\le i\le n$. So you do not need to perform any operations.



#### tags 

#3500 #data_structures #greedy #implementation 