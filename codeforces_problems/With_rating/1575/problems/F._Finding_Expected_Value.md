<h1 style='text-align: center;'> F. Finding Expected Value</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Mr. Chanek opened a letter from his fellow, who is currently studying at Singanesia. Here is what it says.

Define an array $b$ ($0 \leq b_i < k$) with $n$ integers. While there exists a pair $(i, j)$ such that $b_i \ne b_j$, do the following operation:

* Randomly pick a number $i$ satisfying $0 \leq i < n$. Note that each number $i$ has a probability of $\frac{1}{n}$ to be picked.
* Randomly Pick a number $j$ satisfying $0 \leq j < k$.
* Change the value of $b_i$ to $j$. It is possible for $b_i$ to be changed to the same value.

Denote $f(b)$ as the expected number of operations done to $b$ until all elements of $b$ are equal. 

You are given two integers $n$ and $k$, and an array $a$ ($-1 \leq a_i < k$) of $n$ integers. 

For every index $i$ with $a_i = -1$, replace $a_i$ with a random number $j$ satisfying $0 \leq j < k$. Let $c$ be the number of occurrences of $-1$ in $a$. There are $k^c$ possibilites of $a$ after the replacement, each with equal probability of being the final array.

Find the expected value of $f(a)$ modulo $10^9 + 7$. 

Formally, let $M = 10^9 + 7$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. 
####### Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output such an integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

After reading the letter, Mr. Chanek gave the task to you. Solve it for the sake of their friendship!

####### Input

The first line contains two integers $n$ and $k$ ($2 \leq n \leq 10^5$, $2 \leq k \leq 10^9$). 

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-1 \leq a_i < k$).

####### Output

####### Output

 an integer denoting the expected value of $f(a)$ modulo $10^9 + 7$.

## Examples

####### Input


```text
2 2
0 1
```
####### Output


```text
2
```
####### Input


```text
2 2
0 -1
```
####### Output


```text
1
```
####### Input


```text
3 3
0 1 1
```
####### Output


```text
12
```
####### Input


```text
3 3
-1 -1 -1
```
####### Output


```text
11
```
####### Input


```text
10 9
-1 0 -1 1 1 2 2 3 3 3
```
####### Output


```text
652419213
```


#### Tags 

#2900 #NOT OK #math 

## Blogs
- [All Contest Problems](../COMPFEST_13_-_Finals_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [COMPFEST 13 — Editorial (en)](../blogs/COMPFEST_13_—_Editorial_(en).md)
