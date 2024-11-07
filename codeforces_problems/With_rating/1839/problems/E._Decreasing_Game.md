<h1 style='text-align: center;'> E. Decreasing Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Consider the following game for two players:

* Initially, an array of integers $a_1, a_2, \ldots, a_n$ of length $n$ is written on blackboard.
* Game consists of rounds. On each round, the following happens:
	+ The first player selects any $i$ such that $a_i \gt 0$. If there is no such $i$, the first player loses the game (the second player wins) and game ends.
	+ The second player selects any $j \neq i$ such that $a_j \gt 0$. If there is no such $j$, the second player loses the game (the first player wins) and game ends.
	+ Let $d = \min(a_i, a_j)$. The values of $a_i$ and $a_j$ are simultaneously decreased by $d$ and the next round starts.

It can be shown that game always ends after the finite number of rounds.

You have to select which player you will play for (first or second) and win the game.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 300$) — the length of array $a$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 300$) — array $a$.

## Interaction

## Interaction

 begins after reading $n$ and array $a$.

You should start interaction by printing a single line, containing either "First" or "Second", representing the player you select.

On each round, the following happens: 

* If you are playing as the first player, you should print a single integer $i$ ($1 \le i \le n$) on a separate line. After that, you should read a single integer $j$ ($-1 \le j \le n$) written on a separate line.If $j = -1$, then you made an incorrect move. In this case your program should terminate immediately.

If $j = 0$, then the second player can't make a correct move and you win the game. In this case your program should also terminate immediately.

Otherwise $j$ is equal to the index chosen by the second player, and you should proceed to the next round.
* If you are playing as the second player, you should read a single integer $i$ ($-1 \le i \le n$) written on a separate line.If $i = -1$, then you made an incorrect move on the previous round (this cannot happen on the first round). In that case your program should terminate immediately.

If $i = 0$, then the first player can't make a correct move and you win the game. In this case your program should also terminate immediately.

Otherwise $i$ is equal to the index chosen by first player. In this case you should write single integer $j$ ($1 \le j \le n$) on a separate line and proceed to the next round.

After printing $i$ or $j$, do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Hacks

Hacks are disabled in this problem.

## Examples

#### Input


```text
4
10 4 6 3


3

1

0
```
##Output
```text



First
1

2

4
```
#### Input

```text

6
4 5 5 11 3 2

2

5

4

6

1

0
```
##Output
```text



Second 

4

4

3

1

3
```
## Note

In the first example $n = 4$ and array $a$ is $[\, 10, 4, 6, 3 \,]$. The game goes as follows: 

* After reading array $a$ contestant's program chooses to play as the first player and prints "First".
* First round: the first player chooses $i = 1$, the second player chooses $j = 3$. $d = \min(a_1, a_3) = \min(10, 6) = 6$ is calculated. Elements $a_1$ and $a_3$ are decreased by $6$. Array $a$ becomes equal to $[\, 4, 4, 0, 3 \,]$.
* Second round: the first player chooses $i = 2$, the second player chooses $j = 1$. $d = \min(a_2, a_1) = \min(4, 4) = 4$ is calculated. Elements $a_2$ and $a_1$ are decreased by $4$. Array $a$ becomes equal to $[\, 0, 0, 0, 3 \,]$.
* Third round: the first player chooses $i = 4$. There is no $j \neq 4$ such that $a_j > 0$, so the second player can't make a correct move and the first player wins. Jury's program prints $j = 0$. After reading it, contestant's program terminates.

In the second example $n = 6$ and array $a$ is $[\, 4, 5, 5, 11, 3, 2 \,]$. The game goes as follows:

* Contestant's program chooses to play as the second player and prints "Second".
* First round: $i = 2$, $j = 4$, $a = [\, 4, 0, 5, 6, 3, 2 \,]$.
* Second round: $i = 5$, $j = 4$, $a = [\, 4, 0, 5, 3, 0, 2 \,]$.
* Third round: $i = 4$, $j = 3$, $a = [\, 4, 0, 2, 0, 0, 2 \,]$.
* Fourth round: $i = 6$, $j = 1$, $a = [\, 2, 0, 2, 0, 0, 0 \,]$.
* Fifth round: $i = 1$, $j = 3$, $a = [\, 0, 0, 0, 0, 0, 0 \,]$.
* Sixth round: the first player can't make a correct move and the second player wins. Jury's program prints $i = 0$. After reading it, contestant's program terminates.

## Note

 that the example interaction contains extra empty lines so that it's easier to read. The real interaction doesn't contain any empty lines and you shouldn't print any extra empty lines as well.



#### Tags 

#2400 #NOT OK #constructive_algorithms #dfs_and_similar #dp #greedy #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_876_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
