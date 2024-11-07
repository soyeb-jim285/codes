<h1 style='text-align: center;'> E. Collapsing Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ strings $s_1, s_2, \dots, s_n$, consisting of lowercase Latin letters. Let $|x|$ be the length of string $x$.

Let a collapse $C(a, b)$ of two strings $a$ and $b$ be the following operation: 

* if $a$ is empty, $C(a, b) = b$;
* if $b$ is empty, $C(a, b) = a$;
* if the last letter of $a$ is equal to the first letter of $b$, then $C(a, b) = C(a_{1,|a|-1}, b_{2,|b|})$, where $s_{l,r}$ is the substring of $s$ from the $l$-th letter to the $r$-th one;
* otherwise, $C(a, b) = a + b$, i. e. the concatenation of two strings.

Calculate $\sum\limits_{i=1}^n \sum\limits_{j=1}^n |C(s_i, s_j)|$.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 10^6$).

Each of the next $n$ lines contains a string $s_i$ ($1 \le |s_i| \le 10^6$), consisting of lowercase Latin letters.

The total length of the strings doesn't exceed $10^6$.

#### Output

Print a single integer — $\sum\limits_{i=1}^n \sum\limits_{j=1}^n |C(s_i, s_j)|$.

## Examples

#### Input


```text
3abaabba
```
#### Output

```text

20

```
#### Input


```text
5ababbabxxabxbabab
```
#### Output

```text

126

```


#### Tags 

#1900 #NOT OK #data_structures #strings #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_159_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
