<h1 style='text-align: center;'> D. Cube Snake</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got an *n* × *n* × *n* cube, split into unit cubes. Your task is to number all unit cubes in this cube with positive integers from 1 to *n*3 so that: 

* each number was used as a cube's number exactly once;
* for each 1 ≤ *i* < *n*3, unit cubes with numbers *i* and *i* + 1 were neighbouring (that is, shared a side);
* for each 1 ≤ *i* < *n* there were at least two different subcubes with sizes *i* × *i* × *i*, made from unit cubes, which are numbered with consecutive numbers. That is, there are such two numbers *x* and *y*, that the unit cubes of the first subcube are numbered by numbers *x*, *x* + 1, ..., *x* + *i*3 - 1, and the unit cubes of the second subcube are numbered by numbers *y*, *y* + 1, ..., *y* + *i*3 - 1.

Find and print the required numeration of unit cubes of the cube.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 50) — the size of the cube, whose unit cubes need to be numbered.

## Output

Print all layers of the cube as *n* *n* × *n* matrices. Separate them with new lines. Print the layers in the order in which they follow in the cube. See the samples for clarifications. 

It is guaranteed that there always is a solution that meets the conditions given in the problem statement.

## Examples

## Input


```
3  

```
## Output


```
1 4 17   
2 3 18   
27 26 19   
  
8 5 16   
7 6 15   
24 25 20   
  
9 12 13   
10 11 14   
23 22 21   
  

```
## Note

In the sample the cubes with sizes 2 × 2 × 2 are numbered with integers 1, ..., 8 and 5, ..., 12.



#### tags 

#2700 #constructive_algorithms 