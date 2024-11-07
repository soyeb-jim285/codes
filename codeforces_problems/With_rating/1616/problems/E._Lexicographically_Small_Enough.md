<h1 style='text-align: center;'> E. Lexicographically Small Enough</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $s$ and $t$ of equal length $n$. In one move, you can swap any two adjacent characters of the string $s$.

You need to find the minimal number of operations you need to make string $s$ lexicographically smaller than string $t$.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
### Input

The first line of input contains one integer $q$ ($1 \le q \le 10\,000$): the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains the string $s$ consisting of $n$ lowercase English letters.

The third line of each test case contains the string $t$ consisting of $n$ lowercase English letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print in a separate line the minimal number of operations you need to make string $s$ lexicographically smaller than string $t$, or $-1$, if it's impossible.

## Example

### Input


```text
4
1
a
a
3
rll
rrr
3
caa
aca
5
ababa
aabba
```
### Output


```text
-1
0
2
2
```


#### Tags 

#2200 #NOT OK #brute_force #data_structures #greedy #strings 

## Blogs
- [All Contest Problems](../Good_Bye_2021:_2022_is_NEAR.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
