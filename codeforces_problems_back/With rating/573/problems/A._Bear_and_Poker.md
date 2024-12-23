<h1 style='text-align: center;'> A. Bear and Poker</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Limak is an old brown bear. He often plays poker with his friends. Today they went to a casino. There are *n* players (including Limak himself) and right now all of them have bids on the table. *i*-th of them has bid with size *a**i* dollars.

Each player can double his bid any number of times and triple his bid any number of times. The casino has a great jackpot for making all bids equal. Is it possible that Limak and his friends will win a jackpot?

## Input

First line of input contains an integer *n* (2 ≤ *n* ≤ 105), the number of players.

The second line contains *n* integer numbers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109) — the bids of players.

## Output

Print "Yes" (without the quotes) if players can make their bids become equal, or "No" otherwise.

## Examples

## Input


```
4  
75 150 75 50  

```
## Output


```
Yes  

```
## Input


```
3  
100 150 250  

```
## Output


```
No  

```
## Note

In the first sample test first and third players should double their bids twice, second player should double his bid once and fourth player should both double and triple his bid.

It can be shown that in the second sample test there is no way to make all bids equal.



#### tags 

#1300 #implementation #math #number_theory 