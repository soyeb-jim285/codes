<h1 style='text-align: center;'> A. Diagonals</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vitaly503 is given a checkered board with a side of $n$ and $k$ chips. He realized that all these $k$ chips need to be placed on the cells of the board (no more than one chip can be placed on a single cell).

Let's denote the cell in the $i$-th row and $j$-th column as $(i ,j)$. A diagonal is the set of cells for which the value $i + j$ is the same. For example, cells $(3, 1)$, $(2, 2)$, and $(1, 3)$ lie on the same diagonal, but $(1, 2)$ and $(2, 3)$ do not. A diagonal is called occupied if it contains at least one chip. 

Determine what is the minimum possible number of occupied diagonals among all placements of $k$ chips.

### Input

Each test consists of several sets of input data. The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of sets of input data. Then follow the descriptions of the sets of input data.

The only line of each set of input data contains two integers $n$, $k$ ($1 \le n \le 100, 0 \le k \le n^2$) — the side of the checkered board and the number of available chips, respectively.

### Output

For each set of input data, output a single integer — the minimum number of occupied diagonals with at least one chip that he can get after placing all $k$ chips.

## Example

### Input


```text
71 02 22 32 410 50100 2393 9
```
### Output

```text

0
1
2
3
6
3
5

```
## Note

In the first test case, there are no chips, so 0 diagonals will be occupied. In the second test case, both chips can be placed on diagonal $(2, 1), (1, 2)$, so the answer is 1. In the third test case, 3 chips can't be placed on one diagonal, but placing them on $(1, 2), (2, 1), (1, 1)$ makes 2 diagonals occupied. In the 7th test case, chips will occupy all 5 diagonals in any valid placing.



#### Tags 

#800 #NOT OK #brute_force #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_961_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
