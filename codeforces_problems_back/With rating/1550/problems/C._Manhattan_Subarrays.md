<h1 style='text-align: center;'> C. Manhattan Subarrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Suppose you have two points $p = (x_p, y_p)$ and $q = (x_q, y_q)$. Let's denote the Manhattan distance between them as $d(p, q) = |x_p - x_q| + |y_p - y_q|$.

Let's say that three points $p$, $q$, $r$ form a bad triple if $d(p, r) = d(p, q) + d(q, r)$.

Let's say that an array $b_1, b_2, \dots, b_m$ is good if it is impossible to choose three distinct indices $i$, $j$, $k$ such that the points $(b_i, i)$, $(b_j, j)$ and $(b_k, k)$ form a bad triple.

You are given an array $a_1, a_2, \dots, a_n$. Calculate the number of good subarrays of $a$. A subarray of the array $a$ is the array $a_l, a_{l + 1}, \dots, a_r$ for some $1 \le l \le r \le n$.

## Note

 that, according to the definition, subarrays of length $1$ and $2$ are good.

## Input

The first line contains one integer $t$ ($1 \le t \le 5000$) — the number of test cases.

The first line of each test case contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

It's guaranteed that the sum of $n$ doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print the number of good subarrays of array $a$.

## Example

## Input


```

3
4
2 4 1 3
5
6 9 1 9 6
2
13 37

```
## Output


```

10
12
3

```
## Note

In the first test case, it can be proven that any subarray of $a$ is good. For example, subarray $[a_2, a_3, a_4]$ is good since it contains only three elements and: 

* $d((a_2, 2), (a_4, 4)) = |4 - 3| + |2 - 4| = 3$ $<$ $d((a_2, 2), (a_3, 3)) + d((a_3, 3), (a_4, 4)) = 3 + 1 + 2 + 1 = 7$;
* $d((a_2, 2), (a_3, 3))$ $<$ $d((a_2, 2), (a_4, 4)) + d((a_4, 4), (a_3, 3))$;
* $d((a_3, 3), (a_4, 4))$ $<$ $d((a_3, 3), (a_2, 2)) + d((a_2, 2), (a_4, 4))$;

In the second test case, for example, subarray $[a_1, a_2, a_3, a_4]$ is not good, since it contains a bad triple $(a_1, 1)$, $(a_2, 2)$, $(a_4, 4)$: 

* $d((a_1, 1), (a_4, 4)) = |6 - 9| + |1 - 4| = 6$;
* $d((a_1, 1), (a_2, 2)) = |6 - 9| + |1 - 2| = 4$;
* $d((a_2, 2), (a_4, 4)) = |9 - 9| + |2 - 4| = 2$;

So, $d((a_1, 1), (a_4, 4)) = d((a_1, 1), (a_2, 2)) + d((a_2, 2), (a_4, 4))$.



#### tags 

#1700 #brute_force #geometry #greedy #implementation 