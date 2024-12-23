<h1 style='text-align: center;'> A. Points and Segments (easy)</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iahub isn't well prepared on geometry problems, but he heard that this year there will be a lot of geometry problems on the IOI selection camp. Scared, Iahub locked himself in the basement and started thinking of new problems of this kind. One of them is the following.

Iahub wants to draw *n* distinct points and *m* segments on the *OX* axis. He can draw each point with either red or blue. The drawing is good if and only if the following requirement is met: for each segment [*l**i*, *r**i*] consider all the red points belong to it (*r**i* points), and all the blue points belong to it (*b**i* points); each segment *i* should satisfy the inequality |*r**i* - *b**i*| ≤ 1.

Iahub thinks that point *x* belongs to segment [*l*, *r*], if inequality *l* ≤ *x* ≤ *r* holds.

Iahub gives to you all coordinates of points and segments. Please, help him to find any good drawing.

## Input

The first line of input contains two integers: *n* (1 ≤ *n* ≤ 100) and *m* (1 ≤ *m* ≤ 100). The next line contains *n* space-separated integers *x*1, *x*2, ..., *x**n* (0 ≤ *x**i* ≤ 100) — the coordinates of the points. The following *m* lines contain the descriptions of the *m* segments. Each line contains two integers *l**i* and *r**i* (0 ≤ *l**i* ≤ *r**i* ≤ 100) — the borders of the *i*-th segment.

It's guaranteed that all the points are distinct.

## Output

If there is no good drawing for a given test, output a single integer -1. Otherwise output *n* integers, each integer must be 0 or 1. The *i*-th number denotes the color of the *i*-th point (0 is red, and 1 is blue).

If there are multiple good drawings you can output any of them.

## Examples

## Input


```
3 3  
3 7 14  
1 5  
6 10  
11 15  

```
## Output


```
0 0 0
```
## Input


```
3 4  
1 2 3  
1 2  
2 3  
5 6  
2 2  

```
## Output


```
1 0 1 
```


#### tags 

#1600 #constructive_algorithms #sortings 