<h1 style='text-align: center;'> B. Little Elephant and Array</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Little Elephant loves playing with arrays. He has array *a*, consisting of *n* positive integers, indexed from 1 to *n*. Let's denote the number with index *i* as *a**i*. 

Additionally the Little Elephant has *m* queries to the array, each query is characterised by a pair of integers *l**j* and *r**j* (1 ≤ *l**j* ≤ *r**j* ≤ *n*). For each query *l**j*, *r**j* the Little Elephant has to count, how many numbers *x* exist, such that number *x* occurs exactly *x* times among numbers *a**l**j*, *a**l**j* + 1, ..., *a**r**j*.

Help the Little Elephant to count the answers to all queries.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the size of array *a* and the number of queries to it. The next line contains *n* space-separated positive integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109). Next *m* lines contain descriptions of queries, one per line. The *j*-th of these lines contains the description of the *j*-th query as two space-separated integers *l**j* and *r**j* (1 ≤ *l**j* ≤ *r**j* ≤ *n*).

## Output

In *m* lines print *m* integers — the answers to the queries. The *j*-th line should contain the answer to the *j*-th query.

## Examples

## Input


```
7 2  
3 1 2 2 3 3 7  
1 7  
3 4  

```
## Output


```
3  
1  

```


#### tags 

#1800 #constructive_algorithms #data_structures 