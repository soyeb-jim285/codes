<h1 style='text-align: center;'> D. Missile Silos</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A country called Berland consists of *n* cities, numbered with integer numbers from 1 to *n*. Some of them are connected by bidirectional roads. Each road has some length. There is a path from each city to any other one by these roads. According to some Super Duper Documents, Berland is protected by the Super Duper Missiles. The exact position of the Super Duper Secret Missile Silos is kept secret but Bob managed to get hold of the information. That information says that all silos are located exactly at a distance *l* from the capital. The capital is located in the city with number *s*.

The documents give the formal definition: the Super Duper Secret Missile Silo is located at some place (which is either city or a point on a road) if and only if the shortest distance from this place to the capital along the roads of the country equals exactly *l*.

Bob wants to know how many missile silos are located in Berland to sell the information then to enemy spies. Help Bob.

## Input

The first line contains three integers *n*, *m* and *s* (2 ≤ *n* ≤ 105, ![](images/bdb9cd119f4995cb94d6c49d2ab3bd509f7fe600.png), 1 ≤ *s* ≤ *n*) — the number of cities, the number of roads in the country and the number of the capital, correspondingly. Capital is the city no. *s*. 

Then *m* lines contain the descriptions of roads. Each of them is described by three integers *v**i*, *u**i*, *w**i* (1 ≤ *v**i*, *u**i* ≤ *n*, *v**i* ≠ *u**i*, 1 ≤ *w**i* ≤ 1000), where *v**i*, *u**i* are numbers of the cities connected by this road and *w**i* is its length. The last input line contains integer *l* (0 ≤ *l* ≤ 109) — the distance from the capital to the missile silos. It is guaranteed that: 

* between any two cities no more than one road exists;
* each road connects two different cities;
* from each city there is at least one way to any other city by the roads.
## Output

Print the single number — the number of Super Duper Secret Missile Silos that are located in Berland.

## Examples

## Input


```
4 6 1  
1 2 1  
1 3 3  
2 3 1  
2 4 1  
3 4 1  
1 4 2  
2  

```
## Output


```
3  

```
## Input


```
5 6 3  
3 1 1  
3 2 1  
3 4 1  
3 5 1  
1 2 6  
4 5 8  
4  

```
## Output


```
3  

```
## Note

In the first sample the silos are located in cities 3 and 4 and on road (1, 3) at a distance 2 from city 1 (correspondingly, at a distance 1 from city 3).

In the second sample one missile silo is located right in the middle of the road (1, 2). Two more silos are on the road (4, 5) at a distance 3 from city 4 in the direction to city 5 and at a distance 3 from city 5 to city 4.



#### tags 

#1900 #data_structures #dfs_and_similar #graphs #shortest_paths 