<h1 style='text-align: center;'> B. Traffic Lights</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A car moves from point A to point B at speed *v* meters per second. The action takes place on the X-axis. At the distance *d* meters from A there are traffic lights. Starting from time 0, for the first *g* seconds the green light is on, then for the following *r* seconds the red light is on, then again the green light is on for the *g* seconds, and so on.

The car can be instantly accelerated from 0 to *v* and vice versa, can instantly slow down from the *v* to 0. Consider that it passes the traffic lights at the green light instantly. If the car approaches the traffic lights at the moment when the red light has just turned on, it doesn't have time to pass it. But if it approaches the traffic lights at the moment when the green light has just turned on, it can move. The car leaves point A at the time 0.

What is the minimum time for the car to get from point A to point B without breaking the traffic rules?

## Input

The first line contains integers *l*, *d*, *v*, *g*, *r* (1 ≤ *l*, *d*, *v*, *g*, *r* ≤ 1000, *d* < *l*) — the distance between A and B (in meters), the distance from A to the traffic lights, car's speed, the duration of green light and the duration of red light.

## Output

## Output

 a single number — the minimum time that the car needs to get from point A to point B. Your output must have relative or absolute error less than 10- 6.

## Examples

## Input


```
2 1 3 4 5  

```
## Output


```
0.66666667  

```
## Input


```
5 4 3 1 1  

```
## Output


```
2.33333333  

```


#### tags 

#1500 #implementation 