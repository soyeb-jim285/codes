<h1 style='text-align: center;'> E. Opening Portals</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pavel plays a famous computer game. A player is responsible for a whole country and he can travel there freely, complete quests and earn experience.

This country has *n* cities connected by *m* bidirectional roads of different lengths so that it is possible to get from any city to any other one. There are portals in *k* of these cities. At the beginning of the game all portals are closed. When a player visits a portal city, the portal opens. Strange as it is, one can teleport from an open portal to an open one. The teleportation takes no time and that enables the player to travel quickly between rather remote regions of the country.

At the beginning of the game Pavel is in city number 1. He wants to open all portals as quickly as possible. How much time will he need for that?

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n* ≤ 105, 0 ≤ *m* ≤ 105) that show how many cities and roads are in the game.

Each of the next *m* lines contains the description of a road as three space-separated integers *x**i*, *y**i*, *w**i* (1 ≤ *x**i*, *y**i* ≤ *n*, *x**i* ≠ *y**i*, 1 ≤ *w**i* ≤ 109) — the numbers of the cities connected by the *i*-th road and the time needed to go from one city to the other one by this road. Any two cities are connected by no more than one road. It is guaranteed that we can get from any city to any other one, moving along the roads of the country.

The next line contains integer *k* (1 ≤ *k* ≤ *n*) — the number of portals.

The next line contains *k* space-separated integers *p*1, *p*2, ..., *p**k* — numbers of the cities with installed portals. Each city has no more than one portal.

## Output

Print a single number — the minimum time a player needs to open all portals.

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
3 3  
1 2 1  
1 3 1  
2 3 1  
3  
1 2 3  

```
## Output


```
2  

```
## Input


```
4 3  
1 2 1  
2 3 5  
2 4 10  
3  
2 3 4  

```
## Output


```
16  

```
## Input


```
4 3  
1 2 1000000000  
2 3 1000000000  
3 4 1000000000  
4  
1 2 3 4  

```
## Output


```
3000000000  

```
## Note

In the second sample the player has to come to city 2, open a portal there, then go to city 3, open a portal there, teleport back to city 2 and finally finish the journey in city 4.



#### tags 

#2600 #dsu #graphs #shortest_paths 