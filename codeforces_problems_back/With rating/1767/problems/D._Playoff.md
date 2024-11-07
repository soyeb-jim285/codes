<h1 style='text-align: center;'> D. Playoff</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$2^n$ teams participate in a playoff tournament. The tournament consists of $2^n - 1$ games. They are held as follows: in the first phase of the tournament, the teams are split into pairs: team $1$ plays against team $2$, team $3$ plays against team $4$, and so on (so, $2^{n-1}$ games are played in that phase). When a team loses a game, it is eliminated, and each game results in elimination of one team (there are no ties). After that, only $2^{n-1}$ teams remain. If only one team remains, it is declared the champion; otherwise, the second phase begins, where $2^{n-2}$ games are played: in the first one of them, the winner of the game "$1$ vs $2$" plays against the winner of the game "$3$ vs $4$", then the winner of the game "$5$ vs $6$" plays against the winner of the game "$7$ vs $8$", and so on. This process repeats until only one team remains. 

The skill level of the $i$-th team is $p_i$, where $p$ is a permutation of integers $1$, $2$, ..., $2^n$ (a permutation is an array where each element from $1$ to $2^n$ occurs exactly once).

You are given a string $s$ which consists of $n$ characters. These characters denote the results of games in each phase of the tournament as follows: 

* if $s_i$ is equal to 0, then during the $i$-th phase (the phase with $2^{n-i}$ games), in each match, the team with the lower skill level wins;
* if $s_i$ is equal to 1, then during the $i$-th phase (the phase with $2^{n-i}$ games), in each match, the team with the higher skill level wins.

Let's say that an integer $x$ is winning if it is possible to find a permutation $p$ such that the team with skill $x$ wins the tournament. Find all winning integers.

## Input

The first line contains one integer $n$ ($1 \le n \le 18$).

The second line contains the string $s$ of length $n$ consisting of the characters 0 and/or 1.

## Output

Print all the winning integers $x$ in ascending order.

## Examples

## Input


```

3
101

```
## Output


```

4 5 6 7 
```
## Input


```

1
1

```
## Output


```

2 
```
## Input


```

2
01

```
## Output


```

2 3 
```


#### tags 

#1500 #combinatorics #constructive_algorithms #dp #greedy #math 