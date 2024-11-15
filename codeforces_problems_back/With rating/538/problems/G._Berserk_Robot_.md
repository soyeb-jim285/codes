<h1 style='text-align: center;'> G. Berserk Robot </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Help! A robot escaped our lab and we need help finding it. 

The lab is at the point (0, 0) of the coordinate plane, at time 0 the robot was there. The robot's movements are defined by a program — a string of length *l*, consisting of characters U, L, D, R. Each second the robot executes the next command in his program: if the current coordinates of the robot are (*x*, *y*), then commands U, L, D, R move it to cells (*x*, *y* + 1), (*x* - 1, *y*), (*x*, *y* - 1), (*x* + 1, *y*) respectively. The execution of the program started at time 0. The program is looped, i.e. each *l* seconds of executing the program start again from the first character. Unfortunately, we don't know what program was loaded into the robot when he left the lab.

Our radars managed to find out the position of the robot at *n* moments of time: we know that at the moment of time *t**i* the robot is at the point (*x**i*, *y**i*). Given this data, either help to determine what program could be loaded into the robot, or determine that no possible program meets the data and the robot must have broken down.

## Input

The first line of the input contains two space-separated integers *n* and *l* (1 ≤ *n* ≤ 2·105, 1 ≤ *l* ≤ 2·106).

Next *n* lines contain three space-separated integers — *t**i*, *x**i*, *y**i* (1 ≤ *t**i* ≤ 1018,  - 1018 ≤ *x**i*, *y**i* ≤ 1018). The radar data is given chronologically, i.e. *t**i* < *t**i* + 1 for all *i* from 1 to *n* - 1.

## Output

Print any of the possible programs that meet the data. If no program meets the data, print a single word 'NO' (without the quotes).

## Examples

## Input


```
3 3  
1 1 0  
2 1 -1  
3 0 -1  

```
## Output


```
RDL  

```
## Input


```
2 2  
1 1 0  
999 1 0  

```
## Output


```
RL  

```
## Input


```
2 5  
10 10 0  
20 0 0  

```
## Output


```
NO  

```


#### tags 

#3100 #constructive_algorithms #math #sortings 