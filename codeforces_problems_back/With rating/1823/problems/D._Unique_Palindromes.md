<h1 style='text-align: center;'> D. Unique Palindromes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A palindrome is a string that reads the same backwards as forwards. For example, the string abcba is palindrome, while the string abca is not.

Let $p(t)$ be the number of unique palindromic substrings of string $t$, i. e. the number of substrings $t[l \dots r]$ that are palindromes themselves. Even if some substring occurs in $t$ several times, it's counted exactly once. (The whole string $t$ is also counted as a substring of $t$).

For example, string $t$ $=$ abcbbcabcb has $p(t) = 6$ unique palindromic substrings: a, b, c, bb, bcb and cbbc.

Now, let's define $p(s, m) = p(t)$ where $t = s[1 \dots m]$. In other words, $p(s, m)$ is the number of palindromic substrings in the prefix of $s$ of length $m$. For example, $p($abcbbcabcb$, 5)$ $=$ $p($abcbb$) = 5$.

You are given an integer $n$ and $k$ "conditions" ($k \le 20$). Let's say that string $s$, consisting of $n$ lowercase Latin letters, is good if all $k$ conditions are satisfied at the same time. A condition is a pair $(x_i, c_i)$ and have the following meaning: 

* $p(s, x_i) = c_i$, i. e. a prefix of $s$ of length $x_i$ contains exactly $c_i$ unique palindromic substrings.

 Find a good string $s$ or report that such $s$ doesn't exist.Look in ## Note

s if you need further clarifications.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($3 \le n \le 2 \cdot 10^5$; $1 \le k \le 20$) — length of good string $s$ and number of conditions.

The second line of each test case contains $k$ integers $x_1, x_2, \dots, x_k$ ($3 \le x_1 < x_2 < \dots < x_k = n$) where $x_i$ is the length of the prefix in the $i$-th condition.

The third line of each test case contains $k$ integers $c_1, c_2, \dots, c_k$ ($3 \le c_1 \le c_2 \le \dots \le c_k \le \min{\left(10^9, \frac{(n + 1) n}{2} \right)}$) where $c_i$ is the number of palindromic substrings in the $i$-th condition.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10 ^ 5$.

## Output

For each test case, if there is no good string $s$ of length $n$ that satisfies all conditions, print NO.

Otherwise, print YES and a string $s$ of length $n$, consisting of lowercase Latin letters, that satisfies all conditions. If there are multiple answers, print any of them.

## Example

## Input


```

710 25 105 63 1334 23 43 34 23 43 44 14510 34 6 104 5 810 44 6 7 104 5 7 8
```
## Output


```

YES
abcbbcabcb
YES
foo
YES
ayda
YES
wada
NO
YES
abcbcacbab
NO

```
## Note

In the first test case, string $s$ $=$ abcbbcabcb satisfies $k = 2$ conditions: 

* $p(s, x_1) = p(s, 5) =$ $p($abcbb$) = 5 = s_1$. Palindromic substrings are a, b, c, bb and bcb.
* $p(s, x_2) = p(s, 10) =$ $p($abcbbcabcb$) = 6 = s_2$. Palindromic substrings are the same as above, and one extra substring cbbc.

In the second test case, string foo satisfies $k = 1$ condition: 

* $p($foo$) = 3$. Palindromic substrings are f, o and oo.

 There are other possible answers.In the third test case, string ayda satisfies $k = 2$ conditions: 

* $p($ayd$) = 3$. Palindromic substrings are a, y and d.
* $p($ayda$) = 3$. Palindromic substrings are the same.

In the fourth test case, string wada satisfies $k = 2$ conditions: 

* $p($wad$) = 3$. Palindromic substrings are w, a and d.
* $p($wada$) = 4$. Palindromic substrings are the same, and one extra substring ada.

In the fifth test case, it can be proven that there is no string of length $4$ which has $5$ palindromic substrings.

In the sixth test case, string abcbcacbab satisfies $k = 3$ conditions: 

* $p($abcb$) = 4$. Palindromic substrings are a, b, c and bcb.
* $p($abcbca$) = 5$. Palindromic substrings are the same, and one extra substring cbc.
* $p($abcbcacbab$) = 8$. Palindromic substrings are the same, and three extra substrings cac, bab and bcacb.


#### tags 

#1900 #constructive_algorithms #math #strings 