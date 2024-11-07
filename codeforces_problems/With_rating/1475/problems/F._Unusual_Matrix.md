<h1 style='text-align: center;'> F. Unusual Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two binary square matrices $a$ and $b$ of size $n \times n$. A matrix is called binary if each of its elements is equal to $0$ or $1$. You can do the following operations on the matrix $a$ arbitrary number of times (0 or more): 

* vertical xor. You choose the number $j$ ($1 \le j \le n$) and for all $i$ ($1 \le i \le n$) do the following: $a_{i, j} := a_{i, j} \oplus 1$ ($\oplus$ — is the operation [xor](https://en.wikipedia.org/wiki/Exclusive_or) (exclusive or)).
* horizontal xor. You choose the number $i$ ($1 \le i \le n$) and for all $j$ ($1 \le j \le n$) do the following: $a_{i, j} := a_{i, j} \oplus 1$.

## Note

 that the elements of the $a$ matrix change after each operation.

For example, if $n=3$ and the matrix $a$ is: $$ \begin{pmatrix} 1 & 1 & 0 \\\ 0 & 0 & 1 \\\ 1 & 1 & 0 \end{pmatrix} $$ Then the following sequence of operations shows an example of transformations: 

* vertical xor, $j=1$. $$ a= \begin{pmatrix} 0 & 1 & 0 \\\ 1 & 0 & 1 \\\ 0 & 1 & 0 \end{pmatrix} $$
* horizontal xor, $i=2$. $$ a= \begin{pmatrix} 0 & 1 & 0 \\\ 0 & 1 & 0 \\\ 0 & 1 & 0 \end{pmatrix} $$
* vertical xor, $j=2$. $$ a= \begin{pmatrix} 0 & 0 & 0 \\\ 0 & 0 & 0 \\\ 0 & 0 & 0 \end{pmatrix} $$

Check if there is a sequence of operations such that the matrix $a$ becomes equal to the matrix $b$.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. Then $t$ test cases follow.

The first line of each test case contains one integer $n$ ($1 \leq n \leq 1000$) — the size of the matrices.

The following $n$ lines contain strings of length $n$, consisting of the characters '0' and '1' — the description of the matrix $a$.

An empty line follows.

The following $n$ lines contain strings of length $n$, consisting of the characters '0' and '1' — the description of the matrix $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

### Output

For each test case, output on a separate line: 

* "YES", there is such a sequence of operations that the matrix $a$ becomes equal to the matrix $b$;
* "NO" otherwise.

You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).

## Example

### Input


```text
3
3
110
001
110

000
000
000
3
101
010
101

010
101
010
2
01
11

10
10
```
### Output


```text
YES
YES
NO
```
## Note

The first test case is explained in the statements.

In the second test case, the following sequence of operations is suitable: 

* horizontal xor, $i=1$;
* horizontal xor, $i=2$;
* horizontal xor, $i=3$;

It can be proved that there is no sequence of operations in the third test case so that the matrix $a$ becomes equal to the matrix $b$.



#### Tags 

#1900 #NOT OK #2-sat #brute_force #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_697_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
