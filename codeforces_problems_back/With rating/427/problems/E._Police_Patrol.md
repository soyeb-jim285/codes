<h1 style='text-align: center;'> E. Police Patrol</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Imagine that your city is an infinite 2D plane with Cartesian coordinate system. The only crime-affected road of your city is the *x*-axis. Currently, there are *n* criminals along the road. No police station has been built on this road yet, so the mayor wants to build one.

As you are going to be in charge of this new police station, the mayor has asked you to choose a suitable position (some integer point) for building it. You should choose the best position for the police station, so that you could minimize the total time of your criminal catching mission. Your mission of catching the criminals will operate only from this station. 

The new station will have only one patrol car. You will go to the criminals by this car, carry them on the car, bring them back to the police station and put them in prison. The patrol car can carry at most *m* criminals at a time. Note that, the criminals don't know about your mission. So, they will stay where they are instead of running away.

Your task is to find the position for the police station, so that total distance you need to cover to catch all the criminals will be minimum possible. Note that, you also can built the police station on the positions where one or more criminals already exist. In such a case all these criminals are arrested instantly.

## Input

The first line of the input will have two integers *n* (1 ≤ *n* ≤ 106) and *m* (1 ≤ *m* ≤ 106) separated by spaces. The next line will contain *n* integers separated by spaces. The *i**th* integer is the position of the *i**th* criminal on the *x*-axis. Absolute value of positions will not exceed 109. If a criminal has position *x*, he/she is located in the point (*x*, 0) of the plane. 

The positions of the criminals will be given in non-decreasing order. Note, that there can be more than one criminal standing at some point of the plane.

Note: since the size of the input/output could be very large, don't use slow input/output techniques in your language. For example, do not use input/output streams (cin, cout) in C++.

## Output

Print a single integer, that means the minimum possible distance you need to cover to catch all the criminals.

## Examples

## Input


```
3 6  
1 2 3  

```
## Output


```
4  

```
## Input


```
5 5  
-7 -6 -3 -1 1  

```
## Output


```
16  

```
## Input


```
1 369  
0  

```
## Output


```
0  

```
## Input


```
11 2  
-375 -108 1336 1453 1598 1892 2804 3732 4291 4588 4822  

```
## Output


```
18716  

```


#### tags 

#2000 #greedy #implementation #math #ternary_search 