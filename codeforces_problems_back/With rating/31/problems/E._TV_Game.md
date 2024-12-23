<h1 style='text-align: center;'> E. TV Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a new TV game on BerTV. In this game two players get a number *A* consisting of 2*n* digits. Before each turn players determine who will make the next move. Each player should make exactly *n* moves. On it's turn *i*-th player takes the leftmost digit of *A* and appends it to his or her number *S**i*. After that this leftmost digit is erased from *A*. Initially the numbers of both players (*S*1 and *S*2) are «empty». Leading zeroes in numbers *A*, *S*1, *S*2 are allowed. In the end of the game the first player gets *S*1 dollars, and the second gets *S*2 dollars.

One day Homer and Marge came to play the game. They managed to know the number *A* beforehand. They want to find such sequence of their moves that both of them makes exactly *n* moves and which maximizes their total prize. Help them.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 18). The second line contains integer *A* consisting of exactly 2*n* digits. This number can have leading zeroes.

## Output

## Output

 the line of 2*n* characters «H» and «M» — the sequence of moves of Homer and Marge, which gives them maximum possible total prize. Each player must make exactly *n* moves. If there are several solutions, output any of them.

## Examples

## Input


```
2  
1234  

```
## Output


```
HHMM
```
## Input


```
2  
9911  

```
## Output


```
HMHM
```


#### tags 

#2400 #dp 