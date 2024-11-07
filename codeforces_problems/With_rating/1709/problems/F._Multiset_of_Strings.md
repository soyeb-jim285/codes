<h1 style='text-align: center;'> F. Multiset of Strings</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given three integers $n$, $k$ and $f$.

Consider all binary strings (i. e. all strings consisting of characters $0$ and/or $1$) of length from $1$ to $n$. For every such string $s$, you need to choose an integer $c_s$ from $0$ to $k$.

A multiset of binary strings of length exactly $n$ is considered beautiful if for every binary string $s$ with length from $1$ to $n$, the number of strings in the multiset such that $s$ is their prefix is not exceeding $c_s$.

For example, let $n = 2$, $c_{0} = 3$, $c_{00} = 1$, $c_{01} = 2$, $c_{1} = 1$, $c_{10} = 2$, and $c_{11} = 3$. The multiset of strings $\{11, 01, 00, 01\}$ is beautiful, since:

* for the string $0$, there are $3$ strings in the multiset such that $0$ is their prefix, and $3 \le c_0$;
* for the string $00$, there is one string in the multiset such that $00$ is its prefix, and $1 \le c_{00}$;
* for the string $01$, there are $2$ strings in the multiset such that $01$ is their prefix, and $2 \le c_{01}$;
* for the string $1$, there is one string in the multiset such that $1$ is its prefix, and $1 \le c_1$;
* for the string $10$, there are $0$ strings in the multiset such that $10$ is their prefix, and $0 \le c_{10}$;
* for the string $11$, there is one string in the multiset such that $11$ is its prefix, and $1 \le c_{11}$.

Now, for the problem itself. You have to calculate the number of ways to choose the integer $c_s$ for every binary string $s$ of length from $1$ to $n$ in such a way that the maximum possible size of a beautiful multiset is exactly $f$.

####### Input

The only line of input contains three integers $n$, $k$ and $f$ ($1 \le n \le 15$; $1 \le k, f \le 2 \cdot 10^5$).

####### Output

Print one integer — the number of ways to choose the integer $c_s$ for every binary string $s$ of length from $1$ to $n$ in such a way that the maximum possible size of a beautiful multiset is exactly $f$. Since it can be huge, print it modulo $998244353$.

## Examples

####### Input


```text
1 42 2
```
####### Output


```text
3
```
####### Input


```text
2 37 13
```
####### Output


```text
36871576
```
####### Input


```text
4 1252 325
```
####### Output


```text
861735572
```
####### Input


```text
6 153 23699
```
####### Output


```text
0
```
####### Input


```text
15 200000 198756
```
####### Output


```text
612404746
```
## Note

In the first example, the three ways to choose the integers $c_s$ are:

* $c_0 = 0$, $c_1 = 2$, then the maximum beautiful multiset is $\{1, 1\}$;
* $c_0 = 1$, $c_1 = 1$, then the maximum beautiful multiset is $\{0, 1\}$;
* $c_0 = 2$, $c_1 = 0$, then the maximum beautiful multiset is $\{0, 0\}$.


#### Tags 

#2500 #NOT OK #bitmasks #brute_force #dp #fft #flows #graphs #math #meet-in-the-middle #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_132_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
