<h1 style='text-align: center;'> G. Number Deletion Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Alice and Bob play a game. They have a set that initially consists of $n$ integers. The game is played in $k$ turns. During each turn, the following events happen:

1. firstly, Alice chooses an integer from the set. She can choose any integer except for the maximum one. Let the integer chosen by Alice be $a$;
2. secondly, Bob chooses an integer from the set. He can choose any integer that is greater than $a$. Let the integer chosen by Bob be $b$;
3. finally, both $a$ and $b$ are erased from the set, and the value of $b - a$ is added to the score of the game.

Initially, the score is $0$. Alice wants to maximize the resulting score, Bob wants to minimize it. Assuming that both Alice and Bob play optimally, calculate the resulting score of the game.

## Input

The first line contains two integers $n$ and $k$ ($2 \le n \le 400$, $1 \le k \le \lfloor\frac{n}{2}\rfloor$) — the initial size of the set and the number of turns in the game.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$) — the initial contents of the set. These integers are pairwise distinct.

## Output

Print one integer — the resulting score of the game (assuming that both Alice and Bob play optimally).

## Examples

## Input


```

5 2
3 4 1 5 2

```
## Output


```

4

```
## Input


```

7 3
101 108 200 1 201 109 100

```
## Output


```

283

```


#### tags 

#2100 #*special #dp #games #greedy 