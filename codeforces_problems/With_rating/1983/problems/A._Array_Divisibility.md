<h1 style='text-align: center;'> A. Array Divisibility</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array of integers $a_1,a_2,\cdots,a_n$ is beautiful subject to an integer $k$ if it satisfies the following: 

* The sum of $a_{j}$ over all $j$ such that $j$ is a multiple of $k$ and $1 \le j \le n $, itself, is a multiple of $k$.
* More formally, if $\sum_{k | j} a_{j}$ is divisible by $k$ for all $1 \le j \le n$ then the array $a$ is beautiful subject to $k$. Here, the notation ${k|j}$ means $k$ divides $j$, that is, $j$ is a multiple of $k$.

 Given $n$, find an array of positive nonzero integers, with each element less than or equal to $10^5$ that is beautiful subject to all $1 \le k \le n$.It can be shown that an answer always exists.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first and only line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the size of the array.

### Output

For each test case, print the required array as described in the problem statement.

## Example

### Input


```text
3
3
6
7
```
### Output


```text

4 22 18
10 6 15 32 125 54
23 18 27 36 5 66 7
```
## Note

In the second test case, when $n = 6$, for all integers $k$ such that $1 \le k \le 6$, let $S$ be the set of all indices of the array that are divisible by $k$.

* When $k = 1$, $S = \{1, 2, 3,4,5,6\}$ meaning $a_1+a_2+a_3+a_4+a_5+a_6=242$ must be divisible by $1$.
* When $k = 2$, $S = \{2,4,6\}$ meaning $a_2+a_4+a_6=92$ must be divisible by $2$.
* When $k = 3$, $S = \{3,6\}$ meaning $a_3+a_6=69$ must divisible by $3$.
* When $k = 4$, $S = \{4\}$ meaning $a_4=32$ must divisible by $4$.
* When $k = 5$, $S = \{5\}$ meaning $a_5=125$ must divisible by $5$.
* When $k = 6$, $S = \{6\}$ meaning $a_6=54$ must divisible by $6$.

 The array $a = [10, 6, 15, 32, 125, 54]$ satisfies all of the above conditions. Hence, $a$ is a valid array.

#### Tags 

#800 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_956_(Div._2)_and_ByteRace_2024.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
