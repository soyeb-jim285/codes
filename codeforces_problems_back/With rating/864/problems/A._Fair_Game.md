<h1 style='text-align: center;'> A. Fair Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya and Vasya decided to play a game. They have *n* cards (*n* is an even number). A single integer is written on each card.

Before the game Petya will choose an integer and after that Vasya will choose another integer (different from the number that Petya chose). During the game each player takes all the cards with number he chose. For example, if Petya chose number 5 before the game he will take all cards on which 5 is written and if Vasya chose number 10 before the game he will take all cards on which 10 is written.

The game is considered fair if Petya and Vasya can take all *n* cards, and the number of cards each player gets is the same.

Determine whether Petya and Vasya can choose integer numbers before the game so that the game is fair. 

## Input

The first line contains a single integer *n* (2 ≤ *n* ≤ 100) — number of cards. It is guaranteed that *n* is an even number.

The following *n* lines contain a sequence of integers *a*1, *a*2, ..., *a**n* (one integer per line, 1 ≤ *a**i* ≤ 100) — numbers written on the *n* cards.

## Output

If it is impossible for Petya and Vasya to choose numbers in such a way that the game will be fair, print "NO" (without quotes) in the first line. In this case you should not print anything more.

In the other case print "YES" (without quotes) in the first line. In the second line print two distinct integers — number that Petya should choose and the number that Vasya should choose to make the game fair. If there are several solutions, print any of them.

## Examples

## Input


```
4  
11  
27  
27  
11  

```
## Output


```
YES  
11 27  

```
## Input


```
2  
6  
6  

```
## Output


```
NO  

```
## Input


```
6  
10  
20  
30  
20  
10  
20  

```
## Output


```
NO  

```
## Input


```
6  
1  
1  
2  
2  
3  
3  

```
## Output


```
NO  

```
## Note

In the first example the game will be fair if, for example, Petya chooses number 11, and Vasya chooses number 27. Then the will take all cards — Petya will take cards 1 and 4, and Vasya will take cards 2 and 3. Thus, each of them will take exactly two cards.

In the second example fair game is impossible because the numbers written on the cards are equal, but the numbers that Petya and Vasya should choose should be distinct.

In the third example it is impossible to take all cards. Petya and Vasya can take at most five cards — for example, Petya can choose number 10 and Vasya can choose number 20. But for the game to be fair it is necessary to take 6 cards.



#### tags 

#1000 #implementation #sortings 