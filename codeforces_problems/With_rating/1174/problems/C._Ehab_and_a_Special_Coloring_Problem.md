<h1 style='text-align: center;'> C. Ehab and a Special Coloring Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're given an integer $n$. For every integer $i$ from $2$ to $n$, assign a positive integer $a_i$ such that the following conditions hold:

* For any pair of integers $(i,j)$, if $i$ and $j$ are coprime, $a_i \neq a_j$.
* The maximal value of all $a_i$ should be minimized (that is, as small as possible).

A pair of integers is called [coprime](https://en.wikipedia.org/wiki/Coprime_integers) if their [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) is $1$.

#### Input

The only line contains the integer $n$ ($2 \le n \le 10^5$).

#### Output

Print $n-1$ integers, $a_2$, $a_3$, $\ldots$, $a_n$ ($1 \leq a_i \leq n$). 

If there are multiple solutions, print any of them.

## Examples

#### Input


```text
4
```
#### Output


```text
1 2 1 
```
#### Input

```text

3

```
#### Output


```text

2 1
```
## Note

In the first example, notice that $3$ and $4$ are coprime, so $a_3 \neq a_4$. Also, notice that $a=[1,2,3]$ satisfies the first condition, but it's not a correct answer because its maximal value is $3$.



#### Tags 

#1300 #NOT OK #constructive_algorithms #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_563_(Div._2).md)
- [A (en)](../blogs/A_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
