<h1 style='text-align: center;'> B. Prefiquence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two binary strings $a$ and $b$. A binary string is a string consisting of the characters '0' and '1'.

Your task is to determine the maximum possible number $k$ such that a prefix of string $a$ of length $k$ is a subsequence of string $b$.

A sequence $a$ is a subsequence of a sequence $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) elements.

## Input

The first line consists of a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($1\le n,m \le 2 \cdot 10^5$) — the length of string $a$ and the length of string $b$, respectively.

The second line of each test case contains a binary string $a$ of length $n$.

The third line of each test case contains a binary string $b$ of length $m$.

It is guaranteed that the sum of values $n$ over all test cases does not exceed $2 \cdot 10^5$. Similarly, the sum of values $m$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single number — the maximum $k$, such that the first $k$ characters of $a$ form a subsequence of $b$.

## Example

## Input


```

65 41001111103 31001101 311114 4101111113 5100110103 11000
```
## Output


```

2
2
1
1
3
0

```
## Note

In the first example, the string '$10$' is a subsequence of '$1\color{red}11\color{red}0$' but the string '$100$' is not. So the answer is $2$.

In the fifth example, $a$='$100$', $b$='$1\color{red}{10}1\color{red}0$', whole string $a$ is a subsequence of string $b$. So the answer is $3$.

In the sixth example, string $b$ does not contain '$1$' so the answer is $0$.



#### tags 

#800 #greedy #two_pointers 