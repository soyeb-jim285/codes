<h1 style='text-align: center;'> B. Letter Exchange</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A cooperative game is played by $m$ people. In the game, there are $3m$ sheets of paper: $m$ sheets with letter 'w', $m$ sheets with letter 'i', and $m$ sheets with letter 'n'.

Initially, each person is given three sheets (possibly with equal letters).

The goal of the game is to allow each of the $m$ people to spell the word "win" using their sheets of paper. In other words, everyone should have one sheet with letter 'w', one sheet with letter 'i', and one sheet with letter 'n'.

To achieve the goal, people can make exchanges. Two people participate in each exchange. Both of them choose exactly one sheet of paper from the three sheets they own and exchange it with each other.

Find the shortest sequence of exchanges after which everyone has one 'w', one 'i', and one 'n'.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $m$ ($2 \le m \le 10^5$) — the number of people.

The $i$-th of the next $m$ lines contains a string $s_i$ of length $3$ consisting of lowercase English letters 'w', 'i', and 'n', denoting the letters person $i$ has on their sheets of paper at the beginning of the game, in arbitrary order.

Each of the letters 'w', 'i', and 'n' appears on the sheets of paper exactly $m$ times in total.

It is guaranteed that the sum of $m$ over all test cases does not exceed $10^5$.

### Output

For each test case, print a non-negative integer $k$ — the smallest number of exchanges people need to make everyone have one 'w', one 'i', and one 'n'.

In each of the next $k$ lines print four tokens $a_1$ $c_1$ $a_2$ $c_2$, describing the exchanges in chronological order ($1 \le a_1, a_2 \le m$; $a_1 \ne a_2$; $c_1, c_2$ are one of $\{\mathtt{w}, \mathtt{i}, \mathtt{n}\}$): person $a_1$ gives letter $c_1$ to person $a_2$, while person $a_2$ gives letter $c_2$ to person $a_1$ at the same time.

If there are multiple solutions, print any.

## Example

### Input


```text
32nwiinw3innnwwwii4winwwwiiinnn
```
### Output

```text

0
2
2 w 3 i
3 w 1 n
3
2 w 3 i
2 w 4 n
3 i 4 n

```


#### Tags 

#1900 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../VK_Cup_2022_-_Финальный_раунд_(Engine).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
