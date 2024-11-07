<h1 style='text-align: center;'> D. Slime Escape</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing a game called Slime Escape. The game takes place on a number line. Initially, there are $n$ slimes. For all positive integers $i$ where $1 \le i \le n$, the $i$-th slime is located at position $i$ and has health $a_i$. You are controlling the slime at position $k$. 

There are two escapes located at positions $0$ and $n+1$. Your goal is to reach any one of the two escapes by performing any number of game moves.

In one game move, you move your slime to the left or right by one position. However, if there is another slime in the new position, you must absorb it. When absorbing a slime, the health of your slime would be increased by the health of the absorbed slime, then the absorbed slime would be removed from the game.

## Note

 that some slimes might have negative health, so your health would decrease when absorbing such slimes. 

You lose the game immediately if your slime has negative health at any moment during the game.

Can you reach one of two escapes by performing any number of game moves, without ever losing the game?

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 20\,000$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two positive integers $n$, $k$ ($3 \leq n \leq 200\,000$, $1 \leq k \leq n$) — the number of slimes and the position of your slime.

The second line of each test case contains $n$ integers, $a_1, a_2, \ldots, a_n$ ($-10^9 \leq a_i \leq 10^9$) — the health of the slimes.

It is guaranteed that health of your slime is non-negative ($a_k \geq 0$), and all other slimes have non-zero health ($a_i \ne 0$ for $i \ne k$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $200\,000$.

## Output

For each test case, print "YES" (without quotes) if you can escape without losing, and "NO" (without quotes) otherwise.

## Example

## Input


```

67 4-1 -2 -3 6 -2 -3 -13 1232 -500 -7007 4-1 -2 -4 6 -2 -4 -18 4-100 10 -7 6 -2 -3 6 -108 2-999 0 -2 3 4 5 6 77 37 3 3 4 2 1 1
```
## Output


```

YES
YES
NO
YES
NO
YES

```
## Note

In the first test case, you control the slime at position $4$ with health $6$. One way to escape is to absorb the slimes at positions $5$, $6$, and $7$. Your slime escapes with $0$ health at position $8$.

In the second test case, you control the slime with $232$ health at position $1$. Since your slime is already located next to the escape at position $0$, you can move to it without absorbing any slime.

In the third test case, it can be shown that your slime would always have a negative health before reaching any one of two escapes.

In the fourth test case, you control the slime at position $4$ with health $6$. The following describes a possible sequence of moves to win:

1. Absorb the slimes at positions $5$, $6$, and $7$: your health becomes $4$ after absorbing the slime with health $-2$; becomes $1$ after absorbing the slime with health $-3$; and becomes $7$ after absorbing the slime with health $6$.
2. Absorb the slimes at positions $3$, and $2$: your health becomes $7-7+10=10$.
3. Absorb the slime at position $8$: your health becomes $10-10=0$.
4. Use the escape at position $9$.

Since your slime has maintained non-negative health at all times, you have won.



#### tags 

#1800 #data_structures #dp #greedy #two_pointers 