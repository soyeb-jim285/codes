<h1 style='text-align: center;'> A. Cards</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* cards (*n* is even) in the deck. Each card has a positive integer written on it. *n* / 2 people will play new card game. At the beginning of the game each player gets two cards, each card is given to exactly one player. 

Find the way to distribute cards such that the sum of values written of the cards will be equal for each player. It is guaranteed that it is always possible.

## Input

The first line of the input contains integer *n* (2 ≤ *n* ≤ 100) — the number of cards in the deck. It is guaranteed that *n* is even.

The second line contains the sequence of *n* positive integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 100), where *a**i* is equal to the number written on the *i*-th card.

## Output

Print *n* / 2 pairs of integers, the *i*-th pair denote the cards that should be given to the *i*-th player. Each card should be given to exactly one player. Cards are numbered in the order they appear in the input.

It is guaranteed that solution exists. If there are several correct answers, you are allowed to print any of them.

## Examples

## Input


```
6  
1 5 7 4 4 3  

```
## Output


```
1 3  
6 2  
4 5  

```
## Input


```
4  
10 10 10 10  

```
## Output


```
1 2  
3 4  

```
## Note

In the first sample, cards are distributed in such a way that each player has the sum of numbers written on his cards equal to 8. 

In the second sample, all values *a**i* are equal. Thus, any distribution is acceptable.



#### tags 

#800 #greedy #implementation 