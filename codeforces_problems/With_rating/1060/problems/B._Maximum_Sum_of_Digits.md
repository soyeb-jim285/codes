<h1 style='text-align: center;'> B. Maximum Sum of Digits</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a positive integer $n$.

Let $S(x)$ be sum of digits in base 10 representation of $x$, for example, $S(123) = 1 + 2 + 3 = 6$, $S(0) = 0$.

Your task is to find two integers $a, b$, such that $0 \leq a, b \leq n$, $a + b = n$ and $S(a) + S(b)$ is the largest possible among all such pairs.

#### Input

The only line of input contains an integer $n$ $(1 \leq n \leq 10^{12})$.

#### Output

Print largest $S(a) + S(b)$ among all pairs of integers $a, b$, such that $0 \leq a, b \leq n$ and $a + b = n$.

## Examples

#### Input


```text
35  

```
#### Output


```text
17  

```
#### Input


```text
10000000000  

```
#### Output


```text
91  

```
## Note

In the first example, you can choose, for example, $a = 17$ and $b = 18$, so that $S(17) + S(18) = 1 + 7 + 1 + 8 = 17$. It can be shown that it is impossible to get a larger answer.

In the second test example, you can choose, for example, $a = 5000000001$ and $b = 4999999999$, with $S(5000000001) + S(4999999999) = 91$. It can be shown that it is impossible to get a larger answer.



#### Tags 

#1100 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_513_by_Barcelona_Bootcamp_(rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
