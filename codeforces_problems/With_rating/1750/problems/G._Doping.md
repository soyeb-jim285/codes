<h1 style='text-align: center;'> G. Doping</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

We call an array $a$ of length $n$ fancy if for each $1 < i \le n$ it holds that $a_i = a_{i-1} + 1$.

Let's call $f(p)$ applied to a permutation$^\dagger$ of length $n$ as the minimum number of subarrays it can be partitioned such that each one of them is fancy. For example $f([1,2,3]) = 1$, while $f([3,1,2]) = 2$ and $f([3,2,1]) = 3$.

Given $n$ and a permutation $p$ of length $n$, we define a permutation $p'$ of length $n$ to be $k$-special if and only if:

* $p'$ is lexicographically smaller$^\ddagger$ than $p$, and
* $f(p') = k$.

Your task is to count for each $1 \le k \le n$ the number of $k$-special permutations modulo $m$.

$^\dagger$ A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

$^\ddagger$ A permutation $a$ of length $n$ is lexicographically smaller than a permutation $b$ of length $n$ if and only if the following holds: in the first position where $a$ and $b$ differ, the permutation $a$ has a smaller element than the corresponding element in $b$.

###### Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 2000$, $10 \le m \le 10^9$) — the length of the permutation and the required modulo.

The second line contains $n$ distinct integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$) — the permutation $p$.

###### Output

Print $n$ integers, where the $k$-th integer is the number of $k$-special permutations modulo $m$.

## Examples

###### Input


```text
4 666012
1 3 4 2
```
###### Output


```text
1 0 1 1 
```
###### Input

```text

3 10
3 2 1

```
###### Output


```text
1 2 2 
```
###### Input

```text

7 1000000000
7 2 1 3 5 4 6

```
###### Output


```text
1 6 40 201 705 1635 1854 
```
###### Input

```text

10 11
10 9 8 7 6 5 4 3 2 1

```
###### Output


```text

1 9 9 0 1 5 5 0 1 0 
```
## Note

In the first example, the permutations that are lexicographically smaller than $[1,3,4,2]$ are:

* $[1,2,3,4]$, $f([1,2,3,4])=1$;
* $[1,2,4,3]$, $f([1,2,4,3])=3$;
* $[1,3,2,4]$, $f([1,3,2,4])=4$.

Thus our answer is $[1,0,1,1]$.

In the second example, the permutations that are lexicographically smaller than $[3,2,1]$ are:

* $[1,2,3]$, $f([1,2,3])=1$;
* $[1,3,2]$, $f([1,3,2])=3$;
* $[2,1,3]$, $f([2,1,3])=3$;
* $[2,3,1]$, $f([2,3,1])=2$;
* $[3,1,2]$, $f([3,1,2])=2$.

Thus our answer is $[1,2,2]$.



#### Tags 

#3300 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../CodeTON_Round_3_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
