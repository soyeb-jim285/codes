<h1 style='text-align: center;'> E. Yet Another Task with Queens</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A queen is the strongest chess piece. In modern chess the queen can move any number of squares in any horizontal, vertical or diagonal direction (considering that there're no other pieces on its way). The queen combines the options given to the rook and the bishop.

There are *m* queens on a square *n* × *n* chessboard. You know each queen's positions, the *i*-th queen is positioned in the square (*r**i*, *c**i*), where *r**i* is the board row number (numbered from the top to the bottom from 1 to *n*), and *c**i* is the board's column number (numbered from the left to the right from 1 to *n*). No two queens share the same position.

For each queen one can count *w* — the number of other queens that the given queen threatens (attacks). For a fixed attack direction only the first queen in this direction is under attack if there are many queens are on the ray of the attack. Obviously, for any queen *w* is between 0 and 8, inclusive.

Print the sequence *t*0, *t*1, ..., *t*8, where *t**i* is the number of queens that threaten exactly *i* other queens, i.e. the number of queens that their *w* equals *i*.

## Input

The first line of the input contains a pair of integers *n*, *m* (1 ≤ *n*, *m* ≤ 105), where *n* is the size of the board and *m* is the number of queens on the board. Then *m* following lines contain positions of the queens, one per line. Each line contains a pair of integers *r**i*, *c**i* (1 ≤ *r**i*, *c**i* ≤ *n*) — the queen's position. No two queens stand on the same square.

## Output

Print the required sequence *t*0, *t*1, ..., *t*8, separating the numbers with spaces.

## Examples

## Input


```
8 4  
4 3  
4 8  
6 5  
1 6  

```
## Output


```
0 3 0 1 0 0 0 0 0 
```
## Input


```
10 3  
1 1  
1 2  
1 3  

```
## Output


```
0 2 1 0 0 0 0 0 0 
```


#### tags 

#1700 #sortings 