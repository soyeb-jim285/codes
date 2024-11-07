<h1 style='text-align: center;'> D. Not Adding</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a_1, a_2, \dots, a_n$ consisting of $n$ distinct integers. You are allowed to perform the following operation on it:

* Choose two elements from the array $a_i$ and $a_j$ ($i \ne j$) such that $\gcd(a_i, a_j)$ is not present in the array, and add $\gcd(a_i, a_j)$ to the end of the array. Here $\gcd(x, y)$ denotes [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $x$ and $y$.

## Note

 that the array changes after each operation, and the subsequent operations are performed on the new array.

What is the maximum number of times you can perform the operation on the array?

#### Input

The first line consists of a single integer $n$ ($2 \le n \le 10^6$).

The second line consists of $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^6$). All $a_i$ are distinct.

#### Output

#### Output

 a single line containing one integer — the maximum number of times the operation can be performed on the given array.

## Examples

#### Input


```text
5
4 20 1 25 30
```
#### Output


```text
3
```
#### Input

```text

3
6 10 15

```
#### Output


```text

4
```
## Note

In the first example, one of the ways to perform maximum number of operations on the array is: 

* Pick $i = 1, j= 5$ and add $\gcd(a_1, a_5) = \gcd(4, 30) = 2$ to the array.
* Pick $i = 2, j= 4$ and add $\gcd(a_2, a_4) = \gcd(20, 25) = 5$ to the array.
* Pick $i = 2, j= 5$ and add $\gcd(a_2, a_5) = \gcd(20, 30) = 10$ to the array.

It can be proved that there is no way to perform more than $3$ operations on the original array.

In the second example one can add $3$, then $1$, then $5$, and $2$.



#### Tags 

#1900 #NOT OK #brute_force #dp #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_766_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
