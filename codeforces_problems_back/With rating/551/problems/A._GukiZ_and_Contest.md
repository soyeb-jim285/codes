<h1 style='text-align: center;'> A. GukiZ and Contest</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Professor GukiZ likes programming contests. He especially likes to rate his students on the contests he prepares. Now, he has decided to prepare a new contest. 

In total, *n* students will attend, and before the start, every one of them has some positive integer rating. Students are indexed from 1 to *n*. Let's denote the rating of *i*-th student as *a**i*. After the contest ends, every student will end up with some positive integer position. GukiZ expects that his students will take places according to their ratings. 

He thinks that each student will take place equal to ![](images/8525cafdf358474b435e5d3d9562e6bc3bbbe6c5.png). In particular, if student *A* has rating strictly lower then student *B*, *A* will get the strictly better position than *B*, and if two students have equal ratings, they will share the same position. 

GukiZ would like you to reconstruct the results by following his expectations. Help him and determine the position after the end of the contest for each of his students if everything goes as expected.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 2000), number of GukiZ's students. 

The second line contains *n* numbers *a*1, *a*2, ... *a**n* (1 ≤ *a**i* ≤ 2000) where *a**i* is the rating of *i*-th student (1 ≤ *i* ≤ *n*).

## Output

In a single line, print the position after the end of the contest for each of *n* students in the same order as they appear in the input.

## Examples

## Input


```
3  
1 3 3  

```
## Output


```
3 1 1  

```
## Input


```
1  
1  

```
## Output


```
1  

```
## Input


```
5  
3 5 3 4 5  

```
## Output


```
4 1 4 3 1  

```
## Note

In the first sample, students 2 and 3 are positioned first (there is no other student with higher rating), and student 1 is positioned third since there are two students with higher rating.

In the second sample, first student is the only one on the contest.

In the third sample, students 2 and 5 share the first position with highest rating, student 4 is next with third position, and students 1 and 3 are the last sharing fourth position.



#### tags 

#800 #brute_force #implementation #sortings 