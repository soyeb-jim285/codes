<h1 style='text-align: center;'> A. The Artful Expedient</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rock... Paper!

After Karen have found the deterministic winning (losing?) strategy for rock-paper-scissors, her brother, Koyomi, comes up with a new game as a substitute. The game works as follows.

A positive integer *n* is decided first. Both Koyomi and Karen independently choose *n* distinct positive integers, denoted by *x*1, *x*2, ..., *x**n* and *y*1, *y*2, ..., *y**n* respectively. They reveal their sequences, and repeat until all of 2*n* integers become distinct, which is the only final state to be kept and considered.

Then they count the number of ordered pairs (*i*, *j*) (1 ≤ *i*, *j* ≤ *n*) such that the value *x**i* xor *y**j* equals to one of the 2*n* integers. Here xor means the [bitwise exclusive or](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) operation on two integers, and is denoted by operators ^ and/or xor in most programming languages.

Karen claims a win if the number of such pairs is even, and Koyomi does otherwise. And you're here to help determine the winner of their latest game.

## Input

The first line of input contains a positive integer *n* (1 ≤ *n* ≤ 2 000) — the length of both sequences.

The second line contains *n* space-separated integers *x*1, *x*2, ..., *x**n* (1 ≤ *x**i* ≤ 2·106) — the integers finally chosen by Koyomi.

The third line contains *n* space-separated integers *y*1, *y*2, ..., *y**n* (1 ≤ *y**i* ≤ 2·106) — the integers finally chosen by Karen.

## Input

 guarantees that the given 2*n* integers are pairwise distinct, that is, no pair (*i*, *j*) (1 ≤ *i*, *j* ≤ *n*) exists such that one of the following holds: *x**i* = *y**j*; *i* ≠ *j* and *x**i* = *x**j*; *i* ≠ *j* and *y**i* = *y**j*.

## Output

## Output

 one line — the name of the winner, that is, "Koyomi" or "Karen" (without quotes). Please be aware of the capitalization.

## Examples

## Input


```
3  
1 2 3  
4 5 6  

```
## Output


```
Karen  

```
## Input


```
5  
2 4 6 8 10  
9 7 5 3 1  

```
## Output


```
Karen  

```
## Note

In the first example, there are 6 pairs satisfying the constraint: (1, 1), (1, 2), (2, 1), (2, 3), (3, 2) and (3, 3). Thus, Karen wins since 6 is an even number.

In the second example, there are 16 such pairs, and Karen wins again.



#### tags 

#1100 #brute_force #implementation 