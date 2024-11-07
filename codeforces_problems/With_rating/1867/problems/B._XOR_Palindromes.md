<h1 style='text-align: center;'> B. XOR Palindromes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$ of length $n$ (a string that consists only of $0$ and $1$). A number $x$ is good if there exists a binary string $l$ of length $n$, containing $x$ ones, such that if each symbol $s_i$ is replaced by $s_i \oplus l_i$ (where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR)), then the string $s$ becomes a palindrome.

You need to output a binary string $t$ of length $n+1$, where $t_i$ ($0 \leq i \leq n$) is equal to $1$ if number $i$ is good, and $0$ otherwise.

A palindrome is a string that reads the same from left to right as from right to left. For example, 01010, 1111, 0110 are palindromes.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains a binary string $s$ of length $n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output a single line containing a binary string $t$ of length $n+1$ - the answer to the problem.

## Example

### Input


```text
561010115000009100100011310011
```
### Output

```text

0010100
111111
0011111100
0110
11

```
## Note

Consider the first example. 

* $t_2 = 1$ because we can choose $l = $ 010100, then the string $s$ becomes 111111, which is a palindrome.
* $t_4 = 1$ because we can choose $l = $ 101011.
* It can be shown that for all other $i$, there is no answer, so the remaining symbols are $0$.


#### Tags 

#1100 #OK #bitmasks #constructive_algorithms #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_897_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
