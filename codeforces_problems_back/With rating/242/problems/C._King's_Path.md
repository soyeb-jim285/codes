<h1 style='text-align: center;'> C. King's Path</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The black king is standing on a chess field consisting of 109 rows and 109 columns. We will consider the rows of the field numbered with integers from 1 to 109 from top to bottom. The columns are similarly numbered with integers from 1 to 109 from left to right. We will denote a cell of the field that is located in the *i*-th row and *j*-th column as (*i*, *j*).

You know that some squares of the given chess field are allowed. All allowed cells of the chess field are given as *n* segments. Each segment is described by three integers *r**i*, *a**i*, *b**i* (*a**i* ≤ *b**i*), denoting that cells in columns from number *a**i* to number *b**i* inclusive in the *r**i*-th row are allowed.

Your task is to find the minimum number of moves the king needs to get from square (*x*0, *y*0) to square (*x*1, *y*1), provided that he only moves along the allowed cells. In other words, the king can be located only on allowed cells on his way.

Let us remind you that a chess king can move to any of the neighboring cells in one move. Two cells of a chess field are considered neighboring if they share at least one point.

## Input

The first line contains four space-separated integers *x*0, *y*0, *x*1, *y*1 (1 ≤ *x*0, *y*0, *x*1, *y*1 ≤ 109), denoting the initial and the final positions of the king.

The second line contains a single integer *n* (1 ≤ *n* ≤ 105), denoting the number of segments of allowed cells. Next *n* lines contain the descriptions of these segments. The *i*-th line contains three space-separated integers *r**i*, *a**i*, *b**i* (1 ≤ *r**i*, *a**i*, *b**i* ≤ 109, *a**i* ≤ *b**i*), denoting that cells in columns from number *a**i* to number *b**i* inclusive in the *r**i*-th row are allowed. Note that the segments of the allowed cells can intersect and embed arbitrarily.

It is guaranteed that the king's initial and final position are allowed cells. It is guaranteed that the king's initial and the final positions do not coincide. It is guaranteed that the total length of all given segments doesn't exceed 105.

## Output

If there is no path between the initial and final position along allowed cells, print -1.

Otherwise print a single integer — the minimum number of moves the king needs to get from the initial position to the final one.

## Examples

## Input


```
5 7 6 11  
3  
5 3 8  
6 7 11  
5 2 5  

```
## Output


```
4  

```
## Input


```
3 4 3 10  
3  
3 1 4  
4 5 9  
3 10 10  

```
## Output


```
6  

```
## Input


```
1 1 2 10  
2  
1 1 3  
2 6 10  

```
## Output


```
-1  

```


#### tags 

#1800 #dfs_and_similar #graphs #hashing #shortest_paths 