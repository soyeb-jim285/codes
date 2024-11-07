<h1 style='text-align: center;'> E. Farm Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Lunatic Princess - Touhou](https://soundcloud.com/p92402/kaguyas-theme-lunatic-princess)⠀Farmer Nhoj has brought his cows over to Farmer John's farm to play a game! FJ's farm can be modeled by a number line with walls at points $0$ and $l + 1$. On the farm, there are $2n$ cows, with $n$ of the cows belonging to FJ and the other $n$ belonging to FN. They place each of their cows at a distinct point, and no two FJ's cows nor FN's cows are adjacent. Two cows are adjacent if there are no other cows between them. 

Formally, if $a_1, a_2, \ldots, a_n$ represents the positions of FJ's cows and $b_1, b_2, \ldots, b_n$ represents the positions of FN's cows, then either $0 < a_1 < b_1 < a_2 < b_2 < \ldots < a_n < b_n < l + 1$ or $0 < b_1 < a_1 < b_2 < a_2 < \ldots < b_n < a_n < l + 1$.

In one move, a farmer chooses a number $k$ $(1 \leq k \leq n)$ and a direction (left or right). Then, that farmer chooses $k$ of his cows and moves them one position towards the chosen direction. A farmer cannot move any of his cows onto the walls or onto another farmer's cow. If a farmer cannot move any cows, then that farmer loses. FJ starts the game, making the first turn.

Given $l$ and $n$, find the number of possible game configurations for Farmer John to win if both farmers play optimally. It may be the case that the game will continue indefinitely, in which no farmer wins. A configuration is different from another if there is any $i$ such that $a_i$ or $b_i$ is different. ## Output

 the answer modulo $998\,244\,353$.

## Input

The first line contains $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

Each test case contains two integers $l$ and $n$ ($2 \leq l \leq 10^6, 1 \leq n \leq \lfloor \frac{l}{2} \rfloor$) — the length of the number line and the number of cows each farmer will place.

It is guaranteed the sum of $l$ over all test cases does not exceed $10^6$.

## Output

For each test case output an integer: the number of game configurations where Farmer John wins if both farmers play optimally, modulo $998\,244\,353$.

## Example

## Input


```

32 13 1420 69
```
## Output


```

0
2
870279412

```
## Note

Let J denote FJ's cow, N denote FN's cow, and _ denote an empty space.

For the first test case, the two possible configurations are JN or NJ. In both cases, since FJ makes the first turn and cannot make any moves, he cannot win.

For the second case there are two possible configurations for FJ to win: N_J and J_N.



#### tags 

#2300 #combinatorics #games 