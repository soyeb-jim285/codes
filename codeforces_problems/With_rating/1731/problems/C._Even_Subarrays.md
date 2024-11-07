<h1 style='text-align: center;'> C. Even Subarrays</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer array $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$).

Find the number of subarrays of $a$ whose $\operatorname{XOR}$ has an even number of divisors. In other words, find all pairs of indices $(i, j)$ ($i \le j$) such that $a_i \oplus a_{i + 1} \oplus \dots \oplus a_j$ has an even number of divisors.

For example, numbers $2$, $3$, $5$ or $6$ have an even number of divisors, while $1$ and $4$ — odd. Consider that $0$ has an odd number of divisors in this task.

Here $\operatorname{XOR}$ (or $\oplus$) denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Print the number of subarrays but multiplied by 2022... Okay, let's stop. Just print the actual answer.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^4$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 2 \cdot 10^5$) — the length of the array $a$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. 

### Output

For each test case, print the number of subarrays, whose $\operatorname{XOR}$ has an even number of divisors.

## Example

### Input


```text
433 1 254 2 1 5 344 4 4 475 7 3 7 1 7 3
```
### Output

```text

4
11
0
20

```
## Note

In the first test case, there are $4$ subarrays whose $\operatorname{XOR}$ has an even number of divisors: $[3]$, $[3,1]$, $[1,2]$, $[2]$.

In the second test case, there are $11$ subarrays whose $\operatorname{XOR}$ has an even number of divisors: $[4,2]$, $[4,2,1]$, $[4,2,1,5]$, $[2]$, $[2,1]$, $[2,1,5]$, $[2,1,5,3]$, $[1,5,3]$, $[5]$, $[5,3]$, $[3]$.

In the third test case, there is no subarray whose $\operatorname{XOR}$ has an even number of divisors since $\operatorname{XOR}$ of any subarray is either $4$ or $0$.



#### Tags 

#1700 #NOT OK #bitmasks #brute_force #hashing #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_841_(Div._2)_and_Divide_by_Zero_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
