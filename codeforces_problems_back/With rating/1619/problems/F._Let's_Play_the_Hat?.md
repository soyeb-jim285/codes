<h1 style='text-align: center;'> F. Let's Play the Hat?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Hat is a game of speedy explanation/guessing words (similar to Alias). It's fun. Try it! In this problem, we are talking about a variant of the game when the players are sitting at the table and everyone plays individually (i.e. not teams, but individual gamers play).

$n$ people gathered in a room with $m$ tables ($n \ge 2m$). They want to play the Hat $k$ times. Thus, $k$ games will be played at each table. Each player will play in $k$ games.

To do this, they are distributed among the tables for each game. During each game, one player plays at exactly one table. A player can play at different tables.

Players want to have the most "fair" schedule of games. For this reason, they are looking for a schedule (table distribution for each game) such that:

* At any table in each game there are either $\lfloor\frac{n}{m}\rfloor$ people or $\lceil\frac{n}{m}\rceil$ people (that is, either $n/m$ rounded down, or $n/m$ rounded up). Different numbers of people can play different games at the same table.
* Let's calculate for each player the value $b_i$ — the number of times the $i$-th player played at a table with $\lceil\frac{n}{m}\rceil$ persons ($n/m$ rounded up). Any two values of $b_i$must differ by no more than $1$. In other words, for any two players $i$ and $j$, it must be true $|b_i - b_j| \le 1$.

For example, if $n=5$, $m=2$ and $k=2$, then at the request of the first item either two players or three players should play at each table. Consider the following schedules:

* First game: $1, 2, 3$ are played at the first table, and $4, 5$ at the second one. The second game: at the first table they play $5, 1$, and at the second  — $2, 3, 4$. This schedule is not "fair" since $b_2=2$ (the second player played twice at a big table) and $b_5=0$ (the fifth player did not play at a big table).
* First game: $1, 2, 3$ are played at the first table, and $4, 5$ at the second one. The second game: at the first table they play $4, 5, 2$, and at the second one  — $1, 3$. This schedule is "fair": $b=[1,2,1,1,1]$ (any two values of $b_i$ differ by no more than $1$).

Find any "fair" game schedule for $n$ people if they play on the $m$ tables of $k$ games.

## Input

The first line of the input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the test.

Each test case consists of one line that contains three integers $n$, $m$ and $k$ ($2 \le n \le 2\cdot10^5$, $1 \le m \le \lfloor\frac{n}{2}\rfloor$, $1 \le k \le 10^5$) — the number of people, tables and games, respectively.

It is guaranteed that the sum of $nk$ ($n$ multiplied by $k$) over all test cases does not exceed $2\cdot10^5$.

## Output

For each test case print a required schedule  — a sequence of $k$ blocks of $m$ lines. Each block corresponds to one game, a line in a block corresponds to one table. In each line print the number of players at the table and the indices of the players (numbers from $1$ to $n$) who should play at this table.

If there are several required schedules, then output any of them. We can show that a valid solution always exists.

You can output additional blank lines to separate responses to different sets of inputs.

## Example

## Input


```

3
5 2 2
8 3 1
2 1 3

```
## Output


```

3 1 2 3
2 4 5
3 4 5 2
2 1 3

2 6 2
3 3 5 1
3 4 7 8

2 2 1
2 2 1
2 2 1

```


#### tags 

#2000 #brute_force #constructive_algorithms #greedy #math 