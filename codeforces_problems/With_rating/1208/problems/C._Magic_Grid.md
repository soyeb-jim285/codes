<h1 style='text-align: center;'> C. Magic Grid</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let us define a magic grid to be a square matrix of integers of size $n \times n$, satisfying the following conditions. 

* All integers from $0$ to $(n^2 - 1)$ inclusive appear in the matrix exactly once.
* [Bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all elements in a row or a column must be the same for each row and column.

You are given an integer $n$ which is a multiple of $4$. Construct a magic grid of size $n \times n$.

#### Input

The only line of input contains an integer $n$ ($4 \leq n \leq 1000$). It is guaranteed that $n$ is a multiple of $4$.

#### Output

Print a magic grid, i.e. $n$ lines, the $i$-th of which contains $n$ space-separated integers, representing the $i$-th row of the grid.

If there are multiple answers, print any. We can show that an answer always exists.

## Examples

#### Input


```text
4
```
#### Output


```text
8 9 1 13
3 12 7 5
0 2 4 11
6 10 15 14
```
#### Input

```text

8

```
#### Output


```text

19 55 11 39 32 36 4 52
51 7 35 31 12 48 28 20
43 23 59 15 0 8 16 44
3 47 27 63 24 40 60 56
34 38 6 54 17 53 9 37
14 50 30 22 49 5 33 29
2 10 18 46 41 21 57 13
26 42 62 58 1 45 25 61
```
## Note

In the first example, XOR of each row and each column is $13$.

In the second example, XOR of each row and each column is $60$.



#### Tags 

#1800 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Manthan,_Codefest_19_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Manthan — Codefest'19 (en)](../blogs/Manthan_—_Codefest'19_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
