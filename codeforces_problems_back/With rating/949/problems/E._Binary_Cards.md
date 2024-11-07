<h1 style='text-align: center;'> E. Binary Cards</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

It is never too late to play the fancy "Binary Cards" game!

There is an infinite amount of cards of positive and negative ranks that are used in the game. The absolute value of any card rank is a power of two, i.e. each card has a rank of either 2*k* or  - 2*k* for some integer *k* ≥ 0. There is an infinite amount of cards of any valid rank.

At the beginning of the game player forms his deck that is some multiset (possibly empty) of cards. It is allowed to pick any number of cards of any rank but the small deck is considered to be a skill indicator. Game consists of *n* rounds. In the *i*-th round jury tells the player an integer *a**i*. After that the player is obligated to draw such a subset of his deck that the sum of ranks of the chosen cards is equal to *a**i* (it is allowed to not draw any cards, in which case the sum is considered to be equal to zero). If player fails to do so, he loses and the game is over. Otherwise, player takes back all of his cards into his deck and the game proceeds to the next round. Player is considered a winner if he is able to draw the suitable set of cards in each of the rounds.

Somebody told you which numbers *a**i* the jury is going to tell you in each round. Now you want to pick a deck consisting of the minimum number of cards that allows you to win the "Binary Cards" game.

## Input

The first line of input contains an integer *n* (1 ≤ *n* ≤ 100 000), the number of rounds in the game.

The second line of input contains *n* integers *a*1, *a*2, ..., *a**n* ( - 100 000 ≤ *a**i* ≤ 100 000), the numbers that jury is going to tell in each round.

## Output

In the first line print the integer *k* (0 ≤ *k* ≤ 100 000), the minimum number of cards you have to pick in your deck in ordered to win the "Binary Cards".

In the second line print *k* integers *b*1, *b*2, ..., *b**k* ( - 220 ≤ *b**i* ≤ 220, |*b**i*| is a power of two), the ranks of the cards in your deck. You may output ranks in any order. If there are several optimum decks, you are allowed to print any of them.

It is guaranteed that there exists a deck of minimum size satisfying all the requirements above.

## Examples

## Input


```
1  
9  

```
## Output


```
2  
1 8  

```
## Input


```
5  
-1 3 0 4 7  

```
## Output


```
3  
4 -1 4  

```
## Input


```
4  
2 -2 14 18  

```
## Output


```
3  
-2 2 16
```
## Note

In the first sample there is the only round in the game, in which you may simply draw both your cards. ## Note

 that this sample test is the only one satisfying the first test group constraints.

In the second sample you may draw the only card  - 1 in the first round, cards 4 and  - 1 in the second round, nothing in the third round, the only card 4 in the fourth round and the whole deck in the fifth round.



#### tags 

#2700 #brute_force 