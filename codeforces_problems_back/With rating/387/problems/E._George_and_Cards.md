<h1 style='text-align: center;'> E. George and Cards</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

George is a cat, so he loves playing very much.

Vitaly put *n* cards in a row in front of George. Each card has one integer written on it. All cards had distinct numbers written on them. Let's number the cards from the left to the right with integers from 1 to *n*. Then the *i*-th card from the left contains number *p**i* (1 ≤ *p**i* ≤ *n*). 

Vitaly wants the row to have exactly *k* cards left. He also wants the *i*-th card from left to have number *b**i* written on it. Vitaly gave a task to George, to get the required sequence of cards using the remove operation *n* - *k* times.

In one remove operation George can choose *w* (1 ≤ *w*; *w* is not greater than the current number of cards in the row) contiguous cards (contiguous subsegment of cards). Let's denote the numbers written on these card as *x*1, *x*2, ..., *x**w* (from the left to the right). After that, George can remove the card *x**i*, such that *x**i* ≤ *x**j* for each *j* (1 ≤ *j* ≤ *w*). After the described operation George gets *w* pieces of sausage.

George wondered: what maximum number of pieces of sausage will he get in total if he reaches his goal and acts optimally well? Help George, find an answer to his question!

## Input

The first line contains integers *n* and *k* (1 ≤ *k* ≤ *n* ≤ 106) — the initial and the final number of cards.

The second line contains *n* distinct space-separated integers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*) — the initial row of cards. 

The third line contains *k* space-separated integers *b*1, *b*2, ..., *b**k* — the row of cards that you need to get. It is guaranteed that it's possible to obtain the given row by using the remove operation for *n* - *k* times.

## Output

Print a single integer — the maximum number of pieces of sausage that George can get if he acts optimally well.

## Examples

## Input


```
3 2  
2 1 3  
1 3  

```
## Output


```
1  

```
## Input


```
10 5  
1 2 3 4 5 6 7 8 9 10  
2 4 6 8 10  

```
## Output


```
30  

```


#### tags 

#2200 #binary_search #data_structures 