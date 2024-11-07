<h1 style='text-align: center;'> F. String Distance</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Suppose you are given two strings $a$ and $b$. You can apply the following operation any number of times: choose any contiguous substring of $a$ or $b$, and sort the characters in it in non-descending order. Let $f(a, b)$ the minimum number of operations you have to apply in order to make them equal (or $f(a, b) = 1337$ if it is impossible to make $a$ and $b$ equal using these operations).

For example: 

* $f(\text{ab}, \text{ab}) = 0$;
* $f(\text{ba}, \text{ab}) = 1$ (in one operation, we can sort the whole first string);
* $f(\text{ebcda}, \text{ecdba}) = 1$ (in one operation, we can sort the substring of the second string starting from the $2$-nd character and ending with the $4$-th character);
* $f(\text{a}, \text{b}) = 1337$.

You are given $n$ strings $s_1, s_2, \dots, s_k$ having equal length. Calculate $\sum \limits_{i = 1}^{n} \sum\limits_{j = i + 1}^{n} f(s_i, s_j)$.

#### Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of strings.

Then $n$ lines follow, each line contains one of the strings $s_i$, consisting of lowercase Latin letters. $|s_1| = |s_2| = \ldots = |s_n|$, and $n \cdot |s_1| \le 2 \cdot 10^5$. All these strings are pairwise distinct.

#### Output

Print one integer: $\sum \limits_{i = 1}^{n} \sum\limits_{j = i + 1}^{n} f(s_i, s_j)$.

## Examples

#### Input


```text
4
zzz
bac
abc
acb
```
#### Output


```text
4015
```
#### Input


```text
2
a
b
```
#### Output


```text
1337
```


#### Tags 

#3000 #NOT OK #binary_search #brute_force #data_structures #hashing #implementation #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_110_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
