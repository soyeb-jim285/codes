<h1 style='text-align: center;'> D. Take-off Ramps</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya participates in a ski race along the *X* axis. The start is at point 0, and the finish is at *L*, that is, at a distance *L* meters from the start in the positive direction of the axis. Vasya has been training so hard that he can run one meter in exactly one second.

Besides, there are *n* take-off ramps on the track, each ramp is characterized by four numbers: 

* *x**i* represents the ramp's coordinate
* *d**i* represents from how many meters Vasya will land if he goes down this ramp
* *t**i* represents the flight time in seconds
* *p**i* is the number, indicating for how many meters Vasya should gather speed to get ready and fly off the ramp. As Vasya gathers speed, he should ski on the snow (that is, he should not be flying), but his speed still equals one meter per second.

Vasya is allowed to move in any direction on the *X* axis, but he is prohibited to cross the start line, that is go to the negative semiaxis. Vasya himself chooses which take-off ramps he will use and in what order, that is, he is not obliged to take off from all the ramps he encounters. Specifically, Vasya can skip the ramp. It is guaranteed that *x**i* + *d**i* ≤ *L*, that is, Vasya cannot cross the finish line in flight.

Vasya can jump from the ramp only in the positive direction of *X* axis. More formally, when using the *i*-th ramp, Vasya starts gathering speed at point *x**i* - *p**i*, jumps at point *x**i*, and lands at point *x**i* + *d**i*. He cannot use the ramp in opposite direction.

Your task is to find the minimum time that Vasya will spend to cover the distance.

## Input

The first line contains two integers *n* and *L* (0 ≤ *n* ≤ 105, 1 ≤ *L* ≤ 109). Then *n* lines contain the descriptions of the ramps, each description is on a single line. Each description is a group of four non-negative integers *x**i*, *d**i*, *t**i*, *p**i* (0 ≤ *x**i* ≤ *L*, 1 ≤ *d**i*, *t**i*, *p**i* ≤ 109, *x**i* + *d**i* ≤ *L*).

## Output

Print in the first line the minimum time in seconds Vasya needs to complete the track. Print in the second line *k* — the number of take-off ramps that Vasya needs to use, and print on the third line of output *k* numbers the number the take-off ramps Vasya used in the order in which he used them. Print each number exactly once, separate the numbers with a space. The ramps are numbered starting from 1 in the order in which they are given in the input.

## Examples

## Input


```
2 20  
5 10 5 5  
4 16 1 7  

```
## Output


```
15  
1  
1 
```
## Input


```
2 20  
9 8 12 6  
15 5 1 1  

```
## Output


```
16  
1  
2 
```
## Note

In the first sample, Vasya cannot use ramp 2, because then he will need to gather speed starting from point -3, which is not permitted by the statement. The optimal option is using ramp 1, the resulting time is: moving to the point of gathering speed + gathering speed until reaching the takeoff ramp + flight time + moving to the finish line = 0 + 5 + 5 + 5 = 15.

In the second sample using ramp 1 is not optimal for Vasya as *t*1 > *d*1. The optimal option is using ramp 2, the resulting time is: moving to the point of gathering speed + gathering speed until reaching the takeoff ramp + flight time + moving to the finish line = 14 + 1 + 1 + 0 = 16.



#### tags 

#2300 #graphs #shortest_paths 