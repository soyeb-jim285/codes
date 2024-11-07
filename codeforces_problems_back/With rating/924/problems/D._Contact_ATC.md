<h1 style='text-align: center;'> D. Contact ATC</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arkady the air traffic controller is now working with *n* planes in the air. All planes move along a straight coordinate axis with Arkady's station being at point 0 on it. The *i*-th plane, small enough to be represented by a point, currently has a coordinate of *x**i* and is moving with speed *v**i*. It's guaranteed that *x**i*·*v**i* < 0, i.e., all planes are moving towards the station.

Occasionally, the planes are affected by winds. With a wind of speed *v**wind* (not necessarily positive or integral), the speed of the *i*-th plane becomes *v**i* + *v**wind*.

According to weather report, the current wind has a steady speed falling inside the range [ - *w*, *w*] (inclusive), but the exact value cannot be measured accurately since this value is rather small — smaller than the absolute value of speed of any plane.

Each plane should contact Arkady at the exact moment it passes above his station. And you are to help Arkady count the number of pairs of planes (*i*, *j*) (*i* < *j*) there are such that there is a possible value of wind speed, under which planes *i* and *j* contact Arkady at the same moment. This value needn't be the same across different pairs.

The wind speed is the same for all planes. You may assume that the wind has a steady speed and lasts arbitrarily long.

## Input

The first line contains two integers *n* and *w* (1 ≤ *n* ≤ 100 000, 0 ≤ *w* < 105) — the number of planes and the maximum wind speed.

The *i*-th of the next *n* lines contains two integers *x**i* and *v**i* (1 ≤ |*x**i*| ≤ 105, *w* + 1 ≤ |*v**i*| ≤ 105, *x**i*·*v**i* < 0) — the initial position and speed of the *i*-th plane.

Planes are pairwise distinct, that is, no pair of (*i*, *j*) (*i* < *j*) exists such that both *x**i* = *x**j* and *v**i* = *v**j*.

## Output

## Output

 a single integer — the number of unordered pairs of planes that can contact Arkady at the same moment.

## Examples

## Input


```
5 1  
-3 2  
-3 3  
-1 2  
1 -3  
3 -5  

```
## Output


```
3  

```
## Input


```
6 1  
-3 2  
-2 2  
-1 2  
1 -2  
2 -2  
3 -2  

```
## Output


```
9  

```
## Note

In the first example, the following 3 pairs of planes satisfy the requirements: 

* (2, 5) passes the station at time 3 / 4 with *v**wind* = 1;
* (3, 4) passes the station at time 2 / 5 with *v**wind* = 1 / 2;
* (3, 5) passes the station at time 4 / 7 with *v**wind* =  - 1 / 4.

In the second example, each of the 3 planes with negative coordinates can form a valid pair with each of the other 3, totaling 9 pairs.



#### tags 

#2500 