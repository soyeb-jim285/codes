<h1 style='text-align: center;'> B. The String Has a Target</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$. You can apply this operation to the string exactly once: choose index $i$ and move character $s_i$ to the beginning of the string (removing it at the old position). For example, if you apply the operation with index $i=4$ to the string "abaacd" with numbering from $1$, you get the string "aabacd". What is the lexicographically minimal$^{\dagger}$ string you can obtain by this operation?

$^{\dagger}$A string $a$ is lexicographically smaller than a string $b$ of the same length if and only if the following holds: 

* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10 ^ 5$) — the length of the string.

The second line of each test case contains the string $s$ of length $n$, consisting of lowercase English letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10 ^ 5$.

## Output

For each test case, on a separate line print the lexicographically smallest string that can be obtained after applying the operation to the original string exactly once.

## Example

## Input


```

43cba4acac5abbcb4aaba
```
## Output


```

acb
aacc
abbcb
aaab

```
## Note

In the first test case, you need to move the last character to the beginning.

In the second case, you need to move the second letter "a".

In the third set you need to apply the operation with $i=1$, then the string will not change.



#### tags 

#800 #greedy #strings 