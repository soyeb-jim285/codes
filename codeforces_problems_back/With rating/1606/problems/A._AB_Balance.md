<h1 style='text-align: center;'> A. AB Balance</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$ consisting of characters a and/or b.

Let $\operatorname{AB}(s)$ be the number of occurrences of string ab in $s$ as a substring. Analogically, $\operatorname{BA}(s)$ is the number of occurrences of ba in $s$ as a substring.

In one step, you can choose any index $i$ and replace $s_i$ with character a or b.

What is the minimum number of steps you need to make to achieve $\operatorname{AB}(s) = \operatorname{BA}(s)$?

Reminder:

The number of occurrences of string $d$ in $s$ as substring is the number of indices $i$ ($1 \le i \le |s| - |d| + 1$) such that substring $s_i s_{i + 1} \dots s_{i + |d| - 1}$ is equal to $d$. For example, $\operatorname{AB}($aabbbabaa$) = 2$ since there are two indices $i$: $i = 2$ where aabbbabaa and $i = 6$ where aabbbabaa.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). Description of the test cases follows.

The first and only line of each test case contains a single string $s$ ($1 \le |s| \le 100$, where $|s|$ is the length of the string $s$), consisting only of characters a and/or b.

## Output

For each test case, print the resulting string $s$ with $\operatorname{AB}(s) = \operatorname{BA}(s)$ you'll get making the minimum number of steps.

If there are multiple answers, print any of them.

## Example

## Input


```

4
b
aabbbabaa
abbb
abbaab

```
## Output


```

b
aabbbabaa
bbbb
abbaaa
```
## Note

In the first test case, both $\operatorname{AB}(s) = 0$ and $\operatorname{BA}(s) = 0$ (there are no occurrences of ab (ba) in b), so can leave $s$ untouched.

In the second test case, $\operatorname{AB}(s) = 2$ and $\operatorname{BA}(s) = 2$, so you can leave $s$ untouched. 

In the third test case, $\operatorname{AB}(s) = 1$ and $\operatorname{BA}(s) = 0$. For example, we can change $s_1$ to b and make both values zero.

In the fourth test case, $\operatorname{AB}(s) = 2$ and $\operatorname{BA}(s) = 1$. For example, we can change $s_6$ to a and make both values equal to $1$.



#### tags 

#900 #strings 