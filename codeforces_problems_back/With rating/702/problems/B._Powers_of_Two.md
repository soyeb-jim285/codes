<h1 style='text-align: center;'> B. Powers of Two</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* integers *a*1, *a*2, ..., *a**n*. Find the number of pairs of indexes *i*, *j* (*i* < *j*) that *a**i* + *a**j* is a power of 2 (i. e. some integer *x* exists so that *a**i* + *a**j* = 2*x*).

## Input

The first line contains the single positive integer *n* (1 ≤ *n* ≤ 105) — the number of integers.

The second line contains *n* positive integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

## Output

Print the number of pairs of indexes *i*, *j* (*i* < *j*) that *a**i* + *a**j* is a power of 2.

## Examples

## Input


```
4  
7 3 2 1  

```
## Output


```
2  

```
## Input


```
3  
1 1 1  

```
## Output


```
3  

```
## Note

In the first example the following pairs of indexes include in answer: (1, 4) and (2, 4).

In the second example all pairs of indexes (*i*, *j*) (where *i* < *j*) include in answer.



#### tags 

#1500 #brute_force #data_structures #implementation #math 