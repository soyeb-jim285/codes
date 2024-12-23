<h1 style='text-align: center;'> C. Optimal Point</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

When the river brought Gerda to the house of the Old Lady who Knew Magic, this lady decided to make Gerda her daughter. She wants Gerda to forget about Kay, so she puts all the roses from the garden underground.

Mole, who lives in this garden, now can watch the roses without going up to the surface. Typical mole is blind, but this mole was granted as special vision by the Old Lady. He can watch any underground objects on any distance, even through the obstacles and other objects. However, the quality of the picture depends on the Manhattan distance to object being observed.

Mole wants to find an optimal point to watch roses, that is such point with integer coordinates that the maximum Manhattan distance to the rose is minimum possible.

As usual, he asks you to help.

Manhattan distance between points (*x*1,  *y*1,  *z*1) and (*x*2,  *y*2,  *z*2) is defined as |*x*1 - *x*2| + |*y*1 - *y*2| + |*z*1 - *z*2|.

## Input

The first line of the input contains an integer *t* *t* (1 ≤ *t* ≤ 100 000) — the number of test cases. Then follow exactly *t* blocks, each containing the description of exactly one test.

The first line of each block contains an integer *n**i* (1 ≤ *n**i* ≤ 100 000) — the number of roses in the test. Then follow *n**i* lines, containing three integers each — the coordinates of the corresponding rose. ## Note

 that two or more roses may share the same position.

It's guaranteed that the sum of all *n**i* doesn't exceed 100 000 and all coordinates are not greater than 1018 by their absolute value.

## Output

For each of *t* test cases print three integers — the coordinates of the optimal point to watch roses. If there are many optimal answers, print any of them.

The coordinates of the optimal point may coincide with the coordinates of any rose.

## Examples

## Input


```
1  
5  
0 0 4  
0 0 -4  
0 4 0  
4 0 0  
1 1 1  

```
## Output


```
0 0 0  

```
## Input


```
2  
1  
3 5 9  
2  
3 5 9  
3 5 9  

```
## Output


```
3 5 9  
3 5 9  

```
## Note

In the first sample, the maximum Manhattan distance from the point to the rose is equal to 4.

In the second sample, the maximum possible distance is 0. ## Note

 that the positions of the roses may coincide with each other and with the position of the optimal point.



#### tags 

#2900 #binary_search #math 