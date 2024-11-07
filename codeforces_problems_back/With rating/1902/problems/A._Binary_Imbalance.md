<h1 style='text-align: center;'> A. Binary Imbalance</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$, consisting only of characters '0' and/or '1'.

In one operation, you choose a position $i$ from $1$ to $|s| - 1$, where $|s|$ is the current length of string $s$. Then you insert a character between the $i$-th and the $(i+1)$-st characters of $s$. If $s_i = s_{i+1}$, you insert '1'. If $s_i \neq s_{i+1}$, you insert '0'.

Is it possible to make the number of zeroes in the string strictly greater than the number of ones, using any number of operations (possibly, none)?

## Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of testcases.

The first line of each testcase contains an integer $n$ ($1 \le n \le 100$).

The second line contains a string $s$ of length exactly $n$, consisting only of characters '0' and/or '1'.

## Output

For each testcase, print "YES" if it's possible to make the number of zeroes in $s$ strictly greater than the number of ones, using any number of operations (possibly, none). Otherwise, print "NO".

## Example

## Input


```

3200211210
```
## Output


```

YES
NO
YES

```
## Note

In the first testcase, the number of zeroes is already greater than the number of ones.

In the second testcase, it's impossible to insert any zeroes in the string.

In the third testcase, you can choose $i = 1$ to insert a zero between the $1$-st and the $2$-nd characters. Since $s_1 \neq s_2$, you insert a '0'. The resulting string is "100". It has two zeroes and only a single one, so the answer is "YES".



#### tags 

#800 #constructive_algorithms 