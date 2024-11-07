<h1 style='text-align: center;'> G. Periodic RMQ Problem</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array *a* consisting of positive integers and *q* queries to this array. There are two types of queries: 

* 1 *l* *r* *x* — for each index *i* such that *l* ≤ *i* ≤ *r* set *a**i* = *x*.
* 2 *l* *r* — find the minimum among such *a**i* that *l* ≤ *i* ≤ *r*.

We decided that this problem is too easy. So the array *a* is given in a compressed form: there is an array *b* consisting of *n* elements and a number *k* in the input, and before all queries *a* is equal to the concatenation of *k* arrays *b* (so the size of *a* is *n*·*k*).

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 105, 1 ≤ *k* ≤ 104).

The second line contains *n* integers — elements of the array *b* (1 ≤ *b**i* ≤ 109).

The third line contains one integer *q* (1 ≤ *q* ≤ 105).

Then *q* lines follow, each representing a query. Each query is given either as 1 *l* *r* *x* — set all elements in the segment from *l* till *r* (including borders) to *x* (1 ≤ *l* ≤ *r* ≤ *n*·*k*, 1 ≤ *x* ≤ 109) or as 2 *l* *r* — find the minimum among all elements in the segment from *l* till *r* (1 ≤ *l* ≤ *r* ≤ *n*·*k*).

## Output

For each query of type 2 print the answer to this query — the minimum on the corresponding segment.

## Examples

## Input


```
3 1  
1 2 3  
3  
2 1 3  
1 1 2 4  
2 1 3  

```
## Output


```
1  
3  

```
## Input


```
3 2  
1 2 3  
5  
2 4 4  
1 4 4 5  
2 4 4  
1 1 6 1  
2 6 6  

```
## Output


```
1  
5  
1  

```


#### tags 

#2300 #data_structures 