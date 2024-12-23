<h1 style='text-align: center;'> F. Nagini</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nagini, being a horcrux You-know-who created with the murder of Bertha Jorkins, has accumulated its army of snakes and is launching an attack on Hogwarts school. 

Hogwarts' entrance can be imagined as a straight line (x-axis) from 1 to 105. Nagini is launching various snakes at the Hogwarts entrance. Each snake lands parallel to the entrance, covering a segment at a distance *k* from *x* = *l* to *x* = *r*. Formally, each snake can be imagined as being a line segment between points (*l*, *k*) and (*r*, *k*). ## Note

 that *k* can be both positive and negative, but not 0.

Let, at some *x*-coordinate *x* = *i*, there be snakes at point (*i*, *y*1) and point (*i*, *y*2), such that *y*1 > 0 and *y*2 < 0. Then, if for any point (*i*, *y*3) containing a snake such that *y*3 > 0, *y*1 ≤ *y*3 holds and for any point (*i*, *y*4) containing a snake such that *y*4 < 0, |*y*2| ≤ |*y*4| holds, then the danger value at coordinate *x* = *i* is *y*1 + |*y*2|. If no such *y*1 and *y*2 exist, danger value is 0. 

Harry wants to calculate the danger value of various segments of the Hogwarts entrance. Danger value for a segment [*l*, *r*) of the entrance can be calculated by taking the sum of danger values for each integer *x*-coordinate present in the segment.

Formally, you have to implement two types of queries:

* 1 l r k: a snake is added parallel to entrance from *x* = *l* to *x* = *r* at y-coordinate *y* = *k* (*l* inclusive, *r* exclusive).
* 2 l r: you have to calculate the danger value of segment *l* to *r* (*l* inclusive, *r* exclusive).
## Input

First line of input contains a single integer *q* (1 ≤ *q* ≤ 5·104) denoting the number of queries.

Next *q* lines each describe a query. Each query description first contains the query type *type**i* (1 ≤ *type**i* ≤ 2). This is followed by further description of the query. In case of the type being 1, it is followed by integers *l**i*, *r**i* and *k**i* (![](images/19b17a77ae388bfef18ea5e1f5bac67f9c316e60.png),  - 109 ≤ *k**i* ≤ 109, *k* ≠ 0). Otherwise, it just contains two integers, *l**i* and *r**i* (1 ≤ *l**i* < *r**i* ≤ 105).

## Output

## Output

 the answer for each query of type 2 in a separate line.

## Examples

## Input


```
3  
1 1 10 10  
1 2 4 -7  
2 1 10  

```
## Output


```
34  

```
## Input


```
7  
1 2 3 5  
1 1 10 10  
1 4 5 -5  
2 4 8  
1 1 10 -10  
2 4 8  
2 1 10  

```
## Output


```
15  
75  
170  

```
## Note

In the first sample case, the danger value for *x*-coordinates 1 is 0 as there is no *y*2 satisfying the above condition for *x* = 1.

Danger values for *x*-coordinates 2 and 3 is 10 + | - 7| = 17.

Danger values for *x*-coordinates 4 to 9 is again 0 as there is no *y*2 satisfying the above condition for these coordinates.

Thus, total danger value is 17 + 17 = 34.



#### tags 

#3100 #binary_search #data_structures 