<h1 style='text-align: center;'> C. Bath Queue</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* students living in the campus. Every morning all students wake up at the same time and go to wash. There are *m* rooms with wash basins. The *i*-th of these rooms contains *a**i* wash basins. Every student independently select one the rooms with equal probability and goes to it. After all students selected their rooms, students in each room divide into queues by the number of wash basins so that the size of the largest queue is the least possible. Calculate the expected value of the size of the largest queue among all rooms.

## Input

The first line contains two positive integers *n* and *m* (1 ≤ *n*, *m* ≤ 50) — the amount of students and the amount of rooms. The second line contains *m* integers *a*1, *a*2, ... , *a**m* (1 ≤ *a**i* ≤ 50). *a**i* means the amount of wash basins in the *i*-th room.

## Output

## Output

 single number: the expected value of the size of the largest queue. Your answer must have an absolute or relative error less than 10- 9.

## Examples

## Input


```
1 1  
2  

```
## Output


```
1.00000000000000000000  

```
## Input


```
2 2  
1 1  

```
## Output


```
1.50000000000000000000  

```
## Input


```
2 3  
1 1 1  

```
## Output


```
1.33333333333333350000  

```
## Input


```
7 5  
1 1 2 3 1  

```
## Output


```
2.50216960000000070000  

```


#### tags 

#2200 #combinatorics #dp #probabilities 