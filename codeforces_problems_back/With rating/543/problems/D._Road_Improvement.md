<h1 style='text-align: center;'> D. Road Improvement</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The country has *n* cities and *n* - 1 bidirectional roads, it is possible to get from every city to any other one if you move only along the roads. The cities are numbered with integers from 1 to *n* inclusive.

All the roads are initially bad, but the government wants to improve the state of some roads. We will assume that the citizens are happy about road improvement if the path from the capital located in city *x* to any other city contains at most one bad road.

Your task is — for every possible *x* determine the number of ways of improving the quality of some roads in order to meet the citizens' condition. As those values can be rather large, you need to print each value modulo 1 000 000 007 (109 + 7).

## Input

The first line of the input contains a single integer *n* (2 ≤ *n* ≤ 2·105) — the number of cities in the country. Next line contains *n* - 1 positive integers *p*2, *p*3, *p*4, ..., *p**n* (1 ≤ *p**i* ≤ *i* - 1) — the description of the roads in the country. Number *p**i* means that the country has a road connecting city *p**i* and city *i*. 

## Output

Print *n* integers *a*1, *a*2, ..., *a**n*, where *a**i* is the sought number of ways to improve the quality of the roads modulo 1 000 000 007 (109 + 7), if the capital of the country is at city number *i*.

## Examples

## Input


```
3  
1 1  

```
## Output


```
4 3 3
```
## Input


```
5  
1 2 3 4  

```
## Output


```
5 8 9 8 5
```


#### tags 

#2300 #dp #trees 