<h1 style='text-align: center;'> C. Salyg1n and the MEX Game</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem!

salyg1n gave Alice a set $S$ of $n$ distinct integers $s_1, s_2, \ldots, s_n$ ($0 \leq s_i \leq 10^9$). Alice decided to play a game with this set against Bob. The rules of the game are as follows:

* Players take turns, with Alice going first.
* In one move, Alice adds one number $x$ ($0 \leq x \leq 10^9$) to the set $S$. The set $S$ must not contain the number $x$ at the time of the move.
* In one move, Bob removes one number $y$ from the set $S$. The set $S$ must contain the number $y$ at the time of the move. Additionally, the number $y$ must be strictly smaller than the last number added by Alice.
* The game ends when Bob cannot make a move or after $2 \cdot n + 1$ moves (in which case Alice's move will be the last one).
* The result of the game is $\operatorname{MEX}\dagger(S)$ ($S$ at the end of the game).
* Alice aims to maximize the result, while Bob aims to minimize it.

Let $R$ be the result when both players play optimally. In this problem, you play as Alice against the jury program playing as Bob. Your task is to implement a strategy for Alice such that the result of the game is always at least $R$.

$\dagger$ $\operatorname{MEX}$ of a set of integers $c_1, c_2, \ldots, c_k$ is defined as the smallest non-negative integer $x$ which does not occur in the set $c$. For example, $\operatorname{MEX}(\{0, 1, 2, 4\})$ $=$ $3$.

## Input

The first line contains an integer $t$ ($1 \leq t \leq 10^5$) - the number of test cases.

## Interaction

The interaction between your program and the jury program begins with reading an integer $n$ ($1 \leq n \leq 10^5$) - the size of the set $S$ before the start of the game.

Then, read one line - $n$ distinct integers $s_i$ $(0 \leq s_1 < s_2 < \ldots < s_n \leq 10^9)$ - the set $S$ given to Alice.

To make a move, output an integer $x$ ($0 \leq x \leq 10^9$) - the number you want to add to the set $S$. $S$ must not contain $x$ at the time of the move. Then, read one integer $y$ $(-2 \leq y \leq 10^9)$. 

* If $0 \leq y \leq 10^9$ - Bob removes the number $y$ from the set $S$. It's your turn!
* If $y$ $=$ $-1$ - the game is over. After this, proceed to handle the next test case or terminate the program if it was the last test case.
* Otherwise, $y$ $=$ $-2$. This means that you made an invalid query. Your program should immediately terminate to receive the verdict Wrong Answer. Otherwise, it may receive any other verdict.

After printing a query do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

 It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.Do not attempt to hack this problem.

## Example

## Input


```

3
5
1 2 3 5 7

7

5

-1

3
0 1 2

0

-1

3
5 7 57

-1
```
Output
```

8

57

0

3

0

0
```
## Note

In the first test case, the set $S$ changed as follows:

{$1, 2, 3, 5, 7$} $\to$ {$1, 2, 3, 5, 7, 8$} $\to$ {$1, 2, 3, 5, 8$} $\to$ {$1, 2, 3, 5, 8, 57$} $\to$ {$1, 2, 3, 8, 57$} $\to$ {$0, 1, 2, 3, 8, 57$}. In the end of the game, $\operatorname{MEX}(S) = 4$, $R = 4$.

In the second test case, the set $S$ changed as follows:

{$0, 1, 2$} $\to$ {$0, 1, 2, 3$} $\to$ {$1, 2, 3$} $\to$ {$0, 1, 2, 3$}. In the end of the game, $\operatorname{MEX}(S) = 4$, $R = 4$.

In the third test case, the set $S$ changed as follows:

{$5, 7, 57$} $\to$ {$0, 5, 7, 57$}. In the end of the game, $\operatorname{MEX}(S) = 1$, $R = 1$.



#### tags 

#1300 #constructive_algorithms #data_structures #games #greedy #interactive 