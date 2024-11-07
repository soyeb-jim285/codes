<h1 style='text-align: center;'> B. Count the Number of Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kristina has a string $s$ of length $n$, consisting only of lowercase and uppercase Latin letters. For each pair of lowercase letter and its matching uppercase letter, Kristina can get $1$ burl. However, pairs of characters cannot overlap, so each character can only be in one pair.

For example, if she has the string $s$ = "aAaaBACacbE", she can get a burl for the following character pairs: 

* $s_1$ = "a" and $s_2$ = "A"
* $s_4$ = "a" and $s_6$ = "A"
* $s_5$ = "B" and $s_{10}$ = "b"
* $s_7$= "C" and $s_9$ = "c"

Kristina wants to get more burles for her string, so she is going to perform no more than $k$ operations on it. In one operation, she can:

* either select the lowercase character $s_i$ ($1 \le i \le n$) and make it uppercase.
* or select uppercase character $s_i$ ($1 \le i \le n$) and make it lowercase.

For example, when $k$ = 2 and $s$ = "aAaaBACacbE" it can perform one operation: choose $s_3$ = "a" and make it uppercase. Then she will get another pair of $s_3$ = "A" and $s_8$ = "a"

Find maximum number of burles Kristina can get for her string.

## Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains two integers $n$ ($1 \le n \le 2 \cdot 10^5$) and $k$ ($0 \le k \le n$) — the number of characters in the string and the maximum number of operations that can be performed on it.

The second line of each test case contains a string $s$ of length $n$, consisting only of lowercase and uppercase Latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print exactly one integer on a separate line: the maximum number of burles that Kristina can get for her string $s$.

## Example

## Input


```

511 2aAaaBACacbE2 2ab4 1aaBB6 0abBAcC5 3cbccb
```
## Output


```

5
0
1
3
2

```
## Note

The first test case is explained in the problem statement.

In the second test case, it is not possible to get any pair by performing any number of operations.



#### tags 

#1000 #greedy #strings 