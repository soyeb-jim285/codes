<h1 style='text-align: center;'> C. GukiZ hates Boxes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Professor GukiZ is concerned about making his way to school, because massive piles of boxes are blocking his way. 

In total there are *n* piles of boxes, arranged in a line, from left to right, *i*-th pile (1 ≤ *i* ≤ *n*) containing *a**i* boxes. Luckily, *m* students are willing to help GukiZ by removing all the boxes from his way. Students are working simultaneously. At time 0, all students are located left of the first pile. It takes one second for every student to move from this position to the first pile, and after that, every student must start performing sequence of two possible operations, each taking one second to complete. Possible operations are:

1. If *i* ≠ *n*, move from pile *i* to pile *i* + 1;
2. If pile located at the position of student is not empty, remove one box from it.

GukiZ's students aren't smart at all, so they need you to tell them how to remove boxes before professor comes (he is very impatient man, and doesn't want to wait). They ask you to calculate minumum time *t* in seconds for which they can remove all the boxes from GukiZ's way. ## Note

 that students can be positioned in any manner after *t* seconds, but all the boxes must be removed.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 105), the number of piles of boxes and the number of GukiZ's students. 

The second line contains *n* integers *a*1, *a*2, ... *a**n* (0 ≤ *a**i* ≤ 109) where *a**i* represents the number of boxes on *i*-th pile. It's guaranteed that at least one pile of is non-empty.

## Output

In a single line, print one number, minimum time needed to remove all the boxes in seconds.

## Examples

## Input


```
2 1  
1 1  

```
## Output


```
4  

```
## Input


```
3 2  
1 0 2  

```
## Output


```
5  

```
## Input


```
4 100  
3 4 5 4  

```
## Output


```
5  

```
## Note

First sample: Student will first move to the first pile (1 second), then remove box from first pile (1 second), then move to the second pile (1 second) and finally remove the box from second pile (1 second).

Second sample: One of optimal solutions is to send one student to remove a box from the first pile and a box from the third pile, and send another student to remove a box from the third pile. Overall, 5 seconds.

Third sample: With a lot of available students, send three of them to remove boxes from the first pile, four of them to remove boxes from the second pile, five of them to remove boxes from the third pile, and four of them to remove boxes from the fourth pile. Process will be over in 5 seconds, when removing the boxes from the last pile is finished.



#### tags 

#2200 #binary_search #greedy 