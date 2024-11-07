<h1 style='text-align: center;'> G. GCD on a grid</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Not long ago, Egor learned about the Euclidean algorithm for finding the greatest common divisor of two numbers. The greatest common divisor of two numbers $a$ and $b$ is the largest number that divides both $a$ and $b$ without leaving a remainder. With this knowledge, Egor can solve a problem that he once couldn't.

Vasily has a grid with $n$ rows and $m$ columns, and the integer ${a_i}_j$ is located at the intersection of the $i$-th row and the $j$-th column. Egor wants to go from the top left corner (at the intersection of the first row and the first column) to the bottom right corner (at the intersection of the last row and the last column) and find the greatest common divisor of all the numbers along the path. He is only allowed to move down and to the right. Egor has written down several paths and obtained different GCD values. He became interested in finding the maximum possible GCD.

Unfortunately, Egor is tired of calculating GCDs, so he asks for your help in finding the maximum GCD of the integers along the path from the top left corner to the bottom right corner of the grid.

### Input

The first line contains an integer $t$ ($1 \le t \le {10}^{4}$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n, m \le 100$) — the number of rows and columns of the grid.

Then, there are $n$ lines, where the $i$-th line contains $m$ integers $(1 \le a_{i,j} \le {10}^{6}$) — the integers written in the $i$-th row and the $j$-th column of the grid.

It is guaranteed that the sum of $n \cdot m$ does not exceed $2 \cdot {10}^{5}$ over all test cases.

### Output

For each test case, output the maximum possible GCD along the path from the top left cell to the bottom right cell in a separate line.

## Example

### Input


```text
32 330 20 3015 25 403 312 4 93 12 28 3 122 42 4 6 81 3 6 9
```
### Output

```text

10
3
1

```


#### Tags 

#1900 #NOT OK #brute_force #dfs_and_similar #dp #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_938_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
