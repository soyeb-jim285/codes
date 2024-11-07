<h1 style='text-align: center;'> B. Following the String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp lost the string $s$ of length $n$ consisting of lowercase Latin letters, but he still has its trace.

The trace of the string $s$ is an array $a$ of $n$ integers, where $a_i$ is the number of such indices $j$ ($j < i$) that $s_i=s_j$. For example, the trace of the string abracadabra is the array [$0, 0, 0, 1, 0, 2, 0, 3, 1, 1, 4$].

Given a trace of a string, find any string $s$ from which it could have been obtained. The string $s$ should consist only of lowercase Latin letters a-z.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the lost string.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i < n$) — the trace of the string. It is guaranteed that for the given trace, there exists a suitable string $s$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a string $s$ that corresponds to the given trace. If there are multiple such strings $s$, then output any of them.

The string $s$ should consist of lowercase Latin letters a-z.

It is guaranteed that for each test case, a valid answer exists.

## Example

### Input


```text
5110 0 0 1 0 2 0 3 1 1 4100 0 0 0 0 1 0 1 1 01080 1 2 3 4 5 6 780 0 0 0 0 0 0 0
```
### Output

```text

abracadabra
codeforces
a
aaaaaaaa
dijkstra

```


#### Tags 

#900 #OK #constructive_algorithms #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_923_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
