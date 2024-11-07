<h1 style='text-align: center;'> F. Function Sum</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Suppose you have an integer array $a_1, a_2, \dots, a_n$.

Let $\operatorname{lsl}(i)$ be the number of indices $j$ ($1 \le j < i$) such that $a_j < a_i$.

Analogically, let $\operatorname{grr}(i)$ be the number of indices $j$ ($i < j \le n$) such that $a_j > a_i$.

Let's name position $i$ good in the array $a$ if $\operatorname{lsl}(i) < \operatorname{grr}(i)$.

Finally, let's define a function $f$ on array $a$ $f(a)$ as the sum of all $a_i$ such that $i$ is good in $a$.

Given two integers $n$ and $k$, find the sum of $f(a)$ over all arrays $a$ of size $n$ such that $1 \leq a_i \leq k$ for all $1 \leq i \leq n$ modulo $998\,244\,353$.

##### Input

The first and only line contains two integers $n$ and $k$ ($1 \leq n \leq 50$; $2 \leq k < 998\,244\,353$).

##### Output

##### Output

 a single integer — the sum of $f$ over all arrays $a$ of size $n$ modulo $998\,244\,353$.

## Examples

##### Input


```text
3 3
```
##### Output


```text
28
```
##### Input


```text
5 6
```
##### Output


```text
34475
```
##### Input


```text
12 30
```
##### Output


```text
920711694
```
## Note

In the first test case: 

 

| $f([1,1,1]) = 0$ | $f([2,2,3]) = 2 + 2 = 4$ |
| --- | --- |
| $f([1,1,2]) = 1 + 1 = 2$ | $f([2,3,1]) = 2$ |
| $f([1,1,3]) = 1 + 1 = 2$ | $f([2,3,2]) = 2$ |
| $f([1,2,1]) = 1$ | $f([2,3,3]) = 2$ |
| $f([1,2,2]) = 1$ | $f([3,1,1]) = 0$ |
| $f([1,2,3]) = 1$ | $f([3,1,2]) = 1$ |
| $f([1,3,1]) = 1$ | $f([3,1,3]) = 1$ |
| $f([1,3,2]) = 1$ | $f([3,2,1]) = 0$ |
| $f([1,3,3]) = 1$ | $f([3,2,2]) = 0$ |
| $f([2,1,1]) = 0$ | $f([3,2,3]) = 2$ |
| $f([2,1,2]) = 1$ | $f([3,3,1]) = 0$ |
| $f([2,1,3]) = 2 + 1 = 3$ | $f([3,3,2]) = 0$ |
| $f([2,2,1]) = 0$ | $f([3,3,3]) = 0$ |
| $f([2,2,2]) = 0$ |  |

 Adding up all of these values, we get $28$ as the answer.



#### Tags 

#2500 #NOT OK #brute_force #combinatorics #dp #fft #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_841_(Div._2)_and_Divide_by_Zero_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
