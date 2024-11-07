<h1 style='text-align: center;'> H. ±1</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bob has a grid with $3$ rows and $n$ columns, each of which contains either $a_i$ or $-a_i$ for some integer $1 \leq i \leq n$. For example, one possible grid for $n=4$ is shown below:

$$\begin{bmatrix} a_1 & -a_2 & -a_3 & -a_2 \\\ -a_4 & a_4 & -a_1 & -a_3 \\\ a_1 & a_2 & -a_2 & a_4 \end{bmatrix}$$

Alice and Bob play a game as follows: 

* Bob shows Alice his grid.
* Alice gives Bob an array $a_1, a_2, \dots, a_n$ of her choosing, whose elements are all $\mathbf{-1}$ or $\mathbf{1}$.
* Bob substitutes these values into his grid to make a grid of $-1$s and $1$s.
* Bob sorts the elements of each column in non-decreasing order.
* Alice wins if all the elements in the middle row are $1$; otherwise, Bob wins.

For example, suppose Alice gives Bob the array $[1, -1, -1, 1]$ for the grid above. Then the following will happen (colors are added for clarity):

$$\begin{bmatrix} \color{red}{a_1} & \color{green}{-a_2} & \color{blue}{-a_3} & \color{green}{-a_2} \\\ -a_4 & a_4 & \color{red}{-a_1} & \color{blue}{-a_3} \\\ \color{red}{a_1} & \color{green}{a_2} & \color{green}{-a_2} & a_4 \end{bmatrix} \xrightarrow{[\color{red}{1},\color{green}{-1},\color{blue}{-1},1]} \begin{bmatrix} \color{red}{1} & \color{green}{1} & \color{blue}{1} & \color{green}{1} \\\ -1 & 1 & \color{red}{-1} & \color{blue}{1} \\\ \color{red}{1} & \color{green}{-1} & \color{green}{1} & 1 \end{bmatrix} \xrightarrow{\text{sort each column}} \begin{bmatrix} -1 & -1 & -1 & 1 \\\ \mathbf{1} & \mathbf{1} & \mathbf{1} & \mathbf{1} \\\ 1 & 1 & 1 & 1 \\\ \end{bmatrix}\,. $$ Since the middle row is all $1$, Alice wins.

Given Bob's grid, determine whether or not Alice can choose the array $a$ to win the game.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 500$) — the number of columns of Bob's grid.

The next three lines each contain $n$ integers, the $i$-th of which contains $g_{i,1}, g_{i,2}, \dots, g_{i,n}$ ($-n \leq g_{i,j} \leq n$, $g_{i,j} \neq 0$), representing Bob's grid. 

If cell $x > 0$ is in the input, that cell in Bob's grid should contain $a_x$; if $x < 0$ is in the input, that cell in Bob's grid should contain $-a_{-x}$. See the sample input and notes for a better understanding.

### Output

For each test case, output "YES" (without quotes) if Alice can win, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).

## Example

### Input


```text
441 -2 -3 -2-4 4 -1 -31 2 -2 421 2-1 -22 -251 2 3 4 5-2 3 -4 -5 -13 -5 1 2 261 3 -6 2 5 21 3 -2 -3 -6 -5-2 -1 -3 2 3 1
```
### Output

```text

YES
NO
YES
NO

```
## Note

The first test case is described in the statement.

In the second test case, Bob's grid is as follows:

$$\begin{bmatrix} a_1 & a_2 \\\ -a_1 & -a_2 \\\ a_2 & -a_2 \end{bmatrix}$$

For the last column to have $1$ in the middle row when sorted, Alice must pick $a_2 = -1$. However, it is then impossible to choose $a_1$ such that the first column has $1$ in the middle when sorted. Thus, Alice cannot win.

In the third test case, Alice can pick $a = [1,1,1,1,1]$.



#### Tags 

#2100 #NOT OK #2-sat #dfs_and_similar #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_944_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
