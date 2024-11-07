<h1 style='text-align: center;'> A. Divisible Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$. Please find an array $a_1, a_2, \ldots, a_n$ that is perfect.

A perfect array $a_1, a_2, \ldots, a_n$ satisfies the following criteria: 

* $1 \le a_i \le 1000$ for all $1 \le i \le n$.
* $a_i$ is divisible by $i$ for all $1 \le i \le n$.
* $a_1 + a_2 + \ldots + a_n$ is divisible by $n$.
### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 200$). The description of the test cases follows.

The only line of each test case contains a single positive integer $n$ ($1 \le n \le 200$) — the length of the array $a$.

### Output

For each test case, output an array $a_1, a_2, \ldots, a_n$ that is perfect.

We can show that an answer always exists. If there are multiple solutions, print any.

## Example

### Input


```text
71234567
```
### Output

```text

1
2 4
1 2 3
2 8 6 4
3 4 9 4 5
1 10 18 8 5 36
3 6 21 24 10 6 14

```
## Note

In the third test case: 

* $a_1 = 1$ is divisible by $1$.
* $a_2 = 2$ is divisible by $2$.
* $a_3 = 3$ is divisible by $3$.
* $a_1 + a_2 + a_3 = 1 + 2 + 3 = 6$ is divisible by $3$.

In the fifth test case: 

* $a_1 = 3$ is divisible by $1$.
* $a_2 = 4$ is divisible by $2$.
* $a_3 = 9$ is divisible by $3$.
* $a_4 = 4$ is divisible by $4$.
* $a_5 = 5$ is divisible by $5$.
* $a_1 + a_2 + a_3 + a_4 + a_5 = 3 + 4 + 9 + 4 + 5 = 25$ is divisible by $5$.


#### Tags 

#800 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_873_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
