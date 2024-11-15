<h1 style='text-align: center;'> C. Shooting Gallery</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One warm and sunny day king Copa decided to visit the shooting gallery, located at the Central Park, and try to win the main prize — big pink plush panda. The king is not good at shooting, so he invited you to help him.

The shooting gallery is an infinite vertical plane with Cartesian coordinate system on it. The targets are points on this plane. Each target is described by it's coordinates *x**i*, and *y**i*, by the time of it's appearance *t**i* and by the number *p**i*, which gives the probability that Copa hits this target if he aims at it.

A target appears and disappears instantly, so Copa can hit the target only if at the moment *t**i* his gun sight aimed at (*x**i*, *y**i*). Speed of movement of the gun sight on the plane is equal to 1. Copa knows all the information about the targets beforehand (remember, he is a king!). He wants to play in the optimal way, which maximizes the expected value of the amount of hit targets. He can aim at any target at the moment 0.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 1000) — amount of targets in the shooting gallery. Then *n* lines follow, each describing one target. Each description consists of four numbers *x**i*, *y**i*, *t**i*, *p**i* (where *x**i*, *y**i*, *t**i* — integers,  - 1000 ≤ *x**i*, *y**i* ≤ 1000, 0 ≤ *t**i* ≤ 109, real number *p**i* is given with no more than 6 digits after the decimal point, 0 ≤ *p**i* ≤ 1). No two targets may be at the same point.

## Output

## Output

 the maximum expected value of the amount of targets that was shot by the king. Your answer will be accepted if it differs from the correct answer by not more than 10- 6.

## Examples

## Input


```
1  
0 0 0 0.5  

```
## Output


```
0.5000000000  

```
## Input


```
2  
0 0 0 0.6  
5 0 5 0.7  

```
## Output


```
1.3000000000  

```


#### tags 

#1800 #dp #probabilities 