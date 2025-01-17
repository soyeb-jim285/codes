<h1 style='text-align: center;'> D. Cubes</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once Vasya and Petya assembled a figure of *m* cubes, each of them is associated with a number between 0 and *m* - 1 (inclusive, each number appeared exactly once). Let's consider a coordinate system such that the *OX* is the ground, and the *OY* is directed upwards. Each cube is associated with the coordinates of its lower left corner, these coordinates are integers for each cube.

The figure turned out to be stable. This means that for any cube that is not on the ground, there is at least one cube under it such that those two cubes touch by a side or a corner. More formally, this means that for the cube with coordinates (*x*, *y*) either *y* = 0, or there is a cube with coordinates (*x* - 1, *y* - 1), (*x*, *y* - 1) or (*x* + 1, *y* - 1).

Now the boys want to disassemble the figure and put all the cubes in a row. In one step the cube is removed from the figure and being put to the right of the blocks that have already been laid. The guys remove the cubes in such order that the figure remains stable. To make the process more interesting, the guys decided to play the following game. The guys take out the cubes from the figure in turns. It is easy to see that after the figure is disassembled, the integers written on the cubes form a number, written in the *m*-ary positional numerical system (possibly, with a leading zero). Vasya wants the resulting number to be maximum possible, and Petya, on the contrary, tries to make it as small as possible. Vasya starts the game.

Your task is to determine what number is formed after the figure is disassembled, if the boys play optimally. Determine the remainder of the answer modulo 109 + 9.

## Input

The first line contains number *m* (2 ≤ *m* ≤ 105).

The following *m* lines contain the coordinates of the cubes *x**i*, *y**i* ( - 109 ≤ *x**i* ≤ 109, 0 ≤ *y**i* ≤ 109) in ascending order of numbers written on them. It is guaranteed that the original figure is stable.

No two cubes occupy the same place.

## Output

In the only line print the answer to the problem.

## Examples

## Input


```
3  
2 1  
1 0  
0 1  

```
## Output


```
19  

```
## Input


```
5  
0 0  
0 1  
0 2  
0 3  
0 4  

```
## Output


```
2930  

```


#### tags 

#2100 #games #greedy #implementation 