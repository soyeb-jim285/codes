<h1 style='text-align: center;'> B. Recursive Queries</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let us define two functions *f* and *g* on positive integer numbers. 

 ![](images/affd4e3cdcadc3ba7dbceb6a2c0eb4ba928c1e4b.png)![](images/120df92771639f1f51a4b216dccd3ed7c32bb859.png) 

You need to process *Q* queries. In each query, you will be given three integers *l*, *r* and *k*. You need to print the number of integers *x* between *l* and *r* inclusive, such that *g*(*x*) = *k*. 

## Input

The first line of the input contains an integer *Q* (1 ≤ *Q* ≤ 2 × 105) representing the number of queries. 

*Q* lines follow, each of which contains 3 integers *l*, *r* and *k* (1 ≤ *l* ≤ *r* ≤ 106, 1 ≤ *k* ≤ 9).

## Output

For each query, print a single line containing the answer for that query.

## Examples

## Input


```
4  
22 73 9  
45 64 6  
47 55 7  
2 62 4  

```
## Output


```
1  
4  
0  
8  

```
## Input


```
4  
82 94 6  
56 67 4  
28 59 9  
39 74 4  

```
## Output


```
3  
1  
1  
5  

```
## Note

In the first example:

* *g*(33) = 9 as *g*(33) = *g*(3 × 3) = *g*(9) = 9
* *g*(47) = *g*(48) = *g*(60) = *g*(61) = 6
* There are no such integers between 47 and 55.
* *g*(4) = *g*(14) = *g*(22) = *g*(27) = *g*(39) = *g*(40) = *g*(41) = *g*(58) = 4


#### tags 

#1300 #binary_search #data_structures #dfs_and_similar 