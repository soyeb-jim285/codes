<h1 style='text-align: center;'> B. Chess Tournament</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A chess tournament will be held soon, where $n$ chess players will take part. Every participant will play one game against every other participant. Each game ends in either a win for one player and a loss for another player, or a draw for both players.

Each of the players has their own expectations about the tournament, they can be one of two types:

1. a player wants not to lose any game (i. e. finish the tournament with zero losses);
2. a player wants to win at least one game.

You have to determine if there exists an outcome for all the matches such that all the players meet their expectations. If there are several possible outcomes, print any of them. If there are none, report that it's impossible.

### Input

The first line contains a single integer $t$ ($1 \le t \le 200$) — the number of test cases.

The first line of each test case contains one integer $n$ ($2 \le n \le 50$) — the number of chess players.

The second line contains the string $s$ ($|s| = n$; $s_i \in \{1, 2\}$). If $s_i = 1$, then the $i$-th player has expectations of the first type, otherwise of the second type.

### Output

For each test case, print the answer in the following format:

In the first line, print NO if it is impossible to meet the expectations of all players.

Otherwise, print YES, and the matrix of size $n \times n$ in the next $n$ lines.

The matrix element in the $i$-th row and $j$-th column should be equal to:

* +, if the $i$-th player won in a game against the $j$-th player;
* -, if the $i$-th player lost in a game against the $j$-th player;
* =, if the $i$-th and $j$-th players' game resulted in a draw;
* X, if $i = j$.
## Example

### Input


```text
3
3
111
2
21
4
2122
```
### Output


```text
YES
X==
=X=
==X
NO
YES
X--+
+X++
+-X-
--+X
```


#### Tags 

#1000 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_113_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
