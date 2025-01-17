<h1 style='text-align: center;'> E. Shortest Path</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Ancient Berland there were *n* cities and *m* two-way roads of equal length. The cities are numbered with integers from 1 to *n* inclusively. According to an ancient superstition, if a traveller visits three cities *a**i*, *b**i*, *c**i* in row, without visiting other cities between them, a great disaster awaits him. Overall there are *k* such city triplets. Each triplet is ordered, which means that, for example, you are allowed to visit the cities in the following order: *a**i*, *c**i*, *b**i*. Vasya wants to get from the city 1 to the city *n* and not fulfil the superstition. Find out which minimal number of roads he should take. Also you are required to find one of his possible path routes.

## Input

The first line contains three integers *n*, *m*, *k* (2 ≤ *n* ≤ 3000, 1 ≤ *m* ≤ 20000, 0 ≤ *k* ≤ 105) which are the number of cities, the number of roads and the number of the forbidden triplets correspondingly. 

Then follow *m* lines each containing two integers *x**i*, *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*) which are the road descriptions. The road is described by the numbers of the cities it joins. No road joins a city with itself, there cannot be more than one road between a pair of cities. 

Then follow *k* lines each containing three integers *a**i*, *b**i*, *c**i* (1 ≤ *a**i*, *b**i*, *c**i* ≤ *n*) which are the forbidden triplets. Each ordered triplet is listed mo more than one time. All three cities in each triplet are distinct.

City *n* can be unreachable from city 1 by roads.

## Output

If there are no path from 1 to *n* print -1. Otherwise on the first line print the number of roads *d* along the shortest path from the city 1 to the city *n*. On the second line print *d* + 1 numbers — any of the possible shortest paths for Vasya. The path should start in the city 1 and end in the city *n*.

## Examples

## Input


```
4 4 1  
1 2  
2 3  
3 4  
1 3  
1 4 3  

```
## Output


```
2  
1 3 4  

```
## Input


```
3 1 0  
1 2  

```
## Output


```
-1  

```
## Input


```
4 4 2  
1 2  
2 3  
3 4  
1 3  
1 2 3  
1 3 4  

```
## Output


```
4  
1 3 2 3 4  

```


#### tags 

#2000 #graphs #shortest_paths 