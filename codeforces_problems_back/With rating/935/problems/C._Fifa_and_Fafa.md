<h1 style='text-align: center;'> C. Fifa and Fafa</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fifa and Fafa are sharing a flat. Fifa loves video games and wants to download a new soccer game. Unfortunately, Fafa heavily uses the internet which consumes the quota. Fifa can access the internet through his Wi-Fi access point. This access point can be accessed within a range of *r* meters (this range can be chosen by Fifa) from its position. Fifa must put the access point inside the flat which has a circular shape of radius *R*. Fifa wants to minimize the area that is not covered by the access point inside the flat without letting Fafa or anyone outside the flat to get access to the internet.

The world is represented as an infinite 2D plane. The flat is centered at (*x*1, *y*1) and has radius *R* and Fafa's laptop is located at (*x*2, *y*2), not necessarily inside the flat. Find the position and the radius chosen by Fifa for his access point which minimizes the uncovered area.

## Input

The single line of the input contains 5 space-separated integers *R*, *x*1, *y*1, *x*2, *y*2 (1 ≤ *R* ≤ 105, |*x*1|, |*y*1|, |*x*2|, |*y*2| ≤ 105).

## Output

Print three space-separated numbers *x**ap*, *y**ap*, *r* where (*x**ap*, *y**ap*) is the position which Fifa chose for the access point and *r* is the radius of its range. 

Your answer will be considered correct if the radius does not differ from optimal more than 10- 6 absolutely or relatively, and also the radius you printed can be changed by no more than 10- 6 (absolutely or relatively) in such a way that all points outside the flat and Fafa's laptop position are outside circle of the access point range.

## Examples

## Input


```
5 3 3 1 1  

```
## Output


```
3.7677669529663684 3.7677669529663684 3.914213562373095  

```
## Input


```
10 5 5 5 15  

```
## Output


```
5.0 5.0 10.0  

```


#### tags 

#1600 #geometry 