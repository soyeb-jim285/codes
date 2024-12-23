<h1 style='text-align: center;'> E. Roland and Rose</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Roland loves growing flowers. He has recently grown a beautiful rose at point (0, 0) of the Cartesian coordinate system. The rose is so beautiful that Roland is afraid that the evil forces can try and steal it. 

To protect the rose, Roland wants to build *n* watch towers. Let's assume that a tower is a point on the plane at the distance of at most *r* from the rose. Besides, Roland assumes that the towers should be built at points with integer coordinates and the sum of squares of distances between all pairs of towers must be as large as possible. Note, that Roland may build several towers at the same point, also he may build some of them at point (0, 0).

Help Roland build the towers at the integer points so that the sum of squares of distances between all towers is maximum possible. Note that the distance in this problem is defined as the Euclidian distance between points.

## Input

The first line contains two integers, *n* and *r* (2 ≤ *n* ≤ 8; 1 ≤ *r* ≤ 30).

## Output

In the first line print an integer — the maximum possible sum of squared distances. In the *i*-th of the following *n* lines print two integers, *x**i*, *y**i* — the coordinates of the *i*-th tower. Each tower must be inside or on the border of the circle with radius *r*. Note that there may be several towers located at the same point of the plane, also some towers can be located at point (0, 0).

If there are multiple valid optimal arrangements, choose any of them.

## Examples

## Input


```
4 1  

```
## Output


```
16  
0 1  
0 1  
0 -1  
0 -1  

```
## Input


```
3 6  

```
## Output


```
312  
0 6  
5 -3  
-5 -3  

```


#### tags 

#2700 #brute_force #geometry #math #sortings 