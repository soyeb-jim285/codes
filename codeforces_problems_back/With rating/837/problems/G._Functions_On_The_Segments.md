<h1 style='text-align: center;'> G. Functions On The Segments</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You have an array *f* of *n* functions.The function *f**i*(*x*) (1 ≤ *i* ≤ *n*) is characterized by parameters: *x*1, *x*2, *y*1, *a*, *b*, *y*2 and take values: 

* *y*1, if *x* ≤ *x*1.
* *a*·*x* + *b*, if *x*1 < *x* ≤ *x*2.
* *y*2, if *x* > *x*2.

There are *m* queries. Each query is determined by numbers *l*, *r* and *x*. For a query with number *i* (1 ≤ *i* ≤ *m*), you need to calculate the sum of all *f**j*(*x**i*) where *l* ≤ *j* ≤ *r*. The value of *x**i* is calculated as follows: *x**i* = (*x* + *last*) mod 109, where *last* is the answer to the query with number *i* - 1. The value of *last* equals 0 if *i* = 1.

## Input

First line contains one integer number *n* (1 ≤ *n* ≤ 75000).

Each of the next *n* lines contains six integer numbers: *x*1, *x*2, *y*1, *a*, *b*, *y*2 (0 ≤ *x*1 < *x*2 ≤ 2·105, 0 ≤ *y*1, *y*2 ≤ 109, 0 ≤ *a*, *b* ≤ 104).

Next line contains one integer number *m* (1 ≤ *m* ≤ 500000).

Each of the next *m* lines contains three integer numbers: *l*, *r* and *x* (1 ≤ *l* ≤ *r* ≤ *n*, 0 ≤ *x* ≤ 109).

## Examples

## Input


```
1  
1 2 1 4 5 10  
1  
1 1 2  

```
Output
```
13  

```
## Input


```
3  
2 5 1 1 1 4  
3 6 8 2 5 7  
1 3 5 1 4 10  
3  
1 3 3  
2 3 2  
1 2 5  

```
Output
```
19  
17  
11  

```


#### tags 

#2500 #data_structures 