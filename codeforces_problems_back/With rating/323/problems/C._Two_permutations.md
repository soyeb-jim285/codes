<h1 style='text-align: center;'> C. Two permutations</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given two permutations *p* and *q*, consisting of *n* elements, and *m* queries of the form: *l*1, *r*1, *l*2, *r*2 (*l*1 ≤ *r*1; *l*2 ≤ *r*2). The response for the query is the number of such integers from 1 to *n*, that their position in the first permutation is in segment [*l*1, *r*1] (borders included), and position in the second permutation is in segment [*l*2, *r*2] (borders included too).

A permutation of *n* elements is the sequence of *n* distinct integers, each not less than 1 and not greater than *n*.

Position of number *v* (1 ≤ *v* ≤ *n*) in permutation *g*1, *g*2, ..., *g**n* is such number *i*, that *g**i* = *v*.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 106), the number of elements in both permutations. The following line contains *n* integers, separated with spaces: *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*). These are elements of the first permutation. The next line contains the second permutation *q*1, *q*2, ..., *q**n* in same format.

The following line contains an integer *m* (1 ≤ *m* ≤ 2·105), that is the number of queries.

The following *m* lines contain descriptions of queries one in a line. The description of the *i*-th query consists of four integers: *a*, *b*, *c*, *d* (1 ≤ *a*, *b*, *c*, *d* ≤ *n*). Query parameters *l*1, *r*1, *l*2, *r*2 are obtained from the numbers *a*, *b*, *c*, *d* using the following algorithm: 

1. Introduce variable *x*. If it is the first query, then the variable equals 0, else it equals the response for the previous query plus one.
2. Introduce function *f*(*z*) = ((*z* - 1 + *x*) *mod* *n*) + 1.
3. Suppose *l*1 = *min*(*f*(*a*), *f*(*b*)), *r*1 = *max*(*f*(*a*), *f*(*b*)), *l*2 = *min*(*f*(*c*), *f*(*d*)), *r*2 = *max*(*f*(*c*), *f*(*d*)).
## Output

Print a response for each query in a separate line.

## Examples

## Input


```
3  
3 1 2  
3 2 1  
1  
1 2 3 3  

```
## Output


```
1  

```
## Input


```
4  
4 3 2 1  
2 3 4 1  
3  
1 2 3 4  
1 3 2 1  
1 4 2 3  

```
## Output


```
1  
1  
2  

```


#### tags 

#2400 #data_structures 