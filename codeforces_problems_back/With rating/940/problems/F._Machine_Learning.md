<h1 style='text-align: center;'> F. Machine Learning</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You come home and fell some unpleasant smell. Where is it coming from?

You are given an array *a*. You have to answer the following queries: 

1. You are given two integers *l* and *r*. Let *c**i* be the number of occurrences of *i* in *a**l*: *r*, where *a**l*: *r* is the subarray of *a* from *l*-th element to *r*-th inclusive. Find the Mex of {*c*0, *c*1, ..., *c*109}
2. You are given two integers *p* to *x*. Change *a**p* to *x*.

The Mex of a multiset of numbers is the smallest non-negative integer not in the set.

## Note

 that in this problem all elements of *a* are positive, which means that *c*0 = 0 and 0 is never the answer for the query of the second type.

## Input

The first line of input contains two integers *n* and *q* (1 ≤ *n*, *q* ≤ 100 000) — the length of the array and the number of queries respectively.

The second line of input contains *n* integers — *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

Each of the next *q* lines describes a single query.

The first type of query is described by three integers *t**i* = 1, *l**i*, *r**i*, where 1 ≤ *l**i* ≤ *r**i* ≤ *n* — the bounds of the subarray.

The second type of query is described by three integers *t**i* = 2, *p**i*, *x**i*, where 1 ≤ *p**i* ≤ *n* is the index of the element, which must be changed and 1 ≤ *x**i* ≤ 109 is the new value.

## Output

For each query of the first type output a single integer  — the Mex of {*c*0, *c*1, ..., *c*109}.

## Example

## Input


```
10 4  
1 2 3 1 1 2 2 2 9 9  
1 1 1  
1 2 8  
2 7 1  
1 2 8  

```
## Output


```
2  
3  
2  

```
## Note

The subarray of the first query consists of the single element — 1. 

The subarray of the second query consists of four 2s, one 3 and two 1s.

The subarray of the fourth query consists of three 1s, three 2s and one 3.



#### tags 

#2600 #brute_force #data_structures 