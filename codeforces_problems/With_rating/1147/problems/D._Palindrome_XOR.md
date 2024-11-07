<h1 style='text-align: center;'> D. Palindrome XOR</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of characters "1", "0", and "?". The first character of $s$ is guaranteed to be "1". Let $m$ be the number of characters in $s$.

Count the number of ways we can choose a pair of integers $a, b$ that satisfies the following: 

* $1 \leq a < b < 2^m$
* When written without leading zeros, the base-2 representations of $a$ and $b$ are both palindromes.
* The base-2 representation of bitwise XOR of $a$ and $b$ matches the pattern $s$. We say that $t$ matches $s$ if the lengths of $t$ and $s$ are the same and for every $i$, the $i$-th character of $t$ is equal to the $i$-th character of $s$, or the $i$-th character of $s$ is "?".

Compute this count modulo $998244353$. 

###### Input

The first line contains a single string $s$ ($1 \leq |s| \leq 1\,000$). $s$ consists only of characters "1", "0" and "?". It is guaranteed that the first character of $s$ is a "1".

###### Output

Print a single integer, the count of pairs that satisfy the conditions modulo $998244353$.

## Examples

###### Input


```text
10110
```
###### Output


```text
3
```
###### Input


```text
1?0???10
```
###### Output


```text
44
```
###### Input


```text
1?????????????????????????????????????
```
###### Output


```text
519569202
```
###### Input


```text
1
```
###### Output


```text
0
```
## Note

For the first example, the pairs in base-2 are $(111, 10001), (11, 10101), (1001, 11111)$.



#### Tags 

#2400 #NOT OK #dfs_and_similar #graphs 

## Blogs
- [All Contest Problems](../Forethought_Future_Cup_-_Final_Round_(Onsite_Finalists_Only).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
