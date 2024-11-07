<h1 style='text-align: center;'> D. Counting Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Consider an array $a$ of length $n$ with elements numbered from $1$ to $n$. It is possible to remove the $i$-th element of $a$ if $gcd(a_i, i) = 1$, where $gcd$ denotes the greatest common divisor. After an element is removed, the elements to the right are shifted to the left by one position.

An array $b$ with $n$ integers such that $1 \le b_i \le n - i + 1$ is a removal sequence for the array $a$ if it is possible to remove all elements of $a$, if you remove the $b_1$-th element, then the $b_2$-th, ..., then the $b_n$-th element. For example, let $a = [42, 314]$:

* $[1, 1]$ is a removal sequence: when you remove the $1$-st element of the array, the condition $gcd(42, 1) = 1$ holds, and the array becomes $[314]$; when you remove the $1$-st element again, the condition $gcd(314, 1) = 1$ holds, and the array becomes empty.
* $[2, 1]$ is not a removal sequence: when you try to remove the $2$-nd element, the condition $gcd(314, 2) = 1$ is false.

An array is ambiguous if it has at least two removal sequences. For example, the array $[1, 2, 5]$ is ambiguous: it has removal sequences $[3, 1, 1]$ and $[1, 2, 1]$. The array $[42, 314]$ is not ambiguous: the only removal sequence it has is $[1, 1]$.

You are given two integers $n$ and $m$. You have to calculate the number of ambiguous arrays $a$ such that the length of $a$ is from $1$ to $n$ and each $a_i$ is an integer from $1$ to $m$.

###### Input

The only line of the input contains two integers $n$ and $m$ ($2 \le n \le 3 \cdot 10^5$; $1 \le m \le 10^{12}$).

###### Output

Print one integer — the number of ambiguous arrays $a$ such that the length of $a$ is from $1$ to $n$ and each $a_i$ is an integer from $1$ to $m$. Since the answer can be very large, print it modulo $998244353$.

## Examples

###### Input


```text
2 3
```
###### Output


```text
6
```
###### Input


```text
4 2
```
###### Output


```text
26
```
###### Input


```text
4 6
```
###### Output


```text
1494
```
###### Input


```text
1337 424242424242
```
###### Output


```text
119112628
```


#### Tags 

#1900 #NOT OK #combinatorics #dp #math #number_theory 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_138_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
