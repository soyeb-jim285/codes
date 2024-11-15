<h1 style='text-align: center;'> A. Cards with Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya has got 2*n* cards, each card contains some integer. The numbers on the cards can be the same. Let's index all cards by consecutive integers from 1 to 2*n*. We'll denote the number that is written on a card with number *i*, as *a**i*. In order to play one entertaining game with his friends, Petya needs to split the cards into pairs so that each pair had equal numbers on the cards. Help Petya do that.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 3·105). The second line contains the sequence of 2*n* positive integers *a*1, *a*2, ..., *a*2*n* (1 ≤ *a**i* ≤ 5000) — the numbers that are written on the cards. The numbers on the line are separated by single spaces.

## Output

If it is impossible to divide the cards into pairs so that cards in each pair had the same numbers, print on a single line integer -1. But if the required partition exists, then print *n* pairs of integers, a pair per line — the indices of the cards that form the pairs.

Separate the numbers on the lines by spaces. You can print the pairs and the numbers in the pairs in any order. If there are multiple solutions, print any of them.

## Examples

## Input


```
3  
20 30 10 30 20 10  

```
## Output


```
4 2  
1 5  
6 3  

```
## Input


```
1  
1 2  

```
## Output


```
-1
```


#### tags 

#1200 #constructive_algorithms #sortings 