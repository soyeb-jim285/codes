<h1 style='text-align: center;'> B. Let's Play Osu!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're playing a game called Osu! Here's a simplified version of it. There are *n* clicks in a game. For each click there are two outcomes: correct or bad. Let us denote correct as "O", bad as "X", then the whole play can be encoded as a sequence of *n* characters "O" and "X".

Using the play sequence you can calculate the score for the play as follows: for every maximal consecutive "O"s block, add the square of its length (the number of characters "O") to the score. For example, if your play can be encoded as "OOXOOOXXOO", then there's three maximal consecutive "O"s block "OO", "OOO", "OO", so your score will be 22 + 32 + 22 = 17. If there are no correct clicks in a play then the score for the play equals to 0.

You know that the probability to click the *i*-th (1 ≤ *i* ≤ *n*) click correctly is *p**i*. In other words, the *i*-th character in the play sequence has *p**i* probability to be "O", 1 - *p**i* to be "X". You task is to calculate the expected score for your play.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 105) — the number of clicks. The second line contains *n* space-separated real numbers *p*1, *p*2, ..., *p**n* (0 ≤ *p**i* ≤ 1).

There will be at most six digits after the decimal point in the given *p**i*.

## Output

Print a single real number — the expected score for your play. Your answer will be considered correct if its absolute or relative error does not exceed 10- 6.

## Examples

## Input


```
3  
0.5 0.5 0.5  

```
## Output


```
2.750000000000000  

```
## Input


```
4  
0.7 0.2 0.1 0.9  

```
## Output


```
2.489200000000000  

```
## Input


```
5  
1 1 1 1 1  

```
## Output


```
25.000000000000000  

```
## Note

For the first example. There are 8 possible outcomes. Each has a probability of 0.125.

* "OOO"  →  32 = 9;
* "OOX"  →  22 = 4;
* "OXO"  →  12 + 12 = 2;
* "OXX"  →  12 = 1;
* "XOO"  →  22 = 4;
* "XOX"  →  12 = 1;
* "XXO"  →  12 = 1;
* "XXX"  →  0.

So the expected score is ![](images/9aa477286058d4dd02d6f78cad11a658e4f37440.png)



#### tags 

#2000 #dp #math #probabilities 