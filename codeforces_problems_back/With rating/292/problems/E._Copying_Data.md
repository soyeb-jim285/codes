<h1 style='text-align: center;'> E. Copying Data</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We often have to copy large volumes of information. Such operation can take up many computer resources. Therefore, in this problem you are advised to come up with a way to copy some part of a number array into another one, quickly.

More formally, you've got two arrays of integers *a*1, *a*2, ..., *a**n* and *b*1, *b*2, ..., *b**n* of length *n*. Also, you've got *m* queries of two types:

1. Copy the subsegment of array *a* of length *k*, starting from position *x*, into array *b*, starting from position *y*, that is, execute *b**y* + *q* = *a**x* + *q* for all integer *q* (0 ≤ *q* < *k*). The given operation is correct — both subsegments do not touch unexistent elements.
2. Determine the value in position *x* of array *b*, that is, find value *b**x*.

For each query of the second type print the result — the value of the corresponding element of array *b*.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the number of elements in the arrays and the number of queries, correspondingly. The second line contains an array of integers *a*1, *a*2, ..., *a**n* (|*a**i*| ≤ 109). The third line contains an array of integers *b*1, *b*2, ..., *b**n* (|*b**i*| ≤ 109).

Next *m* lines contain the descriptions of the queries. The *i*-th line first contains integer *t**i* — the type of the *i*-th query (1 ≤ *t**i* ≤ 2). If *t**i* = 1, then the *i*-th query means the copying operation. If *t**i* = 2, then the *i*-th query means taking the value in array *b*. If *t**i* = 1, then the query type is followed by three integers *x**i*, *y**i*, *k**i* (1 ≤ *x**i*, *y**i*, *k**i* ≤ *n*) — the parameters of the copying query. If *t**i* = 2, then the query type is followed by integer *x**i* (1 ≤ *x**i* ≤ *n*) — the position in array *b*.

All numbers in the lines are separated with single spaces. It is guaranteed that all the queries are correct, that is, the copying borders fit into the borders of arrays *a* and *b*.

## Output

For each second type query print the result on a single line.

## Examples

## Input


```
5 10  
1 2 0 -1 3  
3 1 5 -2 0  
2 5  
1 3 3 3  
2 5  
2 4  
2 1  
1 2 1 4  
2 1  
2 4  
1 4 2 1  
2 2  

```
## Output


```
0  
3  
-1  
3  
2  
3  
-1  

```


#### tags 

#1900 #data_structures 