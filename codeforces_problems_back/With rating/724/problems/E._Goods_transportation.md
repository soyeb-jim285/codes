<h1 style='text-align: center;'> E. Goods transportation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* cities located along the one-way road. Cities are numbered from 1 to *n* in the direction of the road.

The *i*-th city had produced *p**i* units of goods. No more than *s**i* units of goods can be sold in the *i*-th city.

For each pair of cities *i* and *j* such that 1 ≤ *i* < *j* ≤ *n* you can no more than once transport no more than *c* units of goods from the city *i* to the city *j*. Note that goods can only be transported from a city with a lesser index to the city with a larger index. You can transport goods between cities in any order.

Determine the maximum number of produced goods that can be sold in total in all the cities after a sequence of transportations.

## Input

The first line of the input contains two integers *n* and *c* (1 ≤ *n* ≤ 10 000, 0 ≤ *c* ≤ 109) — the number of cities and the maximum amount of goods for a single transportation.

The second line contains *n* integers *p**i* (0 ≤ *p**i* ≤ 109) — the number of units of goods that were produced in each city.

The third line of input contains *n* integers *s**i* (0 ≤ *s**i* ≤ 109) — the number of units of goods that can be sold in each city.

## Output

Print the maximum total number of produced goods that can be sold in all cities after a sequence of transportations.

## Examples

## Input


```
3 0  
1 2 3  
3 2 1  

```
## Output


```
4  

```
## Input


```
5 1  
7 4 2 1 0  
1 2 3 4 5  

```
## Output


```
12  

```
## Input


```
4 3  
13 10 7 4  
4 7 10 13  

```
## Output


```
34  

```


#### tags 

#2900 #dp #flows #greedy 