<h1 style='text-align: center;'> H. BinaryStringForces</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$ of length $n$. We define a maximal substring as a substring that cannot be extended while keeping all elements equal. For example, in the string $11000111$ there are three maximal substrings: $11$, $000$ and $111$.

In one operation, you can select two maximal adjacent substrings. Since they are maximal and adjacent, it's easy to see their elements must have different values. Let $a$ be the length of the sequence of ones and $b$ be the length of the sequence of zeros. Then do the following:

* If $a \ge b$, then replace $b$ selected zeros with $b$ ones.
* If $a < b$, then replace $a$ selected ones with $a$ zeros.

As an example, for $1110000$ we make it $0000000$, for $0011$ we make it $1111$. We call a string being good if it can be turned into $1111...1111$ using the aforementioned operation any number of times (possibly, zero). Find the number of good substrings among all $\frac{n(n+1)}{2}$ non-empty substrings of $s$.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The description of test cases follows.

The first line of each test case contains $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the string $s$.

The second line of each test case contains the binary string $s$ of length $n$. 

It is guaranteed that sum of $n$ across all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print a single integer — the number of good substrings.

## Example

## Input


```

4610001131015111116010101
```
## Output


```

8
5
15
18

```
## Note

Let's define a substring from index $l$ to index $r$ as $[l, r]$.

For the first test case, the good substrings are:

* $[1,1]$,
* $[1,2]$,
* $[3,6]$,
* $[4,5]$,
* $[4,6]$,
* $[5,5]$,
* $[5,6]$,
* $[6,6]$.

In the second test case, all substrings are good except $[2,2]$.

In the third test case, all substrings are good.



#### tags 

#3500 #constructive_algorithms #data_structures #dp 