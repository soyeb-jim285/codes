<h1 style='text-align: center;'> E. Vanya and Field</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vanya decided to walk in the field of size *n* × *n* cells. The field contains *m* apple trees, the *i*-th apple tree is at the cell with coordinates (*x**i*, *y**i*). Vanya moves towards vector (*dx*, *dy*). That means that if Vanya is now at the cell (*x*, *y*), then in a second he will be at cell ![](images/4cd2e23d078c7836c5f66c3a76cb219288d09e57.png). The following condition is satisfied for the vector: ![](images/04a4e7c6666583d8b8f8df9f9a3817be526a7e2b.png), where ![](images/0c8818210d7d81357d25a255f5d844014e5e7391.png) is the largest integer that divides both *a* and *b*. Vanya ends his path when he reaches the square he has already visited. 

Vanya wonders, from what square of the field he should start his path to see as many apple trees as possible.

## Input

The first line contains integers *n*, *m*, *dx*, *dy*(1 ≤ *n* ≤ 106, 1 ≤ *m* ≤ 105, 1 ≤ *dx*, *dy* ≤ *n*) — the size of the field, the number of apple trees and the vector of Vanya's movement. Next *m* lines contain integers *x**i*, *y**i* (0 ≤ *x**i*, *y**i* ≤ *n* - 1) — the coordinates of apples. One cell may contain multiple apple trees.

## Output

Print two space-separated numbers — the coordinates of the cell from which you should start your path. If there are several answers you are allowed to print any of them.

## Examples

## Input


```
5 5 2 3  
0 0  
1 2  
1 3  
2 4  
3 1  

```
## Output


```
1 3  

```
## Input


```
2 3 1 1  
0 0  
0 1  
1 1  

```
## Output


```
0 0  

```
## Note

In the first sample Vanya's path will look like: (1, 3) - (3, 1) - (0, 4) - (2, 2) - (4, 0) - (1, 3)

In the second sample: (0, 0) - (1, 1) - (0, 0)



#### tags 

#2000 #math 