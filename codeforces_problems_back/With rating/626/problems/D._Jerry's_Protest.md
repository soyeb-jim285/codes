<h1 style='text-align: center;'> D. Jerry's Protest</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Andrew and Jerry are playing a game with Harry as the scorekeeper. The game consists of three rounds. In each round, Andrew and Jerry draw randomly without replacement from a jar containing *n* balls, each labeled with a distinct positive integer. Without looking, they hand their balls to Harry, who awards the point to the player with the larger number and returns the balls to the jar. The winner of the game is the one who wins at least two of the three rounds.

Andrew wins rounds 1 and 2 while Jerry wins round 3, so Andrew wins the game. However, Jerry is unhappy with this system, claiming that he will often lose the match despite having the higher overall total. What is the probability that the sum of the three balls Jerry drew is strictly higher than the sum of the three balls Andrew drew?

## Input

The first line of input contains a single integer *n* (2 ≤ *n* ≤ 2000) — the number of balls in the jar.

The second line contains *n* integers *a**i* (1 ≤ *a**i* ≤ 5000) — the number written on the *i*th ball. It is guaranteed that no two balls have the same number.

## Output

Print a single real value — the probability that Jerry has a higher total, given that Andrew wins the first two rounds and Jerry wins the third. Your answer will be considered correct if its absolute or relative error does not exceed 10- 6. 

Namely: let's assume that your answer is *a*, and the answer of the jury is *b*. The checker program will consider your answer correct, if ![](images/c97ba2000ebfad962bff7ffd8d043594f5ae1086.png).

## Examples

## Input


```
2  
1 2  

```
## Output


```
0.0000000000  

```
## Input


```
3  
1 2 10  

```
## Output


```
0.0740740741  

```
## Note

In the first case, there are only two balls. In the first two rounds, Andrew must have drawn the 2 and Jerry must have drawn the 1, and vice versa in the final round. Thus, Andrew's sum is 5 and Jerry's sum is 4, so Jerry never has a higher total.

In the second case, each game could've had three outcomes — 10 - 2, 10 - 1, or 2 - 1. Jerry has a higher total if and only if Andrew won 2 - 1 in both of the first two rounds, and Jerry drew the 10 in the last round. This has probability ![](images/3c0ec296285f607c66d594132fb91e5e5f2bb007.png).



#### tags 

#1800 #brute_force #combinatorics #dp #probabilities 