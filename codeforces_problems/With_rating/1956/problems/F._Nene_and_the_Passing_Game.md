<h1 style='text-align: center;'> F. Nene and the Passing Game</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nene is training her team as a basketball coach. Nene's team consists of $n$ players, numbered from $1$ to $n$. The $i$-th player has an arm interval $[l_i,r_i]$. Two players $i$ and $j$ ($i \neq j$) can pass the ball to each other if and only if $|i-j|\in[l_i+l_j,r_i+r_j]$ (here, $|x|$ denotes the absolute value of $x$).

Nene wants to test the cooperation ability of these players. In order to do this, she will hold several rounds of assessment.

* In each round, Nene will select a sequence of players $p_1,p_2,\ldots,p_m$ such that players $p_i$ and $p_{i+1}$ can pass the ball to each other for all $1 \le i < m$. The length of the sequence $m$ can be chosen by Nene. Each player can appear in the sequence $p_1,p_2,\ldots,p_m$ multiple times or not appear in it at all.
* Then, Nene will throw a ball to player $p_1$, player $p_1$ will pass the ball to player $p_2$ and so on... Player $p_m$ will throw a ball away from the basketball court so it can no longer be used.

As a coach, Nene wants each of $n$ players to appear in at least one round of assessment. Since Nene has to go on a date after school, Nene wants you to calculate the minimum number of rounds of assessment needed to complete the task.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2\cdot 10^5$). The description of test cases follows.

The first line contains a single integer $n$ ($1 \le n \le 2\cdot 10^6$) — the number of players.

The $i$-th of the next $n$ lines contains two integers $l_i$ and $r_i$ ($1\leq l_i\leq r_i\leq n$) — the arm interval of the $i$-th player.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^6$.

### Output

For each test case, output one integer — the minimum number of rounds of assessment Nene needs to complete her work.

## Example

### Input


```text
521 11 121 12 231 31 31 351 12 21 52 21 161 25 52 32 32 21 2
```
### Output

```text

2
2
2
1
3

```
## Note

In the first two test cases, Nene can host two rounds of assessment: one with $p=[1]$ and one with $p=[2]$. It can be shown that hosting one round of assessment is not enough, so the answer is $2$.

In the third test case, Nene can host two rounds of assessment: one with $p=[1,3]$ and one with $p=[2]$. Player $1$ can pass the ball to player $3$ as $|3-1|=2 \in [1+1,3+3]$. It can be shown that hosting one round of assessment is not enough, so the answer is $2$.



#### Tags 

#3000 #NOT OK #constructive_algorithms #data_structures #dsu #graphs #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_939_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
