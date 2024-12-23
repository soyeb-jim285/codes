<h1 style='text-align: center;'> D. Sign Posts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One Khanate had a lot of roads and very little wood. Riding along the roads was inconvenient, because the roads did not have road signs indicating the direction to important cities.

The Han decided that it's time to fix the issue, and ordered to put signs on every road. The Minister of Transport has to do that, but he has only *k* signs. Help the minister to solve his problem, otherwise the poor guy can lose not only his position, but also his head.

More formally, every road in the Khanate is a line on the *Oxy* plane, given by an equation of the form *Ax* + *By* + *C* = 0 (*A* and *B* are not equal to 0 at the same time). You are required to determine whether you can put signs in at most *k* points so that each road had at least one sign installed.

## Input

The input starts with two positive integers *n*, *k* (1 ≤ *n* ≤ 105, 1 ≤ *k* ≤ 5)

Next *n* lines contain three integers each, *A**i*, *B**i*, *C**i*, the coefficients of the equation that determines the road (|*A**i*|, |*B**i*|, |*C**i*| ≤ 105, *A**i*2 + *B**i*2 ≠ 0).

It is guaranteed that no two roads coincide.

## Output

If there is no solution, print "NO" in the single line (without the quotes).

Otherwise, print in the first line "YES" (without the quotes).

In the second line print a single number *m* (*m* ≤ *k*) — the number of used signs. In the next *m* lines print the descriptions of their locations.

Description of a location of one sign is two integers *v*, *u*. If *u* and *v* are two distinct integers between 1 and *n*, we assume that sign is at the point of intersection of roads number *v* and *u*. If *u* =  - 1, and *v* is an integer between 1 and *n*, then the sign is on the road number *v* in the point not lying on any other road. In any other case the description of a sign will be assumed invalid and your answer will be considered incorrect. In case if *v* = *u*, or if *v* and *u* are the numbers of two non-intersecting roads, your answer will also be considered incorrect.

The roads are numbered starting from 1 in the order in which they follow in the input.

## Examples

## Input


```
3 1  
1 0 0  
0 -1 0  
7 -93 0  

```
## Output


```
YES  
1  
1 2  

```
## Input


```
3 1  
1 0 0  
0 1 0  
1 1 3  

```
## Output


```
NO  

```
## Input


```
2 3  
3 4 5  
5 6 7  

```
## Output


```
YES  
2  
1 -1  
2 -1  

```
## Note

## Note

 that you do not have to minimize *m*, but it shouldn't be more than *k*.

In the first test all three roads intersect at point (0,0).

In the second test all three roads form a triangle and there is no way to place one sign so that it would stand on all three roads at once.



#### tags 

#2800 #brute_force #geometry #math 