<h1 style='text-align: center;'> E. Wojtek and Card Tricks</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Wojtek has just won a maths competition in Byteland! The prize is admirable — a great book called 'Card Tricks for Everyone.' 'Great!' he thought, 'I can finally use this old, dusted deck of cards that's always been lying unused on my desk!'

The first chapter of the book is 'How to Shuffle $k$ Cards in Any Order You Want.' It's basically a list of $n$ intricate methods of shuffling the deck of $k$ cards in a deterministic way. Specifically, the $i$-th recipe can be described as a permutation $(P_{i,1}, P_{i,2}, \dots, P_{i,k})$ of integers from $1$ to $k$. If we enumerate the cards in the deck from $1$ to $k$ from top to bottom, then $P_{i,j}$ indicates the number of the $j$-th card from the top of the deck after the shuffle.

The day is short and Wojtek wants to learn only some of the tricks today. He will pick two integers $l, r$ ($1 \le l \le r \le n$), and he will memorize each trick from the $l$-th to the $r$-th, inclusive. He will then take a sorted deck of $k$ cards and repeatedly apply random memorized tricks until he gets bored. He still likes maths, so he started wondering: how many different decks can he have after he stops shuffling it?

Wojtek still didn't choose the integers $l$ and $r$, but he is still curious. Therefore, he defined $f(l, r)$ as the number of different decks he can get if he memorizes all the tricks between the $l$-th and the $r$-th, inclusive. What is the value of

$$\sum_{l=1}^n \sum_{r=l}^n f(l, r)?$$

## Input

The first line contains two integers $n$, $k$ ($1 \le n \le 200\,000$, $1 \le k \le 5$) — the number of tricks and the number of cards in Wojtek's deck.

Each of the following $n$ lines describes a single trick and is described by $k$ distinct integers $P_{i,1}, P_{i,2}, \dots, P_{i, k}$ ($1 \le P_{i, j} \le k$).

## Output

## Output

 the value of the sum described in the statement.

## Examples

## Input


```

3 3
2 1 3
3 1 2
1 3 2

```
## Output


```

25

```
## Input


```

2 4
4 1 3 2
4 3 1 2

```
## Output


```

31

```
## Note

Consider the first sample:

* The first trick swaps two top cards.
* The second trick takes a card from the bottom and puts it on the top of the deck.
* The third trick swaps two bottom cards.

The first or the third trick allow Wojtek to generate only two distinct decks (either the two cards are swapped or not). Therefore, $f(1, 1) = f(3, 3) = 2$.

The second trick allows him to shuffle the deck in a cyclic order. Therefore, $f(2,2)=3$.

It turns that two first tricks or two last tricks are enough to shuffle the deck in any way desired by Wojtek. Therefore, $f(1,2) = f(2,3) = f(1,3) = 3! = 6$.



#### tags 

#2700 #math 