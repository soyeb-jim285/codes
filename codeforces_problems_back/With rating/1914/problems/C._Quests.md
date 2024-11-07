<h1 style='text-align: center;'> C. Quests</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing a computer game. In order to level up his character, he can complete quests. There are $n$ quests in the game, numbered from $1$ to $n$.

Monocarp can complete quests according to the following rules: 

* the $1$-st quest is always available for completion;
* the $i$-th quest is available for completion if all quests $j < i$ have been completed at least once.

## Note

 that Monocarp can complete the same quest multiple times.

For each completion, the character gets some amount of experience points: 

* for the first completion of the $i$-th quest, he gets $a_i$ experience points;
* for each subsequent completion of the $i$-th quest, he gets $b_i$ experience points.

Monocarp is a very busy person, so he has free time to complete no more than $k$ quests. Your task is to calculate the maximum possible total experience Monocarp can get if he can complete no more than $k$ quests.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$; $1 \le k \le 2 \cdot 10^5$) — the number of quests and the maximum number of quests Monocarp can complete, respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^3$).

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^3$).

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print a single integer — the maximum possible total experience Monocarp can get if he can complete no more than $k$ quests.

## Example

## Input


```

44 74 3 1 21 1 1 13 21 2 53 1 85 53 2 4 1 42 3 1 4 76 41 4 5 4 5 101 5 1 2 5 1
```
## Output


```

13
4
15
15

```
## Note

In the first test case, one of the possible quest completion sequences is as follows: $1, 1, 2, 3, 2, 4, 4$; its total experience is equal to $\underline{4} + 1 + \underline{3} + \underline{1} + 1 + \underline{2} + 1 = 13$ (the underlined numbers correspond to the instances when we complete a quest for the first time).

In the second test case, one of the possible quest completion sequences is as follows: $1, 1$; its total experience is equal to $\underline{1} + 3 = 4$.

In the third test case, one of the possible quest completion sequences is as follows: $1, 2, 2, 2, 3$; its total experience is equal to $\underline{3} + \underline{2} + 3 + 3 + \underline{4} = 15$.



#### tags 

#1100 #greedy #math 