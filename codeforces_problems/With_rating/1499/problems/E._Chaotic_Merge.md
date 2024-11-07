<h1 style='text-align: center;'> E. Chaotic Merge</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $x$ and $y$, both consist only of lowercase Latin letters. Let $|s|$ be the length of string $s$.

Let's call a sequence $a$ a merging sequence if it consists of exactly $|x|$ zeros and exactly $|y|$ ones in some order.

A merge $z$ is produced from a sequence $a$ by the following rules: 

* if $a_i=0$, then remove a letter from the beginning of $x$ and append it to the end of $z$;
* if $a_i=1$, then remove a letter from the beginning of $y$ and append it to the end of $z$.

Two merging sequences $a$ and $b$ are different if there is some position $i$ such that $a_i \neq b_i$.

Let's call a string $z$ chaotic if for all $i$ from $2$ to $|z|$ $z_{i-1} \neq z_i$.

Let $s[l,r]$ for some $1 \le l \le r \le |s|$ be a substring of consecutive letters of $s$, starting from position $l$ and ending at position $r$ inclusive.

Let $f(l_1, r_1, l_2, r_2)$ be the number of different merging sequences of $x[l_1,r_1]$ and $y[l_2,r_2]$ that produce chaotic merges. 
## Note

 that only non-empty substrings of $x$ and $y$ are considered.

Calculate $\sum \limits_{1 \le l_1 \le r_1 \le |x| \\\ 1 \le l_2 \le r_2 \le |y|} f(l_1, r_1, l_2, r_2)$. 
###### Output

 the answer modulo $998\,244\,353$.

###### Input

The first line contains a string $x$ ($1 \le |x| \le 1000$).

The second line contains a string $y$ ($1 \le |y| \le 1000$).

Both strings consist only of lowercase Latin letters.

###### Output

Print a single integer — the sum of $f(l_1, r_1, l_2, r_2)$ over $1 \le l_1 \le r_1 \le |x|$ and $1 \le l_2 \le r_2 \le |y|$ modulo $998\,244\,353$.

## Examples

###### Input


```text
aaa
bb
```
###### Output


```text
24
```
###### Input


```text
code
forces
```
###### Output


```text
1574
```
###### Input


```text
aaaaa
aaa
```
###### Output


```text
0
```
###### Input


```text
justamassivetesttocheck
howwellyouhandlemodulooperations
```
###### Output


```text
667387032
```
## Note

In the first example there are: 

* $6$ pairs of substrings "a" and "b", each with valid merging sequences "01" and "10";
* $3$ pairs of substrings "a" and "bb", each with a valid merging sequence "101";
* $4$ pairs of substrings "aa" and "b", each with a valid merging sequence "010";
* $2$ pairs of substrings "aa" and "bb", each with valid merging sequences "0101" and "1010";
* $2$ pairs of substrings "aaa" and "b", each with no valid merging sequences;
* $1$ pair of substrings "aaa" and "bb" with a valid merging sequence "01010";

Thus, the answer is $6 \cdot 2 + 3 \cdot 1 + 4 \cdot 1 + 2 \cdot 2 + 2 \cdot 0 + 1 \cdot 1 = 24$.



#### Tags 

#2400 #NOT OK #combinatorics #dp #math #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_106_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
