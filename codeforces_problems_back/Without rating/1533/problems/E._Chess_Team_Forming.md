<h1 style='text-align: center;'> E. Chess Team Forming</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp is coaching a team for an upcoming game at the chess tournament. A complete team for the tournament should consist of $n+1$ members.

There are $n$ members in his team, the $i$-th member's skill value is $a_i$. Polycarp is yet to choose the final member for the team.

The opposing team has $n+1$ members, the $j$-th member's skill value is $b_j$.

Polycarp has $m$ options for the final player of the team. The $k$-th of them has a skill value $c_k$.

Before the game starts, Polycarp pairs up the members of his team with the members of the opposing team. Every member of both teams is in exactly one pair. The difficulty of a game for a certain player is the difference between his paired opponent's skill and his own skill. So if the $i$-th player of the Polycarp's team is paired up with the $j$-th member of the opposing team, then the difficulty is equal to $b_j - a_i$. The difficulty of the game for a team is the maximum difficulty of all its players.

So, before the game starts, Polycarp wants to pair up the players in such a way that the difficulty of the game for his team is minimized.

For each of the $m$ options for the final player print the smallest difficulty of the game for the team Polycarp can achieve.

## Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of members in the Polycarp's team.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$), where $a_i$ is the skill value of the $i$-th player of the Polycarp's team.

The third line contains $n+1$ integers $b_1, b_2, \dots, b_{n+1}$ ($1 \le b_j \le 10^9$), where $b_j$ is the skill value of the $j$-th player of the opposing team.

The fourth line contains a single integer $m$ ($1 \le m \le 2 \cdot 10^5$) — the number of options for the final player.

The fifth line contains $m$ integers $c_1, c_2, \dots, c_m$ ($1 \le c_k \le 10^9$), where $c_k$ is the skill value of the $k$-th of the options for the final player of the Polycarp's team.

## Output

Print $m$ integers — the $k$-th of them should be equal to the smallest difficulty of the game for the team Polycarp can achieve if he picks the $k$-th option player as the final one.

## Examples

## Input


```

5
10 3 4 6 1
9 4 2 5 9 8
5
1 7 6 4 8

```
## Output


```

4 2 3 4 2

```
## Input


```

3
5 1 8
8 2 10 1
10
1 2 3 4 5 6 7 8 9 10

```
## Output


```

3 3 3 3 3 2 2 2 1 0

```
## Input


```

1
10
10 5
2
5 15

```
## Output


```

0 -5

```
## Note

In the first example the optimal pairings for the first three options are the following. ## Note

 that there might be multiple valid pairing for the minimum answer.

First option:

Polycarp's team: 6 1 3 1 10 4

Opposing team:  9 4 2 5  9 8

The respective difficulties of the game for each player are: 3, 3, -1, 4, -1, 4. The maximum is 4, thus it's the difficulty of the game for the team.

Second option:

Polycarp's team: 10 4 1 3 7 6

Opposing team:   9 4 2 5 9 8

Third option:

Polycarp's team: 6 3 1 4 10 6

Opposing team:  9 4 2 5  9 8



#### tags 

#*special #binary_search #data_structures #greedy 