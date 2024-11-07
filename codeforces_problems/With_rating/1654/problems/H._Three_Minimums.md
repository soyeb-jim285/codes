<h1 style='text-align: center;'> H. Three Minimums</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Given a list of distinct values, we denote with first minimum, second minimum, and third minimum the three smallest values (in increasing order).

A permutation $p_1, p_2, \dots, p_n$ is good if the following statement holds for all pairs $(l,r)$ with $1\le l < l+2 \le r\le n$. 

* If $\{p_l, p_r\}$ are (not necessarily in this order) the first and second minimum of $p_l, p_{l+1}, \dots, p_r$ then the third minimum of $p_l, p_{l+1},\dots, p_r$ is either $p_{l+1}$ or $p_{r-1}$.

You are given an integer $n$ and a string $s$ of length $m$ consisting of characters "<" and ">".

Count the number of good permutations $p_1, p_2,\dots, p_n$ such that, for all $1\le i\le m$, 

* $p_i < p_{i+1}$ if $s_i =$ "<";
* $p_i > p_{i+1}$ if $s_i =$ ">".

 As the result can be very large, you should print it modulo $998\,244\,353$.
####### Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 2 \cdot 10^5$, $1 \leq m \leq \min(100, n-1)$).

The second line contains a string $s$ of length $m$, consisting of characters "<" and ">".

####### Output

Print a single integer: the number of good permutations satisfying the constraints described in the statement, modulo $998\,244\,353$.

## Examples

####### Input


```text
5 3
>>>
```
####### Output


```text
5
```
####### Input


```text
5 1
<
```
####### Output


```text
56
```
####### Input


```text
6 5
<<><>
```
####### Output


```text
23
```
####### Input


```text
10 5
><<><
```
####### Output


```text
83154
```
####### Input


```text
1008 20
<><<>>><<<<<>>>>>>>>
```
####### Output


```text
284142857
```
## Note

In the first test, there are $5$ good permutations satisfying the constraints given by the string $s$: $[4, 3, 2, 1, 5]$, $[5, 3, 2, 1, 4]$, $[5, 4, 2, 1, 3]$, $[5, 4, 3, 1, 2]$, $[5, 4, 3, 2, 1]$. Each of them 

* is good;
* satisfies $p_1 > p_2$;
* satisfies $p_2 > p_3$;
* satisfies $p_3 > p_4$.

In the second test, there are $60$ permutations such that $p_1 < p_2$. Only $56$ of them are good: the permutations $[1, 4, 3, 5, 2]$, $[1, 5, 3, 4, 2]$, $[2, 4, 3, 5, 1]$, $[2, 5, 3, 4, 1]$ are not good because the required condition doesn't hold for $(l, r)$ = $(1, 5)$. For example, for the permutation $[2, 4, 3, 5, 1]$, 

* the first minimum and the second minimum are $p_5$ and $p_1$, respectively (so they are $\{p_l, p_r\}$ up to reordering);
* the third minimum is $p_3$ (neither $p_{l+1}$ nor $p_{r-1}$).

In the third test, there are $23$ good permutations satisfying the constraints given by the string $s$: $[1, 2, 4, 3, 6, 5]$, $[1, 2, 5, 3, 6, 4]$, $[1, 2, 6, 3, 5, 4]$, $[1, 3, 4, 2, 6, 5]$, $[1, 3, 5, 2, 6, 4]$, $[1, 3, 6, 2, 5, 4]$, $[1, 4, 5, 2, 6, 3]$, $[1, 4, 6, 2, 5, 3]$, $[1, 5, 6, 2, 4, 3]$, $[2, 3, 4, 1, 6, 5]$, $[2, 3, 5, 1, 6, 4]$, $[2, 3, 6, 1, 5, 4]$, $[2, 4, 5, 1, 6, 3]$, $[2, 4, 6, 1, 5, 3]$, $[2, 5, 6, 1, 4, 3]$, $[3, 4, 5, 1, 6, 2]$, $[3, 4, 5, 2, 6, 1]$, $[3, 4, 6, 1, 5, 2]$, $[3, 4, 6, 2, 5, 1]$, $[3, 5, 6, 1, 4, 2]$, $[3, 5, 6, 2, 4, 1]$, $[4, 5, 6, 1, 3, 2]$, $[4, 5, 6, 2, 3, 1]$.



#### Tags 

#3500 #NOT OK #combinatorics #constructive_algorithms #divide_and_conquer #dp #fft #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_778_(Div._1_+_Div._2,_based_on_Technocup_2022_Final_Round).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
