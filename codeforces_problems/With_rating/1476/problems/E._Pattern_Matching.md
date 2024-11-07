<h1 style='text-align: center;'> E. Pattern Matching</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ patterns $p_1, p_2, \dots, p_n$ and $m$ strings $s_1, s_2, \dots, s_m$. Each pattern $p_i$ consists of $k$ characters that are either lowercase Latin letters or wildcard characters (denoted by underscores). All patterns are pairwise distinct. Each string $s_j$ consists of $k$ lowercase Latin letters.

A string $a$ matches a pattern $b$ if for each $i$ from $1$ to $k$ either $b_i$ is a wildcard character or $b_i=a_i$.

You are asked to rearrange the patterns in such a way that the first pattern the $j$-th string matches is $p[mt_j]$. You are allowed to leave the order of the patterns unchanged.

Can you perform such a rearrangement? If you can, then print any valid order.

##### Input

The first line contains three integers $n$, $m$ and $k$ ($1 \le n, m \le 10^5$, $1 \le k \le 4$) — the number of patterns, the number of strings and the length of each pattern and string.

Each of the next $n$ lines contains a pattern — $k$ characters that are either lowercase Latin letters or underscores. All patterns are pairwise distinct.

Each of the next $m$ lines contains a string — $k$ lowercase Latin letters, and an integer $mt$ ($1 \le mt \le n$) — the index of the first pattern the corresponding string should match.

##### Output

Print "NO" if there is no way to rearrange the patterns in such a way that the first pattern that the $j$-th string matches is $p[mt_j]$.

Otherwise, print "YES" in the first line. The second line should contain $n$ distinct integers from $1$ to $n$ — the order of the patterns. If there are multiple answers, print any of them.

## Examples

##### Input


```text
5 3 4
_b_d
__b_
aaaa
ab__
_bcd
abcd 4
abba 2
dbcd 5
```
##### Output


```text
YES
3 2 4 5 1 
```
##### Input


```text
1 1 3
__c
cba 1
```
##### Output


```text
NO
```
##### Input


```text
2 2 2
a_
_b
ab 1
ab 2
```
##### Output


```text
NO
```
## Note

The order of patterns after the rearrangement in the first example is the following: 

* aaaa
* __b_
* ab__
* _bcd
* _b_d

Thus, the first string matches patterns ab__, _bcd, _b_d in that order, the first of them is ab__, that is indeed $p[4]$. The second string matches __b_ and ab__, the first of them is __b_, that is $p[2]$. The last string matches _bcd and _b_d, the first of them is _bcd, that is $p[5]$.

The answer to that test is not unique, other valid orders also exist.

In the second example cba doesn't match __c, thus, no valid order exists.

In the third example the order (a_, _b) makes both strings match pattern $1$ first and the order (_b, a_) makes both strings match pattern $2$ first. Thus, there is no order that produces the result $1$ and $2$.



#### Tags 

#2300 #NOT OK #bitmasks #data_structures #dfs_and_similar #graphs #hashing #sortings #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_103_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
