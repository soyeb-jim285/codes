<h1 style='text-align: center;'> A. Tenzing and Tsondu</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tsondu always runs first! ! !Tsondu and Tenzing are playing a card game. Tsondu has $n$ monsters with ability values $a_1, a_2, \ldots, a_n$ while Tenzing has $m$ monsters with ability values $b_1, b_2, \ldots, b_m$.

Tsondu and Tenzing take turns making moves, with Tsondu going first. In each move, the current player chooses two monsters: one on their side and one on the other side. Then, these monsters will fight each other. Suppose the ability values for the chosen monsters are $x$ and $y$ respectively, then the ability values of the monsters will become $x-y$ and $y-x$ respectively. If the ability value of any monster is smaller than or equal to $0$, the monster dies.

The game ends when at least one player has no monsters left alive. The winner is the player with at least one monster left alive. If both players have no monsters left alive, the game ends in a draw.

Find the result of the game when both players play optimally.

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 2 \cdot 10^3$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq n,m \leq 50$) — the number of monsters Tsondu and Tenzing have respectively.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ $(1 \leq a_i \leq 10^9$) — the ability values of Tsondu's monsters. 

The third line of each test case contains $m$ integers $b_1,b_2,\ldots,b_m$ $(1 \leq b_i \leq 10^9$) — the ability values of Tenzing's monsters. 

## Output

For each test case, output "Tsondu" if Tsondu wins, "Tenzing" if Tenzing wins, and "Draw" if the game ends in a draw. (## Output

 without quotes.)

## Note

 that the output is case-sensitive. For example, if the answer is "Tsondu", the outputs "tsondu", "TSONDU", and "tSonDu" will all be recognized as incorrect outputs.

## Example

## Input


```

61 391 2 32 31 21 1 13 21 2 31 13 31 1 12 2 210 101 2 3 3 2 2 1 1 2 23 3 3 3 2 1 1 1 1 110 101 2 3 4 5 6 7 8 9 106 7 8 9 10 11 1 1 1 1
```
## Output


```

Tsondu
Draw
Tsondu
Tenzing
Draw
Draw

```
## Note

Consider the first test case. It can be shown that Tsondu has a winning strategy. The following is a possible way that Tsondu can win (note that the players may not be playing optimally in this example):

* In the first move, Tsondu chooses a monster with ability value $9$ on his side to fight against a monster with ability value $1$ on Tenzing's side, the ability value of both monsters become $8$ and $-8$ respectively. The monster with ability value $-8$ on Tenzing's side dies.
* In the second move, Tenzing chooses a monster with ability value $2$ on his side to fight against a monster with ability value $8$ on Tsondu's side, the ability value of both monsters become $-6$ and $6$ respectively. The monster with ability value $-6$ on Tenzing's side dies.
* In the third move, Tsondu chooses a monster with ability value $6$ on his side to fight against a monster with ability value $3$ onTenzing's side, the ability value of both monsters become $3$ and $-3$ respectively. The monster with ability value $-3$ on Tenzing's side dies.
* Now, Tenzing has no monsters left alive. Since Tsondu still has monsters left alive, Tsondu wins.


#### tags 

#800 #games #math 