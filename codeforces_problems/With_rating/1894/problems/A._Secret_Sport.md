<h1 style='text-align: center;'> A. Secret Sport</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let's consider a game in which two players, A and B, participate. This game is characterized by two positive integers, $X$ and $Y$.

The game consists of sets, and each set consists of plays. In each play, exactly one of the players, either A or B, wins. A set ends exactly when one of the players reaches $X$ wins in the plays of that set. This player is declared the winner of the set. The players play sets until one of them reaches $Y$ wins in the sets. After that, the game ends, and this player is declared the winner of the entire game.

You have just watched a game but didn't notice who was declared the winner. You remember that during the game, $n$ plays were played, and you know which player won each play. However, you do not know the values of $X$ and $Y$. Based on the available information, determine who won the entire game — A or B. If there is not enough information to determine the winner, you should also report it.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ $(1 \leq t \leq 10^4)$ - the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ $(1 \leq n \leq 20)$ - the number of plays played during the game.

The second line of each test case contains a string $s$ of length $n$, consisting of characters $\texttt{A}$ and $\texttt{B}$. If $s_i = \texttt{A}$, it means that player A won the $i$-th play. If $s_i = \texttt{B}$, it means that player B won the $i$-th play.

It is guaranteed that the given sequence of plays corresponds to at least one valid game scenario, for some values of $X$ and $Y$.

### Output

For each test case, output:

* $\texttt{A}$ — if player A is guaranteed to be the winner of the game.
* $\texttt{B}$ — if player B is guaranteed to be the winner of the game.
* $\texttt{?}$ — if it is impossible to determine the winner of the game.
## Example

### Input


```text
75ABBAA3BBB7BBAAABA20AAAAAAAABBBAABBBBBAB1A13AAAABABBABBAB7BBBAAAA
```
### Output

```text

A
B
A
B
A
B
A

```
## Note

In the first test case, the game could have been played with parameters $X = 3$, $Y = 1$. The game consisted of $1$ set, in which player A won, as they won the first $3$ plays. In this scenario, player A is the winner. The game could also have been played with parameters $X = 1$, $Y = 3$. It can be shown that there are no such $X$ and $Y$ values for which player B would be the winner.

In the second test case, player B won all the plays. It can be easily shown that in this case, player B is guaranteed to be the winner of the game.

In the fourth test case, the game could have been played with parameters $X = 3$, $Y = 3$:

* In the first set, $3$ plays were played: AAA. Player A is declared the winner of the set.
* In the second set, $3$ plays were played: AAA. Player A is declared the winner of the set.
* In the third set, $5$ plays were played: AABBB. Player B is declared the winner of the set.
* In the fourth set, $5$ plays were played: AABBB. Player B is declared the winner of the set.
* In the fifth set, $4$ plays were played: BBAB. Player B is declared the winner of the set.

In total, player B was the first player to win $3$ sets. They are declared the winner of the game.



#### Tags 

#800 #OK #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_908_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
