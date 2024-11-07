<h1 style='text-align: center;'> A. Two Squares</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two squares, one with sides parallel to the coordinate axes, and another one with sides at 45 degrees to the coordinate axes. Find whether the two squares intersect.

The interior of the square is considered to be part of the square, i.e. if one square is completely inside another, they intersect. If the two squares only share one common point, they are also considered to intersect.

## Input

The input data consists of two lines, one for each square, both containing 4 pairs of integers. Each pair represents coordinates of one vertex of the square. Coordinates within each line are either in clockwise or counterclockwise order.

The first line contains the coordinates of the square with sides parallel to the coordinate axes, the second line contains the coordinates of the square at 45 degrees.

All the values are integer and between $-100$ and $100$.

## Output

Print "Yes" if squares intersect, otherwise print "No".

You can print each letter in any case (upper or lower).

## Examples

## Input


```
0 0 6 0 6 6 0 6  
1 3 3 5 5 3 3 1  

```
## Output


```
YES  

```
## Input


```
0 0 6 0 6 6 0 6  
7 3 9 5 11 3 9 1  

```
## Output


```
NO  

```
## Input


```
6 0 6 6 0 6 0 0  
7 4 4 7 7 10 10 7  

```
## Output


```
YES  

```
## Note

In the first example the second square lies entirely within the first square, so they do intersect.

In the second sample squares do not have any points in common.

Here are images corresponding to the samples:

 ![](images/7cee584e1c522d31a1a3be13929a736a2c5a3792.png)  ![](images/53ffe663b0a4477e72b956c2030e803f031f9fd2.png)  ![](images/65f51282cf774e5200930d3189786453a90708fb.png) 

#### tags 

#1600 #geometry #implementation 