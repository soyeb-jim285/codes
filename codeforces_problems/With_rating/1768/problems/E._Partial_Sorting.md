<h1 style='text-align: center;'> E. Partial Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Consider a permutation$^\dagger$ $p$ of length $3n$. Each time you can do one of the following operations:

* Sort the first $2n$ elements in increasing order.
* Sort the last $2n$ elements in increasing order.

We can show that every permutation can be made sorted in increasing order using only these operations. Let's call $f(p)$ the minimum number of these operations needed to make the permutation $p$ sorted in increasing order.

Given $n$, find the sum of $f(p)$ over all $(3n)!$ permutations $p$ of size $3n$.

Since the answer could be very large, output it modulo a prime $M$.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

##### Input

The only line of input contains two numbers $n$ and $M$ ($1 \leq n \leq 10^6$, $10^8 \leq M \leq 10^9$). It is guaranteed that $M$ is a prime number.

##### Output

##### Output

 the answer modulo $M$.

## Examples

##### Input


```text
1 100009067
```
##### Output


```text
9
```
##### Input


```text
2 100000357
```
##### Output


```text
1689
```
##### Input


```text
69 999900997
```
##### Output


```text
193862705
```
## Note

In the first test case, all the permutations are:

* $[1, 2, 3]$, which requires $0$ operations;
* $[1, 3, 2]$, which requires $1$ operation;
* $[2, 1, 3]$, which requires $1$ operation;
* $[2, 3, 1]$, which requires $2$ operations;
* $[3, 1, 2]$, which requires $2$ operations;
* $[3, 2, 1]$, which requires $3$ operations.

Therefore, the answer is $0+1+1+2+2+3=9$.



#### Tags 

#2300 #NOT OK #combinatorics #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_842_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
