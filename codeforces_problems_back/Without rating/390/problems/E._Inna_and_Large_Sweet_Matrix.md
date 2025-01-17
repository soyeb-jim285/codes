<h1 style='text-align: center;'> E. Inna and Large Sweet Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Inna loves sweets very much. That's why she wants to play the "Sweet Matrix" game with Dima and Sereja. But Sereja is a large person, so the game proved small for him. Sereja suggested playing the "Large Sweet Matrix" game.

The "Large Sweet Matrix" playing field is an *n* × *m* matrix. Let's number the rows of the matrix from 1 to *n*, and the columns — from 1 to *m*. Let's denote the cell in the *i*-th row and *j*-th column as (*i*, *j*). Each cell of the matrix can contain multiple candies, initially all cells are empty. The game goes in *w* moves, during each move one of the two following events occurs:

1. Sereja chooses five integers *x*1, *y*1, *x*2, *y*2, *v* (*x*1 ≤ *x*2, *y*1 ≤ *y*2) and adds *v* candies to each matrix cell (*i*, *j*) (*x*1 ≤ *i* ≤ *x*2; *y*1 ≤ *j* ≤ *y*2).
2. Sereja chooses four integers *x*1, *y*1, *x*2, *y*2 (*x*1 ≤ *x*2, *y*1 ≤ *y*2). Then he asks Dima to calculate the total number of candies in cells (*i*, *j*) (*x*1 ≤ *i* ≤ *x*2; *y*1 ≤ *j* ≤ *y*2) and he asks Inna to calculate the total number of candies in the cells of matrix (*p*, *q*), which meet the following logical criteria: (*p* < *x*1 OR *p* > *x*2) AND (*q* < *y*1 OR *q* > *y*2). Finally, Sereja asks to write down the difference between the number Dima has calculated and the number Inna has calculated (D - I).

Unfortunately, Sereja's matrix is really huge. That's why Inna and Dima aren't coping with the calculating. Help them!

## Input

The first line of the input contains three integers *n*, *m* and *w* (3 ≤ *n*, *m* ≤ 4·106; 1 ≤ *w* ≤ 105).

The next *w* lines describe the moves that were made in the game. 

* A line that describes an event of the first type contains 6 integers: 0, *x*1, *y*1, *x*2, *y*2 and *v* (1 ≤ *x*1 ≤ *x*2 ≤ *n*; 1 ≤ *y*1 ≤ *y*2 ≤ *m*; 1 ≤ *v* ≤ 109).
* A line that describes an event of the second type contains 5 integers: 1, *x*1, *y*1, *x*2, *y*2 (2 ≤ *x*1 ≤ *x*2 ≤ *n* - 1; 2 ≤ *y*1 ≤ *y*2 ≤ *m* - 1).

It is guaranteed that the second type move occurs at least once. It is guaranteed that a single operation will not add more than 109 candies.

Be careful, the constraints are very large, so please use optimal data structures. Max-tests will be in pretests.

## Output

For each second type move print a single integer on a single line — the difference between Dima and Inna's numbers.

## Examples

## Input


```
4 5 5  
0 1 1 2 3 2  
0 2 2 3 3 3  
0 1 5 4 5 1  
1 2 3 3 4  
1 3 4 3 4  

```
## Output


```
2  
-21  

```
## Note

## Note

 to the sample. After the first query the matrix looks as: 


```
  
22200  
22200   
00000  
00000  

```
After the second one it is: 


```
  
22200  
25500  
03300   
00000  

```
After the third one it is: 


```
  
22201  
25501  
03301  
00001  

```
For the fourth query, Dima's sum equals 5 + 0 + 3 + 0 = 8 and Inna's sum equals 4 + 1 + 0 + 1 = 6. The answer to the query equals 8 - 6 = 2. For the fifth query, Dima's sum equals 0 and Inna's sum equals 18 + 2 + 0 + 1 = 21. The answer to the query is 0 - 21 = -21.



#### tags 

