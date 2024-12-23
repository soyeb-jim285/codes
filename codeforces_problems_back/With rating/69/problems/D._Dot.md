<h1 style='text-align: center;'> D. Dot</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Anton and Dasha like to play different games during breaks on checkered paper. By the 11th grade they managed to play all the games of this type and asked Vova the programmer to come up with a new game. Vova suggested to them to play a game under the code name "dot" with the following rules: 

* On the checkered paper a coordinate system is drawn. A dot is initially put in the position (*x*, *y*).
* A move is shifting a dot to one of the pre-selected vectors. Also each player can once per game symmetrically reflect a dot relatively to the line *y* = *x*.
* Anton and Dasha take turns. Anton goes first.
* The player after whose move the distance from the dot to the coordinates' origin exceeds *d*, loses.

Help them to determine the winner.

## Input

The first line of the input file contains 4 integers *x*, *y*, *n*, *d* ( - 200 ≤ *x*, *y* ≤ 200, 1 ≤ *d* ≤ 200, 1 ≤ *n* ≤ 20) — the initial coordinates of the dot, the distance *d* and the number of vectors. It is guaranteed that the initial dot is at the distance less than *d* from the origin of the coordinates. The following *n* lines each contain two non-negative numbers *x**i* and *y**i* (0 ≤ *x**i*, *y**i* ≤ 200) — the coordinates of the i-th vector. It is guaranteed that all the vectors are nonzero and different.

## Output

You should print "Anton", if the winner is Anton in case of both players play the game optimally, and "Dasha" otherwise.

## Examples

## Input


```
0 0 2 3  
1 1  
1 2  

```
## Output


```
Anton
```
## Input


```
0 0 2 4  
1 1  
1 2  

```
## Output


```
Dasha
```
## Note

In the first test, Anton goes to the vector (1;2), and Dasha loses. In the second test Dasha with her first move shifts the dot so that its coordinates are (2;3), and Anton loses, as he has the only possible move — to reflect relatively to the line *y* = *x*. Dasha will respond to it with the same move and return the dot in position (2;3).



#### tags 

#1900 #dp #games 