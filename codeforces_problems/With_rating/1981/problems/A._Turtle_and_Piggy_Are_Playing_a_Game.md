<h1 style='text-align: center;'> A. Turtle and Piggy Are Playing a Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Turtle and Piggy are playing a number game.

First, Turtle will choose an integer $x$, such that $l \le x \le r$, where $l, r$ are given. It's also guaranteed that $2l \le r$.

Then, Piggy will keep doing the following operation until $x$ becomes $1$:

* Choose an integer $p$ such that $p \ge 2$ and $p \mid x$ (i.e. $x$ is a multiple of $p$).
* Set $x$ to $\frac{x}{p}$, and the score will increase by $1$.

The score is initially $0$. Both Turtle and Piggy want to maximize the score. Please help them to calculate the maximum score.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $l, r$ ($1 \le l \le r \le 10^9, 2l \le r$) — The range where Turtle can choose the integer from.

### Output

For each test case, output a single integer — the maximum score.

## Example

### Input


```text
52 43 62 156 22114514 1919810
```
### Output

```text

2
2
3
4
20

```
## Note

In the first test case, Turtle can choose an integer $x$, such that $2 \le x \le 4$. He can choose $x = 4$. Then Piggy can choose $p = 2$ for $2$ times. After that, $x$ will become $1$, and the score will be $2$, which is maximized.

In the second test case, Turtle can choose an integer $3 \le x \le 6$. He can choose $x = 6$. Then Piggy can choose $p = 2$, then choose $p = 3$. After that, $x$ will become $1$, and the score will be $2$, which is maximum.

In the third test case, Turtle can choose $x = 12$.

In the fourth test case, Turtle can choose $x = 16$.



#### Tags 

#800 #NOT OK #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_949_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
