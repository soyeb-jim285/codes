<h1 style='text-align: center;'> J. Segments</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a straight line colored in white. *n* black segments are added on it one by one.

After each segment is added, determine the number of connected components of black segments (i. e. the number of black segments in the union of the black segments). 

In particular, if one segment ends in a point *x*, and another segment starts in the point *x*, these two segments belong to the same connected component.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 200 000) — the number of segments.

The *i*-th of the next *n* lines contains two integers *l**i* and *r**i* (1 ≤ *l**i* < *r**i* ≤ 109) — the coordinates of the left and the right ends of the *i*-th segment. The segments are listed in the order they are added on the white line.

## Output

Print *n* integers — the number of connected components of black segments after each segment is added. 

## Examples

## Input


```
3  
1 3  
4 5  
2 4  

```
## Output


```
1 2 1   

```
## Input


```
9  
10 20  
50 60  
30 40  
70 80  
90 100  
60 70  
10 40  
40 50  
80 90  

```
## Output


```
1 2 3 4 5 4 3 2 1   

```
## Note

In the first example there are two components after the addition of the first two segments, because these segments do not intersect. The third added segment intersects the left segment and touches the right segment at the point 4 (these segments belong to the same component, according to the statements). Thus the number of connected components of black segments is equal to 1 after that.



#### tags 

#2100 #data_structures 