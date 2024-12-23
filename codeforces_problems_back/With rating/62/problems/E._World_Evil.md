<h1 style='text-align: center;'> E. World Evil</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As a result of Pinky and Brain's mysterious experiments in the Large Hadron Collider some portals or black holes opened to the parallel dimension. And the World Evil has crept to the veil between their world and ours. Brain quickly evaluated the situation and he understood that the more evil tentacles creep out and become free, the higher is the possibility that Brain will rule the world.

The collider's constriction is a rectangular grid rolled into a cylinder and consisting of *n* rows and *m* columns such as is shown in the picture below:

 ![](images/4e10a3e9266cb910e1524bed0390c5c8980df589.png) In this example *n* = 4, *m* = 5. Dotted lines are corridores that close each column to a ring, i. e. connect the *n*-th and the 1-th rows of the grid.

In the leftmost column of the grid the portals are situated and the tentacles of the World Evil are ready to creep out from there. In the rightmost column the exit doors are located. The tentacles can only get out through those doors. The segments joining the nodes of the grid are corridors.

Brain would be glad to let all the tentacles out but he faces a problem: the infinite number of tentacles can creep out of the portals, every tentacle possesses infinite length and some width and the volume of the corridors are, unfortunately, quite limited. Brain could approximately evaluate the maximal number of tentacles that will be able to crawl through every corridor.

Now help the mice to determine the maximal number of tentacles of the World Evil that will crawl out of the Large Hadron Collider.

## Input

The first line of the input file contains two integers *n* and *m* (2 ≤ *n* ≤ 5, 2 ≤ *m* ≤ 105). They are the sizes of the Large Hadron Collider grid. The next *m* - 1 lines contain *n* numbers each. They are the horizontal corridors' capacities. The next *m* lines contain *n* numbers each. They are the vertical corridors' capacities. Corridors are described from left to right and from top to bottom. Every *n*-th vertical corridor connects nodes of the *n*-th and 1-th rows. A corridor's capacity is a non-negative integer that does not exceed 109.

## Output

Print a single number, the number of the World Evil tentacles Pinky and Brain will command.

Please, do not use %lld specificator to read or write 64-bit integers in C++. It is preffered to use cout (also you may use %I64d).

## Examples

## Input


```
3 4  
4 4 4  
1 1 5  
5 5 3  
4 1 2  
1 3 1  
3 5 4  
1 4 3  

```
## Output


```
7  

```
## Input


```
2 2  
9 2  
2 3  
6 1  

```
## Output


```
11  

```


#### tags 

#2700 #dp #flows 