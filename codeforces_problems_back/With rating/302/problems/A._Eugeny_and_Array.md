<h1 style='text-align: center;'> A. Eugeny and Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Eugeny has array *a* = *a*1, *a*2, ..., *a**n*, consisting of *n* integers. Each integer *a**i* equals to -1, or to 1. Also, he has *m* queries:

* Query number *i* is given as a pair of integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*).
* The response to the query will be integer 1, if the elements of array *a* can be rearranged so as the sum *a**l**i* + *a**l**i* + 1 + ... + *a**r**i* = 0, otherwise the response to the query will be integer 0.

Help Eugeny, answer all his queries.

## Input

The first line contains integers *n* and *m* (1 ≤ *n*, *m* ≤ 2·105). The second line contains *n* integers *a*1, *a*2, ..., *a**n* (*a**i* = -1, 1). Next *m* lines contain Eugene's queries. The *i*-th line contains integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*).

## Output

Print *m* integers — the responses to Eugene's queries in the order they occur in the input.

## Examples

## Input


```
2 3  
1 -1  
1 1  
1 2  
2 2  

```
## Output


```
0  
1  
0  

```
## Input


```
5 5  
-1 1 1 1 -1  
1 1  
2 3  
3 5  
2 5  
1 5  

```
## Output


```
0  
1  
0  
1  
0  

```


#### tags 

#800 #implementation 