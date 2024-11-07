<h1 style='text-align: center;'> J. Necromancer</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp is playing a computer game. In this game, his character is a necromancer. He is fighting $n$ monsters numbered from $1$ to $n$. Each monster has two parameters: health and strength.

Monocarp considers $q$ scenarios of the battle. In each scenario, he chooses some segment $[l, r]$ of monsters and calculates the number of moves it takes to defeat all these monsters.

Each scenario proceeds as follows. First, Monocarp kills monster $l$ and revives it as a zombie (this does not count as a move). Then each move the following happens: let $i$ be the index of the first monster in the segment $[l, r]$ that is still alive. All zombies attack monster $i$, reducing its health by their total strength. After that, if monster $i$ has $0$ or less health, it dies and Monocarp revives it as a zombie.

When the monster is revived, the zombie's strength is equal to the monster's strength.

Help Monocarp for each scenario to calculate how many moves it will take to kill all the monsters in the segment.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$) — the number of monsters and the number of scenarios, respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^4$), where $a_i$ is the number of health points of the $i$-th monster.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^4$), where $b_i$ is the strength of the $i$-th monster.

Then $q$ lines follow. The $j$-th of them contains two integers $l_j$ and $r_j$ ($1 \le l_j \le r_j \le n$) — the boundaries of the $j$-th scenario.

## Output

For each scenario, print a single integer — the number of moves it will take to kill all the monsters in the segment.

## Example

## Input


```

7 54 5 9 9 4 2 41 3 3 1 2 3 33 51 46 61 72 6
```
## Output


```

4
10
0
13
7

```


#### tags 

#3200 #*special 