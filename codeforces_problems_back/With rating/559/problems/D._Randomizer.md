<h1 style='text-align: center;'> D. Randomizer</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gerald got tired of playing board games with the usual six-sided die, and he bought a toy called Randomizer. It functions as follows.

A Randomizer has its own coordinate plane on which a strictly convex polygon is painted, the polygon is called a basic polygon. If you shake a Randomizer, it draws some nondegenerate (i.e. having a non-zero area) convex polygon with vertices at some vertices of the basic polygon. The result of the roll (more precisely, the result of the shaking) is considered to be the number of points with integer coordinates, which were strictly inside (the points on the border are not considered) the selected polygon. Now Gerald is wondering: what is the expected result of shaking the Randomizer?

During the shaking the Randomizer considers all the possible non-degenerate convex polygons with vertices at the vertices of the basic polygon. Let's assume that there are *k* versions of the polygons. Then the Randomizer chooses each of them with probability ![](images/22feb005334cd9870463a00bec8551fb6ba542cc.png).

## Input

The first line of the input contains a single integer *n* (3 ≤ *n* ≤ 100 000) — the number of vertices of the basic polygon. 

Next *n* lines contain the coordinates of the vertices of the basic polygon. The *i*-th of these lines contain two integers *x**i* and *y**i* ( - 109 ≤ *x**i*, *y**i* ≤ 109) — the coordinates of the *i*-th vertex of the polygon. The vertices are given in the counter-clockwise order.

## Output

Print the sought expected value with absolute or relative error at most 10- 9.

## Examples

## Input


```
4  
0 0  
2 0  
2 2  
0 2  

```
## Output


```
0.2  

```
## Input


```
5  
0 0  
2 0  
2 2  
1 3  
0 2  

```
## Output


```
0.8125  

```
## Note

A polygon is called strictly convex if it is convex and no its vertices lie on the same line.

Let's assume that a random variable takes values *x*1, ..., *x**n* with probabilities *p*1, ..., *p**n*, correspondingly. Then the expected value of this variable equals to ![](images/e592ba0986f3722e82626df9d579add61ddc5d36.png).



#### tags 

#2800 #combinatorics #geometry #probabilities 