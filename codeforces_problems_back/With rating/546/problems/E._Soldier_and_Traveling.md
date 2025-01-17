<h1 style='text-align: center;'> E. Soldier and Traveling</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the country there are *n* cities and *m* bidirectional roads between them. Each city has an army. Army of the *i*-th city consists of *a**i* soldiers. Now soldiers roam. After roaming each soldier has to either stay in his city or to go to the one of neighboring cities by at moving along at most one road.

Check if is it possible that after roaming there will be exactly *b**i* soldiers in the *i*-th city.

## Input

First line of input consists of two integers *n* and *m* (1 ≤ *n* ≤ 100, 0 ≤ *m* ≤ 200).

Next line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 100).

Next line contains *n* integers *b*1, *b*2, ..., *b**n* (0 ≤ *b**i* ≤ 100).

Then *m* lines follow, each of them consists of two integers *p* and *q* (1 ≤ *p*, *q* ≤ *n*, *p* ≠ *q*) denoting that there is an undirected road between cities *p* and *q*. 

It is guaranteed that there is at most one road between each pair of cities.

## Output

If the conditions can not be met output single word "NO".

Otherwise output word "YES" and then *n* lines, each of them consisting of *n* integers. Number in the *i*-th line in the *j*-th column should denote how many soldiers should road from city *i* to city *j* (if *i* ≠ *j*) or how many soldiers should stay in city *i* (if *i* = *j*).

If there are several possible answers you may output any of them.

## Examples

## Input


```
4 4  
1 2 6 3  
3 5 3 1  
1 2  
2 3  
3 4  
4 2  

```
## Output


```
YES  
1 0 0 0   
2 0 0 0   
0 5 1 0   
0 0 2 1   

```
## Input


```
2 0  
1 2  
2 1  

```
## Output


```
NO
```


#### tags 

#2100 #flows #graphs #math 