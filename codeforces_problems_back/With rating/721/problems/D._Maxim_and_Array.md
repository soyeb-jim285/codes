<h1 style='text-align: center;'> D. Maxim and Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently Maxim has found an array of *n* integers, needed by no one. He immediately come up with idea of changing it: he invented positive integer *x* and decided to add or subtract it from arbitrary array elements. Formally, by applying single operation Maxim chooses integer *i* (1 ≤ *i* ≤ *n*) and replaces the *i*-th element of array *a**i* either with *a**i* + *x* or with *a**i* - *x*. Please note that the operation may be applied more than once to the same position.

Maxim is a curious minimalis, thus he wants to know what is the minimum value that the product of all array elements (i.e. ![](images/2f9309f35d7faa3a510387f08ee16afbd2ef1d2a.png)) can reach, if Maxim would apply no more than *k* operations to it. Please help him in that.

## Input

The first line of the input contains three integers *n*, *k* and *x* (1 ≤ *n*, *k* ≤ 200 000, 1 ≤ *x* ≤ 109) — the number of elements in the array, the maximum number of operations and the number invented by Maxim, respectively.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (![](images/9a8b1c66df023fb7075ec9dba75e73a53f173334.png)) — the elements of the array found by Maxim.

## Output

Print *n* integers *b*1, *b*2, ..., *b**n* in the only line — the array elements after applying no more than *k* operations to the array. In particular, ![](images/25a4bad1de460e01b26a65b4e7c0cc0680b347dd.png) should stay true for every 1 ≤ *i* ≤ *n*, but the product of all array elements should be minimum possible.

If there are multiple answers, print any of them.

## Examples

## Input


```
5 3 1  
5 4 3 5 2  

```
## Output


```
5 4 3 5 -1   

```
## Input


```
5 3 1  
5 4 3 5 5  

```
## Output


```
5 4 0 5 5   

```
## Input


```
5 3 1  
5 4 4 5 5  

```
## Output


```
5 1 4 5 5   

```
## Input


```
3 2 7  
5 4 2  

```
## Output


```
5 11 -5   

```


#### tags 

#2000 #constructive_algorithms #data_structures #greedy #math 