<h1 style='text-align: center;'> E. Bertown roads</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bertown has *n* junctions and *m* bidirectional roads. We know that one can get from any junction to any other one by the existing roads. 

As there were more and more cars in the city, traffic jams started to pose real problems. To deal with them the government decided to make the traffic one-directional on all the roads, thus easing down the traffic. Your task is to determine whether there is a way to make the traffic one-directional so that there still is the possibility to get from any junction to any other one. If the answer is positive, you should also find one of the possible ways to orient the roads.

## Input

The first line contains two space-separated integers *n* and *m* (2 ≤ *n* ≤ 105, *n* - 1 ≤ *m* ≤ 3·105) which represent the number of junctions and the roads in the town correspondingly. Then follow *m* lines, each containing two numbers which describe the roads in the city. Each road is determined by two integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*) — the numbers of junctions it connects.

It is guaranteed that one can get from any junction to any other one along the existing bidirectional roads. Each road connects different junctions, there is no more than one road between each pair of junctions.

## Output

If there's no solution, print the single number 0. Otherwise, print *m* lines each containing two integers *p**i* and *q**i* — each road's orientation. That is the traffic flow will move along a one-directional road from junction *p**i* to junction *q**i*. You can print the roads in any order. If there are several solutions to that problem, print any of them.

## Examples

## Input


```
6 8  
1 2  
2 3  
1 3  
4 5  
4 6  
5 6  
2 4  
3 5  

```
## Output


```
1 2  
2 3  
3 1  
4 5  
5 6  
6 4  
4 2  
3 5  

```
## Input


```
6 7  
1 2  
2 3  
1 3  
4 5  
4 6  
5 6  
2 4  

```
## Output


```
0  

```


#### tags 

#2000 #dfs_and_similar #graphs 