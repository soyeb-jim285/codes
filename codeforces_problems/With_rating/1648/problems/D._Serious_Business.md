<h1 style='text-align: center;'> D. Serious Business</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Dima is taking part in a show organized by his friend Peter. In this show Dima is required to cross a $3 \times n$ rectangular field. Rows are numbered from $1$ to $3$ and columns are numbered from $1$ to $n$.

The cell in the intersection of the $i$-th row and the $j$-th column of the field contains an integer $a_{i,j}$. Initially Dima's score equals zero, and whenever Dima reaches a cell in the row $i$ and the column $j$, his score changes by $a_{i,j}$. 
## Note

 that the score can become negative.

Initially all cells in the first and the third row are marked as available, and all cells in the second row are marked as unavailable. However, Peter offered Dima some help: there are $q$ special offers in the show, the $i$-th special offer allows Dima to mark cells in the second row between $l_i$ and $r_i$ as available, though Dima's score reduces by $k_i$ whenever he accepts a special offer. Dima is allowed to use as many special offers as he wants, and might mark the same cell as available multiple times.

Dima starts his journey in the cell $(1, 1)$ and would like to reach the cell $(3, n)$. He can move either down to the next row or right to the next column (meaning he could increase the current row or column by 1), thus making $n + 1$ moves in total, out of which exactly $n - 1$ would be horizontal and $2$ would be vertical.

Peter promised Dima to pay him based on his final score, so the sum of all numbers of all visited cells minus the cost of all special offers used. Please help Dima to maximize his final score.

#### Input

The first input line contains two integers $n$ and $q$ ($1 \le n, q \le 500\,000$) — the number of columns in the field and the number of special offers.

The next three lines describe the field, $i$-th of them contains $n$ integers $a_{i1}$, $a_{i2}$, ..., $a_{in}$ ($-10^9 \le a_{ij} \le 10^9)$ — the values in the $i$-th row.

The next $q$ lines describe special offers: the $i$-th offer is described by 3 integers $l_i$, $r_i$ and $k_i$ ($1 \leq l_i \leq r_i \leq n$, $1\leq k_i\leq 10^9$) — the segment that becomes unblocked and the cost of this special offer.

#### Output

#### Output

 one integer — the maximum final score Dima can achieve.

## Examples

#### Input


```text
4 3
1 0 2 -1
-3 1 9 2
3 2 4 1
1 2 5
2 3 4
1 4 14
```
#### Output


```text
13
```
#### Input

```text

5 4
-20 -10 -11 -10 1
1 3 3 6 3
14 -20 3 6 2
1 5 13
1 2 2
3 5 3
2 3 1

```
#### Output


```text

-4
```
## Note

In the first example, it is optimal to use Peter's second offer of $4$ rubles and go through the cells $(1, 1)$, $(1, 2)$, $(1, 3)$, $(2, 3)$, $(3, 3)$, $(3, 4)$, earning $1 + 0 + 2 + 9 + 4 + 1 - 4 = 13$ rubles in total.

In the second example, it is optimal to use Peter's second and third offers of $2$ and $3$ rubles, respectively, and go through the cells $(1, 1)$, $(2, 1)$, $(2, 2)$, $(2, 3)$, $(2, 4)$, $(3, 4)$, $(3, 5)$, earning $-20 + 1 + 3 + 3 + 6 + 6 + 2 - 2 - 3= -4$ rubles.



#### Tags 

#2800 #NOT OK #data_structures #divide_and_conquer #dp #implementation #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_775_(Div._1,_based_on_Moscow_Open_Olympiad_in_Informatics).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
