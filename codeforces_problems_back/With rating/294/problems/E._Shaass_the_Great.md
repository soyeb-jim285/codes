<h1 style='text-align: center;'> E. Shaass the Great</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The great Shaass is the new king of the Drakht empire. The empire has *n* cities which are connected by *n* - 1 bidirectional roads. Each road has an specific length and connects a pair of cities. There's a unique simple path connecting each pair of cities.

His majesty the great Shaass has decided to tear down one of the roads and build another road with the same length between some pair of cities. He should build such road that it's still possible to travel from each city to any other city. He might build the same road again.

You as his advisor should help him to find a way to make the described action. You should find the way that minimize the total sum of pairwise distances between cities after the action. So calculate the minimum sum.

## Input

The first line of the input contains an integer *n* denoting the number of cities in the empire, (2 ≤ *n* ≤ 5000). The next *n* - 1 lines each contains three integers *a**i*, *b**i* and *w**i* showing that two cities *a**i* and *b**i* are connected using a road of length *w**i*, (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*, 1 ≤ *w**i* ≤ 106).

## Output

On the only line of the output print the minimum pairwise sum of distances between the cities.

Please do not use the %lld specificator to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specificator.

## Examples

## Input


```
3  
1 2 2  
1 3 4  

```
## Output


```
12  

```
## Input


```
6  
1 2 1  
2 3 1  
3 4 1  
4 5 1  
5 6 1  

```
## Output


```
29  

```
## Input


```
6  
1 3 1  
2 3 1  
3 4 100  
4 5 2  
4 6 1  

```
## Output


```
825  

```


#### tags 

#2300 #dp #trees 