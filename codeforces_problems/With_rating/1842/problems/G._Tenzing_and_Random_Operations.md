<h1 style='text-align: center;'> G. Tenzing and Random Operations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Yet another random problem.Tenzing has an array $a$ of length $n$ and an integer $v$.

Tenzing will perform the following operation $m$ times:

1. Choose an integer $i$ such that $1 \leq i \leq n$ uniformly at random.
2. For all $j$ such that $i \leq j \leq n$, set $a_j := a_j + v$.

Tenzing wants to know the expected value of $\prod_{i=1}^n a_i$ after performing the $m$ operations, modulo $10^9+7$.

Formally, let $M = 10^9+7$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. 
#### Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output the integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

#### Input

The first line of input contains three integers $n$, $m$ and $v$ ($1\leq n\leq 5000$, $1\leq m,v\leq 10^9$).

The second line of input contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\leq a_i\leq 10^9$).

#### Output

#### Output

 the expected value of $\prod_{i=1}^n a_i$ modulo $10^9+7$.

## Examples

#### Input


```text
2 2 5
2 2
```
#### Output


```text
84
```
#### Input


```text
5 7 9
9 9 8 2 4
```
#### Output


```text
975544726
```
## Note

There are three types of $a$ after performing all the $m$ operations : 

1. $a_1=2,a_2=12$ with $\frac{1}{4}$ probability.

2. $a_1=a_2=12$ with $\frac{1}{4}$ probability.

3. $a_1=7,a_2=12$ with $\frac{1}{2}$ probability.

So the expected value of $a_1\cdot a_2$ is $\frac{1}{4}\cdot (24+144) + \frac{1}{2}\cdot 84=84$.



#### Tags 

#2800 #NOT OK #combinatorics #dp #math #probabilities 

## Blogs
- [All Contest Problems](../CodeTON_Round_5_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
