<h1 style='text-align: center;'> A. Triangle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

At a geometry lesson Bob learnt that a triangle is called right-angled if it is nondegenerate and one of its angles is right. Bob decided to draw such a triangle immediately: on a sheet of paper he drew three points with integer coordinates, and joined them with segments of straight lines, then he showed the triangle to Peter. Peter said that Bob's triangle is not right-angled, but is almost right-angled: the triangle itself is not right-angled, but it is possible to move one of the points exactly by distance 1 so, that all the coordinates remain integer, and the triangle become right-angled. Bob asks you to help him and find out if Peter tricks him. By the given coordinates of the triangle you should find out if it is right-angled, almost right-angled, or neither of these.

## Input

The first input line contains 6 space-separated integers *x*1, *y*1, *x*2, *y*2, *x*3, *y*3 — coordinates of the triangle's vertices. All the coordinates are integer and don't exceed 100 in absolute value. It's guaranteed that the triangle is nondegenerate, i.e. its total area is not zero.

## Output

If the given triangle is right-angled, output RIGHT, if it is almost right-angled, output ALMOST, and if it is neither of these, output NEITHER.

## Examples

## Input


```
0 0 2 0 0 1  

```
## Output


```
RIGHT  

```
## Input


```
2 3 4 5 6 6  

```
## Output


```
NEITHER  

```
## Input


```
-1 0 2 0 0 1  

```
## Output


```
ALMOST  

```


#### tags 

#1500 #brute_force #geometry 