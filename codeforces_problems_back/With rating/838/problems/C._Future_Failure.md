<h1 style='text-align: center;'> C. Future Failure</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game with a string of characters, with Alice going first. The string consists *n* characters, each of which is one of the first *k* letters of the alphabet. On a player’s turn, they can either arbitrarily permute the characters in the words, or delete exactly one character in the word (if there is at least one character). In addition, their resulting word cannot have appeared before throughout the entire game. The player unable to make a valid move loses the game.

Given *n*, *k*, *p*, find the number of words with exactly *n* characters consisting of the first *k* letters of the alphabet such that Alice will win if both Alice and Bob play optimally. Return this number modulo the prime number *p*.

## Input

The first line of input will contain three integers *n*, *k*, *p* (1 ≤ *n* ≤ 250 000, 1 ≤ *k* ≤ 26, 108 ≤ *p* ≤ 109 + 100, *p* will be prime).

## Output

Print a single integer, the number of winning words for Alice, modulo *p*.

## Example

## Input


```
4 2 100000007  

```
## Output


```
14  

```
## Note

There are 14 strings that that Alice can win with. For example, some strings are "bbaa" and "baaa". Alice will lose on strings like "aaaa" or "bbbb".



#### tags 

#2800 #dp #games 