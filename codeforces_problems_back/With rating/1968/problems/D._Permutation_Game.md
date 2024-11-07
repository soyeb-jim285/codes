<h1 style='text-align: center;'> D. Permutation Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bodya and Sasha found a permutation $p_1,\dots,p_n$ and an array $a_1,\dots,a_n$. They decided to play a well-known "Permutation game".

A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

Both of them chose a starting position in the permutation.

The game lasts $k$ turns. The players make moves simultaneously. On each turn, two things happen to each player: 

* If the current position of the player is $x$, his score increases by $a_x$.
* Then the player either stays at his current position $x$ or moves from $x$ to $p_x$.

 The winner of the game is the player with the higher score after exactly $k$ turns.Knowing Bodya's starting position $P_B$ and Sasha's starting position $P_S$, determine who wins the game if both players are trying to win.

## Input

The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of testcases.

The first line of each testcase contains integers $n$, $k$, $P_B$, $P_S$ ($1\le P_B,P_S\le n\le 2\cdot 10^5$, $1\le k\le 10^9$) — length of the permutation, duration of the game, starting positions respectively.

The next line contains $n$ integers $p_1,\dots,p_n$ ($1 \le p_i \le n$) — elements of the permutation $p$.

The next line contains $n$ integers $a_1,\dots,a_n$ ($1\le a_i\le 10^9$) — elements of array $a$.

It is guaranteed that the sum of values of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each testcase output: 

* "Bodya" if Bodya wins the game.
* "Sasha" if Sasha wins the game.
* "Draw" if the players have the same score.
## Example

## Input


```

104 2 3 24 1 2 37 2 5 610 8 2 103 1 4 5 2 7 8 10 6 95 10 5 1 3 7 10 15 4 32 1000000000 1 21 24 48 10 4 15 1 4 3 2 8 6 71 1 2 1 2 100 101 1025 1 2 51 2 4 5 34 6 9 4 24 2 3 14 1 3 26 8 5 36 9 5 46 1 3 5 2 46 9 8 9 5 104 8 4 22 3 4 15 2 8 74 2 3 14 1 3 26 8 5 32 1000000000 1 21 21000000000 2
```
## Output


```

Bodya
Sasha
Draw
Draw
Bodya
Sasha
Sasha
Sasha
Sasha
Bodya

```
## Note

Below you can find the explanation for the first testcase, where the game consists of $k=2$ turns.

 

| Turn | Bodya's position | Bodya's score | Bodya's move | Sasha's position | Sasha's score | Sasha's move |
| --- | --- | --- | --- | --- | --- | --- |
| first | $3$ | $0 + a_3 = 0 + 5 = 5$ | stays on the same position | $2$ | $0 + a_2 = 0 + 2 = 2$ | moves to $p_2=1$ |
| second | $3$ | $5 + a_3 = 5 + 5 = 10$ | stays on the same position | $1$ | $2 + a_1 = 2 + 7 = 9$ | stays on the same position |
| final results | $3$ | $10$ |  | $1$ | $9$ |  |

 As we may see, Bodya's score is greater, so he wins the game. It can be shown that Bodya always can win this game.



#### tags 

#1300 #brute_force #dfs_and_similar #games #graphs #greedy #math 