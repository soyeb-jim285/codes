<h1 style='text-align: center;'> C. Factorials and Powers of Two</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A number is called powerful if it is a power of two or a factorial. In other words, the number $m$ is powerful if there exists a non-negative integer $d$ such that $m=2^d$ or $m=d!$, where $d!=1\cdot 2\cdot \ldots \cdot d$ (in particular, $0! = 1$). For example $1$, $4$, and $6$ are powerful numbers, because $1=1!$, $4=2^2$, and $6=3!$ but $7$, $10$, or $18$ are not.

You are given a positive integer $n$. Find the minimum number $k$ such that $n$ can be represented as the sum of $k$ distinct powerful numbers, or say that there is no such $k$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

A test case consists of only one line, containing one integer $n$ ($1\le n\le 10^{12}$).

### Output

For each test case print the answer on a separate line.

If $n$ can not be represented as the sum of distinct powerful numbers, print $-1$.

Otherwise, print a single positive integer  — the minimum possible value of $k$.

## Example

### Input


```text
471124017179869184
```
### Output

```text

2
3
4
1

```
## Note

In the first test case, $7$ can be represented as $7=1+6$, where $1$ and $6$ are powerful numbers. Because $7$ is not a powerful number, we know that the minimum possible value of $k$ in this case is $k=2$.

In the second test case, a possible way to represent $11$ as the sum of three powerful numbers is $11=1+4+6$. We can show that there is no way to represent $11$ as the sum of two or less powerful numbers. 

In the third test case, $240$ can be represented as $240=24+32+64+120$. Observe that $240=120+120$ is not a valid representation, because the powerful numbers have to be distinct. 

In the fourth test case, $17179869184=2^{34}$, so $17179869184$ is a powerful number and the minimum $k$ in this case is $k=1$.



#### Tags 

#1500 #NOT OK #bitmasks #brute_force #constructive_algorithms #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_774_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
