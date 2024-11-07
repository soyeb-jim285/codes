<h1 style='text-align: center;'> B. Two Binary Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $a$ and $b$ of equal length, consisting of only characters 0 and/or 1; both strings start with character 0 and end with character 1. 

You can perform the following operation any number of times (possibly zero): 

* choose one of the strings and two equal characters in it; then turn all characters between them into those characters.

Formally, you choose one of these two strings (let the chosen string be $s$), then pick two integers $l$ and $r$ such that $1 \le l < r \le |s|$ and $s_l = s_r$, then replace every character $s_i$ such that $l < i < r$ with $s_l$.

For example, if the chosen string is 010101, you can transform it into one of the following strings by applying one operation:

* 000101 if you choose $l = 1$ and $r = 3$;
* 000001 if you choose $l = 1$ and $r = 5$;
* 010001 if you choose $l = 3$ and $r = 5$;
* 010111 if you choose $l = 4$ and $r = 6$;
* 011111 if you choose $l = 2$ and $r = 6$;
* 011101 if you choose $l = 2$ and $r = 4$.

You have to determine if it's possible to make the given strings equal by applying this operation any number of times.

### Input

The first line contains a single integer $t$ ($1 \le t \le 2000$)  — the number of test cases.

Each test case consists of two lines: 

* the first line contains the string $a$ ($2 \le |a| \le 5000$), consisting of only characters 0 and/or 1.
* the second line contains the string $b$ ($2 \le |b| \le 5000$), consisting of only characters 0 and/or 1.

Additional constraints on the input: 

* in each test case, $|a| = |b|$ (the strings have equal length);
* in each test case, both strings start with 0 and end with 1;
* the total length of all strings $a$ in all test cases does not exceed $5000$.
### Output

For each test case, print YES if it is possible to make the strings equal. Otherwise, print NO. You can print each letter in any register.

## Example

### Input


```text
7010100010111010101001010010001010101110000101111011001001001011011010001011011
```
### Output

```text

YES
YES
YES
NO
NO
NO
YES

```
## Note

In the first test case, we can perform the following operations: 

1. choose the string $a$, $l = 2$, $r = 4$; after this operation, $a$ is 01110001, $b$ is 01110101;
2. choose the string $b$, $l = 5$, $r = 7$; after this operation, $a$ is 01110001, $b$ is 01110001.

In the second test case, the strings are already equal.

In the third test case, we can perform the following operations: 

1. choose the string $a$, $l = 4$, $r = 6$; after this operation, $a$ is 000111, $b$ is 010111;
2. choose the string $b$, $l = 1$, $r = 3$; after this operation, $a$ is 000111, $b$ is 000111;

In the fourth and fifth test cases, it's impossible to make the given strings equal.



#### Tags 

#1000 #OK #constructive_algorithms #dp #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_154_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
