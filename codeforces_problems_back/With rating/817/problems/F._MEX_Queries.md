<h1 style='text-align: center;'> F. MEX Queries</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a set of integer numbers, initially it is empty. You should perform *n* queries.

There are three different types of queries: 

* 1 *l* *r* — Add all missing numbers from the interval [*l*, *r*]
* 2 *l* *r* — Remove all present numbers from the interval [*l*, *r*]
* 3 *l* *r* — Invert the interval [*l*, *r*] — add all missing and remove all present numbers from the interval [*l*, *r*]

After each query you should output MEX of the set — the smallest positive (MEX  ≥ 1) integer number which is not presented in the set.

## Input

The first line contains one integer number *n* (1 ≤ *n* ≤ 105).

Next *n* lines contain three integer numbers *t*, *l*, *r* (1 ≤ *t* ≤ 3, 1 ≤ *l* ≤ *r* ≤ 1018) — type of the query, left and right bounds.

## Output

Print MEX of the set after each query.

## Examples

## Input


```
3  
1 3 4  
3 1 6  
2 1 3  

```
## Output


```
1  
3  
1  

```
## Input


```
4  
1 1 3  
3 5 6  
2 4 4  
3 1 6  

```
## Output


```
4  
4  
4  
1  

```
## Note

Here are contents of the set after each query in the first example:

1. {3, 4} — the interval [3, 4] is added
2. {1, 2, 5, 6} — numbers {3, 4} from the interval [1, 6] got deleted and all the others are added
3. {5, 6} — numbers {1, 2} got deleted


#### tags 

#2300 #binary_search #data_structures #trees 