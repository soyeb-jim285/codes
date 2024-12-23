<h1 style='text-align: center;'> A. 24 Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little X used to play a card game called "24 Game", but recently he has found it too easy. So he invented a new game.

Initially you have a sequence of *n* integers: 1, 2, ..., *n*. In a single step, you can pick two of them, let's denote them *a* and *b*, erase them from the sequence, and append to the sequence either *a* + *b*, or *a* - *b*, or *a* × *b*.

After *n* - 1 steps there is only one number left. Can you make this number equal to 24?

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 105).

## Output

If it's possible, print "YES" in the first line. Otherwise, print "NO" (without the quotes).

If there is a way to obtain 24 as the result number, in the following *n* - 1 lines print the required operations an operation per line. Each operation should be in form: "*a* *op* *b* = *c*". Where *a* and *b* are the numbers you've picked at this operation; *op* is either "+", or "-", or "*"; *c* is the result of corresponding operation. Note, that the absolute value of *c* mustn't be greater than 1018. The result of the last operation must be equal to 24. Separate operator sign and equality sign from numbers with spaces.

If there are multiple valid answers, you may print any of them.

## Examples

## Input


```
1  

```
## Output


```
NO  

```
## Input


```
8  

```
## Output


```
YES  
8 * 7 = 56  
6 * 5 = 30  
3 - 4 = -1  
1 - 2 = -1  
30 - -1 = 31  
56 - 31 = 25  
25 + -1 = 24  

```


#### tags 

#1500 #constructive_algorithms #greedy #math 