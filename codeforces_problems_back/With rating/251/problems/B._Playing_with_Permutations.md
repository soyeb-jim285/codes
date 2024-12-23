<h1 style='text-align: center;'> B. Playing with Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Petya likes permutations a lot. Recently his mom has presented him permutation *q*1, *q*2, ..., *q**n* of length *n*.

A permutation *a* of length *n* is a sequence of integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ *n*), all integers there are distinct. 

There is only one thing Petya likes more than permutations: playing with little Masha. As it turns out, Masha also has a permutation of length *n*. Petya decided to get the same permutation, whatever the cost may be. For that, he devised a game with the following rules:

* Before the beginning of the game Petya writes permutation 1, 2, ..., *n* on the blackboard. After that Petya makes exactly *k* moves, which are described below.
* During a move Petya tosses a coin. If the coin shows heads, he performs point 1, if the coin shows tails, he performs point 2.
	1. Let's assume that the board contains permutation *p*1, *p*2, ..., *p**n* at the given moment. Then Petya removes the written permutation *p* from the board and writes another one instead: *p**q*1, *p**q*2, ..., *p**q**n*. In other words, Petya applies permutation *q* (which he has got from his mother) to permutation *p*.
	2. All actions are similar to point 1, except that Petya writes permutation *t* on the board, such that: *t**q**i* = *p**i* for all *i* from 1 to *n*. In other words, Petya applies a permutation that is inverse to *q* to permutation *p*.

We know that after the *k*-th move the board contained Masha's permutation *s*1, *s*2, ..., *s**n*. Besides, we know that throughout the game process Masha's permutation never occurred on the board before the *k*-th move. ## Note

 that the game has exactly *k* moves, that is, throughout the game the coin was tossed exactly *k* times.

Your task is to determine whether the described situation is possible or else state that Petya was mistaken somewhere. See samples and notes to them for a better understanding.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n*, *k* ≤ 100). The second line contains *n* space-separated integers *q*1, *q*2, ..., *q**n* (1 ≤ *q**i* ≤ *n*) — the permutation that Petya's got as a present. The third line contains Masha's permutation *s*, in the similar format.

It is guaranteed that the given sequences *q* and *s* are correct permutations.

## Output

If the situation that is described in the statement is possible, print "YES" (without the quotes), otherwise print "NO" (without the quotes).

## Examples

## Input


```
4 1  
2 3 4 1  
1 2 3 4  

```
## Output


```
NO  

```
## Input


```
4 1  
4 3 1 2  
3 4 2 1  

```
## Output


```
YES  

```
## Input


```
4 3  
4 3 1 2  
3 4 2 1  

```
## Output


```
YES  

```
## Input


```
4 2  
4 3 1 2  
2 1 4 3  

```
## Output


```
YES  

```
## Input


```
4 1  
4 3 1 2  
2 1 4 3  

```
## Output


```
NO  

```
## Note

In the first sample Masha's permutation coincides with the permutation that was written on the board before the beginning of the game. Consequently, that violates the condition that Masha's permutation never occurred on the board before *k* moves were performed.

In the second sample the described situation is possible, in case if after we toss a coin, we get tails.

In the third sample the possible coin tossing sequence is: heads-tails-tails.

In the fourth sample the possible coin tossing sequence is: heads-heads.



#### tags 

#1800 #implementation #math 