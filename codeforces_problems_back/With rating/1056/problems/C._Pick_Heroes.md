<h1 style='text-align: center;'> C. Pick Heroes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Don't you tell me what you think that I can beIf you say that Arkady is a bit old-fashioned playing checkers, you won't be right. There is also a modern computer game Arkady and his friends are keen on. We won't discuss its rules, the only feature important to this problem is that each player has to pick a distinct hero in the beginning of the game.

There are $2$ teams each having $n$ players and $2n$ heroes to distribute between the teams. The teams take turns picking heroes: at first, the first team chooses a hero in its team, after that the second team chooses a hero and so on. ## Note

 that after a hero is chosen it becomes unavailable to both teams.

The friends estimate the power of the $i$-th of the heroes as $p_i$. Each team wants to maximize the total power of its heroes. However, there is one exception: there are $m$ pairs of heroes that are especially strong against each other, so when any team chooses a hero from such a pair, the other team must choose the other one on its turn. Each hero is in at most one such pair.

This is an interactive problem. You are to write a program that will optimally choose the heroes for one team, while the jury's program will play for the other team. ## Note

 that the jury's program may behave inefficiently, in this case you have to take the opportunity and still maximize the total power of your team. Formally, if you ever have chance to reach the total power of $q$ or greater regardless of jury's program choices, you must get $q$ or greater to pass a test.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^3$, $0 \le m \le n$) — the number of players in one team and the number of special pairs of heroes.

The second line contains $2n$ integers $p_1, p_2, \ldots, p_{2n}$ ($1 \le p_i \le 10^3$) — the powers of the heroes.

Each of the next $m$ lines contains two integer $a$ and $b$ ($1 \le a, b \le 2n$, $a \ne b$) — a pair of heroes that are especially strong against each other. It is guaranteed that each hero appears at most once in this list.

The next line contains a single integer $t$ ($1 \le t \le 2$) — the team you are to play for. If $t = 1$, the first turn is yours, otherwise you have the second turn.

Hacks

In order to hack, use the format described above with one additional line. In this line output $2n$ distinct integers from $1$ to $2n$ — the priority order for the jury's team. The jury's team will on each turn select the first possible hero from this list. Here possible means that it is not yet taken and does not contradict the rules about special pair of heroes.

## Interaction

When it is your turn, print a single integer $x$ ($1 \le x \le 2n$) — the index of the hero chosen by you. ## Note

 that you can't choose a hero previously chosen by either you of the other player, and you must follow the rules about special pairs of heroes.

When it is the other team's turn, read a line containing a single integer $x$ ($1 \le x \le 2n$) — the index of the hero chosen by the other team. It is guaranteed that this index is not chosen before and that the other team also follows the rules about special pairs of heroes.

After the last turn you should terminate without printing anything.

After printing your choice do not forget to output end of line and flush the output. Otherwise you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Jury's answer $-1$ instead of a valid choice means that you made an invalid turn. Exit immediately after receiving $-1$ and you will see Wrong answer verdict. Otherwise you can get an arbitrary verdict because your solution will continue to read from a closed stream.

## Examples

## Input


```

3 1
1 2 3 4 5 6
2 6
1

2

4

1

```
Output
```





6

5

3

```
## Input


```

3 1
1 2 3 4 5 6
1 5
2
6

1

3

```
Output
```






5

4

2

```
## Note

In the first example the first turn is yours. In example, you choose $6$, the other team is forced to reply with $2$. You choose $5$, the other team chooses $4$. Finally, you choose $3$ and the other team choose $1$.

In the second example you have the second turn. The other team chooses $6$, you choose $5$, forcing the other team to choose $1$. Now you choose $4$, the other team chooses $3$ and you choose $2$.



#### tags 

#1700 #greedy #implementation #interactive #sortings 