<h1 style='text-align: center;'> C. Arithmetic Progression</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Everybody knows what an arithmetic progression is. Let us remind you just in case that an arithmetic progression is such sequence of numbers *a*1, *a*2, ..., *a**n* of length *n*, that the following condition fulfills: 

*a*2 - *a*1 = *a*3 - *a*2 = *a*4 - *a*3 = ... = *a**i* + 1 - *a**i* = ... = *a**n* - *a**n* - 1.For example, sequences [1, 5], [10], [5, 4, 3] are arithmetic progressions and sequences [1, 3, 2], [1, 2, 4] are not.

Alexander has *n* cards containing integers. Arthur wants to give Alexander exactly one more card with a number so that he could use the resulting *n* + 1 cards to make an arithmetic progression (Alexander has to use all of his cards).

Arthur has already bought a card but he hasn't written a number on it. Help him, print all integers that you can write on a card so that the described condition fulfilled.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of cards. The next line contains the sequence of integers — the numbers on Alexander's cards. The numbers are positive integers, each of them doesn't exceed 108.

## Output

If Arthur can write infinitely many distinct integers on the card, print on a single line -1.

Otherwise, print on the first line the number of integers that suit you. In the second line, print the numbers in the increasing order. Note that the numbers in the answer can exceed 108 or even be negative (see test samples).

## Examples

## Input


```
3  
4 1 7  

```
## Output


```
2  
-2 10  

```
## Input


```
1  
10  

```
## Output


```
-1  

```
## Input


```
4  
1 3 5 9  

```
## Output


```
1  
7  

```
## Input


```
4  
4 3 4 5  

```
## Output


```
0  

```
## Input


```
2  
2 4  

```
## Output


```
3  
0 3 6  

```


#### tags 

#1700 #implementation #sortings 