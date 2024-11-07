<h1 style='text-align: center;'> E. You Are Given Some Strings...</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $t$ and $n$ strings $s_1, s_2, \dots, s_n$. All strings consist of lowercase Latin letters.

Let $f(t, s)$ be the number of occurences of string $s$ in string $t$. For example, $f('\text{aaabacaa}', '\text{aa}') = 3$, and $f('\text{ababa}', '\text{aba}') = 2$.

Calculate the value of $\sum\limits_{i=1}^{n} \sum\limits_{j=1}^{n} f(t, s_i + s_j)$, where $s + t$ is the concatenation of strings $s$ and $t$. Note that if there are two pairs $i_1$, $j_1$ and $i_2$, $j_2$ such that $s_{i_1} + s_{j_1} = s_{i_2} + s_{j_2}$, you should include both $f(t, s_{i_1} + s_{j_1})$ and $f(t, s_{i_2} + s_{j_2})$ in answer.

#### Input

The first line contains string $t$ ($1 \le |t| \le 2 \cdot 10^5$).

The second line contains integer $n$ ($1 \le n \le 2 \cdot 10^5$).

Each of next $n$ lines contains string $s_i$ ($1 \le |s_i| \le 2 \cdot 10^5$).

It is guaranteed that $\sum\limits_{i=1}^{n} |s_i| \le 2 \cdot 10^5$. All strings consist of lowercase English letters.

#### Output

Print one integer — the value of $\sum\limits_{i=1}^{n} \sum\limits_{j=1}^{n} f(t, s_i + s_j)$.

## Examples

#### Input


```text
aaabacaa
2
a
aa
```
#### Output


```text
5
```
#### Input


```text
aaabacaa
4
a
a
a
b
```
#### Output


```text
33
```


#### Tags 

#2400 #NOT OK #brute_force #string_suffix_structures #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_70_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
