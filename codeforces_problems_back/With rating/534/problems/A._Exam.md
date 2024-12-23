<h1 style='text-align: center;'> A. Exam</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An exam for *n* students will take place in a long and narrow room, so the students will sit in a line in some order. The teacher suspects that students with adjacent numbers (*i* and *i* + 1) always studied side by side and became friends and if they take an exam sitting next to each other, they will help each other for sure.

Your task is to choose the maximum number of students and make such an arrangement of students in the room that no two students with adjacent numbers sit side by side.

## Input

A single line contains integer *n* (1 ≤ *n* ≤ 5000) — the number of students at an exam.

## Output

In the first line print integer *k* — the maximum number of students who can be seated so that no two students with adjacent numbers sit next to each other.

In the second line print *k* distinct integers *a*1, *a*2, ..., *a**k* (1 ≤ *a**i* ≤ *n*), where *a**i* is the number of the student on the *i*-th position. The students on adjacent positions mustn't have adjacent numbers. Formally, the following should be true: |*a**i* - *a**i* + 1| ≠ 1 for all *i* from 1 to *k* - 1.

If there are several possible answers, output any of them.

## Examples

## Input


```
6
```
## Output


```
6  
1 5 3 6 2 4
```
## Input


```
3  

```
## Output


```
2  
1 3
```


#### tags 

#1100 #constructive_algorithms #implementation #math 