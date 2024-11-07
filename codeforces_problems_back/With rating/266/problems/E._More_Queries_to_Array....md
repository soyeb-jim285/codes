<h1 style='text-align: center;'> E. More Queries to Array...</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got an array, consisting of *n* integers: *a*1, *a*2, ..., *a**n*. Your task is to quickly run the queries of two types:

1. Assign value *x* to all elements from *l* to *r* inclusive. After such query the values of the elements of array *a**l*, *a**l* + 1, ..., *a**r* become equal to *x*.
2. Calculate and print sum ![](images/920d5e77b57e41992ceefa42465edf8cfc006a39.png), where *k* doesn't exceed 5. As the value of the sum can be rather large, you should print it modulo 1000000007 (109 + 7).
## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 105), showing, how many numbers are in the array and the number of queries, correspondingly. The second line contains *n* integers: *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 109) — the initial values of the array elements.

Then *m* queries follow, one per line:

1. The assign query has the following format: "![](images/b2ef693fd11e9e29c50f180848ea668ed6d33b22.png)", (1 ≤ *l* ≤ *r* ≤ *n*; 0 ≤ *x* ≤ 109).
2. The query to calculate the sum has the following format: "![](images/6a63948f42b361ef379406ad9a679d1da1aee76b.png)", (1 ≤ *l* ≤ *r* ≤ *n*; 0 ≤ *k* ≤ 5).

All numbers in the input are integers.

## Output

For each query to calculate the sum print an integer — the required sum modulo 1000000007 (109 + 7).

## Examples

## Input


```
4 5  
5 10 2 1  
? 1 2 1  
= 2 2 0  
? 2 4 3  
= 1 4 1  
? 1 4 5  

```
## Output


```
25  
43  
1300  

```
## Input


```
3 1  
1000000000 1000000000 1000000000  
? 1 3 0  

```
## Output


```
999999986  

```


#### tags 

#2500 #data_structures #math 