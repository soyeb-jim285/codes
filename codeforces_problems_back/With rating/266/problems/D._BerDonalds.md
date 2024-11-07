<h1 style='text-align: center;'> D. BerDonalds</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

BerDonalds, a well-known fast food restaurant, is going to open a cafe in Bertown. The important thing is to choose the new restaurant's location so that it would be easy to get there. The Bertown road system is represented by *n* junctions, connected by *m* bidirectional roads. For each road we know its length. We also know that we can get from any junction to any other one, moving along the roads.

Your task is to find such location of the restaurant, that the shortest distance along the roads from the cafe to the farthest junction would be minimum. Note that the restaurant can be located not only on the junction, but at any point of any road.

## Input

The first line contains two integers *n* and *m* (![](images/e77c9ba339b03020eea469a8624f475d88cf28b8.png)) — the number of junctions and the number of roads, correspondingly. Then *m* lines follow, describing all Bertown roads. Each road is described by three integers *a**i*, *b**i*, *w**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*; 1 ≤ *w**i* ≤ 105), where *a**i* and *b**i* are the numbers of the junctions, connected by the *i*-th road, and *w**i* is the length of the *i*-th road. 

It is guaranteed that each road connects two distinct junctions, there is at most one road between any two junctions, and you can get from any junction to any other one.

## Output

Print a single real number — the shortest distance from the optimal restaurant location to the farthest junction. The answer will be considered correct, if its absolute or relative error doesn't exceed 10- 9.

## Examples

## Input


```
2 1  
1 2 1  

```
## Output


```
0.50  

```
## Input


```
3 3  
1 2 1  
2 3 1  
1 3 1  

```
## Output


```
1.00  

```
## Input


```
3 2  
1 2 100  
2 3 1  

```
## Output


```
50.50  

```


#### tags 

#2400 #graphs #math #shortest_paths 