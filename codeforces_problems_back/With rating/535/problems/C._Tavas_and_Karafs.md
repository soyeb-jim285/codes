<h1 style='text-align: center;'> C. Tavas and Karafs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Karafs is some kind of vegetable in shape of an 1 × *h* rectangle. Tavaspolis people love Karafs and they use Karafs in almost any kind of food. Tavas, himself, is crazy about Karafs.

 ![](images/9ad61b29003e0a31ebea4f147ad0b728164ec3ae.png) Each Karafs has a positive integer height. Tavas has an infinite 1-based sequence of Karafses. The height of the *i*-th Karafs is *s**i* = *A* + (*i* - 1) × *B*.

For a given *m*, let's define an *m*-bite operation as decreasing the height of at most *m* distinct not eaten Karafses by 1. Karafs is considered as eaten when its height becomes zero.

Now SaDDas asks you *n* queries. In each query he gives you numbers *l*, *t* and *m* and you should find the largest number *r* such that *l* ≤ *r* and sequence *s**l*, *s**l* + 1, ..., *s**r* can be eaten by performing *m*-bite no more than *t* times or print -1 if there is no such number *r*.

## Input

The first line of input contains three integers *A*, *B* and *n* (1 ≤ *A*, *B* ≤ 106, 1 ≤ *n* ≤ 105).

Next *n* lines contain information about queries. *i*-th line contains integers *l*, *t*, *m* (1 ≤ *l*, *t*, *m* ≤ 106) for *i*-th query.

## Output

For each query, print its answer in a single line.

## Examples

## Input


```
2 1 4  
1 5 3  
3 3 10  
7 10 2  
6 4 8  

```
## Output


```
4  
-1  
8  
-1  

```
## Input


```
1 5 2  
1 5 10  
2 7 4  

```
## Output


```
1  
2  

```


#### tags 

#1900 #binary_search #greedy #math 