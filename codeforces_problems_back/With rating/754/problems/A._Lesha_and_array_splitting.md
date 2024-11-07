<h1 style='text-align: center;'> A. Lesha and array splitting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One spring day on his way to university Lesha found an array *A*. Lesha likes to split arrays into several parts. This time Lesha decided to split the array *A* into several, possibly one, new arrays so that the sum of elements in each of the new arrays is not zero. One more condition is that if we place the new arrays one after another they will form the old array *A*.

Lesha is tired now so he asked you to split the array. Help Lesha!

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 100) — the number of elements in the array *A*.

The next line contains *n* integers *a*1, *a*2, ..., *a**n* ( - 103 ≤ *a**i* ≤ 103) — the elements of the array *A*.

## Output

If it is not possible to split the array *A* and satisfy all the constraints, print single line containing "NO" (without quotes).

Otherwise in the first line print "YES" (without quotes). In the next line print single integer *k* — the number of new arrays. In each of the next *k* lines print two integers *l**i* and *r**i* which denote the subarray *A*[*l**i*... *r**i*] of the initial array *A* being the *i*-th new array. Integers *l**i*, *r**i* should satisfy the following conditions:

* *l*1 = 1
* *r**k* = *n*
* *r**i* + 1 = *l**i* + 1 for each 1 ≤ *i* < *k*.

If there are multiple answers, print any of them.

## Examples

## Input


```
3  
1 2 -3  

```
## Output


```
YES  
2  
1 2  
3 3  

```
## Input


```
8  
9 -12 3 4 -4 -10 7 3  

```
## Output


```
YES  
2  
1 2  
3 8  

```
## Input


```
1  
0  

```
## Output


```
NO  

```
## Input


```
4  
1 2 3 -5  

```
## Output


```
YES  
4  
1 1  
2 2  
3 3  
4 4  

```


#### tags 

#1200 #constructive_algorithms #greedy #implementation 