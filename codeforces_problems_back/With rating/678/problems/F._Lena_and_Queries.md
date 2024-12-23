<h1 style='text-align: center;'> F. Lena and Queries</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Lena is a programmer. She got a task to solve at work.

There is an empty set of pairs of integers and *n* queries to process. Each query is one of three types:

1. Add a pair (*a*, *b*) to the set.
2. Remove a pair added in the query number *i*. All queries are numbered with integers from 1 to *n*.
3. For a given integer *q* find the maximal value *x*·*q* + *y* over all pairs (*x*, *y*) from the set.

Help Lena to process the queries.

## Input

The first line of input contains integer *n* (1 ≤ *n* ≤ 3·105) — the number of queries.

Each of the next *n* lines starts with integer *t* (1 ≤ *t* ≤ 3) — the type of the query.

A pair of integers *a* and *b* ( - 109 ≤ *a*, *b* ≤ 109) follows in the query of the first type.

An integer *i* (1 ≤ *i* ≤ *n*) follows in the query of the second type. It is guaranteed that *i* is less than the number of the query, the query number *i* has the first type and the pair from the *i*-th query is not already removed.

An integer *q* ( - 109 ≤ *q* ≤ 109) follows in the query of the third type.

## Output

For the queries of the third type print on a separate line the desired maximal value of *x*·*q* + *y*.

If there are no pairs in the set print "EMPTY SET".

## Example

## Input


```
7  
3 1  
1 2 3  
3 1  
1 -1 100  
3 1  
2 4  
3 1  

```
## Output


```
EMPTY SET  
5  
99  
5  

```


#### tags 

#2500 #data_structures #divide_and_conquer #geometry 