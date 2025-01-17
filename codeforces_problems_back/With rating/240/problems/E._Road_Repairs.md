<h1 style='text-align: center;'> E. Road Repairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A country named Berland has *n* cities. They are numbered with integers from 1 to *n*. City with index 1 is the capital of the country. Some pairs of cities have monodirectional roads built between them. However, not all of them are in good condition. For each road we know whether it needs repairing or not. If a road needs repairing, then it is forbidden to use it. However, the Berland government can repair the road so that it can be used.

Right now Berland is being threatened by the war with the neighbouring state. So the capital officials decided to send a military squad to each city. The squads can move only along the existing roads, as there's no time or money to build new roads. However, some roads will probably have to be repaired in order to get to some cities.

Of course the country needs much resources to defeat the enemy, so you want to be careful with what you're going to throw the forces on. That's why the Berland government wants to repair the minimum number of roads that is enough for the military troops to get to any city from the capital, driving along good or repaired roads. Your task is to help the Berland government and to find out, which roads need to be repaired.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the number of cities and the number of roads in Berland.

Next *m* lines contain three space-separated integers *a**i*, *b**i*, *c**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*, 0 ≤ *c**i* ≤ 1), describing the road from city *a**i* to city *b**i*. If *c**i* equals 0, than the given road is in a good condition. If *c**i* equals 1, then it needs to be repaired.

It is guaranteed that there is not more than one road between the cities in each direction.

## Output

If even after all roads are repaired, it is still impossible to get to some city from the capital, print  - 1. Otherwise, on the first line print the minimum number of roads that need to be repaired, and on the second line print the numbers of these roads, separated by single spaces.

The roads are numbered starting from 1 in the order, in which they are given in the input.

If there are multiple sets, consisting of the minimum number of roads to repair to make travelling to any city from the capital possible, print any of them.

If it is possible to reach any city, driving along the roads that already are in a good condition, print 0 in the only output line.

## Examples

## Input


```
3 2  
1 3 0  
3 2 1  

```
## Output


```
1  
2  

```
## Input


```
4 4  
2 3 0  
3 4 0  
4 1 0  
4 2 1  

```
## Output


```
-1  

```
## Input


```
4 3  
1 2 0  
1 3 0  
1 4 0  

```
## Output


```
0  
  

```


#### tags 

#2800 #dfs_and_similar #graphs #greedy 