<h1 style='text-align: center;'> D. Minesweeper 1D</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Game "Minesweeper 1D" is played on a line of squares, the line's height is 1 square, the line's width is *n* squares. Some of the squares contain bombs. If a square doesn't contain a bomb, then it contains a number from 0 to 2 — the total number of bombs in adjacent squares.

For example, the correct field to play looks like that: 001*2***101*. The cells that are marked with "*" contain bombs. ## Note

 that on the correct field the numbers represent the number of bombs in adjacent cells. For example, field 2* is not correct, because cell with value 2 must have two adjacent cells with bombs.

Valera wants to make a correct field to play "Minesweeper 1D". He has already painted a squared field with width of *n* cells, put several bombs on the field and wrote numbers into some cells. Now he wonders how many ways to fill the remaining cells with bombs and numbers are there if we should get a correct field in the end.

## Input

The first line contains sequence of characters without spaces *s*1*s*2... *s**n* (1 ≤ *n* ≤ 106), containing only characters "*", "?" and digits "0", "1" or "2". If character *s**i* equals "*", then the *i*-th cell of the field contains a bomb. If character *s**i* equals "?", then Valera hasn't yet decided what to put in the *i*-th cell. Character *s**i*, that is equal to a digit, represents the digit written in the *i*-th square.

## Output

Print a single integer — the number of ways Valera can fill the empty cells and get a correct field.

As the answer can be rather large, print it modulo 1000000007 (109 + 7).

## Examples

## Input


```
?01???  

```
## Output


```
4  

```
## Input


```
?  

```
## Output


```
2  

```
## Input


```
**12  

```
## Output


```
0  

```
## Input


```
1  

```
## Output


```
0  

```
## Note

In the first test sample you can get the following correct fields: 001**1, 001***, 001*2*, 001*10.



#### tags 

#1900 #dp #implementation 