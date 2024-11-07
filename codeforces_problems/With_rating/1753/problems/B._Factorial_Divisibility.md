<h1 style='text-align: center;'> B. Factorial Divisibility</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $x$ and an array of integers $a_1, a_2, \ldots, a_n$. You have to determine if the number $a_1! + a_2! + \ldots + a_n!$ is divisible by $x!$.

Here $k!$ is a factorial of $k$ — the product of all positive integers less than or equal to $k$. For example, $3! = 1 \cdot 2 \cdot 3 = 6$, and $5! = 1 \cdot 2 \cdot 3 \cdot 4 \cdot 5 = 120$.

####### Input

The first line contains two integers $n$ and $x$ ($1 \le n \le 500\,000$, $1 \le x \le 500\,000$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le x$) — elements of given array.

####### Output

In the only line print "Yes" (without quotes) if $a_1! + a_2! + \ldots + a_n!$ is divisible by $x!$, and "No" (without quotes) otherwise.

## Examples

####### Input


```text
6 4
3 2 2 2 3 3
```
####### Output


```text
Yes
```
####### Input


```text
8 3
3 2 2 2 2 2 1 1
```
####### Output


```text
Yes
```
####### Input


```text
7 8
7 7 7 7 7 7 7
```
####### Output


```text
No
```
####### Input


```text
10 5
4 3 2 1 4 3 2 4 3 4
```
####### Output


```text
No
```
####### Input


```text
2 500000
499999 499999
```
####### Output


```text
No
```
## Note

In the first example $3! + 2! + 2! + 2! + 3! + 3! = 6 + 2 + 2 + 2 + 6 + 6 = 24$. Number $24$ is divisible by $4! = 24$.

In the second example $3! + 2! + 2! + 2! + 2! + 2! + 1! + 1! = 18$, is divisible by $3! = 6$.

In the third example $7! + 7! + 7! + 7! + 7! + 7! + 7! = 7 \cdot 7!$. It is easy to prove that this number is not divisible by $8!$.



#### Tags 

#1600 #NOT OK #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_829_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
