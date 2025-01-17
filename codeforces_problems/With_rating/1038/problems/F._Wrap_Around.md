<h1 style='text-align: center;'> F. Wrap Around</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$.

Find the number of distinct cyclical binary strings of length $n$ which contain $s$ as a substring.

The cyclical string $t$ contains $s$ as a substring if there is some cyclical shift of string $t$, such that $s$ is a substring of this cyclical shift of $t$.

For example, the cyclical string "000111" contains substrings "001", "01110" and "10", but doesn't contain "0110" and "10110".

Two cyclical strings are called different if they differ from each other as strings. For example, two different strings, which differ from each other by a cyclical shift, are still considered different cyclical strings.

##### Input

The first line contains a single integer $n$ ($1 \le n \le 40$) — the length of the target string $t$.

The next line contains the string $s$ ($1 \le |s| \le n$) — the string which must be a substring of cyclical string $t$. String $s$ contains only characters '0' and '1'.

##### Output

Print the only integer — the number of distinct cyclical binary strings $t$, which contain $s$ as a substring.

## Examples

##### Input


```text
2  
0  

```
##### Output


```text
3
```
##### Input


```text
4  
1010  

```
##### Output


```text
2
```
##### Input


```text
20  
10101010101010  

```
##### Output


```text
962
```
## Note

In the first example, there are three cyclical strings, which contain "0" — "00", "01" and "10".

In the second example, there are only two such strings — "1010", "0101".



#### Tags 

#2900 #NOT OK #dp #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_508_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
