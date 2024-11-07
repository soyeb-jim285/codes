<h1 style='text-align: center;'> G. Game of Questions</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Genie is taking part in an intellectual game. The game consists of $n$ questions, and there are $m$ participants numbered from $1$ to $m$. Genie is the participant number $1$.

For each question $i$ and participant $j$, it is known whether the participant will answer the question correctly or not.

The goal of the game is to be the last participant staying in the game.

The game is conducted as follows. First, all $n$ questions get shuffled uniformly at random (all $n!$ permutations are equally likely). Then, the questions are asked one by one. Each participant answers the question. If all participants still in the game answer the question correctly, or if all of them answer the question incorrectly, nothing happens. Otherwise, those participants who answer the question incorrectly lose and leave the game.

After all $n$ questions are asked, all participants who are still in the game are declared to be the winners.

What is the probability that Genie will win the game?

## Input

The first line contains two integers $n$ and $m$ — the number of questions and the number of participants ($1 \le n \le 2 \cdot 10^5$; $2 \le m \le 17$).

The $i$-th of the next $n$ lines contains $m$ characters $s_{i, 1}, s_{i, 2}, \ldots, s_{i, m}$. Character $s_{i, j}$ is '1' if participant $j$ answers question $i$ correctly or '0' otherwise.

## Output

Print the probability that Genie will win the game. Your answer will be considered correct if its absolute or relative error does not exceed $10^{-9}$.

## Examples

## Input


```

1 5
11010

```
## Output


```

1.0000000000000000

```
## Input


```

3 3
011
101
110

```
## Output


```

0.3333333333333333

```
## Input


```

6 4
1011
0110
1111
0110
0000
1101

```
## Output


```

0.1666666666666667

```
## Note

In the first example, there is a single question and Genie will answer it correctly, thus winning the game (along with participants $2$ and $4$).

In the second example, one participant will leave after the first asked question, and another participant will leave after the second asked question. Each participant will win with probability $\frac{1}{3}$.



#### tags 

#2800 #bitmasks #combinatorics #dp #fft #math #probabilities 