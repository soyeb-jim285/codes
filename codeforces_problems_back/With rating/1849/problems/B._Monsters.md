<h1 style='text-align: center;'> B. Monsters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing yet another computer game. And yet again, his character is killing some monsters. There are $n$ monsters, numbered from $1$ to $n$, and the $i$-th of them has $a_i$ health points initially.

Monocarp's character has an ability that deals $k$ damage to the monster with the highest current health. If there are several of them, the one with the smaller index is chosen. If a monster's health becomes less than or equal to $0$ after Monocarp uses his ability, then it dies.

Monocarp uses his ability until all monsters die. Your task is to determine the order in which monsters will die.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 3 \cdot 10^5$; $1 \le k \le 10^9$) — the number of monsters and the damage which Monocarp's ability deals.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the initial health points of monsters.

The sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

## Output

For each test case, print $n$ integers — the indices of monsters in the order they die. 

## Example

## Input


```

33 21 2 32 31 14 32 8 3 5
```
## Output


```

2 1 3 
1 2 
3 1 2 4 

```
## Note

In the first example, the health points change as follows: $[1, 2, \underline{3}] \rightarrow [1, \underline{2}, 1] \rightarrow [\underline{1}, 0, 1] \rightarrow [-1, 0, \underline{1}] \rightarrow [-1, 0, -1]$. The monster that is going to take damage the next time Monocarp uses his ability is underlined.

In the second example, the health points change as follows: $[\underline{1}, 1] \rightarrow [-2, \underline{1}] \rightarrow [-2, -2]$.

In the third example, the health points change as follows: $[2, \underline{8}, 3, 5] \rightarrow [2, \underline{5}, 3, 5] \rightarrow [2, 2, 3, \underline{5}] \rightarrow [2, 2, \underline{3}, 2] \rightarrow [\underline{2}, 2, 0, 2] \rightarrow [-1, \underline{2}, 0, 2] \rightarrow [-1, -1, 0, \underline{2}] \rightarrow [-1, -1, 0, -1]$. 



#### tags 

#1000 #greedy #math #sortings 