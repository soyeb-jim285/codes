<h1 style='text-align: center;'> C. Largest Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given is a string $s$ of length $n$. In one operation you can select the lexicographically largest$^\dagger$ subsequence of string $s$ and cyclic shift it to the right$^\ddagger$. 

Your task is to calculate the minimum number of operations it would take for $s$ to become sorted, or report that it never reaches a sorted state.

$^\dagger$A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds:

* $a$ is a prefix of $b$, but $a \ne b$;
* In the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.

$^\ddagger$By cyclic shifting the string $t_1t_2\ldots t_m$ to the right, we get the string $t_mt_1\ldots t_{m-1}$.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the string $s$.

The second line of each test case contains a single string $s$ of length $n$, consisting of lowercase English letters.

It is guaranteed that sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimum number of operations required to make $s$ sorted, or $-1$ if it's impossible.

## Example

### Input


```text
65aaabc3acb3bac4zbca15czddeneeeemigec13cdefmopqsvxzz
```
### Output

```text

0
1
-1
2
6
0

```
## Note

In the first test case, the string $s$ is already sorted, so we need no operations.

In the second test case, doing one operation, we will select cb and cyclic shift it. The string $s$ is now abc which is sorted.

In the third test case, $s$ cannot be sorted.

In the fourth test case we will perform the following operations:

* The lexicographically largest subsequence is zca. Then $s$ becomes abzc.
* The lexicographically largest subsequence is zc. Then $s$ becomes abcz. The string becomes sorted.

Thus, we need $2$ operations.



#### Tags 

#1400 #NOT OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_915_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
