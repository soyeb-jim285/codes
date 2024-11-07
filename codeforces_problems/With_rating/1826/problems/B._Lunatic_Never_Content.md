<h1 style='text-align: center;'> B. Lunatic Never Content</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ of $n$ non-negative integers. Let's define $f(a, x) = [a_1 \bmod x, a_2 \bmod x, \dots, a_n \bmod x]$ for some positive integer $x$. Find the biggest $x$, such that $f(a, x)$ is a palindrome.

Here, $a \bmod x$ is the remainder of the integer division of $a$ by $x$.

An array is a palindrome if it reads the same backward as forward. More formally, an array $a$ of length $n$ is a palindrome if for every $i$ ($1 \leq i \leq n$) $a_i = a_{n - i + 1}$.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$).

The second line of each test case contains $n$ integers $a_i$ ($0 \leq a_i \leq 10^9$).

It's guaranteed that the sum of all $n$ does not exceed $10^5$.

### Output

For each test case output the biggest $x$, such that $f(a, x)$ is a palindrome. If $x$ can be infinitely large, output $0$ instead.

## Example

### Input


```text
421 283 0 1 2 0 3 2 1103100 1 1000000000
```
### Output

```text

1
2
0
999999900

```
## Note

In the first example, $f(a, x = 1) = [0, 0]$ which is a palindrome.

In the second example, $f(a, x = 2) = [1, 0, 1, 0, 0, 1, 0, 1]$ which is a palindrome.

It can be proven that in the first two examples, no larger $x$ satisfies the condition.

In the third example, $f(a, x) = [0]$ for any $x$, so we can choose it infinitely large, so the answer is $0$.



#### Tags 

#1100 #OK #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_870_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
