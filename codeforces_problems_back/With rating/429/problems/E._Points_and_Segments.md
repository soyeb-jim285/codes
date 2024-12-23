<h1 style='text-align: center;'> E. Points and Segments</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iahub isn't well prepared on geometry problems, but he heard that this year there will be a lot of geometry problems on the IOI selection camp. Scared, Iahub locked himself in the basement and started thinking of new problems of this kind. One of them is the following.

Iahub wants to draw *n* distinct segments [*l**i*, *r**i*] on the *OX* axis. He can draw each segment with either red or blue. The drawing is good if and only if the following requirement is met: for each point *x* of the *OX* axis consider all the segments that contains point *x*; suppose, that *r**x* red segments and *b**x* blue segments contain point *x*; for each point *x* inequality |*r**x* - *b**x*| ≤ 1 must be satisfied.

A segment [*l*, *r*] contains a point *x* if and only if *l* ≤ *x* ≤ *r*.

Iahub gives you the starting and ending points of all the segments. You have to find any good drawing for him.

## Input

The first line of input contains integer *n* (1 ≤ *n* ≤ 105) — the number of segments. The *i*-th of the next *n* lines contains two integers *l**i* and *r**i* (0 ≤ *l**i* ≤ *r**i* ≤ 109) — the borders of the *i*-th segment.

It's guaranteed that all the segments are distinct.

## Output

If there is no good drawing for a given test, output a single integer -1. Otherwise output *n* integers; each integer must be 0 or 1. The *i*-th number denotes the color of the *i*-th segment (0 is red and 1 is blue).

If there are multiple good drawings you can output any of them.

## Examples

## Input


```
2  
0 2  
2 3  

```
## Output


```
0 1  

```
## Input


```
6  
1 5  
1 3  
3 5  
2 10  
11 11  
12 12  

```
## Output


```
0 1 0 1 0 0  

```


#### tags 

#3000 #graphs 