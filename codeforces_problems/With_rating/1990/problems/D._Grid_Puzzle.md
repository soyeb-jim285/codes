<h1 style='text-align: center;'> D. Grid Puzzle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of size $n$.

There is an $n \times n$ grid. In the $i$-th row, the first $a_i$ cells are black and the other cells are white. In other words, note $(i,j)$ as the cell in the $i$-th row and $j$-th column, cells $(i,1), (i,2), \ldots, (i,a_i)$ are black, and cells $(i,a_i+1), \ldots, (i,n)$ are white.

You can do the following operations any number of times in any order: 

* Dye a $2 \times 2$ subgrid white;
* Dye a whole row white. 
## Note

 you can not dye a whole column white.

Find the minimum number of operations to dye all cells white.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

For each test case: 

* The first line contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the size of the array $a$.
* The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq n$).

It's guaranteed that the sum of $n$ over all test cases will not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimum number of operations to dye all cells white.

## Example

### Input


```text
101042 4 4 243 2 1 030 3 030 1 333 1 043 1 0 340 2 2 261 3 4 2 0 482 2 5 2 3 4 2 4
```
### Output

```text

0
3
2
1
2
2
3
2
4
6

```
## Note

In the first test case, you don't need to do any operation.

In the second test case, you can do:

* Dye $(1,1), (1,2), (2,1)$, and $(2,2)$ white;
* Dye $(2,3), (2,4), (3,3)$, and $(3,4)$ white;
* Dye $(3,1), (3,2), (4,1)$, and $(4,2)$ white.

It can be proven $3$ is the minimum number of operations.

In the third test case, you can do:

* Dye the first row white;
* Dye $(2,1), (2,2), (3,1)$, and $(3,2)$ white.

It can be proven $2$ is the minimum number of operations.



#### Tags 

#1800 #NOT OK #bitmasks #brute_force #dp #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_960_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
