<h1 style='text-align: center;'> D. Ksusha and Square</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ksusha is a vigorous mathematician. She is keen on absolutely incredible mathematical riddles. 

Today Ksusha came across a convex polygon of non-zero area. She is now wondering: if she chooses a pair of distinct points uniformly among all integer points (points with integer coordinates) inside or on the border of the polygon and then draws a square with two opposite vertices lying in the chosen points, what will the expectation of this square's area be?

A pair of distinct points is chosen uniformly among all pairs of distinct points, located inside or on the border of the polygon. Pairs of points *p*, *q* (*p* ≠ *q*) and *q*, *p* are considered the same.

Help Ksusha! Count the required expectation.

## Input

The first line contains integer *n* (3 ≤ *n* ≤ 105) — the number of vertices of Ksusha's convex polygon. Next *n* lines contain the coordinates of the polygon vertices in clockwise or counterclockwise order. The *i*-th line contains integers *x**i*, *y**i* (|*x**i*|, |*y**i*| ≤ 106) — the coordinates of the vertex that goes *i*-th in that order.

## Output

Print a single real number — the required expected area. 

The answer will be considered correct if its absolute and relative error doesn't exceed 10- 6.

## Examples

## Input


```
3  
0 0  
5 5  
5 0  

```
## Output


```
4.6666666667  

```
## Input


```
4  
-1 3  
4 5  
6 2  
3 -5  

```
## Output


```
8.1583333333  

```
## Input


```
3  
17 136  
859 937  
16 641  

```
## Output


```
66811.3704155169  

```


#### tags 

#2700 #geometry #math #probabilities #two_pointers 