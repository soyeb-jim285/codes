<h1 style='text-align: center;'> H. Olympic Team Building</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iron and Werewolf are participating in a chess Olympiad, so they want to practice team building. They gathered $n$ players, where $n$ is a power of $2$, and they will play sports. Iron and Werewolf are among those $n$ people.

One of the sports is tug of war. For each $1\leq i \leq n$, the $i$-th player has strength $s_i$. Elimination rounds will be held until only one player remains — we call that player the absolute winner.

In each round: 

* Assume that $m>1$ players are still in the game, where $m$ is a power of $2$.
* The $m$ players are split into two teams of equal sizes (i. e., with $m/2$ players in each team). The strength of a team is the sum of the strengths of its players.
* If the teams have equal strengths, Iron chooses who wins; otherwise, the stronger team wins.
* Every player in the losing team is eliminated, so $m/2$ players remain.

Iron already knows each player's strength and is wondering who can become the absolute winner and who can't if he may choose how the teams will be formed in each round, as well as the winning team in case of equal strengths.

####### Input

The first line contains a single integer $n$ ($4 \leq n \leq 32$) — the number of players participating in tug of war. It is guaranteed that $n$ is a power of $2$.

The second line consists of a sequence $s_1,s_2, \ldots, s_n$ of integers ($1 \leq s_i \leq 10^{15}$) — the strengths of the players.

####### Output

In a single line output a binary string $s$ of length $n$ — the $i$-th character of $s$ should be $1$ if the $i$-th player can become the absolute winner and it should be $0$ otherwise.

## Examples

####### Input


```text
4
60 32 59 87
```
####### Output


```text
1001
```
####### Input


```text
4
100 100 100 100
```
####### Output


```text
1111
```
####### Input


```text
8
8 8 8 8 4 4 4 4
```
####### Output


```text
11110000
```
####### Input


```text
32
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
```
####### Output


```text
00000000000000001111111111111111
```
####### Input


```text
16
1 92875987325987 1 1 92875987325986 92875987325985 1 92875987325988 92875987325990 92875987325989 1 1 92875987325984 92875987325983 1 1
```
####### Output


```text
0100110111001000
```
## Note

In the first example, players $1$ and $4$ with their respective strengths of $60$ and $87$ can become the absolute winners.

Let's describe the process for player $1$. Firstly, we divide the players into teams $[1,3]$ and $[2,4]$. Strengths of those two teams are $60+59=119$ and $32+87=119$. They they are equal, Iron can choose to disqualify any of the two teams. Let his choice be the second team.

We are left with players $1$ and $3$. Since $1$ has greater strength ($60>59$) they win and are declared the absolute winner as they are the last remaining player.

In the third example, the strengths of the remaining players may look like $[8,8,8,8,4,4,4,4] \rightarrow [8,8,4,4] \rightarrow [8,4] \rightarrow [8]$. Each person with strength $8$ can become the absolute winner and it can be proved that others can't.



#### Tags 

#3500 #NOT OK #brute_force #meet-in-the-middle 

## Blogs
- [All Contest Problems](../Hello_2023.md)
- [Hello 2023 (en)](../blogs/Hello_2023_(en).md)
- [Editorial for Hello 2023 (en)](../blogs/Editorial_for_Hello_2023_(en).md)
