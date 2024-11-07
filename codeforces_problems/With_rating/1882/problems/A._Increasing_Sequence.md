<h1 style='text-align: center;'> A. Increasing Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence $a_{1}, a_{2}, \ldots, a_{n}$. A sequence $b_{1}, b_{2}, \ldots, b_{n}$ is called good, if it satisfies all of the following conditions: 

* $b_{i}$ is a positive integer for $i = 1, 2, \ldots, n$;
* $b_{i} \neq a_{i}$ for $i = 1, 2, \ldots, n$;
* $b_{1} < b_{2} < \ldots < b_{n}$.

 Find the minimum value of $b_{n}$ among all good sequences $b_{1}, b_{2}, \ldots, b_{n}$.
### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^{9}$).

### Output

For each test case, print a single integer — the minimum value of $b_{n}$ among all good sequences $b$.

## Example

### Input


```text
351 3 2 6 742 3 4 511
```
### Output

```text

8
4
2

```
## Note

In the first test case, $b = [2, 4, 5, 7, 8]$ is a good sequence. It can be proved that there is no good $b$ with $b_{5} < 8$.

In the second test case, $b = [1, 2, 3, 4]$ is an optimal good sequence.

In the third test case, $b = [2]$ is an optimal good sequence.



#### Tags 

#800 #OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_899_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
