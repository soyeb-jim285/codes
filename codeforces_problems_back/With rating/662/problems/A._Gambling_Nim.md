<h1 style='text-align: center;'> A. Gambling Nim</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

As you know, the game of "Nim" is played with *n* piles of stones, where the *i*-th pile initially contains *a**i* stones. Two players alternate the turns. During a turn a player picks any non-empty pile and removes any positive number of stones from it. The one who is not able to make a move loses the game.

Petya and Vasya are tired of playing Nim, so they invented their own version of the game and named it the "Gambling Nim". They have *n* two-sided cards, one side of the *i*-th card has number *a**i* written on it, while the other side has number *b**i*. At the beginning of the game the players put all the cards on the table, each card only one of its sides up, and this side is chosen independently and uniformly. Thus they obtain a sequence *c*1, *c*2, ..., *c**n*, where *c**i* is equal to *a**i* or *b**i*. Then they take *n* piles of stones, with *i*-th pile containing exactly *c**i* stones and play Nim. Petya takes the first turn.

Given that both players play optimally, find the probability of Petya's victory. ## Output

 the answer as an irreducible fraction.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 500 000) — the number of cards in the deck.

Each of the following *n* lines contains the description of one card, consisting of two integers *a**i* and *b**i* (0 ≤ *a**i*, *b**i* ≤ 1018).

## Output

## Output

 the answer as an irreducible fraction *p* / *q*. If the probability of Petya's victory is 0, print 0/1.

## Examples

## Input


```
2  
1 1  
1 1  

```
## Output


```
0/1  

```
## Input


```
2  
1 2  
1 2  

```
## Output


```
1/2  

```
## Input


```
3  
0 4  
1 5  
2 3  

```
## Output


```
1/1  

```


#### tags 

#2400 #bitmasks #math #matrices #probabilities 