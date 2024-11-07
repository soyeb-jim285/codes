<h1 style='text-align: center;'> F. Drivers Dissatisfaction</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In one kingdom there are *n* cities and *m* two-way roads. Each road connects a pair of cities, and for each road we know the level of drivers dissatisfaction — the value *w**i*.

For each road we know the value *c**i* — how many lamziks we should spend to reduce the level of dissatisfaction with this road by one. Thus, to reduce the dissatisfaction with the *i*-th road by *k*, we should spend *k*·*c**i* lamziks. And it is allowed for the dissatisfaction to become zero or even negative.

In accordance with the king's order, we need to choose *n* - 1 roads and make them the main roads. An important condition must hold: it should be possible to travel from any city to any other by the main roads.

The road ministry has a budget of *S* lamziks for the reform. The ministry is going to spend this budget for repair of some roads (to reduce the dissatisfaction with them), and then to choose the *n* - 1 main roads.

Help to spend the budget in such a way and then to choose the main roads so that the total dissatisfaction with the main roads will be as small as possible. The dissatisfaction with some roads can become negative. It is not necessary to spend whole budget *S*.

It is guaranteed that it is possible to travel from any city to any other using existing roads. Each road in the kingdom is a two-way road.

## Input

The first line contains two integers *n* and *m* (2 ≤ *n* ≤ 2·105, *n* - 1 ≤ *m* ≤ 2·105) — the number of cities and the number of roads in the kingdom, respectively.

The second line contains *m* integers *w*1, *w*2, ..., *w**m* (1 ≤ *w**i* ≤ 109), where *w**i* is the drivers dissatisfaction with the *i*-th road.

The third line contains *m* integers *c*1, *c*2, ..., *c**m* (1 ≤ *c**i* ≤ 109), where *c**i* is the cost (in lamziks) of reducing the dissatisfaction with the *i*-th road by one.

The next *m* lines contain the description of the roads. The *i*-th of this lines contain a pair of integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*) which mean that the *i*-th road connects cities *a**i* and *b**i*. All roads are two-way oriented so it is possible to move by the *i*-th road from *a**i* to *b**i*, and vice versa. It is allowed that a pair of cities is connected by more than one road. 

The last line contains one integer *S* (0 ≤ *S* ≤ 109) — the number of lamziks which we can spend for reforms. 

## Output

In the first line print *K* — the minimum possible total dissatisfaction with main roads.

In each of the next *n* - 1 lines print two integers *x*, *v**x*, which mean that the road *x* is among main roads and the road *x*, after the reform, has the level of dissatisfaction *v**x*.

Consider that roads are numbered from 1 to *m* in the order as they are given in the input data. The edges can be printed in arbitrary order. If there are several answers, print any of them. 

## Examples

## Input


```
6 9  
1 3 1 1 3 1 2 2 2  
4 1 4 2 2 5 3 1 6  
1 2  
1 3  
2 3  
2 4  
2 5  
3 5  
3 6  
4 5  
5 6  
7  

```
## Output


```
0  
1 1  
3 1  
6 1  
7 2  
8 -5  

```
## Input


```
3 3  
9 5 1  
7 7 2  
2 1  
3 1  
3 2  
2  

```
## Output


```
5  
3 0  
2 5  

```


#### tags 

#2200 #data_structures #dsu #graphs #trees 