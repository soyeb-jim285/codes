<h1 style='text-align: center;'> F. SUM and REPLACE</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let *D*(*x*) be the number of positive divisors of a positive integer *x*. For example, *D*(2) = 2 (2 is divisible by 1 and 2), *D*(6) = 4 (6 is divisible by 1, 2, 3 and 6).

You are given an array *a* of *n* integers. You have to process two types of queries:

1. REPLACE *l* *r* — for every ![](images/6afb5e3d414ffbb040c175e23c6627da949add06.png) replace *a**i* with *D*(*a**i*);
2. SUM *l* *r* — calculate ![](images/1e50b9417bb7e50d92d43134922596e938249431.png).

Print the answer for each SUM query.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 3·105) — the number of elements in the array and the number of queries to process, respectively.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 106) — the elements of the array.

Then *m* lines follow, each containing 3 integers *t**i*, *l**i*, *r**i* denoting *i*-th query. If *t**i* = 1, then *i*-th query is REPLACE *l**i* *r**i*, otherwise it's SUM *l**i* *r**i* (1 ≤ *t**i* ≤ 2, 1 ≤ *l**i* ≤ *r**i* ≤ *n*).

There is at least one SUM query.

## Output

For each SUM query print the answer to it.

## Example

## Input


```
7 6  
6 4 1 10 3 2 4  
2 1 7  
2 4 5  
1 3 5  
2 4 4  
1 5 7  
2 1 7  

```
## Output


```
30  
13  
4  
22  

```


#### tags 

#2000 #brute_force #data_structures #dsu #number_theory 