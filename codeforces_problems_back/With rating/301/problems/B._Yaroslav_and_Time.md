<h1 style='text-align: center;'> B. Yaroslav and Time</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Yaroslav is playing a game called "Time". The game has a timer showing the lifespan he's got left. As soon as the timer shows 0, Yaroslav's character dies and the game ends. Also, the game has *n* clock stations, station number *i* is at point (*x**i*, *y**i*) of the plane. As the player visits station number *i*, he increases the current time on his timer by *a**i*. The stations are for one-time use only, so if the player visits some station another time, the time on his timer won't grow.

A player spends *d*·*dist* time units to move between stations, where *dist* is the distance the player has covered and *d* is some constant. The distance between stations *i* and *j* is determined as |*x**i* - *x**j*| + |*y**i* - *y**j*|.

Initially, the player is at station number 1, and the player has strictly more than zero and strictly less than one units of time. At station number 1 one unit of money can increase the time on the timer by one time unit (you can buy only integer number of time units).

Now Yaroslav is wondering, how much money he needs to get to station *n*. Help Yaroslav. Consider the time to buy and to increase the timer value negligibly small.

## Input

The first line contains integers *n* and *d* (3 ≤ *n* ≤ 100, 103 ≤ *d* ≤ 105) — the number of stations and the constant from the statement.

The second line contains *n* - 2 integers: *a*2, *a*3, ..., *a**n* - 1 (1 ≤ *a**i* ≤ 103). The next *n* lines contain the coordinates of the stations. The *i*-th of them contains two integers *x**i*, *y**i* (-100 ≤ *x**i*, *y**i* ≤ 100).

It is guaranteed that no two stations are located at the same point.

## Output

In a single line print an integer — the answer to the problem.

## Examples

## Input


```
3 1000  
1000  
0 0  
0 1  
0 3  

```
## Output


```
2000  

```
## Input


```
3 1000  
1000  
1 0  
1 1  
1 2  

```
## Output


```
1000  

```


#### tags 

#2100 #binary_search #graphs #shortest_paths 