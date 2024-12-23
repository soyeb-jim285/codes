<h1 style='text-align: center;'> B. Vasya and Public Transport</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya often uses public transport. The transport in the city is of two types: trolleys and buses. The city has *n* buses and *m* trolleys, the buses are numbered by integers from 1 to *n*, the trolleys are numbered by integers from 1 to *m*.

Public transport is not free. There are 4 types of tickets: 

1. A ticket for one ride on some bus or trolley. It costs *c*1 burles;
2. A ticket for an unlimited number of rides on some bus or on some trolley. It costs *c*2 burles;
3. A ticket for an unlimited number of rides on all buses or all trolleys. It costs *c*3 burles;
4. A ticket for an unlimited number of rides on all buses and trolleys. It costs *c*4 burles.

Vasya knows for sure the number of rides he is going to make and the transport he is going to use. He asked you for help to find the minimum sum of burles he will have to spend on the tickets.

## Input

The first line contains four integers *c*1, *c*2, *c*3, *c*4 (1 ≤ *c*1, *c*2, *c*3, *c*4 ≤ 1000) — the costs of the tickets.

The second line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 1000) — the number of buses and trolleys Vasya is going to use.

The third line contains *n* integers *a**i* (0 ≤ *a**i* ≤ 1000) — the number of times Vasya is going to use the bus number *i*.

The fourth line contains *m* integers *b**i* (0 ≤ *b**i* ≤ 1000) — the number of times Vasya is going to use the trolley number *i*.

## Output

Print a single number — the minimum sum of burles Vasya will have to spend on the tickets.

## Examples

## Input


```
1 3 7 19  
2 3  
2 5  
4 4 4  

```
## Output


```
12  

```
## Input


```
4 3 2 1  
1 3  
798  
1 2 3  

```
## Output


```
1  

```
## Input


```
100 100 8 100  
3 5  
7 94 12  
100 1 47 0 42  

```
## Output


```
16  

```
## Note

In the first sample the profitable strategy is to buy two tickets of the first type (for the first bus), one ticket of the second type (for the second bus) and one ticket of the third type (for all trolleys). It totals to (2·1) + 3 + 7 = 12 burles.

In the second sample the profitable strategy is to buy one ticket of the fourth type.

In the third sample the profitable strategy is to buy two tickets of the third type: for all buses and for all trolleys.



#### tags 

#1100 #greedy #implementation 