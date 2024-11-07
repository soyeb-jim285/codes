<h1 style='text-align: center;'> D. Boxes And Balls</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ivan has *n* different boxes. The first of them contains some balls of *n* different colors.

Ivan wants to play a strange game. He wants to distribute the balls into boxes in such a way that for every *i* (1 ≤ *i* ≤ *n*) *i*-th box will contain all balls with color *i*.

In order to do this, Ivan will make some turns. Each turn he does the following:

1. Ivan chooses any non-empty box and takes all balls from this box;
2. Then Ivan chooses any *k* empty boxes (the box from the first step becomes empty, and Ivan is allowed to choose it), separates the balls he took on the previous step into *k* non-empty groups and puts each group into one of the boxes. He should put each group into a separate box. He can choose either *k* = 2 or *k* = 3.

The penalty of the turn is the number of balls Ivan takes from the box during the first step of the turn. And penalty of the game is the total penalty of turns made by Ivan until he distributes all balls to corresponding boxes.

Help Ivan to determine the minimum possible penalty of the game!

## Input

The first line contains one integer number *n* (1 ≤ *n* ≤ 200000) — the number of boxes and colors.

The second line contains *n* integer numbers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109), where *a**i* is the number of balls with color *i*.

## Output

Print one number — the minimum possible penalty of the game.

## Examples

## Input


```
3  
1 2 3  

```
## Output


```
6  

```
## Input


```
4  
2 3 4 5  

```
## Output


```
19  

```
## Note

In the first example you take all the balls from the first box, choose *k* = 3 and sort all colors to corresponding boxes. Penalty is 6.

In the second example you make two turns: 

1. Take all the balls from the first box, choose *k* = 3, put balls of color 3 to the third box, of color 4 — to the fourth box and the rest put back into the first box. Penalty is 14;
2. Take all the balls from the first box, choose *k* = 2, put balls of color 1 to the first box, of color 2 — to the second box. Penalty is 5.

Total penalty is 19.



#### tags 

#2300 #data_structures #greedy 