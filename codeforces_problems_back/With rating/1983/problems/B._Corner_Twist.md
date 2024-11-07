<h1 style='text-align: center;'> B. Corner Twist</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two grids of numbers $a$ and $b$, with $n$ rows and $m$ columns. All the values in the grid are $0$, $1$ or $2$.

You can perform the following operation on $a$ any number of times: 

* Pick any subrectangle in the grid with length and width $\ge 2$. You are allowed to choose the entire grid as a subrectangle.
* The subrectangle has four corners. Take any pair of diagonally opposite corners of the chosen subrectangle and add $1$ to their values modulo $3$.
* For the pair of corners not picked, add $2$ to their values modulo $3$.

## Note

 that the operation only changes the values of the corners of the picked subrectangle.

Is it possible to convert the grid $a$ into grid $b$ by applying the above operation any number of times (possibly zero)?

## Input

The first line contains an integer $t$, the number of testcases ($1 \le t \le 250$).

For each testcase:

The first line contains two integers $n$ and $m$, the number of rows and columns in the grid ($2 \le n,m \le 500$).

Each of the next n lines contain m characters — the $j$-th character of the $i$-th line represents $a_{i,j}$.

Each of the next n lines contain m characters — the $j$-th character of the $i$-th line represents $b_{i,j}$ ($0 \le a_{i,j}, b_{i,j} \le 2$).

It is guaranteed that the sum of $n$ over all test cases and the sum of $m$ over all test cases do not exceed $500$.

## Output

For each test case print "YES" (without quotes) if it is possible to convert grid $a$ into grid $b$ and "NO" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

## Input


```

73 30000000001111111114 4000000000000000021001200001200214 4102012001210000000001200220000003 30120120120101110118 8000000000000000000000000000000000000000000000000000000001000000000000000012000000201000000102000000201000000102000000210100000002 700000000000000222011101112222 70000000010001022201111210202
```
## Output


```

YES
YES
YES
NO
YES
NO
YES

```
## Note

In the first testcase, grid $a$ can be converted into $b$ in the following manner:

$\begin{matrix}\fbox{0} & 0 & \fbox{0}\\\ 0 & 0 & 0\\\ \fbox{0} & 0 & \fbox{0}\end{matrix} \Rightarrow \begin{matrix}1 & 0 & 2\\\ 0 & \fbox{0} & \fbox{0}\\\ 2 & \fbox{0} & \fbox{1}\end{matrix} \Rightarrow \begin{matrix}1 & 0 & 2\\\ \fbox{0} & \fbox{1} & 2\\\ \fbox{2} & \fbox{2} & 2\end{matrix} \Rightarrow \begin{matrix}1 & \fbox{0} & \fbox{2}\\\ 1 & 0 & 2\\\ 1 & \fbox{0} & \fbox{2}\end{matrix} \Rightarrow \begin{matrix}1 & 1 & 1\\\ 1 & \fbox{0} & \fbox{2}\\\ 1 & \fbox{2} & \fbox{0}\end{matrix} \Rightarrow \begin{matrix}1 & 1 & 1\\\ 1 & 1 & 1\\\ 1 & 1 & 1\end{matrix}$

Here, in each operation, the top-right and bottom-left corners highlighted by a box are incremented by $2$ modulo $3$, while the top-left and bottom-right corners are incremented by $1$ modulo $3$.

In the fourth testcase, it can be proven that it is not possible to convert grid $a$ into grid $b$ using the above-mentioned operations any number of times.



#### tags 

#1200 #constructive_algorithms #greedy #implementation #math 