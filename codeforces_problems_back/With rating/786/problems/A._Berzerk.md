<h1 style='text-align: center;'> A. Berzerk</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rick and Morty are playing their own version of Berzerk (which has nothing in common with the famous Berzerk game). This game needs a huge space, so they play it with a computer.

In this game there are *n* objects numbered from 1 to *n* arranged in a circle (in clockwise order). Object number 1 is a black hole and the others are planets. There's a monster in one of the planet. Rick and Morty don't know on which one yet, only that he's not initially in the black hole, but Unity will inform them before the game starts. But for now, they want to be prepared for every possible scenario.

 ![](images/5223c66459688e507de83718a3822a5087713359.png) Each one of them has a set of numbers between 1 and *n* - 1 (inclusive). Rick's set is *s*1 with *k*1 elements and Morty's is *s*2 with *k*2 elements. One of them goes first and the player changes alternatively. In each player's turn, he should choose an arbitrary number like *x* from his set and the monster will move to his *x*-th next object from its current position (clockwise). If after his move the monster gets to the black hole he wins.

Your task is that for each of monster's initial positions and who plays first determine if the starter wins, loses, or the game will stuck in an infinite loop. In case when player can lose or make game infinity, it more profitable to choose infinity game.

## Input

The first line of input contains a single integer *n* (2 ≤ *n* ≤ 7000) — number of objects in game.

The second line contains integer *k*1 followed by *k*1 distinct integers *s*1, 1, *s*1, 2, ..., *s*1, *k*1 — Rick's set.

The third line contains integer *k*2 followed by *k*2 distinct integers *s*2, 1, *s*2, 2, ..., *s*2, *k*2 — Morty's set

1 ≤ *k**i* ≤ *n* - 1 and 1 ≤ *s**i*, 1, *s**i*, 2, ..., *s**i*, *k**i* ≤ *n* - 1 for 1 ≤ *i* ≤ 2.

## Output

In the first line print *n* - 1 words separated by spaces where *i*-th word is "Win" (without quotations) if in the scenario that Rick plays first and monster is initially in object number *i* + 1 he wins, "Lose" if he loses and "Loop" if the game will never end.

Similarly, in the second line print *n* - 1 words separated by spaces where *i*-th word is "Win" (without quotations) if in the scenario that Morty plays first and monster is initially in object number *i* + 1 he wins, "Lose" if he loses and "Loop" if the game will never end.

## Examples

## Input


```
5  
2 3 2  
3 1 2 3  

```
## Output


```
Lose Win Win Loop  
Loop Win Win Win  

```
## Input


```
8  
4 6 2 3 4  
2 3 6  

```
## Output


```
Win Win Win Win Win Win Win  
Lose Win Lose Lose Win Lose Lose  

```


#### tags 

#2000 #dfs_and_similar #dp #games 