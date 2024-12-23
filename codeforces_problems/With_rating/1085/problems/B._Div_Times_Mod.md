<h1 style='text-align: center;'> B. Div Times Mod</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya likes to solve equations. Today he wants to solve $(x~\mathrm{div}~k) \cdot (x \bmod k) = n$, where $\mathrm{div}$ and $\mathrm{mod}$ stand for integer division and modulo operations (refer to the 
## Note

s below for exact definition). In this equation, $k$ and $n$ are positive integer parameters, and $x$ is a positive integer unknown. If there are several solutions, Vasya wants to find the smallest possible $x$. Can you help him?

##### Input

The first line contains two integers $n$ and $k$ ($1 \leq n \leq 10^6$, $2 \leq k \leq 1000$).

##### Output

Print a single integer $x$ — the smallest positive integer solution to $(x~\mathrm{div}~k) \cdot (x \bmod k) = n$. It is guaranteed that this equation has at least one positive integer solution.

## Examples

##### Input


```text
6 3
```
##### Output


```text
11
```
##### Input


```text
1 2
```
##### Output


```text
3
```
##### Input


```text
4 6
```
##### Output


```text
10
```
## Note

The result of integer division $a~\mathrm{div}~b$ is equal to the largest integer $c$ such that $b \cdot c \leq a$. $a$ modulo $b$ (shortened $a \bmod b$) is the only integer $c$ such that $0 \leq c < b$, and $a - c$ is divisible by $b$.

In the first sample, $11~\mathrm{div}~3 = 3$ and $11 \bmod 3 = 2$. Since $3 \cdot 2 = 6$, then $x = 11$ is a solution to $(x~\mathrm{div}~3) \cdot (x \bmod 3) = 6$. One can see that $19$ is the only other positive integer solution, hence $11$ is the smallest one.



#### Tags 

#1100 #NOT OK #math 

## Blogs
- [All Contest Problems](../Technocup_2019_-_Elimination_Round_4.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
