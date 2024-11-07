<h1 style='text-align: center;'> G. Maximize the Remaining String</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$, consisting of lowercase Latin letters. While there is at least one character in the string $s$ that is repeated at least twice, you perform the following operation: 

* you choose the index $i$ ($1 \le i \le |s|$) such that the character at position $i$ occurs at least two times in the string $s$, and delete the character at position $i$, that is, replace $s$ with $s_1 s_2 \ldots s_{i-1} s_{i+1} s_{i+2} \ldots s_n$.

For example, if $s=$"codeforces", then you can apply the following sequence of operations: 

* $i=6 \Rightarrow s=$"codefrces";
* $i=1 \Rightarrow s=$"odefrces";
* $i=7 \Rightarrow s=$"odefrcs";

Given a given string $s$, find the lexicographically maximum string that can be obtained after applying a certain sequence of operations after which all characters in the string become unique.

A string $a$ of length $n$ is lexicographically less than a string $b$ of length $m$, if: 

* there is an index $i$ ($1 \le i \le \min(n, m)$) such that the first $i-1$ characters of the strings $a$ and $b$ are the same, and the $i$-th character of the string $a$ is less than $i$-th character of string $b$;
* or the first $\min(n, m)$ characters in the strings $a$ and $b$ are the same and $n < m$.

For example, the string $a=$"aezakmi" is lexicographically less than the string $b=$"aezus".

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$). Then $t$ test cases follow.

Each test case is characterized by a string $s$, consisting of lowercase Latin letters ($1 \le |s| \le 2 \cdot 10^5$).

It is guaranteed that the sum of the lengths of the strings in all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the lexicographically maximum string that can be obtained after applying a certain sequence of operations after which all characters in the string become unique.

## Example

### Input


```text
6
codeforces
aezakmi
abacaba
convexhull
swflldjgpaxs
myneeocktxpqjpz
```
### Output


```text
odfrces
ezakmi
cba
convexhul
wfldjgpaxs
myneocktxqjpz
```


#### Tags 

#2000 #NOT OK #brute_force #data_structures #dp #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_710_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Разбор](../blogs/Разбор.md)
