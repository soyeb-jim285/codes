<h1 style='text-align: center;'> C. Bus</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a bus stop near the university. The lessons are over, and *n* students come to the stop. The *i*-th student will appear at the bus stop at time *t**i* (all *t**i*'s are distinct).

We shall assume that the stop is located on the coordinate axis *Ox*, at point *x* = 0, and the bus goes along the ray *Ox*, that is, towards the positive direction of the coordinate axis, and back. The *i*-th student needs to get to the point with coordinate *x**i* (*x**i* > 0).

The bus moves by the following algorithm. Initially it is at point 0. The students consistently come to the stop and get on it. The bus has a seating capacity which is equal to *m* passengers. At the moment when *m* students get on the bus, it starts moving in the positive direction of the coordinate axis. Also it starts moving when the last (*n*-th) student gets on the bus. The bus is moving at a speed of 1 unit of distance per 1 unit of time, i.e. it covers distance *y* in time *y*.

Every time the bus passes the point at which at least one student needs to get off, it stops and these students get off the bus. The students need 1 + [*k* / 2] units of time to get off the bus, where *k* is the number of students who leave at this point. Expression [*k* / 2] denotes rounded down *k* / 2. As soon as the last student leaves the bus, the bus turns around and goes back to the point *x* = 0. It doesn't make any stops until it reaches the point. At the given point the bus fills with students once more, and everything is repeated.

If students come to the stop when there's no bus, they form a line (queue) and get on the bus in the order in which they came. Any number of students get on the bus in negligible time, you should assume that it doesn't take any time. Any other actions also take no time. The bus has no other passengers apart from the students.

Write a program that will determine for each student the time when he got off the bus. The moment a student got off the bus is the moment the bus stopped at the student's destination stop (despite the fact that the group of students need some time to get off).

## Input

The first line contains two space-separated integers *n*, *m* (1 ≤ *n*, *m* ≤ 105) — the number of students and the number of passengers the bus can transport, correspondingly. Next *n* lines contain descriptions of the students, one per line. Each line contains a pair of integers *t**i*, *x**i* (1 ≤ *t**i* ≤ 105, 1 ≤ *x**i* ≤ 104). The lines are given in the order of strict increasing of *t**i*. Values of *x**i* can coincide.

## Output

Print *n* numbers *w*1, *w*2, ..., *w**n*, *w**i* — the moment of time when the *i*-th student got off the bus. Print the numbers on one line and separate them with single spaces.

## Examples

## Input


```
1 10  
3 5  

```
## Output


```
8  

```
## Input


```
2 1  
3 5  
4 5  

```
## Output


```
8 19  

```
## Input


```
5 4  
3 5  
4 5  
5 5  
6 5  
7 1  

```
## Output


```
11 11 11 11 20  

```
## Input


```
20 4  
28 13  
31 13  
35 6  
36 4  
52 6  
53 4  
83 2  
84 4  
87 1  
93 6  
108 4  
113 6  
116 1  
125 2  
130 2  
136 13  
162 2  
166 4  
184 1  
192 2  

```
## Output


```
51 51 43 40 93 89 86 89 114 121 118 121 137 139 139 152 195 199 193 195  

```
## Note

In the first sample the bus waits for the first student for 3 units of time and drives him to his destination in additional 5 units of time. So the student leaves the bus at the moment of time 3 + 5 = 8.

In the second sample the capacity of the bus equals 1, that's why it will drive the first student alone. This student is the same as the student from the first sample. So the bus arrives to his destination at the moment of time 8, spends 1 + [1 / 2] = 1 units of time on getting him off, and returns back to 0 in additional 5 units of time. That is, the bus returns to the bus stop at the moment of time 14. By this moment the second student has already came to the bus stop. So he immediately gets in the bus, and is driven to his destination in additional 5 units of time. He gets there at the moment 14 + 5 = 19. 

In the third sample the bus waits for the fourth student for 6 units of time, then drives for 5 units of time, then gets the passengers off for 1 + [4 / 2] = 3 units of time, then returns for 5 units of time, and then drives the fifth student for 1 unit of time.



#### tags 

#1500 #*special #implementation #sortings 