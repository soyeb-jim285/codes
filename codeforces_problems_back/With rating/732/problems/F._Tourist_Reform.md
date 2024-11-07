<h1 style='text-align: center;'> F. Tourist Reform</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Berland is a tourist country! At least, it can become such — the government of Berland is confident about this. 

There are *n* cities in Berland, some pairs of which are connected by two-ways roads. Each road connects two different cities. In Berland there are no roads which connect the same pair of cities. It is possible to get from any city to any other city using given two-ways roads. 

According to the reform each road will become one-way. It will be oriented to one of two directions.

To maximize the tourist attraction of Berland, after the reform for each city *i* the value *r**i* will be calculated. It will equal to the number of cities *x* for which there is an oriented path from the city *i* to the city *x*. In other words, *r**i* will equal the number of cities which can be reached from the city *i* by roads. 

The government is sure that tourist's attention will be focused on the minimum value of *r**i*.

Help the government of Berland make the reform to maximize the minimum of *r**i*.

## Input

The first line contains two integers *n*, *m* (2 ≤ *n* ≤ 400 000, 1 ≤ *m* ≤ 400 000) — the number of cities and the number of roads. 

The next *m* lines describe roads in Berland: the *j*-th of them contains two integers *u**j* and *v**j* (1 ≤ *u**j*, *v**j* ≤ *n*, *u**j* ≠ *v**j*), where *u**j* and *v**j* are the numbers of cities which are connected by the *j*-th road.

The cities are numbered from 1 to *n*. It is guaranteed that it is possible to get from any city to any other by following two-ways roads. In Berland there are no roads which connect the same pair of cities. 

## Output

In the first line print single integer — the maximum possible value *min*1 ≤ *i* ≤ *n*{*r**i*} after the orientation of roads. 

The next *m* lines must contain the description of roads after the orientation: the *j*-th of them must contain two integers *u**j*, *v**j*, it means that the *j*-th road will be directed from the city *u**j* to the city *v**j*. Print roads in the same order as they are given in the input data. 

## Example

## Input


```
7 9  
4 3  
2 6  
7 1  
4 1  
7 3  
3 5  
7 4  
6 5  
2 5  

```
## Output


```
4  
4 3  
6 2  
7 1  
1 4  
3 7  
5 3  
7 4  
5 6  
2 5  

```


#### tags 

#2300 #dfs_and_similar #graphs 