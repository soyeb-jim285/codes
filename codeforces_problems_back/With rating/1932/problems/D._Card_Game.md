<h1 style='text-align: center;'> D. Card Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Two players are playing an online card game. The game is played using a 32-card deck. Each card has a suit and a rank. There are four suits: clubs, diamonds, hearts, and spades. We will encode them with characters 'C', 'D', 'H', and 'S', respectively. And there are 8 ranks, in increasing order: '2', '3', '4', '5', '6', '7', '8', '9'.

Each card is denoted by two letters: its rank and its suit. For example, the 8 of Hearts is denoted as 8H.

At the beginning of the game, one suit is chosen as the trump suit.

In each round, players make moves like this: the first player places one of his cards on the table, and the second player must beat this card with one of their cards. After that, both cards are moved to the discard pile.

A card can beat another card if both cards have the same suit and the first card has a higher rank than the second. For example, 8S can beat 4S. Additionally, a trump card can beat any non-trump card, regardless of the rank of the cards, for example, if the trump suit is clubs ('C'), then 3C can beat 9D. Note that trump cards can be beaten only by the trump cards of higher rank.

There were $n$ rounds played in the game, so the discard pile now contains $2n$ cards. You want to reconstruct the rounds played in the game, but the cards in the discard pile are shuffled. Find any possible sequence of $n$ rounds that might have been played in the game.

## Input

The first line contains integer $t$ ($1 \le t \le 100$) — the number of test cases. Then $t$ test cases follow.

The first line of a test case contains the integer number $n$ ($1\le n\le 16$).

The second line of a test case contains one character, the trump suit. It is one of "CDHS".

The third line of a test case contains the description of $2n$ cards. Each card is described by a two-character string, the first character is the rank of the card, which is one of "23456789", and the second one is the suit of the card, which is one of "CDHS". All cards are different.

## Output

For each test case print the answer to it:

* Print $n$ lines. In each line, print the description of two cards, in the same format as in the input: the first card that was played by the first player, and then the card that was used by the second player to beat it.
* If there is no solution, print a single line "IMPOSSIBLE".

If there are multiple solutions, print any of them.

## Example

## Input


```

83S3C 9S 4C 6D 3S 7S2C3S 5D 9S 6H1H6C 5D1S7S 3S1H9S 9H1S9S 9H1C9D 8H2C9C 9S 6H 8C
```
## Output


```

3C 4C
6D 9S
3S 7S
IMPOSSIBLE
IMPOSSIBLE
3S 7S
9S 9H
9H 9S
IMPOSSIBLE
6H 9C
9S 8C

```


#### tags 

#1400 #greedy #implementation 