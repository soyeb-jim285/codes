<h1 style='text-align: center;'> E. Location</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given two arrays of integers $a_1, a_2, \ldots, a_n$ and $b_1, b_2, \ldots, b_n$. You need to handle $q$ queries of the following two types:

* $1$ $l$ $r$ $x$: assign $a_i := x$ for all $l \leq i \leq r$;
* $2$ $l$ $r$: find the minimum value of the following expression among all $l \leq i \leq r$: $$\frac{\operatorname{lcm}(a_i, b_i)}{\gcd(a_i, b_i)}.$$

In this problem $\gcd(x, y)$ denotes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of $x$ and $y$, and $\operatorname{lcm}(x, y)$ denotes the [least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple) of $x$ and $y$.

#### Input

The first line contains two integers $n$ and $q$ ($1 \leq n, q \leq 5 \cdot 10^4$) — the number of numbers in the arrays $a$ and $b$ and the number of queries.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 5 \cdot 10^4$) — the elements of the array $a$.

The third line contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \leq b_i \leq 5 \cdot 10^4$) — the elements of the array $b$.

Then $q$ lines follow, $j$-th of which starts with an integer $t_j$ ($1 \leq t_j \leq 2$) and means that the $j$-th query has type $t_j$.

If $t_j = 1$, it is followed by three integers $l_j$, $r_j$, and $x_j$ ($1 \leq l_j \leq r_j \leq n$, $1 \leq x_j \leq 5 \cdot 10^4$).

If $t_j = 2$, it is followed by two integers $l_j$ and $r_j$ ($1 \leq l_j \leq r_j \leq n$).

It is guaranteed that there is at least one query of type $2$.

#### Output

For each query of the second type, output the minimum value of the expression.

## Examples

#### Input


```text
10 106 10 15 4 9 25 2 3 5 301 2 3 4 6 9 12 15 18 302 1 101 7 10 92 5 101 1 6 142 4 72 3 91 2 9 302 1 42 3 72 5 10
```
#### Output

```text

1
2
12
2
10
5
2

```
#### Input


```text
4 410 2 12 51 12 16 12 2 41 2 3 181 2 2 102 2 3
```
#### Output

```text

5
30

```
## Note

In the first example:

* For the first query we can choose $i = 4$. So the value is $\frac{\operatorname{lcm}(4, 4)}{\gcd(4, 4)} = \frac{4}{4} = 1$.
* After the second query the array $a = [6, 10, 15, 4, 9, 25, 9, 9, 9, 9]$.
* For the third query we can choose $i = 9$. So the value is $\frac{\operatorname{lcm}(9, 18)}{\gcd(9, 18)} = \frac{18}{9} = 2$.

In the second:

* For the first query we can choose $i = 4$. So the value is $\frac{\operatorname{lcm}(1, 5)}{\gcd(1, 5)} = \frac{5}{1} = 5$.
* After the second query the array $a = [10, 18, 18, 5]$.
* After the third query the array $a = [10, 10, 18, 5]$.
* For the fourth query we can choose $i = 2$. So the value is $\frac{\operatorname{lcm}(10, 12)}{\gcd(10, 12)} = \frac{60}{2} = 30$.


#### Tags 

#2800 #NOT OK #data_structures #dp #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_830_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
