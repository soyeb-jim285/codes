<h1 style='text-align: center;'> E. Contact</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Petya is preparing for the first contact with aliens. He knows that alien spaceships have shapes of non-degenerate triangles and there will be exactly 4 ships. Landing platform for a ship can be made of 3 special columns located at some points of a Cartesian plane such that these 3 points form a triangle equal to the ship with respect to rotations, translations (parallel shifts along some vector) and reflections (symmetries along the edges). The ships can overlap after the landing.

Each column can be used to land more than one ship, for example, if there are two equal ships, we don't need to build 6 columns to land both ships, 3 will be enough. Petya wants to know what minimum number of columns will be enough to land all ships. 

## Input

Each of 4 lines will contain 6 integers *x*1 *y*1 *x*2 *y*2 *x*3 *y*3 (0 ≤ *x*1, *y*1, *x*2, *y*2, *x*3, *y*3 ≤ 20), representing 3 points that describe the shape of each of 4 ships. It is guaranteed that 3 points in each line will represent a non-degenerate triangle.

## Output

First line should contain minimum number of columns enough to land all spaceships.

## Examples

## Input


```
0 0 1 0 1 2  
0 0 0 2 2 2  
0 0 3 0 1 2  
0 0 3 0 2 2  

```
## Output


```
4  

```
## Input


```
0 0 0 1 1 1  
0 0 0 2 2 2  
0 0 0 5 5 5  
0 0 0 17 17 17  

```
## Output


```
9  

```
## Note

In the first test case columns can be put in these points: (0, 0), (1, 0), (3, 0), (1, 2). ## Note

 that the second ship can land using last 3 columns.

In the second test case following points can be chosen: (0, 0), (0, 1), (1, 0), (0, 2), (2, 0), (0, 5), (5, 0), (0, 17), (17, 0). It is impossible to use less than 9 columns.



#### tags 

#2900 #geometry 