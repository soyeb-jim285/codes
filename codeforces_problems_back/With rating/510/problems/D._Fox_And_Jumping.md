<h1 style='text-align: center;'> D. Fox And Jumping</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fox Ciel is playing a game. In this game there is an infinite long tape with cells indexed by integers (positive, negative and zero). At the beginning she is standing at the cell 0.

There are also *n* cards, each card has 2 attributes: length *l**i* and cost *c**i*. If she pays *c**i* dollars then she can apply *i*-th card. After applying *i*-th card she becomes able to make jumps of length *l**i*, i. e. from cell *x* to cell (*x* - *l**i*) or cell (*x* + *l**i*).

She wants to be able to jump to any cell on the tape (possibly, visiting some intermediate cells). For achieving this goal, she wants to buy some cards, paying as little money as possible. 

If this is possible, calculate the minimal cost.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 300), number of cards.

The second line contains *n* numbers *l**i* (1 ≤ *l**i* ≤ 109), the jump lengths of cards.

The third line contains *n* numbers *c**i* (1 ≤ *c**i* ≤ 105), the costs of cards.

## Output

If it is impossible to buy some cards and become able to jump to any cell, output -1. Otherwise output the minimal cost of buying such set of cards.

## Examples

## Input


```
3  
100 99 9900  
1 1 1  

```
## Output


```
2  

```
## Input


```
5  
10 20 30 40 50  
1 1 1 1 1  

```
## Output


```
-1  

```
## Input


```
7  
15015 10010 6006 4290 2730 2310 1  
1 1 1 1 1 1 10  

```
## Output


```
6  

```
## Input


```
8  
4264 4921 6321 6984 2316 8432 6120 1026  
4264 4921 6321 6984 2316 8432 6120 1026  

```
## Output


```
7237  

```
## Note

In first sample test, buying one card is not enough: for example, if you buy a card with length 100, you can't jump to any cell whose index is not a multiple of 100. The best way is to buy first and second card, that will make you be able to jump to any cell.

In the second sample test, even if you buy all cards, you can't jump to any cell whose index is not a multiple of 10, so you should output -1.



#### tags 

#1900 #bitmasks #brute_force #dp #math 