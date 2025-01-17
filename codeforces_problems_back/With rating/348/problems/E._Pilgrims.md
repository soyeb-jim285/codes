<h1 style='text-align: center;'> E. Pilgrims</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A long time ago there was a land called Dudeland. Dudeland consisted of *n* towns connected with *n* - 1 bidirectonal roads. The towns are indexed from 1 to *n* and one can reach any city from any other city if he moves along the roads of the country. There are *m* monasteries in Dudeland located in *m* different towns. In each monastery lives a pilgrim.

At the beginning of the year, each pilgrim writes down which monastery is the farthest from the monastery he is living in. If there is more than one farthest monastery, he lists all of them. On the Big Lebowski day each pilgrim picks one town from his paper at random and starts walking to that town. 

Walter hates pilgrims and wants to make as many of them unhappy as possible by preventing them from finishing their journey. He plans to destroy exactly one town that does not contain a monastery. A pilgrim becomes unhappy if all monasteries in his list become unreachable from the monastery he is living in. 

You need to find the maximum number of pilgrims Walter can make unhappy. Also find the number of ways he can make this maximal number of pilgrims unhappy: the number of possible towns he can destroy.

## Input

The first line contains two integers *n* (3 ≤ *n* ≤ 105) and *m* (2 ≤ *m* < *n*). The next line contains *m* distinct integers representing indices of towns that contain monasteries.

Next *n* - 1 lines contain three integers each, *a**i*, *b**i*, *c**i*, indicating that there is an edge between towns *a**i* and *b**i* of length *c**i* (1 ≤ *a**i*, *b**i* ≤ *n*, 1 ≤ *c**i* ≤ 1000, *a**i* ≠ *b**i*).

## Output

## Output

 two integers: the maximum number of pilgrims Walter can make unhappy and the number of ways in which he can make his plan come true.

## Examples

## Input


```
8 5  
7 2 5 4 8  
1 2 1  
2 3 2  
1 4 1  
4 5 2  
1 6 1  
6 7 8  
6 8 10  

```
## Output


```
5 1  

```


#### tags 

#2800 #dfs_and_similar #dp #trees 