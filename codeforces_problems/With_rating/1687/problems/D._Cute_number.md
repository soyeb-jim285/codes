<h1 style='text-align: center;'> D. Cute number</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ran is especially skilled in computation and mathematics. It is said that she can do unimaginable calculation work in an instant.—Perfect Memento in Strict SenseRan Yakumo is a cute girl who loves creating cute Maths problems.

Let $f(x)$ be the minimal [square number](https://en.wikipedia.org/wiki/Square_number) strictly greater than $x$, and $g(x)$ be the maximal square number less than or equal to $x$. For example, $f(1)=f(2)=g(4)=g(8)=4$.

A positive integer $x$ is cute if $x-g(x)<f(x)-x$. For example, $1,5,11$ are cute integers, while $3,8,15$ are not. 

Ran gives you an array $a$ of length $n$. She wants you to find the smallest non-negative integer $k$ such that $a_i + k$ is a cute number for any element of $a$.

##### Input

The first line contains one integer $n$ ($1 \leq n \leq 10^6$) — the length of $a$.

The second line contains $n$ intergers $a_1,a_2,\ldots,a_n$ ($1 \leq a_1 \leq a_2 \leq \ldots \leq a_n \leq 2\cdot 10^6$) — the array $a$.

##### Output

Print a single interger $k$ — the answer.

## Examples

##### Input


```text
4
1 3 8 10
```
##### Output


```text
1
```
##### Input


```text
5
2 3 8 9 11
```
##### Output


```text
8
```
##### Input


```text
8
1 2 3 4 5 6 7 8
```
##### Output


```text
48
```
## Note

Test case 1:

$3$ is not cute integer, so $k\ne 0$.

$2,4,9,11$ are cute integers, so $k=1$.



#### Tags 

#2900 #NOT OK #binary_search #brute_force #data_structures #dsu #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_796_(Div._1).md)
- [Codeforces Round #796 (en)](../blogs/Codeforces_Round_796_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
