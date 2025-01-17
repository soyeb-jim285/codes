<h1 style='text-align: center;'> B. Unnatural Conditions</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $s(x)$ be sum of digits in decimal representation of positive integer $x$. Given two integers $n$ and $m$, find some positive integers $a$ and $b$ such that 

* $s(a) \ge n$,
* $s(b) \ge n$,
* $s(a + b) \le m$.
#### Input

The only line of input contain two integers $n$ and $m$ ($1 \le n, m \le 1129$).

#### Output

Print two lines, one for decimal representation of $a$ and one for decimal representation of $b$. Both numbers must not contain leading zeros and must have length no more than $2230$.

## Examples

#### Input


```text
6 5  

```
#### Output


```text
6   
7  

```
#### Input


```text
8 16  

```
#### Output


```text
35   
53  

```
## Note

In the first sample, we have $n = 6$ and $m = 5$. One valid solution is $a = 6$, $b = 7$. Indeed, we have $s(a) = 6 \ge n$ and $s(b) = 7 \ge n$, and also $s(a + b) = s(13) = 4 \le m$.



#### Tags 

#1200 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../AIM_Tech_Round_5_(rated,_Div._1_+_Div._2).md)
- [Анонс](../blogs/Анонс.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
