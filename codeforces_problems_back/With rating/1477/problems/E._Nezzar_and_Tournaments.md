<h1 style='text-align: center;'> E. Nezzar and Tournaments</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

In the famous Oh-Suit-United tournament, two teams are playing against each other for the grand prize of precious pepper points.

The first team consists of $n$ players, and the second team consists of $m$ players. Each player has a potential: the potential of the $i$-th player in the first team is $a_i$, and the potential of the $i$-th player in the second team is $b_i$.

In the tournament, all players will be on the stage in some order. There will be a scoring device, initially assigned to an integer $k$, which will be used to value the performance of all players.

The scores for all players will be assigned in the order they appear on the stage. Let the potential of the current player be $x$, and the potential of the previous player be $y$ ($y$ equals $x$ for the first player). Then, $x-y$ is added to the value in the scoring device, Afterwards, if the value in the scoring device becomes negative, the value will be reset to $0$. Lastly, the player's score is assigned to the current value on the scoring device. The score of a team is the sum of the scores of all its members.

As an insane fan of the first team, Nezzar desperately wants the biggest win for the first team. He now wonders what is the maximum difference between scores of the first team and the second team.

Formally, let the score of the first team be $score_f$ and the score of the second team be $score_s$. Nezzar wants to find the maximum value of $score_f - score_s$ over all possible orders of players on the stage.

However, situation often changes and there are $q$ events that will happen. There are three types of events:

* $1$ $pos$ $x$ — change $a_{pos}$ to $x$;
* $2$ $pos$ $x$ — change $b_{pos}$ to $x$;
* $3$ $x$ — tournament is held with $k = x$ and Nezzar wants you to compute the maximum value of $score_f - score_s$.

Can you help Nezzar to answer the queries of the third type?

## Input

The first line contains three integers $n$, $m$, and $q$ ($1 \le n,m \le 2 \cdot 10^5, 1 \le q \le 5 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^6$).

The third line contains $m$ integers $b_1, b_2, \ldots, b_m$ ($0 \le b_i \le 10^6$).

The following $q$ lines contain descriptions of events, described in the statement, each in one of the three possible formats:

* $1$ $pos$ $x$ ($1 \le pos \le n$, $0 \le x \le 10^6$);
* $2$ $pos$ $x$ ($1 \le pos \le m$, $0 \le x \le 10^6$);
* $3$ $x$ ($0 \le x \le 10^6$).
## Output

For each query of the third type print the answer to this query.

## Examples

## Input


```

3 4 3
1 2 7
3 4 5 6
3 5
1 1 10
3 5

```
## Output


```

-4
9

```
## Input


```

7 8 12
958125 14018 215153 35195 90380 30535 204125
591020 930598 252577 333333 999942 1236 9456 82390
3 123458
2 4 444444
3 123456
1 2 355555
3 123478
3 1111
2 6 340324
3 1111
2 8 999999
2 7 595959
3 222222
3 100

```
## Output


```

1361307
1361311
1702804
1879305
1821765
1078115
1675180

```
## Note

In the first query of the first test, the tournament is held with $k = 5$. It would be optimal to arrange players in such way (here their potentials are written):

$\underline{7}$, $3$, $5$, $4$, $6$, $\underline{1}$, $\underline{2}$ (underlined numbers are potentials of players that are from the first team). 

The individual scores of players, numbered in the order of their appearance, are:

* $\max(5 + (7 - 7), 0) = 5$ for the $\underline{1}$-st player;
* $\max(5 + (3 - 7), 0) = 1$ for the $2$-nd player;
* $\max(1 + (5 - 3), 0) = 3$ for the $3$-rd player;
* $\max(3 + (4 - 5), 0) = 2$ for the $4$-th player;
* $\max(2 + (6 - 4), 0) = 4$ for the $5$-th player;
* $\max(4 + (1 - 6), 0) = 0$ for the $\underline{6}$-th player;
* $\max(0 + (2 - 1), 0) = 1$ for the $\underline{7}$-th player.

 So, $score_f = 5 + 0 + 1 = 6$ and $score_s = 1 + 3 + 2 + 4 = 10$. The score difference is $6 - 10 = -4$. It can be proven, that it is the maximum possible score difference.



#### tags 

#3300 #data_structures #greedy 