<h1 style='text-align: center;'> E. Vasya and Binary String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has a string $s$ of length $n$ consisting only of digits 0 and 1. Also he has an array $a$ of length $n$. 

Vasya performs the following operation until the string becomes empty: choose some consecutive substring of equal characters, erase it from the string and glue together the remaining parts (any of them can be empty). For example, if he erases substring 111 from string 111110 he will get the string 110. Vasya gets $a_x$ points for erasing substring of length $x$.

Vasya wants to maximize his total points, so help him with this! 

#### Input

The first line contains one integer $n$ ($1 \le n \le 100$) — the length of string $s$.

The second line contains string $s$, consisting only of digits 0 and 1.

The third line contains $n$ integers $a_1, a_2, \dots a_n$ ($1 \le a_i \le 10^9$), where $a_i$ is the number of points for erasing the substring of length $i$.

#### Output

Print one integer — the maximum total points Vasya can get.

## Examples

#### Input


```text
7
1101001
3 4 9 100 1 2 3
```
#### Output


```text
109
```
#### Input


```text
5
10101
3 10 15 15 15
```
#### Output


```text
23
```
## Note

In the first example the optimal sequence of erasings is: 1101001 $\rightarrow$ 111001 $\rightarrow$ 11101 $\rightarrow$ 1111 $\rightarrow$ $\varnothing$.

In the second example the optimal sequence of erasings is: 10101 $\rightarrow$ 1001 $\rightarrow$ 11 $\rightarrow$ $\varnothing$.



#### Tags 

#2400 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_59_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Tutorial #2](../blogs/Tutorial_2.md)
