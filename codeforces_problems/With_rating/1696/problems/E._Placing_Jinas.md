<h1 style='text-align: center;'> E. Placing Jinas</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

We say an infinite sequence $a_{0}, a_{1}, a_2, \ldots$ is non-increasing if and only if for all $i\ge 0$, $a_i \ge a_{i+1}$.

There is an infinite right and down grid. The upper-left cell has coordinates $(0,0)$. Rows are numbered $0$ to infinity from top to bottom, columns are numbered from $0$ to infinity from left to right.

There is also a non-increasing infinite sequence $a_{0}, a_{1}, a_2, \ldots$. You are given $a_0$, $a_1$, $\ldots$, $a_n$; for all $i>n$, $a_i=0$. For every pair of $x$, $y$, the cell with coordinates $(x,y)$ (which is located at the intersection of $x$-th row and $y$-th column) is white if $y<a_x$ and black otherwise.

Initially there is one doll named Jina on $(0,0)$. You can do the following operation.

* Select one doll on $(x,y)$. Remove it and place a doll on $(x,y+1)$ and place a doll on $(x+1,y)$.

## Note

 that multiple dolls can be present at a cell at the same time; in one operation, you remove only one. Your goal is to make all white cells contain $0$ dolls.

What's the minimum number of operations needed to achieve the goal? Print the answer modulo $10^9+7$.

#### Input

The first line of input contains one integer $n$ ($1\le n\le 2\cdot 10^5$).

The second line of input contains $n+1$ integers $a_0,a_1,\ldots,a_n$ ($0\le a_i\le 2\cdot 10^5$).

It is guaranteed that the sequence $a$ is non-increasing.

#### Output

Print one integer — the answer to the problem, modulo $10^9+7$.

## Examples

#### Input


```text
2
2 2 0
```
#### Output


```text
5
```
#### Input

```text

10
12 11 8 8 6 6 6 5 3 2 1

```
#### Output


```text

2596
```
## Note

Consider the first example. In the given grid, cells $(0,0),(0,1),(1,0),(1,1)$ are white, and all other cells are black. Let us use triples to describe the grid: triple $(x,y,z)$ means that there are $z$ dolls placed on cell $(x,y)$. Initially the state of the grid is $(0,0,1)$.

One of the optimal sequence of operations is as follows:

* Do the operation with $(0,0)$. Now the state of the grid is $(1,0,1),(0,1,1)$.
* Do the operation with $(0,1)$. Now the state of the grid is $(1,0,1),(1,1,1),(0,2,1)$.
* Do the operation with $(1,0)$. Now the state of the grid is $(1,1,2),(0,2,1),(2,0,1)$.
* Do the operation with $(1,1)$. Now the state of the grid is $(1,1,1),(0,2,1),(2,0,1),(1,2,1),(2,1,1)$.
* Do the operation with $(1,1)$. Now the state of the grid is $(0,2,1),(2,0,1),(1,2,2),(2,1,2)$.

Now all white cells contain $0$ dolls, so we have achieved the goal with $5$ operations.



#### Tags 

#2000 #NOT OK #combinatorics #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_21.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
