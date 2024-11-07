<h1 style='text-align: center;'> F. Binary String Partition</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a string $t$ consisting of characters 0 and/or 1 beautiful, if either the number of occurrences of character 0 in this string does not exceed $k$, or the number of occurrences of characters 1 in this string does not exceed $k$ (or both). For example, if $k = 3$, the strings 101010, 111, 0, 00000, 1111111000 are beautiful, and the strings 1111110000, 01010101 are not beautiful.

You are given a string $s$. You have to divide it into the minimum possible number of beautiful strings, i. e., find a sequence of strings $t_1, t_2, \dots, t_m$ such that every $t_i$ is beautiful, $t_1 + t_2 + \dots + t_m = s$ (where $+$ is the concatenation operator), and $m$ is minimum possible.

For every $k$ from $1$ to $|s|$, find the minimum possible number of strings such that $s$ can be divided into them (i. e. the minimum possible $m$ in the partition).

#### Input

The only line contains one string $s$ ($1 \le |s| \le 2 \cdot 10^5$). Each character of $s$ is either 0 or 1.

#### Output

Print $|s|$ integers. The $i$-th integer should be equal to the minimum number of strings in the partition of $s$, when $k = i$.

## Examples

#### Input


```text
00100010
```
#### Output


```text
2 1 1 1 1 1 1 1
```
#### Input


```text
1001011100
```
#### Output


```text
3 2 2 2 1 1 1 1 1 1
```


#### Tags 

#NOT OK #*special #binary_search #greedy 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_7.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
