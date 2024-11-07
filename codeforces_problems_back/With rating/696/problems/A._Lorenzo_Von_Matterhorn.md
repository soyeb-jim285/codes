<h1 style='text-align: center;'> A. Lorenzo Von Matterhorn</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Barney lives in NYC. NYC has infinite number of intersections numbered with positive integers starting from 1. There exists a bidirectional road between intersections *i* and 2*i* and another road between *i* and 2*i* + 1 for every positive integer *i*. You can clearly see that there exists a unique shortest path between any two intersections.

 ![](images/fd572f581f93165db5f0cd5d32ce4227bf30dafe.png) Initially anyone can pass any road for free. But since SlapsGiving is ahead of us, there will *q* consecutive events happen soon. There are two types of events:

1. Government makes a new rule. A rule can be denoted by integers *v*, *u* and *w*. As the result of this action, the passing fee of all roads on the shortest path from *u* to *v* increases by *w* dollars. 

2. Barney starts moving from some intersection *v* and goes to intersection *u* where there's a girl he wants to cuddle (using his fake name Lorenzo Von Matterhorn). He always uses the shortest path (visiting minimum number of intersections or roads) between two intersections.

Government needs your calculations. For each time Barney goes to cuddle a girl, you need to tell the government how much money he should pay (sum of passing fee of all roads he passes).

## Input

The first line of input contains a single integer *q* (1 ≤ *q* ≤ 1 000).

The next *q* lines contain the information about the events in chronological order. Each event is described in form 1 *v* *u* *w* if it's an event when government makes a new rule about increasing the passing fee of all roads on the shortest path from *u* to *v* by *w* dollars, or in form 2 *v* *u* if it's an event when Barnie goes to cuddle from the intersection *v* to the intersection *u*.

1 ≤ *v*, *u* ≤ 1018, *v* ≠ *u*, 1 ≤ *w* ≤ 109 states for every description line.

## Output

For each event of second type print the sum of passing fee of all roads Barney passes in this event, in one line. Print the answers in chronological order of corresponding events.

## Example

## Input


```
7  
1 3 4 30  
1 4 1 2  
1 3 6 8  
2 4 3  
1 6 1 40  
2 3 7  
2 2 4  

```
## Output


```
94  
0  
32  

```
## Note

In the example testcase:

Here are the intersections used:

 ![](images/76e4ebc2530c688a5e22ff76fac8cbb0bf3a51f4.png) 1. Intersections on the path are 3, 1, 2 and 4.
2. Intersections on the path are 4, 2 and 1.
3. Intersections on the path are only 3 and 6.
4. Intersections on the path are 4, 2, 1 and 3. Passing fee of roads on the path are 32, 32 and 30 in order. So answer equals to 32 + 32 + 30 = 94.
5. Intersections on the path are 6, 3 and 1.
6. Intersections on the path are 3 and 7. Passing fee of the road between them is 0.
7. Intersections on the path are 2 and 4. Passing fee of the road between them is 32 (increased by 30 in the first event and by 2 in the second).


#### tags 

#1500 #brute_force #data_structures #implementation #trees 