<h1 style='text-align: center;'> D. Prefixes and Suffixes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have two strings $s_1$ and $s_2$ of length $n$, consisting of lowercase English letters. You can perform the following operation any (possibly zero) number of times: 

* Choose a positive integer $1 \leq k \leq n$.
* Swap the prefix of the string $s_1$ and the suffix of the string $s_2$ of length $k$.

Is it possible to make these two strings equal by doing described operations?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then the test cases follow.

Each test case consists of three lines.

The first line contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the strings $s_1$ and $s_2$. 

The second line contains the string $s_1$ of length $n$, consisting of lowercase English letters.

The third line contains the string $s_2$ of length $n$, consisting of lowercase English letters.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print "YES" if it is possible to make the strings equal, and "NO" otherwise.

## Example

## Input


```

73cbcaba5abcaacbabb5abcaacbabz1aa1ab6abadaaadaaba8abcabdaaadabcaba
```
## Output


```

YES
YES
NO
YES
NO
NO
YES

```
## Note

In the first test case:

* Initially $s_1 = \mathtt{cbc}$, $s_2 = \mathtt{aba}$.
* Operation with $k = 1$, after the operation $s_1 = \mathtt{abc}$, $s_2 = \mathtt{abc}$.

In the second test case:

* Initially $s_1 = \mathtt{abcaa}$, $s_2 = \mathtt{cbabb}$.
* Operation with $k = 2$, after the operation $s_1 = \mathtt{bbcaa}$, $s_2 = \mathtt{cbaab}$.
* Operation with $k = 3$, after the operation $s_1 = \mathtt{aabaa}$, $s_2 = \mathtt{cbbbc}$.
* Operation with $k = 1$, after the operation $s_1 = \mathtt{cabaa}$, $s_2 = \mathtt{cbbba}$.
* Operation with $k = 2$, after the operation $s_1 = \mathtt{babaa}$, $s_2 = \mathtt{cbbca}$.
* Operation with $k = 1$, after the operation $s_1 = \mathtt{aabaa}$, $s_2 = \mathtt{cbbcb}$.
* Operation with $k = 2$, after the operation $s_1 = \mathtt{cbbaa}$, $s_2 = \mathtt{cbbaa}$.

In the third test case, it's impossible to make strings equal.



#### tags 

#2200 #constructive_algorithms #strings #two_pointers 