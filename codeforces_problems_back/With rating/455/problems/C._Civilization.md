<h1 style='text-align: center;'> C. Civilization</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Andrew plays a game called "Civilization". Dima helps him.

The game has *n* cities and *m* bidirectional roads. The cities are numbered from 1 to *n*. Between any pair of cities there either is a single (unique) path, or there is no path at all. A path is such a sequence of distinct cities *v*1, *v*2, ..., *v**k*, that there is a road between any contiguous cities *v**i* and *v**i* + 1 (1 ≤ *i* < *k*). The length of the described path equals to (*k* - 1). We assume that two cities lie in the same region if and only if, there is a path connecting these two cities.

During the game events of two types take place:

1. Andrew asks Dima about the length of the longest path in the region where city *x* lies.
2. Andrew asks Dima to merge the region where city *x* lies with the region where city *y* lies. If the cities lie in the same region, then no merging is needed. Otherwise, you need to merge the regions as follows: choose a city from the first region, a city from the second region and connect them by a road so as to minimize the length of the longest path in the resulting region. If there are multiple ways to do so, you are allowed to choose any of them.

Dima finds it hard to execute Andrew's queries, so he asks you to help him. Help Dima.

## Input

The first line contains three integers *n*, *m*, *q* (1 ≤ *n* ≤ 3·105; 0 ≤ *m* < *n*; 1 ≤ *q* ≤ 3·105) — the number of cities, the number of the roads we already have and the number of queries, correspondingly.

Each of the following *m* lines contains two integers, *a**i* and *b**i* (*a**i* ≠ *b**i*; 1 ≤ *a**i*, *b**i* ≤ *n*). These numbers represent the road between cities *a**i* and *b**i*. There can be at most one road between two cities.

Each of the following *q* lines contains one of the two events in the following format:

* 1 *x**i*. It is the request Andrew gives to Dima to find the length of the maximum path in the region that contains city *x**i* (1 ≤ *x**i* ≤ *n*).
* 2 *x**i* *y**i*. It is the request Andrew gives to Dima to merge the region that contains city *x**i* and the region that contains city *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*). Note, that *x**i* can be equal to *y**i*.
## Output

For each event of the first type print the answer on a separate line.

## Examples

## Input


```
6 0 6  
2 1 2  
2 3 4  
2 5 6  
2 3 2  
2 5 3  
1 1  

```
## Output


```
4  

```


#### tags 

#2100 #dfs_and_similar #dp #dsu #ternary_search #trees 