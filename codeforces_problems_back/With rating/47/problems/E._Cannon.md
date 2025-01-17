<h1 style='text-align: center;'> E. Cannon</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bertown is under siege! The attackers have blocked all the ways out and their cannon is bombarding the city. Fortunately, Berland intelligence managed to intercept the enemies' shooting plan. Let's introduce the Cartesian system of coordinates, the origin of which coincides with the cannon's position, the *Ox* axis is directed rightwards in the city's direction, the *Oy* axis is directed upwards (to the sky). The cannon will make *n* more shots. The cannon balls' initial speeds are the same in all the shots and are equal to *V*, so that every shot is characterized by only one number *alpha**i* which represents the angle at which the cannon fires. Due to the cannon's technical peculiarities this angle does not exceed 45 angles (π / 4). We disregard the cannon sizes and consider the firing made from the point (0, 0).

The balls fly according to the known physical laws of a body thrown towards the horizon at an angle: 

*v**x*(*t*) = *V*·*cos*(*alpha*) *v**y*(*t*) = *V*·*sin*(*alpha*)  –  *g*·*t* *x*(*t*) = *V*·*cos*(*alpha*)·*t* *y*(*t*) = *V*·*sin*(*alpha*)·*t*  –  *g*·*t*2 / 2Think of the acceleration of gravity *g* as equal to 9.8.

Bertown defends *m* walls. The *i*-th wall is represented as a vertical segment (*x**i*, 0) - (*x**i*, *y**i*). When a ball hits a wall, it gets stuck in it and doesn't fly on. If a ball doesn't hit any wall it falls on the ground (*y* = 0) and stops. If the ball exactly hits the point (*x**i*, *y**i*), it is considered stuck. 

Your task is to find for each ball the coordinates of the point where it will be located in the end.

## Input

The first line contains integers *n* and *V* (1 ≤ *n* ≤ 104, 1 ≤ *V* ≤ 1000) which represent the number of shots and the initial speed of every ball. The second line contains *n* space-separated real numbers *alpha**i* (0 < *alpha**i* < π / 4) which represent the angles in radians at which the cannon will fire. The third line contains integer *m* (1 ≤ *m* ≤ 105) which represents the number of walls. Then follow *m* lines, each containing two real numbers *x**i* and *y**i* (1 ≤ *x**i* ≤ 1000, 0 ≤ *y**i* ≤ 1000) which represent the wall’s coordinates. All the real numbers have no more than 4 decimal digits. The walls may partially overlap or even coincide.

## Output

Print *n* lines containing two real numbers each — calculate for every ball the coordinates of its landing point. Your answer should have the relative or absolute error less than 10- 4.

## Examples

## Input


```
2 10  
0.7853  
0.3  
3  
5.0 5.0  
4.0 2.4  
6.0 1.9  

```
## Output


```
5.000000000 2.549499369  
4.000000000 0.378324889  

```
## Input


```
2 10  
0.7853  
0.3  
2  
4.0 2.4  
6.0 1.9  

```
## Output


```
10.204081436 0.000000000  
4.000000000 0.378324889  

```


#### tags 

#2200 #data_structures #geometry #sortings 