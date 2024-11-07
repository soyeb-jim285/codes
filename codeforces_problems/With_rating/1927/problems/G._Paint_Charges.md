<h1 style='text-align: center;'> G. Paint Charges</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A horizontal grid strip of $n$ cells is given. In the $i$-th cell, there is a paint charge of size $a_i$. This charge can be:

* either used to the left — then all cells to the left at a distance less than $a_i$ (from $\max(i - a_i + 1, 1)$ to $i$ inclusive) will be painted,
* or used to the right — then all cells to the right at a distance less than $a_i$ (from $i$ to $\min(i + a_i - 1, n)$ inclusive) will be painted,
* or not used at all.

## Note

 that a charge can be used no more than once (that is, it cannot be used simultaneously to the left and to the right). It is allowed for a cell to be painted more than once.

What is the minimum number of times a charge needs to be used to paint all the cells of the strip?

### Input

The first line of the input contains an integer $t$ ($1 \le t \le 100$) — the number of test cases in the test. This is followed by descriptions of $t$ test cases.

Each test case is specified by two lines. The first one contains an integer $n$ ($1 \le n \le 100$) — the number of cells in the strip. The second line contains $n$ positive integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$), where $a_i$ is the size of the paint charge in the $i$-th cell from the left of the strip.

It is guaranteed that the sum of the values of $n$ in the test does not exceed $1000$.

### Output

For each test case, output the minimum number of times the charges need to be used to paint all the cells of the strip.

## Example

### Input


```text
131121 122 121 222 231 1 133 1 231 3 171 2 3 1 2 4 272 1 1 1 2 3 1102 2 5 1 6 1 8 2 8 262 1 2 1 1 261 1 4 1 3 2
```
### Output

```text

1
2
1
1
1
3
1
2
3
4
2
3
3

```
## Note

In the third test case of the example, it is sufficient to use the charge from the $1$-st cell to the right, then it will cover both cells $1$ and $2$.

In the ninth test case of the example, you need to: 

* use the charge from the $3$-rd cell to the left, covering cells from the $1$-st to the $3$-rd;
* use the charge from the $5$-th cell to the left, covering cells from the $4$-th to the $5$-th;
* use the charge from the $7$-th cell to the left, covering cells from the $6$-th to the $7$-th.

In the eleventh test case of the example, you need to: 

* use the charge from the $5$-th cell to the right, covering cells from the $5$-th to the $10$-th;
* use the charge from the $7$-th cell to the left, covering cells from the $1$-st to the $7$-th.


#### Tags 

#2300 #NOT OK #data_structures #dp #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_923_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
