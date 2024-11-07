<h1 style='text-align: center;'> A. Equality</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$, which consists only of the first $k$ letters of the Latin alphabet. All letters in string $s$ are uppercase.

A subsequence of string $s$ is a string that can be derived from $s$ by deleting some of its symbols without changing the order of the remaining symbols. For example, "ADE" and "BD" are subsequences of "ABCDE", but "DEA" is not.

A subsequence of $s$ called good if the number of occurences of each of the first $k$ letters of the alphabet is the same.

Find the length of the longest good subsequence of $s$. 

#### Input

The first line of the input contains integers $n$ ($1\le n \le 10^5$) and $k$ ($1 \le k \le 26$).

The second line of the input contains the string $s$ of length $n$. String $s$ only contains uppercase letters from 'A' to the $k$-th letter of Latin alphabet.

#### Output

Print the only integer — the length of the longest good subsequence of string $s$.

## Examples

#### Input


```text
9 3  
ACAABCCAB  

```
#### Output


```text
6
```
#### Input


```text
9 4  
ABCABCABC  

```
#### Output


```text
0
```
## Note

In the first example, "ACBCAB" ("ACAABCCAB") is one of the subsequences that has the same frequency of 'A', 'B' and 'C'. Subsequence "CAB" also has the same frequency of these letters, but doesn't have the maximum possible length.

In the second example, none of the subsequences can have 'D', hence the answer is $0$.



#### Tags 

#800 #NOT OK #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_508_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
