<h1 style='text-align: center;'> C. Game with Reversing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game. They have two strings $S$ and $T$ of the same length $n$ consisting of lowercase latin letters. Players take turns alternately, with Alice going first.

On her turn, Alice chooses an integer $i$ from $1$ to $n$, one of the strings $S$ or $T$, and any lowercase latin letter $c$, and replaces the $i$-th symbol in the chosen string with the character $c$.

On his turn, Bob chooses one of the strings $S$ or $T$, and reverses it. More formally, Bob makes the replacement $S := \operatorname{rev}(S)$ or $T := \operatorname{rev}(T)$, where $\operatorname{rev}(P) = P_n P_{n-1} \ldots P_1$.

The game lasts until the strings $S$ and $T$ are equal. As soon as the strings become equal, the game ends instantly.

Define the duration of the game as the total number of moves made by both players during the game. For example, if Alice made $2$ moves in total, and Bob made $1$ move, then the duration of this game is $3$.

Alice's goal is to minimize the duration of the game, and Bob's goal is to maximize the duration of the game.

What will be the duration of the game, if both players play optimally? It can be shown that the game will end in a finite number of turns.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the strings $S$ and $T$.

The second line of each test case contains a string $S$ of length $n$ consisting of lowercase latin letters.

The third line of each test case contains a string $T$ of length $n$ consisting of lowercase latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output a single number on a separate line — the duration of the described game, if both players play optimally.

## Example

## Input


```

75abcdeabxde5helloolleo2abcd7aaaaaaaabbbbba1qq6yoyoyooyoyoy8abcdefghhguedfbh
```
## Output


```

1
2
3
9
0
2
6

```
## Note

In the first test case, in her turn, Alice can replace the third symbol of the string $S$ with x. After that, both strings will become equal to "abxde" and the game will end after one move. Since Alice's goal is to finish the game in as few moves as possible, this move will be one of her optimal first moves, and the final answer will be $1$.

In the second test case, in her turn, Alice can replace the fifth symbol of the string $T$ with h. After this move, $S =$ "hello", $T =$ "olleh". Then Bob makes his turn. In his turn, he must reverse one of the strings. If Bob chooses the string $S$, then after his turn both strings will be equal to "olleh", and if he chooses the string $T$, then after his turn both strings will be equal to "hello". Thus, after the presented first move of Alice, the game will definitely end in $2$ moves. It can be shown that there is no strategy for Alice to finish the game in less than $2$ moves, with both players playing optimally. The final answer is $2$.

In the third test case, in her first move, Alice can replace the second symbol of the string $S$ with c. After this move, $S =$ "ac", $T =$ "cd". Then Bob makes his turn. If Bob reverses the string $S$, then after his turn $S =$ "ca", $T =$ "cd". Then it is easy to see that in this case Alice can definitely finish the game on the $3$-rd move, by replacing the second symbol of the string $T$ with a, after which both strings will become equal to "ca". If Bob reverses the string $T$, then after his turn $S =$ "ac", $T =$ "dc". In this case, Alice can also definitely finish the game on the $3$rd move, by replacing the first symbol of the string $S$ with d, after which both strings will become equal to "dc". Thus, Alice can definitely finish the game in $3$ moves regardless of Bob's moves. It can be shown that the game cannot end in less than $3$ moves, with both players playing optimally.

In the fifth test case, the strings $S$ and $T$ are equal, so the game will end without starting, in $0$ moves.



#### tags 

#1200 #games #greedy #math #strings 