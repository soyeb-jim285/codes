<h1 style='text-align: center;'> E. A and B and Lecture Rooms</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A and B are preparing themselves for programming contests.

The University where A and B study is a set of rooms connected by corridors. Overall, the University has *n* rooms connected by *n* - 1 corridors so that you can get from any room to any other one by moving along the corridors. The rooms are numbered from 1 to *n*.

Every day А and B write contests in some rooms of their university, and after each contest they gather together in the same room and discuss problems. A and B want the distance from the rooms where problems are discussed to the rooms where contests are written to be equal. The distance between two rooms is the number of edges on the shortest path between them.

As they write contests in new rooms every day, they asked you to help them find the number of possible rooms to discuss problems for each of the following *m* days.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of rooms in the University.

The next *n* - 1 lines describe the corridors. The *i*-th of these lines (1 ≤ *i* ≤ *n* - 1) contains two integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*), showing that the *i*-th corridor connects rooms *a**i* and *b**i*.

The next line contains integer *m* (1 ≤ *m* ≤ 105) — the number of queries.

Next *m* lines describe the queries. The *j*-th of these lines (1 ≤ *j* ≤ *m*) contains two integers *x**j* and *y**j* (1 ≤ *x**j*, *y**j* ≤ *n*) that means that on the *j*-th day A will write the contest in the room *x**j*, B will write in the room *y**j*.

## Output

In the *i*-th (1 ≤ *i* ≤ *m*) line print the number of rooms that are equidistant from the rooms where A and B write contest on the *i*-th day.

## Examples

## Input


```
4  
1 2  
1 3  
2 4  
1  
2 3  

```
## Output


```
1  

```
## Input


```
4  
1 2  
2 3  
2 4  
2  
1 2  
1 3  

```
## Output


```
0  
2  

```
## Note

in the first sample there is only one room at the same distance from rooms number 2 and 3 — room number 1.



#### tags 

#2100 #binary_search #data_structures #dfs_and_similar #dp #trees 