<h1 style='text-align: center;'> D. Buy a Ticket</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Musicians of a popular band "Flayer" have announced that they are going to "make their exit" with a world tour. Of course, they will visit Berland as well.

There are *n* cities in Berland. People can travel between cities using two-directional train routes; there are exactly *m* routes, *i*-th route can be used to go from city *v**i* to city *u**i* (and from *u**i* to *v**i*), and it costs *w**i* coins to use this route.

Each city will be visited by "Flayer", and the cost of the concert ticket in *i*-th city is *a**i* coins.

You have friends in every city of Berland, and they, knowing about your programming skills, asked you to calculate the minimum possible number of coins they have to pay to visit the concert. For every city *i* you have to compute the minimum number of coins a person from city *i* has to spend to travel to some city *j* (or possibly stay in city *i*), attend a concert there, and return to city *i* (if *j* ≠ *i*).

Formally, for every ![](images/29cd41d3b7a01103f80f7f1a061fdf146ffa49b1.png) you have to calculate ![](images/bf13f50757d9e541885105265d178755c39ad551.png), where *d*(*i*, *j*) is the minimum number of coins you have to spend to travel from city *i* to city *j*. If there is no way to reach city *j* from city *i*, then we consider *d*(*i*, *j*) to be infinitely large.

## Input

The first line contains two integers *n* and *m* (2 ≤ *n* ≤ 2·105, 1 ≤ *m* ≤ 2·105).

Then *m* lines follow, *i*-th contains three integers *v**i*, *u**i* and *w**i* (1 ≤ *v**i*, *u**i* ≤ *n*, *v**i* ≠ *u**i*, 1 ≤ *w**i* ≤ 1012) denoting *i*-th train route. There are no multiple train routes connecting the same pair of cities, that is, for each (*v*, *u*) neither extra (*v*, *u*) nor (*u*, *v*) present in input.

The next line contains *n* integers *a*1, *a*2, ... *a**k* (1 ≤ *a**i* ≤ 1012) — price to attend the concert in *i*-th city.

## Output

Print *n* integers. *i*-th of them must be equal to the minimum number of coins a person from city *i* has to spend to travel to some city *j* (or possibly stay in city *i*), attend a concert there, and return to city *i* (if *j* ≠ *i*).

## Examples

## Input


```
4 2  
1 2 4  
2 3 7  
6 20 1 25  

```
## Output


```
6 14 1 25   

```
## Input


```
3 3  
1 2 1  
2 3 1  
1 3 1  
30 10 20  

```
## Output


```
12 10 12   

```


#### tags 

#2000 #data_structures #graphs #shortest_paths 