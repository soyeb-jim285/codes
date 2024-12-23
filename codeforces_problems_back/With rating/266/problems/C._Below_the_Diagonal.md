<h1 style='text-align: center;'> C. Below the Diagonal</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a square matrix consisting of *n* rows and *n* columns. We assume that the rows are numbered from 1 to *n* from top to bottom and the columns are numbered from 1 to *n* from left to right. Some cells (*n* - 1 cells in total) of the the matrix are filled with ones, the remaining cells are filled with zeros. We can apply the following operations to the matrix:

1. Swap *i*-th and *j*-th rows of the matrix;
2. Swap *i*-th and *j*-th columns of the matrix.

You are asked to transform the matrix into a special form using these operations. In that special form all the ones must be in the cells that lie below the main diagonal. Cell of the matrix, which is located on the intersection of the *i*-th row and of the *j*-th column, lies below the main diagonal if *i* > *j*.

## Input

The first line contains an integer *n* (2 ≤ *n* ≤ 1000) — the number of rows and columns. Then follow *n* - 1 lines that contain one's positions, one per line. Each position is described by two integers *x**k*, *y**k* (1 ≤ *x**k*, *y**k* ≤ *n*), separated by a space. A pair (*x**k*, *y**k*) means that the cell, which is located on the intersection of the *x**k*-th row and of the *y**k*-th column, contains one.

It is guaranteed that all positions are distinct.

## Output

Print the description of your actions. These actions should transform the matrix to the described special form.

In the first line you should print a non-negative integer *m* (*m* ≤ 105) — the number of actions. In each of the next *m* lines print three space-separated integers *t*, *i*, *j* (1 ≤ *t* ≤ 2, 1 ≤ *i*, *j* ≤ *n*, *i* ≠ *j*), where *t* = 1 if you want to swap rows, *t* = 2 if you want to swap columns, and *i* and *j* denote the numbers of rows or columns respectively.

Please note, that you do not need to minimize the number of operations, but their number should not exceed 105. If there are several solutions, you may print any of them.

## Examples

## Input


```
2  
1 2  

```
## Output


```
2  
2 1 2  
1 1 2  

```
## Input


```
3  
3 1  
1 3  

```
## Output


```
3  
2 2 3  
1 1 3  
1 1 2  

```
## Input


```
3  
2 1  
3 2  

```
## Output


```
0  

```


#### tags 

#2100 #constructive_algorithms #greedy #math 