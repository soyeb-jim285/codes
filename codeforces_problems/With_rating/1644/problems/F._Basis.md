<h1 style='text-align: center;'> F. Basis</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

For an array of integers $a$, let's define $|a|$ as the number of elements in it.

Let's denote two functions:

* $F(a, k)$ is a function that takes an array of integers $a$ and a positive integer $k$. The result of this function is the array containing $|a|$ first elements of the array that you get by replacing each element of $a$ with exactly $k$ copies of that element.For example, $F([2, 2, 1, 3, 5, 6, 8], 2)$ is calculated as follows: first, you replace each element of the array with $2$ copies of it, so you obtain $[2, 2, 2, 2, 1, 1, 3, 3, 5, 5, 6, 6, 8, 8]$. Then, you take the first $7$ elements of the array you obtained, so the result of the function is $[2, 2, 2, 2, 1, 1, 3]$.
* $G(a, x, y)$ is a function that takes an array of integers $a$ and two different integers $x$ and $y$. The result of this function is the array $a$ with every element equal to $x$ replaced by $y$, and every element equal to $y$ replaced by $x$.For example, $G([1, 1, 2, 3, 5], 3, 1) = [3, 3, 2, 1, 5]$.

An array $a$ is a parent of the array $b$ if:

* either there exists a positive integer $k$ such that $F(a, k) = b$;
* or there exist two different integers $x$ and $y$ such that $G(a, x, y) = b$.

An array $a$ is an ancestor of the array $b$ if there exists a finite sequence of arrays $c_0, c_1, \dots, c_m$ ($m \ge 0$) such that $c_0$ is $a$, $c_m$ is $b$, and for every $i \in [1, m]$, $c_{i-1}$ is a parent of $c_i$.

And now, the problem itself.

You are given two integers $n$ and $k$. Your goal is to construct a sequence of arrays $s_1, s_2, \dots, s_m$ in such a way that:

* every array $s_i$ contains exactly $n$ elements, and all elements are integers from $1$ to $k$;
* for every array $a$ consisting of exactly $n$ integers from $1$ to $k$, the sequence contains at least one array $s_i$ such that $s_i$ is an ancestor of $a$.

Print the minimum number of arrays in such sequence.

######## Input

The only line contains two integers $n$ and $k$ ($1 \le n, k \le 2 \cdot 10^5$).

######## Output

Print one integer — the minimum number of elements in a sequence of arrays meeting the constraints. Since the answer can be large, output it modulo $998244353$.

## Examples

######## Input


```text
3 2
```
######## Output


```text
2
```
######## Input


```text
4 10
```
######## Output


```text
12
```
######## Input


```text
13 37
```
######## Output


```text
27643508
```
######## Input


```text
1337 42
```
######## Output


```text
211887828
```
######## Input


```text
198756 123456
```
######## Output


```text
159489391
```
######## Input


```text
123456 198756
```
######## Output


```text
460526614
```
## Note

Let's analyze the first example.

One of the possible answers for the first example is the sequence $[[2, 1, 2], [1, 2, 2]]$. Every array of size $3$ consisting of elements from $1$ to $2$ has an ancestor in this sequence:

* for the array $[1, 1, 1]$, the ancestor is $[1, 2, 2]$: $F([1, 2, 2], 13) = [1, 1, 1]$;
* for the array $[1, 1, 2]$, the ancestor is $[1, 2, 2]$: $F([1, 2, 2], 2) = [1, 1, 2]$;
* for the array $[1, 2, 1]$, the ancestor is $[2, 1, 2]$: $G([2, 1, 2], 1, 2) = [1, 2, 1]$;
* for the array $[1, 2, 2]$, the ancestor is $[1, 2, 2]$;
* for the array $[2, 1, 1]$, the ancestor is $[1, 2, 2]$: $G([1, 2, 2], 1, 2) = [2, 1, 1]$;
* for the array $[2, 1, 2]$, the ancestor is $[2, 1, 2]$;
* for the array $[2, 2, 1]$, the ancestor is $[2, 1, 2]$: $F([2, 1, 2], 2) = [2, 2, 1]$;
* for the array $[2, 2, 2]$, the ancestor is $[1, 2, 2]$: $G(F([1, 2, 2], 4), 1, 2) = G([1, 1, 1], 1, 2) = [2, 2, 2]$.


#### Tags 

#2900 #NOT OK #combinatorics #fft #math #number_theory 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_123_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
