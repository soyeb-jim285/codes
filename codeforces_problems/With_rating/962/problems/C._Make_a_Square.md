<h1 style='text-align: center;'> C. Make a Square</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$, written without leading zeroes (for example, the number 04 is incorrect). 

In one operation you can delete any digit of the given integer so that the result remains a positive integer without leading zeros.

Determine the minimum number of operations that you need to consistently apply to the given integer $n$ to make from it the square of some positive integer or report that it is impossible.

An integer $x$ is the square of some positive integer if and only if $x=y^2$ for some positive integer $y$.

##### Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^{9}$). The number is given without leading zeroes.

##### Output

If it is impossible to make the square of some positive integer from $n$, print -1. In the other case, print the minimal number of operations required to do it.

## Examples

##### Input


```text
8314  

```
##### Output


```text
2  

```
##### Input


```text
625  

```
##### Output


```text
0  

```
##### Input


```text
333  

```
##### Output


```text
-1  

```
## Note

In the first example we should delete from $8314$ the digits $3$ and $4$. After that $8314$ become equals to $81$, which is the square of the integer $9$.

In the second example the given $625$ is the square of the integer $25$, so you should not delete anything. 

In the third example it is impossible to make the square from $333$, so the answer is -1.



#### Tags 

#1400 #NOT OK #brute_force #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_42_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Разбор задач](../blogs/Разбор_задач.md)
