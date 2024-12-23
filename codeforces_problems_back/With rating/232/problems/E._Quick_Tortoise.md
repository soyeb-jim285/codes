<h1 style='text-align: center;'> E. Quick Tortoise</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

John Doe has a field, which is a rectangular table of size *n* × *m*. We assume that the field rows are numbered from 1 to *n* from top to bottom, and the field columns are numbered from 1 to *m* from left to right. Then the cell of the field at the intersection of the *x*-th row and the *y*-th column has coordinates (*x*; *y*).

We know that some cells of John's field are painted white, and some are painted black. Also, John has a tortoise, which can move along the white cells of the field. The tortoise can get from a white cell with coordinates (*x*; *y*) into cell (*x* + 1; *y*) or (*x*; *y* + 1), if the corresponding cell is painted white. In other words, the turtle can move only along the white cells of the field to the right or down. The turtle can not go out of the bounds of the field.

In addition, John has *q* queries, each of them is characterized by four numbers *x*1, *y*1, *x*2, *y*2 (*x*1 ≤ *x*2, *y*1 ≤ *y*2). For each query John wants to know whether the tortoise can start from the point with coordinates (*x*1; *y*1), and reach the point with coordinates (*x*2; *y*2), moving only along the white squares of the field.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 500) — the field sizes.

Each of the next *n* lines contains *m* characters "#" and ".": the *j*-th character of the *i*-th line equals "#", if the cell (*i*; *j*) is painted black and ".", if it is painted white.

The next line contains integer *q* (1 ≤ *q* ≤ 6·105) — the number of queries. Next *q* lines contain four space-separated integers *x*1, *y*1, *x*2 and *y*2 (1 ≤ *x*1 ≤ *x*2 ≤ *n*, 1 ≤ *y*1 ≤ *y*2 ≤ *m*) — the coordinates of the starting and the finishing cells. It is guaranteed that cells (*x*1; *y*1) and (*x*2; *y*2) are white.

## Output

For each of *q* queries print on a single line "Yes", if there is a way from cell (*x*1; *y*1) to cell (*x*2; *y*2), that meets the requirements, and "No" otherwise. Print the answers to the queries in the order, in which the queries are given in the input.

## Examples

## Input


```
3 3  
...  
.##  
.#.  
5  
1 1 3 3  
1 1 1 3  
1 1 3 1  
1 1 1 2  
1 1 2 1  

```
## Output


```
No  
Yes  
Yes  
Yes  
Yes  

```
## Input


```
5 5  
.....  
.###.  
.....  
.###.  
.....  
5  
1 1 5 5  
1 1 1 5  
1 1 3 4  
2 1 2 5  
1 1 2 5  

```
## Output


```
Yes  
Yes  
Yes  
No  
Yes  

```


#### tags 

#3000 #bitmasks #divide_and_conquer #dp 