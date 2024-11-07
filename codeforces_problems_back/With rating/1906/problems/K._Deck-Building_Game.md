<h1 style='text-align: center;'> K. Deck-Building Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are playing a deck-building game with your friend. There are $N$ cards, numbered from $1$ to $N$. Card $i$ has the value of $A_i$.

You want to build two decks; one for you and one for your friend. A card cannot be inside both decks, and it is allowed to not use all $N$ cards. It is also allowed for a deck to be empty, i.e. does not contain any cards.

The power of a deck is represented as the bitwise XOR of the value of the cards in the deck. The power of an empty deck is $0$.

The game is balanced if both decks have the same power.

Determine the number of ways to build two decks such that the game is balanced. Two ways are considered different if one of the decks contains at least one different card. Since the answer can be very large, calculate the answer modulo $998\,244\,353$.

## Input

The first line consists of an integer $N$ ($2 \le N \le 100\,000$).

The following line consists of $N$ integers $A_i$ ($1 \le A_i \le 100\,000$).

## Output

## Output

 an integer representing the number of ways to build two decks such that the game is balanced. ## Output

 the answer modulo $998\,244\,353$.

## Examples

## Input


```

4
16 12 4 8

```
## Output


```

9

```
## Input


```

4
1 2 4 8

```
## Output


```

1

```
## Input


```

2
1 1

```
## Output


```

5

```
## Input


```

6
1 1 1 2 2 2

```
## Output


```

169

```
## Note

Explanation for the sample input/output #1

Denote $S$ and $T$ as the set of cards in your deck and your friend's deck, respectively. There are $9$ ways to build the decks such that the game is balanced.

* $S = \{\}$ and $T = \{\}$. Both decks have the power of $0$.
* $S = \{2, 3, 4\}$ and $T = \{\}$. Both decks have the power of $0$.
* $S = \{\}$ and $T = \{2, 3, 4\}$. Both decks have the power of $0$.
* $S = \{2, 4\}$ and $T = \{3\}$. Both decks have the power of $4$.
* $S = \{3\}$ and $T = \{2, 4\}$. Both decks have the power of $4$.
* $S = \{2, 3\}$ and $T = \{4\}$. Both decks have the power of $8$.
* $S = \{4\}$ and $T = \{2, 3\}$. Both decks have the power of $8$.
* $S = \{3, 4\}$ and $T = \{2\}$. Both decks have the power of $12$.
* $S = \{2\}$ and $T = \{3, 4\}$. Both decks have the power of $12$.

Explanation for the sample input/output #2

The only way to make the game balanced is to have both decks empty.

Explanation for the sample input/output #3

There are $5$ ways to build the decks such that the game is balanced.

* $S = \{\}$ and $T = \{\}$. Both decks have the power of $0$.
* $S = \{1, 2\}$ and $T = \{\}$. Both decks have the power of $0$.
* $S = \{\}$ and $T = \{1, 2\}$. Both decks have the power of $0$.
* $S = \{1\}$ and $T = \{2\}$. Both decks have the power of $1$.
* $S = \{2\}$ and $T = \{1\}$. Both decks have the power of $1$.


#### tags 

#2500 #divide_and_conquer #math 