<h1 style='text-align: center;'> G. Zimpha Fan Club</h1>

<h5 style='text-align: center;'>time limit per test: 12 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

One day, Zimpha casually came up with a problem. As a member of "Zimpha fan club", you decided to solve that problem.

You are given two strings $s$ and $t$ of length $n$ and $m$, respectively. Both strings only consist of lowercase English letters, - and *.

You need to replace all occurrences of * and -, observing the following rules:

* For each -, you must replace it with any lowercase English letter.
* For each *, you must replace it with a string of any (possibly, zero) length which only consists of lowercase English letters.

## Note

 that you can replace two different instances of - with different characters. You can also replace each two different instances of * with different strings.

Suppose $s$ and $t$ have been transformed into $s'$ and $t'$. Now you're wondering if there's a replacement that makes $s'=t'$.

####### Input

The first line of input contains two integers $n$ and $m$ ($1 \leq n, m \leq 2 \cdot 10^6$) — the length of the strings $s$ and $t$, respectively.

The second line contains the string $s$ of length $n$. It is guaranteed that $s$ only consists of lowercase English letters, - and *.

The third line contains the string $t$ of length $m$. It is guaranteed that $t$ only consists of lowercase English letters, - and *.

####### Output

For each test case, output "Yes" if there is a replacement that makes $s'=t'$, and output "No" otherwise.

You can output "Yes" and "No" in any case (for example, strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive response).

## Examples

####### Input


```text
10 10justmonikaj-stsayori
```
####### Output

```text

No
```
####### Input


```text
7 8ttk-wxx*tt-l-xx
```
####### Output

```text

Yes
```
####### Input


```text
13 11asoulwangziji-soulg*z-y-
```
####### Output

```text

No
```
####### Input


```text
7 3abc*cbaa*c
```
####### Output

```text

No
```
####### Input


```text
20 18bulijiojio-dibuliduo*li*ji-*ox*i*-du*-
```
####### Output

```text

Yes
```
## Note

In the second test case, we can transform both strings into ttklwxx. In $s$, - will be replaced with l. In $t$, * will be replaced by the empty string with the first and second - will be replaced with k and w respectively.

In the fifth test case, we can transform both strings into bulijiojioxdibuliduo.



#### Tags 

#3000 #NOT OK #fft #greedy #math #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_947_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
