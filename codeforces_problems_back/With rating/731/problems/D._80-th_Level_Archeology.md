<h1 style='text-align: center;'> D. 80-th Level Archeology</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Archeologists have found a secret pass in the dungeon of one of the pyramids of Cycleland. To enter the treasury they have to open an unusual lock on the door. The lock consists of *n* words, each consisting of some hieroglyphs. The wall near the lock has a round switch. Each rotation of this switch changes the hieroglyphs according to some rules. The instruction nearby says that the door will open only if words written on the lock would be sorted in lexicographical order (the definition of lexicographical comparison in given in notes section).

The rule that changes hieroglyphs is the following. One clockwise rotation of the round switch replaces each hieroglyph with the next hieroglyph in alphabet, i.e. hieroglyph *x* (1 ≤ *x* ≤ *c* - 1) is replaced with hieroglyph (*x* + 1), and hieroglyph *c* is replaced with hieroglyph 1.

Help archeologist determine, how many clockwise rotations they should perform in order to open the door, or determine that this is impossible, i.e. no cyclic shift of the alphabet will make the sequence of words sorted lexicographically.

## Input

The first line of the input contains two integers *n* and *c* (2 ≤ *n* ≤ 500 000, 1 ≤ *c* ≤ 106) — the number of words, written on the lock, and the number of different hieroglyphs.

Each of the following *n* lines contains the description of one word. The *i*-th of these lines starts with integer *l**i* (1 ≤ *l**i* ≤ 500 000), that denotes the length of the *i*-th word, followed by *l**i* integers *w**i*, 1, *w**i*, 2, ..., *w**i*, *l**i* (1 ≤ *w**i*, *j* ≤ *c*) — the indices of hieroglyphs that make up the *i*-th word. Hieroglyph with index 1 is the smallest in the alphabet and with index *c* — the biggest.

It's guaranteed, that the total length of all words doesn't exceed 106.

## Output

If it is possible to open the door by rotating the round switch, print integer *x* (0 ≤ *x* ≤ *c* - 1) that defines the required number of clockwise rotations. If there are several valid *x*, print any of them.

If it is impossible to open the door by this method, print  - 1.

## Examples

## Input


```
4 3  
2 3 2  
1 1  
3 2 3 1  
4 2 3 1 2  

```
## Output


```
1  

```
## Input


```
2 5  
2 4 2  
2 4 2  

```
## Output


```
0  

```
## Input


```
4 4  
1 2  
1 3  
1 4  
1 2  

```
## Output


```
-1  

```
## Note

Word *a*1, *a*2, ..., *a**m* of length *m* is lexicographically not greater than word *b*1, *b*2, ..., *b**k* of length *k*, if one of two conditions hold: 

* at first position *i*, such that *a**i* ≠ *b**i*, the character *a**i* goes earlier in the alphabet than character *b**i*, i.e. *a* has smaller character in the first position where they differ;
* if there is no such position *i* and *m* ≤ *k*, i.e. the first word is a prefix of the second or two words are equal.

The sequence of words is said to be sorted in lexicographical order if each word (except the last one) is lexicographically not greater than the next word.

In the first sample, after the round switch is rotated 1 position clockwise the words look as follows:


```
  
1 3  
2  
3 1 2  
3 1 2 3  

```
In the second sample, words are already sorted in lexicographical order.

In the last sample, one can check that no shift of the alphabet will work.



#### tags 

#2200 #brute_force #data_structures #greedy #sortings 