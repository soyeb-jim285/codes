<h1 style='text-align: center;'> E. Rectangular Congruence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a prime number $n$, and an array of $n$ integers $b_1,b_2,\ldots, b_n$, where $0 \leq b_i < n$ for each $1 \le i \leq n$.

You have to find a matrix $a$ of size $n \times n$ such that all of the following requirements hold:

* $0 \le a_{i,j} < n$ for all $1 \le i, j \le n$.
* $a_{r_1, c_1} + a_{r_2, c_2} \not\equiv a_{r_1, c_2} + a_{r_2, c_1} \pmod n$ for all positive integers $r_1$, $r_2$, $c_1$, and $c_2$ such that $1 \le r_1 < r_2 \le n$ and $1 \le c_1 < c_2 \le n$.
* $a_{i,i} = b_i$ for all $1 \le i \leq n$.

Here $x \not \equiv y \pmod m$ denotes that $x$ and $y$ give different remainders when divided by $m$.

If there are multiple solutions, output any. It can be shown that such a matrix always exists under the given constraints.

##### Input

The first line contains a single positive integer $n$ ($2 \le n < 350$). 

The second line contains $n$ integers $b_1, b_2, \ldots, b_n$ ($0 \le b_i < n$) — the required values on the main diagonal of the matrix.

It is guaranteed that $n$ is prime.

##### Output

Print $n$ lines. On the $i$-th line, print $n$ integers $a_{i, 1}, a_{i, 2}, \ldots, a_{i, n}$, each separated with a space.

If there are multiple solutions, output any.

## Examples

##### Input


```text
2
0 0
```
##### Output


```text
0 1 
0 0
```
##### Input

```text

3
1 1 1

```
##### Output


```text
1 2 2
1 1 0
1 0 1
```
##### Input

```text

5
1 4 1 2 4

```
##### Output


```text

1 0 1 3 4
1 4 3 1 0
2 4 1 0 2
1 2 2 2 2
2 2 0 1 4
```
## Note

In the first example, the answer is valid because all entries are non-negative integers less than $n = 2$, and $a_{1,1}+a_{2,2} \not\equiv a_{1,2}+a_{2,1} \pmod 2$ (because $a_{1,1}+a_{2,2} = 0 + 0 \equiv 0 \pmod 2$ and $a_{1,2}+a_{2,1} = 1 + 0 \equiv 1 \pmod 2 $). Moreover, the values on the main diagonals are equal to $0,0$ as required.

In the second example, the answer is correct because all entries are non-negative integers less than $n = 3$, and the second condition is satisfied for all quadruplets $(r_1, r_2, c_1, c_2)$. For example: 

* When $r_1=1$, $r_2=2$, $c_1=1$ and $c_2=2$, $a_{1,1}+a_{2,2} \not\equiv a_{1,2}+a_{2,1} \pmod 3$ because $a_{1,1}+a_{2,2} = 1 + 1 \equiv 2 \pmod 3$ and $a_{1,2}+a_{2,1} = 2 + 1 \equiv 0 \pmod 3 $.
* When $r_1=2$, $r_2=3$, $c_1=1$, and $c_2=3$, $a_{2,1}+a_{3,3} \not\equiv a_{2,3}+a_{3,1} \pmod 3$ because $a_{2,1}+a_{3,3} = 1 + 1 \equiv 2 \pmod 3$ and $a_{2,3}+a_{3,1} = 0 + 1 \equiv 1 \pmod 3 $.

 Moreover, the values on the main diagonal are equal to $1,1,1$ as required.

#### Tags 

#2100 #NOT OK #constructive_algorithms #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_822_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
