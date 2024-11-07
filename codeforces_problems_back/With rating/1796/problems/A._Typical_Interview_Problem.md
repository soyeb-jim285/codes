<h1 style='text-align: center;'> A. Typical Interview Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The FB-string is formed as follows. Initially, it is empty. We go through all positive integers, starting from $1$, in ascending order, and do the following for each integer:

* if the current integer is divisible by $3$, append F to the end of the FB-string;
* if the current integer is divisible by $5$, append B to the end of the FB-string.

Note that if an integer is divisible by both $3$ and $5$, we append F, and then B, not in the opposite order.

The first $10$ characters of the FB-string are FBFFBFFBFB: the first F comes from the integer $3$, the next character (B) comes from $5$, the next F comes from the integer $6$, and so on. It's easy to see that this string is infinitely long. Let $f_i$ be the $i$-th character of FB-string; so, $f_1$ is F, $f_2$ is B, $f_3$ is F, $f_4$ is F, and so on.

You are given a string $s$, consisting of characters F and/or B. You have to determine whether it is a substring (contiguous subsequence) of the FB-string. In other words, determine if it is possible to choose two integers $l$ and $r$ ($1 \le l \le r$) so that the string $f_l f_{l+1} f_{l+2} \dots f_r$ is exactly $s$.

For example:

* FFB is a substring of the FB-string: if we pick $l = 3$ and $r = 5$, the string $f_3 f_4 f_5$ is exactly FFB;
* BFFBFFBF is a substring of the FB-string: if we pick $l = 2$ and $r = 9$, the string $f_2 f_3 f_4 \dots f_9$ is exactly BFFBFFBF;
* BBB is not a substring of the FB-string.
## Input

The first line contains one integer $t$ ($1 \le t \le 2046$) — the number of test cases.

Each test case consists of two lines. The first line contains one integer $k$ ($1 \le k \le 10$) — the number of characters in $s$. The second line contains $s$, which is a string of exactly $k$ characters. Each character of $s$ is either F or B.

## Output

For each test case, print YES if $s$ is a substring of the FB-string, or NO otherwise.

You may print each letter in any case (YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

## Example

## Input


```

33FFB8BFFBFFBF3BBB
```
## Output


```

YES
YES
NO

```


#### tags 

#800 #brute_force #implementation #strings 