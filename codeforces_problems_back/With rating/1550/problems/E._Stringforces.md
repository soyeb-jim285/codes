<h1 style='text-align: center;'> E. Stringforces</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$. Each character is either one of the first $k$ lowercase Latin letters or a question mark.

You are asked to replace every question mark with one of the first $k$ lowercase Latin letters in such a way that the following value is maximized.

Let $f_i$ be the maximum length substring of string $s$, which consists entirely of the $i$-th Latin letter. A substring of a string is a contiguous subsequence of that string. If the $i$-th letter doesn't appear in a string, then $f_i$ is equal to $0$.

The value of a string $s$ is the minimum value among $f_i$ for all $i$ from $1$ to $k$.

What is the maximum value the string can have?

## Input

The first line contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$; $1 \le k \le 17$) — the length of the string and the number of first Latin letters used.

The second line contains a string $s$, consisting of $n$ characters. Each character is either one of the first $k$ lowercase Latin letters or a question mark.

## Output

Print a single integer — the maximum value of the string after every question mark is replaced with one of the first $k$ lowercase Latin letters.

## Examples

## Input


```

10 2
a??ab????b

```
## Output


```

4

```
## Input


```

9 4
?????????

```
## Output


```

2

```
## Input


```

2 3
??

```
## Output


```

0

```
## Input


```

15 3
??b?babbc??b?aa

```
## Output


```

3

```
## Input


```

4 4
cabd

```
## Output


```

1

```
## Note

In the first example the question marks can be replaced in the following way: "aaaababbbb". $f_1 = 4$, $f_2 = 4$, thus the answer is $4$. Replacing it like this is also possible: "aaaabbbbbb". That way $f_1 = 4$, $f_2 = 6$, however, the minimum of them is still $4$.

In the second example one of the possible strings is "aabbccdda".

In the third example at least one letter won't appear in the string, thus, the minimum of values $f_i$ is always $0$.



#### tags 

#2500 #binary_search #bitmasks #brute_force #dp #strings #two_pointers 