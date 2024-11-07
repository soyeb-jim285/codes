<h1 style='text-align: center;'> E. Poman Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got a string $S$ consisting of $n$ lowercase English letters from your friend. It turned out that this is a number written in poman numerals. The poman numeral system is long forgotten. All that's left is the algorithm to transform number from poman numerals to the numeral system familiar to us. Characters of $S$ are numbered from $1$ to $n$ from left to right. Let's denote the value of $S$ as $f(S)$, it is defined as follows: 

* If $|S| > 1$, an arbitrary integer $m$ ($1 \le m < |S|$) is chosen, and it is defined that $f(S) = -f(S[1, m]) + f(S[m + 1, |S|])$, where $S[l, r]$ denotes the substring of $S$ from the $l$-th to the $r$-th position, inclusively.
* Otherwise $S = c$, where $c$ is some English letter. Then $f(S) = 2^{pos(c)}$, where $pos(c)$ is the position of letter $c$ in the alphabet ($pos($a$) = 0$, $pos($z$) = 25$).

## Note

 that $m$ is chosen independently on each step.

Your friend thinks it is possible to get $f(S) = T$ by choosing the right $m$ on every step. Is he right?

##### Input

The first line contains two integers $n$ and $T$ ($2 \leq n \leq 10^5$, $-10^{15} \leq T \leq 10^{15}$).

The second line contains a string $S$ consisting of $n$ lowercase English letters.

##### Output

Print "Yes" if it is possible to get the desired value. Otherwise, print "No".

You can print each letter in any case (upper or lower).

## Examples

##### Input


```text
2 -1
ba
```
##### Output


```text
Yes
```
##### Input


```text
3 -7
abc
```
##### Output


```text
No
```
##### Input


```text
7 -475391
qohshra
```
##### Output


```text
Yes
```
## Note

In the second example, you cannot get $-7$. But you can get $1$, for example, as follows: 

1. First choose $m = 1$, then $f($abc$) = -f($a$) + f($bc$)$
2. $f($a$) = 2^0 = 1$
3. $f($bc$) = -f($b$) + f($c$) = -2^1 + 2^2 = 2$
4. In the end $f($abc$) = -1 + 2 = 1$


#### Tags 

#2300 #NOT OK #bitmasks #greedy #math #strings 

## Blogs
- [All Contest Problems](../Technocup_2021_-_Elimination_Round_3.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
