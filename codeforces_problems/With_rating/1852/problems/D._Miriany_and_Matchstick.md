<h1 style='text-align: center;'> D. Miriany and Matchstick</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Miriany's matchstick is a $2 \times n$ grid that needs to be filled with characters A or B. 

He has already filled in the first row of the grid and would like you to fill in the second row. You must do so in a way such that the number of adjacent pairs of cells with different characters$^\dagger$ is equal to $k$. If it is impossible, report so.

$^\dagger$ An adjacent pair of cells with different characters is a pair of cells $(r_1, c_1)$ and $(r_2, c_2)$ ($1 \le r_1, r_2 \le 2$, $1 \le c_1, c_2 \le n$) such that $|r_1 - r_2| + |c_1 - c_2| = 1$ and the characters in $(r_1, c_1)$ and $(r_2, c_2)$ are different.

### Input

The first line consists of an integer $t$, the number of test cases ($1 \leq t \leq 1000$). The description of the test cases follows.

The first line of each test case has two integers, $n$ and $k$ ($1 \leq n \leq 2 \cdot 10^5, 0 \leq k \leq 3 \cdot n$) – the number of columns of the matchstick, and the number of adjacent pairs of cells with different characters required.

The following line contains string $s$ of $n$ characters ($s_i$ is either A or B) – Miriany's top row of the matchstick.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, if there is no way to fill the second row with the number of adjacent pairs of cells with different characters equals $k$, output "NO". 

Otherwise, output "YES". Then, print $n$ characters that a valid bottom row for Miriany's matchstick consists of. If there are several answers, output any of them.

## Example

### Input


```text
410 1ABBAAABBAA4 5AAAA9 17BAAABBAAB4 9ABAB
```
### Output

```text

NO
YES
BABB
YES
ABABAABAB
NO
```
## Note

In the first test case, it can be proved that there exists no possible way to fill in row $2$ of the grid such that $k = 1$. 

For the second test case, BABB is one possible answer.

The grid below is the result of filling in BABB as the second row.

 $\begin{array}{|c|c|} \hline A & A & A & A \cr \hline B & A & B & B \cr \hline \end{array}$ The pairs of different characters are shown below in red:

 $\begin{array}{|c|c|} \hline \color{red}{A} & A & A & A \cr \hline \color{red}{B} & A & B & B \cr \hline \end{array}$—————————————————

$\begin{array}{|c|c|} \hline A & A & \color{red}{A} & A \cr \hline B & A & \color{red}{B} & B \cr \hline \end{array}$

—————————————————

$\begin{array}{|c|c|} \hline A & A & A & \color{red}{A} \cr \hline B & A & B & \color{red}{B} \cr \hline \end{array}$

—————————————————

$\begin{array}{|c|c|} \hline A & A & A & A \cr \hline \color{red}{B} & \color{red}{A} & B & B \cr \hline \end{array}$

—————————————————

$\begin{array}{|c|c|} \hline A & A & A & A \cr \hline B & \color{red}{A} & \color{red}{B} & B \cr \hline \end{array}$

There are a total of $5$ pairs, which satisfies $k$.



#### Tags 

#2800 #NOT OK #constructive_algorithms #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_887_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
