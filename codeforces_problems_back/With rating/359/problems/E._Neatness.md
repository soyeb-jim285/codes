<h1 style='text-align: center;'> E. Neatness</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Simon loves neatness. So before he goes to bed, Simon wants to complete all chores in the house.

Simon's house looks like a rectangular table consisting of *n* rows and *n* columns from above. All rows of the table are numbered from 1 to *n* from top to bottom. All columns of the table are numbered from 1 to *n* from left to right. Each cell of the table is a room. Pair (*x*, *y*) denotes the room, located at the intersection of the *x*-th row and the *y*-th column. For each room we know if the light is on or not there.

Initially Simon is in room (*x*0, *y*0). He wants to turn off the lights in all the rooms in the house, and then return to room (*x*0, *y*0). Suppose that at the current moment Simon is in the room (*x*, *y*). To reach the desired result, he can perform the following steps:

1. The format of the action is "1". The action is to turn on the light in room (*x*, *y*). Simon cannot do it if the room already has light on.
2. The format of the action is "2". The action is to turn off the light in room (*x*, *y*). Simon cannot do it if the room already has light off.
3. The format of the action is "dir" (*dir* is a character). The action is to move to a side-adjacent room in direction *dir*. The direction can be left, right, up or down (the corresponding dir is L, R, U or D). Additionally, Simon can move only if he see a light in the direction *dir*. More formally, if we represent the room, Simon wants to go, as (*nx*, *ny*), there shold be an integer *k* (*k* > 0), that room (*x* + (*nx* - *x*)*k*, *y* + (*ny* - *y*)*k*) has a light. Of course, Simon cannot move out of his house.

Help Simon, find the sequence of actions that lets him achieve the desired result.

## Input

The first line contains three positive integers *n*, *x*0, *y*0 (2 ≤ *n* ≤ 500, 1 ≤ *x*0, *y*0 ≤ *n*).

Next *n* lines contain the description of rooms in the house. The *i*-th line contains *n* space-separated integers *a**i*1, *a**i*2, ..., *a**in*. If number *a**ij* equals zero, then room (*i*, *j*) has light off, and if number *a**ij* equals one, then room (*i*, *j*) has light on. It is guaranteed that at least one room has light on.

## Output

If there is no desired sequence of actions, print "NO" (without the quotes). Otherwise, print "YES" (without the quotes) and the description of the required sequence of actions as a string. Note that you do not have to minimize the length of the sequence of actions but you shouldn't use more than 3·106 actions.

## Examples

## Input


```
3 1 1  
1 0 0  
0 1 0  
1 0 0  

```
## Output


```
YES  
D1R2L2D2UU2  

```
## Input


```
3 1 1  
1 0 0  
0 1 0  
0 0 1  

```
## Output


```
NO  

```


#### tags 

#2400 #constructive_algorithms #dfs_and_similar 