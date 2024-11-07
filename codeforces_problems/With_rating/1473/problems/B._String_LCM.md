<h1 style='text-align: center;'> B. String LCM</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's define a multiplication operation between a string $a$ and a positive integer $x$: $a \cdot x$ is the string that is a result of writing $x$ copies of $a$ one after another. For example, "abc" $\cdot~2~=$ "abcabc", "a" $\cdot~5~=$ "aaaaa".

A string $a$ is divisible by another string $b$ if there exists an integer $x$ such that $b \cdot x = a$. For example, "abababab" is divisible by "ab", but is not divisible by "ababab" or "aa".

LCM of two strings $s$ and $t$ (defined as $LCM(s, t)$) is the shortest non-empty string that is divisible by both $s$ and $t$.

You are given two strings $s$ and $t$. Find $LCM(s, t)$ or report that it does not exist. It can be shown that if $LCM(s, t)$ exists, it is unique.

### Input

The first line contains one integer $q$ ($1 \le q \le 2000$) — the number of test cases.

Each test case consists of two lines, containing strings $s$ and $t$ ($1 \le |s|, |t| \le 20$). Each character in each of these strings is either 'a' or 'b'.

### Output

For each test case, print $LCM(s, t)$ if it exists; otherwise, print -1. It can be shown that if $LCM(s, t)$ exists, it is unique.

## Example

### Input


```text
3
baba
ba
aa
aaa
aba
ab
```
### Output


```text
baba
aaaaaa
-1
```
## Note

In the first test case, "baba" = "baba" $\cdot~1~=$ "ba" $\cdot~2$.

In the second test case, "aaaaaa" = "aa" $\cdot~3~=$ "aaa" $\cdot~2$.



#### Tags 

#1000 #NOT OK #brute_force #math #number_theory #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_102_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
