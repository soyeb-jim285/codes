<h1 style='text-align: center;'> D. Appleman and Complicated Task</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Toastman came up with a very complicated task. He gives it to Appleman, but Appleman doesn't know how to solve it. Can you help him?

Given a *n* × *n* checkerboard. Each cell of the board has either character 'x', or character 'o', or nothing. How many ways to fill all the empty cells with 'x' or 'o' (each cell must contain only one character in the end) are there, such that for each cell the number of adjacent cells with 'o' will be even? Find the number of ways modulo 1000000007 (109 + 7). Two cells of the board are adjacent if they share a side.

## Input

The first line contains two integers *n*, *k* (1 ≤ *n*, *k* ≤ 105) — the size of the board, and the number of cells that has characters initially. 

Then *k* lines follows. The *i*-th line contains two integers and a character: *a**i*, *b**i*, *c**i* (1 ≤ *a**i*, *b**i* ≤ *n*; *c**i* is either 'o' or 'x'). This line means: there is a character *c**i* in the cell that is located on the intersection of the *a**i*-th row and *b**i*-th column. All the given cells are distinct.

Consider that the rows are numbered from 1 to *n* from top to bottom. Analogically, the columns are numbered from 1 to *n* from left to right.

## Output

Print a single integer — the answer to the problem.

## Examples

## Input


```
3 2  
1 1 x  
2 2 o  

```
## Output


```
2  

```
## Input


```
4 3  
2 4 x  
3 4 x  
3 2 x  

```
## Output


```
2  

```
## Note

In the first example there are two ways:


```
  
    xxo          xoo  
    xox          ooo  
    oxx          oox  

```


#### tags 

#2800 #dsu #math 