<h1 style='text-align: center;'> C. Game on Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game. They have a permutation $p$ of size $n$ (a permutation of size $n$ is an array of size $n$ where each element from $1$ to $n$ occurs exactly once). They also have a chip, which can be placed on any element of the permutation.

Alice and Bob make alternating moves: Alice makes the first move, then Bob makes the second move, then Alice makes the third move, and so on. During the first move, Alice chooses any element of the permutation and places the chip on that element. During each of the next moves, the current player has to move the chip to any element that is simultaneously to the left and strictly less than the current element (i. e. if the chip is on the $i$-th element, it can be moved to the $j$-th element if $j < i$ and $p_j < p_i$). If a player cannot make a move (it is impossible to move the chip according to the rules of the game), that player wins the game.

Let's say that the $i$-th element of the permutation is lucky if the following condition holds:

* if Alice places the chip on the $i$-th element during her first move, she can win the game no matter how Bob plays (i. e. she has a winning strategy).

You have to calculate the number of lucky elements in the permutation.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 3 \cdot 10^5$) – the number of elements in the permutation.

The second line contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \le p_i \le n$). All $p_i$ are distinct. 

The sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

## Output

For each test case, print a single integer — the number of lucky elements in the permutation.

## Example

## Input


```

432 1 322 131 2 342 1 4 3
```
## Output


```

1
0
1
2

```
## Note

In the first test case of the example, the $3$-rd element of the permutation is lucky.

In the second test case of the example, there are no lucky elements.

In the third test case of the example, the $2$-nd element of the permutation is lucky.

In the fourth test case of the example, the $3$-rd and the $4$-th element of the permutation are lucky.



#### tags 

#1400 #data_structures #dp #games #greedy 