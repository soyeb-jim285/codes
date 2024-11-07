<h1 style='text-align: center;'> B. Chip and Ribbon</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a ribbon divided into $n$ cells, numbered from $1$ to $n$ from left to right. Initially, an integer $0$ is written in each cell.

Monocarp plays a game with a chip. The game consists of several turns. During the first turn, Monocarp places the chip in the $1$-st cell of the ribbon. During each turn except for the first turn, Monocarp does exactly one of the two following actions:

* move the chip to the next cell (i. e. if the chip is in the cell $i$, it is moved to the cell $i+1$). This action is impossible if the chip is in the last cell;
* choose any cell $x$ and teleport the chip into that cell. It is possible to choose the cell where the chip is currently located.

At the end of each turn, the integer written in the cell with the chip is increased by $1$.

Monocarp's goal is to make some turns so that the $1$-st cell contains the integer $c_1$, the $2$-nd cell contains the integer $c_2$, ..., the $n$-th cell contains the integer $c_n$. He wants to teleport the chip as few times as possible.

Help Monocarp calculate the minimum number of times he has to teleport the chip. 

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of two lines: 

* the first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$);
* the second line contains $n$ integers $c_1, c_2, \dots, c_n$ ($0 \le c_i \le 10^9$; $c_1 \ge 1$).

It can be shown that under these constraints, it is always possible to make a finite amount of turns so that the integers in the cells match the sequence $c_1, c_2, \dots, c_n$.

Additional constraint on the input: the sum of values of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the minimum number of times Monocarp has to teleport the chip.

## Example

### Input


```text
441 2 2 151 0 1 0 155 4 3 2 1112
```
### Output

```text

1
2
4
11

```
## Note

In the first test case of the example, Monocarp can perform the turns as follows:

* place the chip in the $1$-st cell; the numbers in the cells are $[1, 0, 0, 0]$;
* move the chip to the next ($2$-nd) cell; the numbers in the cells are $[1, 1, 0, 0]$;
* move the chip to the next ($3$-rd) cell; the numbers in the cells are $[1, 1, 1, 0]$;
* teleport the chip to the $2$-nd cell; the numbers in the cells are $[1, 2, 1, 0]$;
* move the chip to the next ($3$-rd) cell; the numbers in the cells are $[1, 2, 2, 0]$;
* move the chip to the next ($4$-th) cell; the numbers in the cells are $[1, 2, 2, 1]$.


#### Tags 

#1100 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_158_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
