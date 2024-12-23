<h1 style='text-align: center;'> D. Board Game</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing a board card game. In this game the player has two characteristics, *x* and *y* — the white magic skill and the black magic skill, respectively. There are *n* spell cards lying on the table, each of them has four characteristics, *a**i*, *b**i*, *c**i* and *d**i*. In one move a player can pick one of the cards and cast the spell written on it, but only if first two of it's characteristics meet the requirement *a**i* ≤ *x* and *b**i* ≤ *y*, i.e. if the player has enough magic skill to cast this spell. However, after casting the spell the characteristics of a player change and become equal to *x* = *c**i* and *y* = *d**i*.

At the beginning of the game both characteristics of a player are equal to zero. The goal of the game is to cast the *n*-th spell. Your task is to make it in as few moves as possible. You are allowed to use spell in any order and any number of times (for example, you may not use some spells at all).

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 100 000) — the number of cards on the table.

Each of the next *n* lines contains four integers *a**i*, *b**i*, *c**i*, *d**i* (0 ≤ *a**i*, *b**i*, *c**i*, *d**i* ≤ 109) — the characteristics of the corresponding card.

## Output

In the first line print a single integer *k* — the minimum number of moves needed to cast the *n*-th spell and in the second line print *k* numbers — the indices of the cards in the order in which you should cast them. In case there are multiple possible solutions, print any of them.

If it is impossible to cast the *n*-th spell, print  - 1.

## Examples

## Input


```
4  
0 0 3 4  
2 2 5 3  
4 1 1 7  
5 3 8 8  

```
## Output


```
3  
1 2 4  

```
## Input


```
2  
0 0 4 6  
5 1 1000000000 1000000000  

```
## Output


```
-1  

```


#### tags 

#2500 #data_structures #dfs_and_similar 