<h1 style='text-align: center;'> C. Inquisition</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Medieval times existed the tradition of burning witches at steaks together with their pets, black cats. By the end of the 15-th century the population of black cats ceased to exist. The difficulty of the situation led to creating the EIC - the Emergency Inquisitory Commission.

The resolution #666 says that a white cat is considered black when and only when the perimeter of its black spots exceeds the acceptable norm. But what does the acceptable norm equal to? Every inquisitor will choose it himself depending on the situation. And your task is to find the perimeter of black spots on the cat's fur.

The very same resolution says that the cat's fur is a white square with the length of 105. During the measurement of spots it is customary to put the lower left corner of the fur into the origin of axes (0;0) and the upper right one — to the point with coordinates (105;105). The cats' spots are nondegenerate triangles. The spots can intersect and overlap with each other, but it is guaranteed that each pair of the triangular spots' sides have no more than one common point.

We'll regard the perimeter in this problem as the total length of the boarders where a cat's fur changes color.

## Input

The first input line contains a single integer *n* (0 ≤ *n* ≤ 100). It is the number of spots on the cat's fur. The *i*-th of the last *n* lines contains 6 integers: *x*1*i*, *y*1*i*, *x*2*i*, *y*2*i*, *x*3*i*, *y*3*i*. They are the coordinates of the *i*-th triangular spot (0 < *x**ji*, *y**ji* < 105).

## Output

Print a single number, the answer to the problem, perimeter of the union of triangles. Your answer should differ from the correct one in no more than 10- 6.

## Examples

## Input


```
1  
1 1 2 1 1 2  

```
## Output


```
3.4142135624  

```
## Input


```
3  
3 3 10 3 3 10  
1 1 9 4 5 6  
2 2 11 7 6 11  

```
## Output


```
37.7044021497  

```


#### tags 

#2300 #geometry #implementation #sortings 