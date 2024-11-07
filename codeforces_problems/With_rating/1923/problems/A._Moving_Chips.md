<h1 style='text-align: center;'> A. Moving Chips</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a ribbon divided into $n$ cells, numbered from $1$ to $n$ from left to right. Each cell either contains a chip or is free.

You can perform the following operation any number of times (possibly zero): choose a chip and move it to the closest free cell to the left. You can choose any chip that you want, provided that there is at least one free cell to the left of it. When you move the chip, the cell where it was before the operation becomes free.

Your goal is to move the chips in such a way that they form a single block, without any free cells between them. What is the minimum number of operations you have to perform?

### Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case consists of two lines:

* the first line contains one integer $n$ ($2 \le n \le 50$) — the number of cells;
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 1$); $a_i = 0$ means that the $i$-th cell is free; $a_i = 1$ means that the $i$-th cell contains a chip.

Additional constraint on the input: in each test case, at least one cell contains a chip.

### Output

For each test case, print one integer — the minimum number of operations you have to perform so that all chips form a single block without any free cells between them.

## Example

### Input


```text
580 1 1 1 0 1 1 060 1 0 0 0 061 1 1 1 1 151 0 1 0 190 1 1 0 0 0 1 1 0
```
### Output

```text

1
0
0
2
3

```
## Note

In the first example, you can perform the operation on the chip in the $7$-th cell. The closest free cell to the left is the $5$-th cell, so it moves there. After that, all chips form a single block.

In the second example, all chips are already in a single block. Same for the third example.



#### Tags 

#800 #OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_162_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
