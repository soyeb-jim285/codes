<h1 style='text-align: center;'> E. MST Company</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The MST (Meaningless State Team) company won another tender for an important state reform in Berland.

There are *n* cities in Berland, some pairs of the cities are connected by roads. Each road has its price. One can move along any road in any direction. The MST team should carry out the repair works on some set of roads such that one can get from any city to any other one moving only along the repaired roads. Moreover, this set should contain exactly *k* capital roads (that is, the roads that start or finish in the capital). The number of the capital is 1.

As the budget has already been approved, the MST Company will profit by finding the set with minimum lengths of roads.

## Input

The first input line contains three integers *n*, *m*, *k* (1 ≤ *n* ≤ 5000;0 ≤ *m* ≤ 105;0 ≤ *k* < 5000), where *n* is the number of cities in the country, *m* is the number of roads in the country, *k* is the number of capital roads in the required set. Then *m* lines enumerate the roads in question. Each road is specified by three numbers *a**i*, *b**i*, *w**i* (1 ≤ *a**i*, *b**i* ≤ *n*; 1 ≤ *w* ≤ 105), where *a**i*, *b**i* are the numbers of cities linked by a road and *w**i* is its length. 

Between each pair of cities no more than one road exists. There are no roads that start and finish in one city. The capital's number is 1.

## Output

In the first line print the number of roads in the required set. The second line should contain the numbers of roads included in the sought set. If the sought set does not exist, print -1.

## Examples

## Input


```
4 5 2  
1 2 1  
2 3 1  
3 4 1  
1 3 3  
1 4 2  

```
## Output


```
3  
1 5 2 
```


#### tags 

#2400 #binary_search #graphs 