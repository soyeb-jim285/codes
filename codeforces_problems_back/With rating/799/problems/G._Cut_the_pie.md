<h1 style='text-align: center;'> G. Cut the pie</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arkady reached the *n*-th level in Township game, so Masha decided to bake a pie for him! Of course, the pie has a shape of convex *n*-gon, i.e. a polygon with *n* vertices.

Arkady decided to cut the pie in two equal in area parts by cutting it by a straight line, so that he can eat one of them and give the other to Masha. There is a difficulty because Arkady has already put a knife at some point of the pie, so he now has to cut the pie by a straight line passing trough this point.

Help Arkady: find a line that passes through the point Arkady has put a knife into and cuts the pie into two parts of equal area, or determine that it's impossible. Your program has to quickly answer many queries with the same pie, but different points in which Arkady puts a knife.

## Input

The first line contains two integers *n* and *q* (3 ≤ *n* ≤ 104, 1 ≤ *q* ≤ 105) — the number of vertices in the pie and the number of queries.

*n* line follow describing the polygon vertices in clockwise order. The *i*-th of these line contains two integers *x**i* and *y**i* ( - 106 ≤ *x**i*, *y**i* ≤ 106) — the coordinates of the *i*-th vertex. It is guaranteed that the polygon is strictly convex, in particular, no three vertices line on the same line.

An empty line follows.

*q* lines follow describing the query points. The *i*-th of these lines contain two integers *x**i* and *y**i* ( - 106 ≤ *x**i*, *y**i* ≤ 106) — the coordinates of the point in which Arkady puts the knife in the *i*-th query. In is guaranteed that in each query the given point is strictly inside the polygon, in particular, is not on its edges.

## Output

For each query print single integer — the polar angle of the line that is the answer for the corresponding query, in radians. The angle should be in the segment [0;π], the angles are measured from the direction of *OX* axis in counter-clockwise order. For example, the polar angle of the *OY* axis is ![](images/7813100388622a69c767d297b453832a9df166fb.png). If there is no answer in that query, print -1.

If there are several answers, print any of them. Your answer is considered correct if the difference between the areas of the parts divided by the total area of the polygon doesn't exceed 10- 4 by absolute value. In other words, if *a* and *b* are the areas of the parts after the cut, then your answer is correct if and only of ![](images/66732d29ae8aa4996ab1b0496838647802874bed.png).

## Examples

## Input


```
3 1  
0 0  
0 3  
3 0  
  
1 1  

```
## Output


```
2.67794504460098710000  

```
## Input


```
5 3  
6 5  
6 3  
5 0  
0 0  
0 5  
  
5 4  
3 3  
5 2  

```
## Output


```
0.60228734612690049000  
1.27933953226473580000  
2.85805511179015910000  

```


#### tags 

#3500 #binary_search #data_structures #geometry 