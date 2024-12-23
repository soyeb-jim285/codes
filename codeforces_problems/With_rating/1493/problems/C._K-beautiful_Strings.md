<h1 style='text-align: center;'> C. K-beautiful Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of lowercase English letters and a number $k$. Let's call a string consisting of lowercase English letters beautiful if the number of occurrences of each letter in that string is divisible by $k$. You are asked to find the lexicographically smallest beautiful string of length $n$, which is lexicographically greater or equal to string $s$. If such a string does not exist, output $-1$.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
### Input

The first line contains a single integer $T$ ($1 \le T \le 10\,000$) — the number of test cases.

The next $2 \cdot T$ lines contain the description of test cases. The description of each test case consists of two lines.

The first line of the description contains two integers $n$ and $k$ ($1 \le k \le n \le 10^5$) — the length of string $s$ and number $k$ respectively.

The second line contains string $s$ consisting of lowercase English letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case output in a separate line lexicographically smallest beautiful string of length $n$, which is greater or equal to string $s$, or $-1$ if such a string does not exist.

## Example

### Input


```text
4
4 2
abcd
3 1
abc
4 3
aaaa
9 3
abaabaaaa
```
### Output


```text
acac
abc
-1
abaabaaab
```
## Note

In the first test case "acac" is greater than or equal to $s$, and each letter appears $2$ or $0$ times in it, so it is beautiful.

In the second test case each letter appears $0$ or $1$ times in $s$, so $s$ itself is the answer.

We can show that there is no suitable string in the third test case.

In the fourth test case each letter appears $0$, $3$, or $6$ times in "abaabaaab". All these integers are divisible by $3$.



#### Tags 

#2000 #NOT OK #binary_search #brute_force #constructive_algorithms #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_705_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
