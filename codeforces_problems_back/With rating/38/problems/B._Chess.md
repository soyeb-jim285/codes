<h1 style='text-align: center;'> B. Chess</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Two chess pieces, a rook and a knight, stand on a standard chessboard 8 × 8 in size. The positions in which they are situated are known. It is guaranteed that none of them beats the other one.

Your task is to find the number of ways to place another knight on the board so that none of the three pieces on the board beat another one. A new piece can only be placed on an empty square.

## Input

The first input line contains the description of the rook's position on the board. This description is a line which is 2 in length. Its first symbol is a lower-case Latin letter from a to h, and its second symbol is a number from 1 to 8. The second line contains the description of the knight's position in a similar way. It is guaranteed that their positions do not coincide.

## Output

Print a single number which is the required number of ways.

## Examples

## Input


```
a1  
b2  

```
## Output


```
44  

```
## Input


```
a8  
d4  

```
## Output


```
38  

```


#### tags 

#1200 #brute_force #implementation #math 