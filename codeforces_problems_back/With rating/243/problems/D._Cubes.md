<h1 style='text-align: center;'> D. Cubes</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Petya got a set of wooden cubes as a present from his mom. Petya immediately built a whole city from these cubes.

The base of the city is an *n* × *n* square, divided into unit squares. The square's sides are parallel to the coordinate axes, the square's opposite corners have coordinates (0, 0) and (*n*, *n*). On each of the unit squares Petya built a tower of wooden cubes. The side of a wooden cube also has a unit length.

After that Petya went an infinitely large distance away from his masterpiece and looked at it in the direction of vector *v* = (*v**x*, *v**y*, 0). Petya wonders, how many distinct cubes are visible from this position. Help him, find this number.

Each cube includes the border. We think that a cube is visible if there is a ray emanating from some point *p*, belonging to the cube, in the direction of vector  - *v*, that doesn't contain any points, belonging to other cubes.

## Input

The first line contains three integers *n*, *v**x* and *v**y* (1 ≤ *n* ≤ 103, |*v**x*|, |*v**y*| ≤ |104|, |*v**x*| + |*v**y*| > 0).

Next *n* lines contain *n* integers each: the *j*-th integer in the *i*-th line *a**ij* (0 ≤ *a**ij* ≤ 109, 1 ≤ *i*, *j* ≤ *n*) represents the height of the cube tower that stands on the unit square with opposite corners at points (*i* - 1, *j* - 1) and (*i*, *j*).

## Output

Print a single integer — the number of visible cubes.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
5 -1 2  
5 0 0 0 1  
0 0 0 0 2  
0 0 0 1 2  
0 0 0 0 2  
2 2 2 2 3  

```
## Output


```
20
```
## Input


```
5 1 -2  
5 0 0 0 1  
0 0 0 0 2  
0 0 0 1 2  
0 0 0 0 2  
2 2 2 2 3  

```
## Output


```
15
```


#### tags 

#2700 #data_structures #dp #geometry #two_pointers 