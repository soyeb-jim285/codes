<h1 style='text-align: center;'> B. Card Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Suneet and Slavic play a card game. The rules of the game are as follows:

* Each card has an integer value between $1$ and $10$.
* Each player receives $2$ cards which are face-down (so a player doesn't know their cards).
* The game is turn-based and consists exactly of two turns. In a round, both players pick a random unflipped card and flip it. The player who flipped a card with a strictly greater number wins the round. In case of equality, no one wins the round.
* A player wins a game if he wins the most number of rounds (i.e. strictly greater than the other player). In case of equality, no one wins the game.

Since Suneet and Slavic aren't best friends, you need to calculate the number of ways the game could happen that Suneet would end up as the winner.

For a better understanding, please check the notes section.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first and only line of each test case contains $4$ integers $a_1$, $a_2$, $b_1$, $b_2$ ($1 \leq a_1, a_2, b_1, b_2 \leq 10$) where $a_1$ and $a_2$ represent the cards Suneet has, and $b_1$ and $b_2$ represent the cards Slavic has, respectively.

### Output

For each test case, output a single integer — the number of games Suneet would win considering all possible games.

## Example

### Input


```text
53 8 2 61 1 1 110 10 2 21 1 10 103 8 7 2
```
### Output

```text

2
0
4
0
2

```
## Note

Consider the first test case when Slavic starts with the cards that have the values $2$ and $6$, and Suneet starts with cards that have the values $3$ and $8$. The game could happen in $4$ different ways:

* Suneet flips $3$ and Slavic flips $2$. Suneet wins the first round. Then, Suneet flips $8$ and Slavic flips $6$. Suneet wins the second round as well. Since Suneet won $2$ rounds, he wins the game.
* Suneet flips $3$ and Slavic flips $6$. Slavic wins the first round. Then, Suneet flips $8$ and Slavic flips $2$. Suneet wins the second round. Nobody wins since both players won an equal amount of rounds.
* Suneet flips $8$ and Slavic flips $6$. Suneet wins the first round. Then, Suneet flips $3$ and Slavic flips $2$. Suneet wins the second round as well. Since Suneet won $2$ rounds, he wins the game.
* Suneet flips $8$ and Slavic flips $2$. Suneet wins the first round. Then, Suneet flips $3$ and Slavic flips $6$. Slavic wins the round. Nobody wins since both players won an equal amount of rounds.


#### Tags 

#NOT OK #brute_force #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_964_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
