<h1 style='text-align: center;'> A. Ice Skating</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bajtek is learning to skate on ice. He's a beginner, so his only mode of transportation is pushing off from a snow drift to the north, east, south or west and sliding until he lands in another snow drift. He has noticed that in this way it's impossible to get from some snow drifts to some other by any sequence of moves. He now wants to heap up some additional snow drifts, so that he can get from any snow drift to any other one. He asked you to find the minimal number of snow drifts that need to be created.

We assume that Bajtek can only heap up snow drifts at integer coordinates.

## Input

The first line of input contains a single integer *n* (1 ≤ *n* ≤ 100) — the number of snow drifts. Each of the following *n* lines contains two integers *x**i* and *y**i* (1 ≤ *x**i*, *y**i* ≤ 1000) — the coordinates of the *i*-th snow drift.

Note that the north direction coinсides with the direction of *Oy* axis, so the east direction coinсides with the direction of the *Ox* axis. All snow drift's locations are distinct.

## Output

## Output

 the minimal number of snow drifts that need to be created in order for Bajtek to be able to reach any snow drift from any other one.

## Examples

## Input


```
2  
2 1  
1 2  

```
## Output


```
1  

```
## Input


```
2  
2 1  
4 1  

```
## Output


```
0  

```


#### tags 

#1200 #brute_force #dfs_and_similar #dsu #graphs 