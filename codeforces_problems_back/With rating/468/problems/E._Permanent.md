<h1 style='text-align: center;'> E. Permanent</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Little X has solved the #P-complete problem in polynomial time recently. So he gives this task to you. 

There is a special *n* × *n* matrix *A*, you should calculate its permanent modulo 1000000007 (109 + 7). The special property of matrix *A* is almost all its elements equal to 1. Only *k* elements have specified value.

You can find the definition of permanent at the link: https://en.wikipedia.org/wiki/Permanent

## Input

The first line contains two space-separated integers *n*, *k* (1 ≤ *n* ≤ 105; 1 ≤ *k* ≤ 50).

The next *k* lines contain the description of the matrix. The *i*-th line contains three space-separated integers *x**i*, *y**i*, *w**i* (1 ≤ *x**i*,  *y**i* ≤  *n*; 0  ≤  *w**i*  ≤ 109). These numbers denote that *A**x**i*, *y**i* = *w**i*. All the elements of the matrix except of the given elements are equal to 1.

It's guaranteed that all the positions (*x**i*, *y**i*) are distinct.

## Output

Print the permanent of the matrix modulo 1000000007 (109  +  7).

## Examples

## Input


```
3 1  
1 1 2  

```
## Output


```
8  

```
## Input


```
10 10  
3 3 367056794  
6 2 124561273  
1 3 46718146  
6 9 415916869  
10 5 985968336  
3 1 526792265  
1 4 386357058  
10 4 349304187  
2 7 102032499  
3 6 502679075  

```
## Output


```
233333333  

```


#### tags 

#3100 #dp #graph_matchings #math #meet-in-the-middle 