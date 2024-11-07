<h1 style='text-align: center;'> B. Earn or Unlock</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Andrea is playing the game Tanto Cuore.

 ![](images/9530fd0a2ed9a8c0f1f686637cff167fb8ac008b.png) He has a deck of $n$ cards with values $a_1, \ldots, a_n$ from top to bottom. Each card can be either locked or unlocked. Initially, only the topmost card is unlocked. 

The game proceeds in turns. In each turn, Andrea chooses an unlocked card in the deck — the value written on the card is $v$ — and performs exactly one of the following two operations: 

1. Unlock the first $v$ locked cards in the deck from the top. If there are less than $v$ locked cards in the deck, then unlock all the locked cards.
2. Earn $v$ victory points.

 In both cases, after performing the operation, he removes the card from the deck.The game ends when all the cards remaining in the deck are locked, or there are no more cards in the deck.

What is the maximum number of victory points Andrea can earn?

##### Input

The first line contains a single integer $n$ ($1 \leq n \leq 10^5$) — the number of cards in the deck.

The second line contains $n$ integers $a_1, \ldots, a_n$ ($0 \leq a_1, \ldots, a_n \leq n$) — the values of the cards in the deck.

##### Output

##### Output

 a single integer — the maximum number of victory points Andrea can earn.

## Examples

##### Input


```text
2
1 2
```
##### Output


```text
2
```
##### Input


```text
5
2 4 5 0 1
```
##### Output


```text
9
```
##### Input


```text
4
0 4 4 4
```
##### Output


```text
0
```
## Note

In the first sample test, the deck starts as [unlocked, locked]. Then, Andrea uses the first card to unlock the second card. Then he uses the second card to earn $2$ victory points.

In the second sample test, Andrea can use the first card to unlock the second and the third card. Then he uses the second and the third card to earn $4+5=9$ victory points.

In the third sample test, Andrea can't unlock any cards or gain any victory points with the first card.



#### Tags 

#2200 #NOT OK #bitmasks #brute_force #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_889_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
