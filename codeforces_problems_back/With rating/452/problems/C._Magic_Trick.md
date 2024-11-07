<h1 style='text-align: center;'> C. Magic Trick</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alex enjoys performing magic tricks. He has a trick that requires a deck of *n* cards. He has *m* identical decks of *n* different cards each, which have been mixed together. When Alex wishes to perform the trick, he grabs *n* cards at random and performs the trick with those. The resulting deck looks like a normal deck, but may have duplicates of some cards.

The trick itself is performed as follows: first Alex allows you to choose a random card from the deck. You memorize the card and put it back in the deck. Then Alex shuffles the deck, and pulls out a card. If the card matches the one you memorized, the trick is successful.

You don't think Alex is a very good magician, and that he just pulls a card randomly from the deck. Determine the probability of the trick being successful if this is the case.

## Input

First line of the input consists of two integers *n* and *m* (1 ≤ *n*, *m* ≤ 1000), separated by space — number of cards in each deck, and number of decks.

## Output

On the only line of the output print one floating point number – probability of Alex successfully performing the trick. Relative or absolute error of your answer should not be higher than 10- 6.

## Examples

## Input


```
2 2  

```
## Output


```
0.6666666666666666  

```
## Input


```
4 4  

```
## Output


```
0.4000000000000000  

```
## Input


```
1 2  

```
## Output


```
1.0000000000000000  

```
## Note

In the first sample, with probability ![](images/64c94d13eeb330b494061e86538db66574ad0f7d.png) Alex will perform the trick with two cards with the same value from two different decks. In this case the trick is guaranteed to succeed.

With the remaining ![](images/14b21b617fcd2e25700376368355f7bbf975d8de.png) probability he took two different cards, and the probability of pulling off the trick is ![](images/eb946338365d9781f7d2e9ec692c26702d0ae3a7.png).

The resulting probability is ![](images/f54a03c9fa9df64ba08161730756d50b780a5f43.png)



#### tags 

#2100 #combinatorics #math #probabilities 