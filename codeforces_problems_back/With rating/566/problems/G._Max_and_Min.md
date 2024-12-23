<h1 style='text-align: center;'> G. Max and Min</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Two kittens, Max and Min, play with a pair of non-negative integers *x* and *y*. As you can guess from their names, kitten Max loves to maximize and kitten Min loves to minimize. As part of this game Min wants to make sure that both numbers, *x* and *y* became negative at the same time, and kitten Max tries to prevent him from doing so.

Each kitten has a set of pairs of integers available to it. Kitten Max has *n* pairs of non-negative integers (*a**i*, *b**i*) (1 ≤ *i* ≤ *n*), and kitten Min has *m* pairs of non-negative integers (*c**j*, *d**j*) (1 ≤ *j* ≤ *m*). As kitten Max makes a move, it can take any available pair (*a**i*, *b**i*) and add *a**i* to *x* and *b**i* to *y*, and kitten Min can take any available pair (*c**j*, *d**j*) and subtract *c**j* from *x* and *d**j* from *y*. Each kitten can use each pair multiple times during distinct moves.

Max moves first. Kitten Min is winning if at some moment both numbers *a*, *b* are negative simultaneously. Otherwise, the winner of the game is kitten Max. Determine which kitten wins if both of them play optimally.

## Input

The first line contains two integers, *n* and *m* (1 ≤ *n*, *m* ≤ 100 000) — the number of pairs of numbers available to Max and Min, correspondingly.

The second line contains two integers *x*, *y* (1 ≤ *x*, *y* ≤ 109) — the initial values of numbers with which the kittens are playing.

Next *n* lines contain the pairs of numbers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ 109) — the pairs available to Max.

The last *m* lines contain pairs of numbers *c**j*, *d**j* (1 ≤ *c**j*, *d**j* ≤ 109) — the pairs available to Min.

## Output

Print «Max» (without the quotes), if kitten Max wins, or "Min" (without the quotes), if kitten Min wins.

## Examples

## Input


```
2 2  
42 43  
2 3  
3 2  
3 10  
10 3  

```
## Output


```
Min  

```
## Input


```
1 1  
1 1  
3 4  
1 1  

```
## Output


```
Max  

```
## Note

In the first test from the statement Min can respond to move (2, 3) by move (3, 10), and to move (3, 2) by move (10, 3). Thus, for each pair of Max and Min's moves the values of both numbers *x* and *y* will strictly decrease, ergo, Min will win sooner or later.

In the second sample test after each pair of Max and Min's moves both numbers *x* and *y* only increase, thus none of them will become negative.



#### tags 

#2500 #geometry 