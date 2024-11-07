<h1 style='text-align: center;'> C. Bulmart</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A new trade empire is rising in Berland. Bulmart, an emerging trade giant, decided to dominate the market of ... shovels! And now almost every city in Berland has a Bulmart store, and some cities even have several of them! The only problem is, at the moment sales are ... let's say a little below estimates. Some people even say that shovels retail market is too small for such a big company to make a profit. But the company management believes in the future of that market and seeks new ways to increase income. 

There are *n* cities in Berland connected with *m* bi-directional roads. All roads have equal lengths. It can happen that it is impossible to reach a city from another city using only roads. There is no road which connects a city to itself. Any pair of cities can be connected by at most one road.

There are *w* Bulmart stores in Berland. Each of them is described by three numbers: 

* *c**i* — the number of city where the *i*-th store is located (a city can have no stores at all or have several of them),
* *k**i* — the number of shovels in the *i*-th store,
* *p**i* — the price of a single shovel in the *i*-th store (in burles).

The latest idea of the Bulmart management is to create a program which will help customers get shovels as fast as possible for affordable budget. Formally, the program has to find the minimum amount of time needed to deliver *r**j* shovels to the customer in the city *g**j* for the total cost of no more than *a**j* burles. The delivery time between any two adjacent cities is equal to 1. If shovels are delivered from several cities, the delivery time is equal to the arrival time of the last package. The delivery itself is free of charge.

The program needs to find answers to *q* such queries. Each query has to be processed independently from others, i.e. a query does not change number of shovels in stores for the next queries.

## Input

The first line contains two integers *n*, *m* (1 ≤ *n* ≤ 5000, 0 ≤ *m* ≤ *min*(5000, *n*·(*n* - 1) / 2)). Each of the next *m* lines contains two integers *x**e* and *y**e*, meaning that the *e*-th road connects cities *x**e* and *y**e* (1 ≤ *x**e*, *y**e* ≤ *n*).

The next line contains a single integer *w* (1 ≤ *w* ≤ 5000) — the total number of Bulmart stores in Berland. Each of the next *w* lines contains three integers describing the *i*-th store: *c**i*, *k**i*, *p**i* (1 ≤ *c**i* ≤ *n*, 1 ≤ *k**i*, *p**i* ≤ 2·105).

The next line contains a single integer *q* (1 ≤ *q* ≤ 1000) — the number of queries. Each of the next *q* lines contains three integers describing the *j*-th query: *g**j*, *r**j* and *a**j* (1 ≤ *g**j* ≤ *n*, 1 ≤ *r**j*, *a**j* ≤ 109)

## Output

## Output

 *q* lines. On the *j*-th line, print an answer for the *j*-th query — the minimum amount of time needed to deliver *r**j* shovels to the customer in city *g**j* spending no more than *a**j* burles. Print -1 if there is no solution for the *j*-th query.

## Example

## Input


```
6 4  
4 2  
5 4  
1 2  
3 2  
2  
4 1 2  
3 2 3  
6  
1 2 6  
2 3 7  
3 1 2  
4 3 8  
5 2 5  
6 1 10  

```
## Output


```
2  
-1  
2  
2  
3  
-1  

```


#### tags 

#2100 #binary_search #dfs_and_similar 