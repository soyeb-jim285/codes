<h1 style='text-align: center;'> D. Top-Notch Insertions</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Consider the insertion sort algorithm used to sort an integer sequence $[a_1, a_2, \ldots, a_n]$ of length $n$ in non-decreasing order.

For each $i$ in order from $2$ to $n$, do the following. If $a_i \ge a_{i-1}$, do nothing and move on to the next value of $i$. Otherwise, find the smallest $j$ such that $a_i < a_j$, shift the elements on positions from $j$ to $i-1$ by one position to the right, and write down the initial value of $a_i$ to position $j$. In this case we'll say that we performed an insertion of an element from position $i$ to position $j$.

It can be noticed that after processing any $i$, the prefix of the sequence $[a_1, a_2, \ldots, a_i]$ is sorted in non-decreasing order, therefore, the algorithm indeed sorts any sequence.

For example, sorting $[4, 5, 3, 1, 3]$ proceeds as follows: 

* $i = 2$: $a_2 \ge a_1$, do nothing;
* $i = 3$: $j = 1$, insert from position $3$ to position $1$: $[3, 4, 5, 1, 3]$;
* $i = 4$: $j = 1$, insert from position $4$ to position $1$: $[1, 3, 4, 5, 3]$;
* $i = 5$: $j = 3$, insert from position $5$ to position $3$: $[1, 3, 3, 4, 5]$.

You are given an integer $n$ and a list of $m$ integer pairs $(x_i, y_i)$. We are interested in sequences such that if you sort them using the above algorithm, exactly $m$ insertions will be performed: first from position $x_1$ to position $y_1$, then from position $x_2$ to position $y_2$, ..., finally, from position $x_m$ to position $y_m$.

How many sequences of length $n$ consisting of (not necessarily distinct) integers between $1$ and $n$, inclusive, satisfy the above condition? Print this number modulo $998\,244\,353$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($2 \le n \le 2 \cdot 10^5$; $0 \le m < n$) — the length of the sequence and the number of insertions.

The $i$-th of the following $m$ lines contains two integers $x_i$ and $y_i$ ($2 \le x_1 < x_2 < \ldots < x_m \le n$; $1 \le y_i < x_i$). These lines describe the sequence of insertions in chronological order.

It is guaranteed that the sum of $m$ over all test cases does not exceed $2 \cdot 10^5$. 
## Note

 that there is no constraint on the sum of $n$ of the same kind.

### Output

For each test case, print the number of sequences of length $n$ consisting of integers from $1$ to $n$ such that sorting them with the described algorithm produces the given sequence of insertions, modulo $998\,244\,353$.

## Example

### Input


```text
3
3 0
3 2
2 1
3 1
5 3
3 1
4 1
5 3
```
### Output


```text
10
1
21
```
## Note

In the first test case, the algorithm performs no insertions — therefore, the initial sequence is already sorted in non-decreasing order. There are $10$ such sequences: $[1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 2], [1, 2, 3], [1, 3, 3], [2, 2, 2], [2, 2, 3], [2, 3, 3], [3, 3, 3]$.

In the second test case, the only sequence satisfying the conditions is $[3, 2, 1]$.

In the third test case, $[4, 5, 3, 1, 3]$ is one of the sought sequences.



#### Tags 

#2600 #NOT OK #combinatorics #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_740_(Div._1,_based_on_VK_Cup_2021_-_Final_(Engine)).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
