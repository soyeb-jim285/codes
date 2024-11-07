<h1 style='text-align: center;'> C. Card Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ cards stacked in a deck. Initially, $a_{i}$ is written on the $i$-th card from the top. The value written on a card does not change.

You will play a game. Initially your score is $0$. In each turn, you can do one of the following operations: 

* Choose an odd$^{\dagger}$ positive integer $i$, which is not greater than the number of cards left in the deck. Remove the $i$-th card from the top of the deck and add the number written on the card to your score. The remaining cards will be reindexed starting from the top.
* Choose an even$^{\ddagger}$ positive integer $i$, which is not greater than the number of cards left in the deck. Remove the $i$-th card from the top of the deck. The remaining cards will be reindexed starting from the top.
* End the game. You can end the game whenever you want, you do not have to remove all cards from the initial deck.

What is the maximum score you can get when the game ends?

$^{\dagger}$ An integer $i$ is odd, if there exists an integer $k$ such that $i = 2k + 1$.

$^{\ddagger}$ An integer $i$ is even, if there exists an integer $k$ such that $i = 2k$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^{4}$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^{5}$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^{9} \le a_i \le 10^{9}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^{5}$.

## Output

For each test case, print a single integer — the maximum score you can get when the game ends.

## Example

## Input


```

44-4 1 -3 541 -2 3 -43-1 3 -51-1
```
## Output


```

5
4
2
0

```
## Note

In the first test case, one can get the score of $5$ as follows: 

1. In the first turn, choose $i=2$. Your score remains $0$ and the numbers written on the cards from the top will become $[-4, -3, 5]$.
2. In the second turn, choose $i=3$. Your score will become $5$ and the numbers written on the cards from the top will become $[-4, -3]$.
3. In the third turn, end the game with the score of $5$.

In the second test case, one can get the score of $4$ as follows: 

1. In the first turn, choose $i=3$. Your score will become $3$ and the numbers written on the cards from the top will become $[1, -2, -4]$.
2. In the second turn, choose $i=1$. Your score will become $4$ and the numbers written on the cards from the top will become $[-2, -4]$.
3. In the third turn, end the game with the score of $4$.

In the third test case, one can get the score of $2$ as follows: 

1. In the first turn, choose $i=1$. Your score will become $-1$ and the numbers written on the cards from the top will become $[3, -5]$.
2. In the second turn, choose $i=1$. Your score will become $2$ and the numbers written on the cards from the top will become $[-5]$.
3. In the third turn, end the game with the score of $2$.


#### tags 

#1500 #brute_force #greedy 