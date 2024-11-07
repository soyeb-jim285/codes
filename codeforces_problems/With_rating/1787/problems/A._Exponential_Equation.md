<h1 style='text-align: center;'> A. Exponential Equation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$.

Find any pair of integers $(x,y)$ ($1\leq x,y\leq n$) such that $x^y\cdot y+y^x\cdot x = n$.

### Input

The first line contains a single integer $t$ ($1\leq t\leq 10^4$) — the number of test cases.

Each test case contains one line with a single integer $n$ ($1\leq n\leq 10^9$).

### Output

For each test case, if possible, print two integers $x$ and $y$ ($1\leq x,y\leq n$). If there are multiple answers, print any.

Otherwise, print $-1$.

## Example

### Input


```text
537423125020732790
```
### Output

```text

-1
-1
2 3
5 5
3 13

```
## Note

In the third test case, $2^3 \cdot 3+3^2 \cdot 2 = 42$, so $(2,3),(3,2)$ will be considered as legal solutions.

In the fourth test case, $5^5 \cdot 5+5^5 \cdot 5 = 31250$, so $(5,5)$ is a legal solution.



#### Tags 

#800 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../TypeDB_Forces_2023_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement #1 (en)](../blogs/Announcement_1_(en).md)
- [TypeDB Forces 2023 (en)](../blogs/TypeDB_Forces_2023_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
