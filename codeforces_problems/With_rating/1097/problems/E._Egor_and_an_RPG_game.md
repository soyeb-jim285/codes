<h1 style='text-align: center;'> E. Egor and an RPG game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One Saturday afternoon Egor was playing his favorite RPG game. While discovering new lands and territories, he came across the following sign:

 ![](images/d337946654aa58d1548d48f8c110c1200fd60fdf.png) Egor is a passionate player, but he is an algorithmician as well. That's why he instantly spotted four common letters in two words on the sign above — if we permute the letters "R", "E", "G", "O" from the first word, we can obtain the letters "O", "G", "R", "E". Egor got inspired by the sign and right away he came up with a problem about permutations.

You are given a permutation of length $n$. You have to split it into some non-empty subsequences so that each element of the permutation belongs to exactly one subsequence. Each subsequence must be monotonic — that is, either increasing or decreasing.

Sequence is called to be a subsequence if it can be derived from permutation by deleting some (possibly none) elements without changing the order of the remaining elements.

The number of subsequences should be small enough — let $f(n)$ be the minimum integer $k$ such that every permutation of length $n$ can be partitioned into at most $k$ monotonic subsequences.

You need to split the permutation into at most $f(n)$ monotonic subsequences.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases.

You can only use $t = 1$ in hacks.

Next, descriptions of $t$ test cases come, each of them in the following format.

The first line of a single test case contains one integer $n$ ($1 \leq n \leq 10^5$) — the length of the permutation. The second line contains $n$ distinct integers $a_i$ ($1 \leq a_i \leq n$) — the permutation itself.

The sum of the values of $n$ over all test cases doesn't exceed $10^5$.

### Output

For each test case print the answer in the following format:

In the first line print $k$ ($1 \leq k \leq f(n)$) — the number of the subsequences in the partition. In the next $k$ lines, print the descriptions of found subsequences. Each description should start with a number $l_i$ ($1 \leq l_i \leq n$) — the length of the corresponding subsequence, followed by $l_i$ integers — the values of this subsequence in the order in which they occur in the permutation.

Each subsequence you output must be either increasing or decreasing. 

In case there are multiple possible answers, print any of them.

## Example

### Input


```text
3
4
4 3 1 2
6
4 5 6 1 3 2
10
1 2 3 4 5 6 7 8 9 10
```
### Output


```text
2
3 4 3 1
1 2
3
2 4 1
2 5 6
2 3 2
1
10 1 2 3 4 5 6 7 8 9 10
```
## Note

In the example, we can split:

* $[4, 3, 1, 2]$ into $[4, 3, 1]$, $[2]$
* $[4, 5, 6, 1, 3, 2]$ into $[4, 1]$, $[5, 6]$ and $[3, 2]$
* $[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]$ into $[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]$

Surely, there are many more answers possible.



#### Tags 

#3400 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Hello_2019.md)
- [a (en)](../blogs/a_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
