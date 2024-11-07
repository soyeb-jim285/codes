<h1 style='text-align: center;'> B. Mirror in the String</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a string $s_1 s_2 \ldots s_n$ and you stand on the left of the string looking right. You want to choose an index $k$ ($1 \le k \le n$) and place a mirror after the $k$-th letter, so that what you see is $s_1 s_2 \ldots s_k s_k s_{k - 1} \ldots s_1$. What is the lexicographically smallest string you can see?

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
## Input

The first line of input contains one integer $t$ ($1 \leq t \leq 10\,000$): the number of test cases.

The next $t$ lines contain the description of the test cases, two lines per a test case.

In the first line you are given one integer $n$ ($1 \leq n \leq 10^5$): the length of the string.

The second line contains the string $s$ consisting of $n$ lowercase English characters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case print the lexicographically smallest string you can see.

## Example

## Input


```

4
10
codeforces
9
cbacbacba
3
aaa
4
bbaa

```
## Output


```

cc
cbaabc
aa
bb

```
## Note

In the first test case choose $k = 1$ to obtain "cc".

In the second test case choose $k = 3$ to obtain "cbaabc".

In the third test case choose $k = 1$ to obtain "aa".

In the fourth test case choose $k = 1$ to obtain "bb".



#### tags 

#1100 #greedy #strings 