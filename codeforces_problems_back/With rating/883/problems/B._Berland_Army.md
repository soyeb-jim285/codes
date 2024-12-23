<h1 style='text-align: center;'> B. Berland Army</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* military men in the Berland army. Some of them have given orders to other military men by now. Given *m* pairs (*x**i*, *y**i*), meaning that the military man *x**i* gave the *i*-th order to another military man *y**i*.

It is time for reform! The Berland Ministry of Defence plans to introduce ranks in the Berland army. Each military man should be assigned a rank — integer number between 1 and *k*, inclusive. Some of them have been already assigned a rank, but the rest of them should get a rank soon.

Help the ministry to assign ranks to the rest of the army so that:

* for each of *m* orders it is true that the rank of a person giving the order (military man *x**i*) is strictly greater than the rank of a person receiving the order (military man *y**i*);
* for each rank from 1 to *k* there is at least one military man with this rank.
## Input

The first line contains three integers *n*, *m* and *k* (1 ≤ *n* ≤ 2·105, 0 ≤ *m* ≤ 2·105, 1 ≤ *k* ≤ 2·105) — number of military men in the Berland army, number of orders and number of ranks.

The second line contains *n* integers *r*1, *r*2, ..., *r**n*, where *r**i* > 0 (in this case 1 ≤ *r**i* ≤ *k*) means that the *i*-th military man has been already assigned the rank *r**i*; *r**i* = 0 means the *i*-th military man doesn't have a rank yet.

The following *m* lines contain orders one per line. Each order is described with a line containing two integers *x**i*, *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*, *x**i* ≠ *y**i*). This line means that the *i*-th order was given by the military man *x**i* to the military man *y**i*. For each pair (*x*, *y*) of military men there could be several orders from *x* to *y*.

## Output

Print *n* integers, where the *i*-th number is the rank of the *i*-th military man. If there are many solutions, print any of them.

If there is no solution, print the only number -1.

## Examples

## Input


```
5 3 3  
0 3 0 0 2  
2 4  
3 4  
3 5  

```
## Output


```
1 3 3 2 2   

```
## Input


```
7 6 5  
0 4 5 4 1 0 0  
6 1  
3 6  
3 1  
7 5  
7 1  
7 4  

```
## Output


```
2 4 5 4 1 3 5   

```
## Input


```
2 2 2  
2 1  
1 2  
2 1  

```
## Output


```
-1  

```


#### tags 

#2600 #constructive_algorithms #graphs #greedy 