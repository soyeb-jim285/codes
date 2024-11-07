<h1 style='text-align: center;'> C. Tiles Comeback</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vlad remembered that he had a series of $n$ tiles and a number $k$. The tiles were numbered from left to right, and the $i$-th tile had colour $c_i$.

If you stand on the first tile and start jumping any number of tiles right, you can get a path of length $p$. The length of the path is the number of tiles you stood on.

Vlad wants to see if it is possible to get a path of length $p$ such that: 

* it ends at tile with index $n$;
* $p$ is divisible by $k$
* the path is divided into blocks of length exactly $k$ each;
* tiles in each block have the same colour, the colors in adjacent blocks are not necessarily different.

For example, let $n = 14$, $k = 3$.

The colours of the tiles are contained in the array $c$ = [$\color{red}{1}, \color{violet}{2}, \color{red}{1}, \color{red}{1}, \color{gray}{7}, \color{orange}{5}, \color{green}{3}, \color{green}{3}, \color{red}{1}, \color{green}{3}, \color{blue}{4}, \color{blue}{4}, \color{violet}{2}, \color{blue}{4}$]. Then we can construct a path of length $6$ consisting of $2$ blocks:

$\color{red}{c_1} \rightarrow \color{red}{c_3} \rightarrow \color{red}{c_4} \rightarrow \color{blue}{c_{11}} \rightarrow \color{blue}{c_{12}} \rightarrow \color{blue}{c_{14}}$

All tiles from the $1$-st block will have colour $\color{red}{\textbf{1}}$, from the $2$-nd block will have colour $\color{blue}{\textbf{4}}$.

It is also possible to construct a path of length $9$ in this example, in which all tiles from the $1$-st block will have colour $\color{red}{\textbf{1}}$, from the $2$-nd block will have colour $\color{green}{\textbf{3}}$, and from the $3$-rd block will have colour $\color{blue}{\textbf{4}}$.

### Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 2 \cdot 10^5$)—the number of tiles in the series and the length of the block.

The second line of each test case contains $n$ integers $c_1, c_2, c_3, \dots, c_n$ ($1 \le c_i \le n$) — the colours of the tiles.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output on a separate line: 

* YES if you can get a path that satisfies these conditions;
* NO otherwise.

You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as positive response).

## Example

### Input


```text
104 21 1 1 114 31 2 1 1 7 5 3 3 1 3 4 4 2 43 33 1 310 41 2 1 2 1 2 1 2 1 26 21 3 4 1 6 62 21 14 22 1 1 12 11 23 22 2 24 11 1 2 2
```
### Output

```text

YES
YES
NO
NO
YES
YES
NO
YES
YES
YES

```
## Note

In the first test case, you can jump from the first tile to the last tile;

The second test case is explained in the problem statement.



#### Tags 

#1000 #OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_888_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
