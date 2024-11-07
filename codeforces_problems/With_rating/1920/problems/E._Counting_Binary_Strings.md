<h1 style='text-align: center;'> E. Counting Binary Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Patrick calls a substring$^\dagger$ of a binary string$^\ddagger$ good if this substring contains exactly one 1. 

Help Patrick count the number of binary strings $s$ such that $s$ contains exactly $n$ good substrings and has no good substring of length strictly greater than $k$. 
## Note

 that substrings are differentiated by their location in the string, so if $s =$ 1010 you should count both occurrences of 10.

$^\dagger$ A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

$^\ddagger$ A binary string is a string that only contains the characters 0 and 1.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2500$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $n$ and $k$ ($1 \leq n \leq 2500$, $1 \leq k \leq n$) — the number of required good substrings and the maximum allowed length of a good substring. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $2500$. 

### Output

For each test case, output a single integer — the number of binary strings $s$ such that $s$ contains exactly $n$ good substrings and has no good substring of length strictly greater than $k$. Since this integer can be too large, output it modulo $998\,244\,353$.

## Example

### Input


```text
61 13 24 25 46 22450 2391
```
### Output

```text

1
3
5
12
9
259280854

```
## Note

In the first test case, the only suitable binary string is 1. String 01 is not suitable because it contains a substring 01 with length $2 > 1$.

In the second test case, suitable binary strings are 011, 110 and 111.

In the third test case, suitable binary strings are 101, 0110, 0111, 1110, and 1111.



#### Tags 

#2100 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_919_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
