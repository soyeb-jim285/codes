<h1 style='text-align: center;'> G. Mass Change Queries</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array *a* consisting of *n* integers. You have to process *q* queries to this array; each query is given as four numbers *l*, *r*, *x* and *y*, denoting that for every *i* such that *l* ≤ *i* ≤ *r* and *a**i* = *x* you have to set *a**i* equal to *y*.

Print the array after all queries are processed.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 200000) — the size of array *a*.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 100) — the elements of array *a*.

The third line contains one integer *q* (1 ≤ *q* ≤ 200000) — the number of queries you have to process.

Then *q* lines follow. *i*-th line contains four integers *l*, *r*, *x* and *y* denoting *i*-th query (1 ≤ *l* ≤ *r* ≤ *n*, 1 ≤ *x*, *y* ≤ 100).

## Output

Print *n* integers — elements of array *a* after all changes are made.

## Example

## Input


```
5  
1 2 3 4 5  
3  
3 5 3 5  
1 5 5 1  
1 5 1 5  

```
## Output


```
5 2 5 4 5 
```


#### tags 

#2500 #data_structures 