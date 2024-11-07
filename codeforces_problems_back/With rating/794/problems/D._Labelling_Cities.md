<h1 style='text-align: center;'> D. Labelling Cities</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Oleg the bank client lives in Bankopolia. There are *n* cities in Bankopolia and some pair of cities are connected directly by bi-directional roads. The cities are numbered from 1 to *n*. There are a total of *m* roads in Bankopolia, the *i*-th road connects cities *u**i* and *v**i*. It is guaranteed that from each city it is possible to travel to any other city using some of the roads.

Oleg wants to give a label to each city. Suppose the label of city *i* is equal to *x**i*. Then, it must hold that for all pairs of cities (*u*, *v*) the condition |*x**u* - *x**v*| ≤ 1 holds if and only if there is a road connecting *u* and *v*.

Oleg wonders if such a labeling is possible. Find an example of such labeling if the task is possible and state that it is impossible otherwise.

## Input

The first line of input contains two space-separated integers *n* and *m* (2 ≤ *n* ≤ 3·105, 1 ≤ *m* ≤ 3·105) — the number of cities and the number of roads.

Next, *m* lines follow. The *i*-th line contains two space-separated integers *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*, *u**i* ≠ *v**i*) — the cities connected by the *i*-th road. It is guaranteed that there is at most one road between each pair of cities and it is possible to travel from any city to any other city using some roads.

## Output

If the required labeling is not possible, output a single line containing the string "NO" (without quotes).

Otherwise, output the string "YES" (without quotes) on the first line. On the next line, output *n* space-separated integers, *x*1, *x*2, ..., *x**n*. The condition 1 ≤ *x**i* ≤ 109 must hold for all *i*, and for all pairs of cities (*u*, *v*) the condition |*x**u* - *x**v*| ≤ 1 must hold if and only if there is a road connecting *u* and *v*.

## Examples

## Input


```
4 4  
1 2  
1 3  
1 4  
3 4  

```
## Output


```
YES  
2 3 1 1   

```
## Input


```
5 10  
1 2  
1 3  
1 4  
1 5  
2 3  
2 4  
2 5  
3 4  
3 5  
5 4  

```
## Output


```
YES  
1 1 1 1 1   

```
## Input


```
4 3  
1 2  
1 3  
1 4  

```
## Output


```
NO  

```
## Note

For the first sample, *x*1 = 2, *x*2 = 3, *x*3 = *x*4 = 1 is a valid labeling. Indeed, (3, 4), (1, 2), (1, 3), (1, 4) are the only pairs of cities with difference of labels not greater than 1, and these are precisely the roads of Bankopolia.

For the second sample, all pairs of cities have difference of labels not greater than 1 and all pairs of cities have a road connecting them.

For the last sample, it is impossible to construct a labeling satisfying the given constraints.



#### tags 

#2400 #dfs_and_similar #graphs #hashing 