<h1 style='text-align: center;'> D. 2048</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The programmers from the R2 company love playing 2048. One day, they decided to invent their own simplified version of this game — 2*k* on a stripe.

Imagine an infinite in one direction stripe, consisting of unit squares (the side of each square is equal to the height of the stripe). Each square can either be empty or contain some number.

Initially, all squares are empty. Then at infinity one of the unit squares number 2 or 4 appears. Then the player presses a button once, and the appeared number begins to move towards the beginning of the stripe. Let's assume that some number *x* moves to the beginning of the stripe, then it will stop if:

1. it either gets in the first square of the stripe;
2. or it is in the square that is preceded by a square with number *y* (*y* ≠ *x*). But if number *x* at some point of time gets to the square with the same number then both numbers add to each other and result in 2*x*. The new number 2*x* continues moving to the beginning of the stripe by the same rules.

After the final stop of the number moving process, the infinity gets a new number 2 or 4 and the process repeats. Read the notes to the test samples to better understand the moving strategy.

I guess you've understood that the game progress fully depends on the order in which numbers 2 and 4 appear. Let's look at some sequence of numbers 2 and 4 in the game. We assume that the sequence is winning if it results in at least one square getting the number greater or equal than 2*k*. 

The goal of the game is to make up a winning sequence of *n* numbers. But not everything is so simple, some numbers in the sequence are identified beforehand. You are given a sequence consisting of numbers 0, 2, 4. Count how many ways there are to replace each 0 of the sequence with 2 or 4 to get a winning sequence.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 2000; 3 ≤ *k* ≤ 11). The next line contains sequence of *n* integers, each of them is either 0, or 2, or 4.

## Output

Print a single integer — the number of ways to replace zeroes by numbers 2 or 4 to get a winning sequence. As this number can be rather large, print it modulo 1000000007 (109 + 7).

## Examples

## Input


```
7 4  
2 2 4 2 2 2 2  

```
## Output


```
1  

```
## Input


```
1 3  
0  

```
## Output


```
0  

```
## Input


```
2 3  
0 4  

```
## Output


```
1  

```
## Input


```
5 4  
2 0 0 4 4  

```
## Output


```
2  

```
## Note

Consider the first example. The beginning of the strip will look as follows: 

2  →  4  →  8  →  8 2  →  8 4  →  8 4 2  →  16.

To better understand the game, you can see the original game on http://gabrielecirulli.github.io/2048/. Please note that the game that is described on the strip is slightly different from the original game (when the two numbers add up in the original game, they do not keep moving). Be careful, the game is addictive, there isn't much time for the contest!



#### tags 

#2000 #bitmasks #dp 