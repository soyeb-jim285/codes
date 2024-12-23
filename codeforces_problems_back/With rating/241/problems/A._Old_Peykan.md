<h1 style='text-align: center;'> A. Old Peykan</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* cities in the country where the Old Peykan lives. These cities are located on a straight line, we'll denote them from left to right as *c*1, *c*2, ..., *c**n*. The Old Peykan wants to travel from city *c*1 to *c**n* using roads. There are (*n* - 1) one way roads, the *i*-th road goes from city *c**i* to city *c**i* + 1 and is *d**i* kilometers long.

The Old Peykan travels 1 kilometer in 1 hour and consumes 1 liter of fuel during this time.

Each city *c**i* (except for the last city *c**n*) has a supply of *s**i* liters of fuel which immediately transfers to the Old Peykan if it passes the city or stays in it. This supply refreshes instantly *k* hours after it transfers. The Old Peykan can stay in a city for a while and fill its fuel tank many times. 

Initially (at time zero) the Old Peykan is at city *c*1 and *s*1 liters of fuel is transferred to it's empty tank from *c*1's supply. The Old Peykan's fuel tank capacity is unlimited. Old Peykan can not continue its travel if its tank is emptied strictly between two cities.

Find the minimum time the Old Peykan needs to reach city *c**n*.

## Input

The first line of the input contains two space-separated integers *m* and *k* (1 ≤ *m*, *k* ≤ 1000). The value *m* specifies the number of roads between cities which is equal to *n* - 1.

The next line contains *m* space-separated integers *d*1, *d*2, ..., *d**m* (1 ≤ *d**i* ≤ 1000) and the following line contains *m* space-separated integers *s*1, *s*2, ..., *s**m* (1 ≤ *s**i* ≤ 1000).

## Output

In the only line of the output print a single integer — the minimum time required for The Old Peykan to reach city *c**n* from city *c*1.

## Examples

## Input


```
4 6  
1 2 5 2  
2 3 3 4  

```
## Output


```
10  

```
## Input


```
2 3  
5 6  
5 5  

```
## Output


```
14  

```
## Note

In the second sample above, the Old Peykan stays in *c*1 for 3 hours.



#### tags 

#1300 #greedy 