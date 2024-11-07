<h1 style='text-align: center;'> C. Table Compression</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Petya is now fond of data compression algorithms. He has already studied gz, bz, zip algorithms and many others. Inspired by the new knowledge, Petya is now developing the new compression algorithm which he wants to name dis.

Petya decided to compress tables. He is given a table *a* consisting of *n* rows and *m* columns that is filled with positive integers. He wants to build the table *a*' consisting of positive integers such that the relative order of the elements in each row and each column remains the same. That is, if in some row *i* of the initial table *a**i*, *j* < *a**i*, *k*, then in the resulting table *a*'*i*, *j* < *a*'*i*, *k*, and if *a**i*, *j* = *a**i*, *k* then *a*'*i*, *j* = *a*'*i*, *k*. Similarly, if in some column *j* of the initial table *a**i*, *j* < *a**p*, *j* then in compressed table *a*'*i*, *j* < *a*'*p*, *j* and if *a**i*, *j* = *a**p*, *j* then *a*'*i*, *j* = *a*'*p*, *j*. 

Because large values require more space to store them, the maximum value in *a*' should be as small as possible.

Petya is good in theory, however, he needs your help to implement the algorithm.

## Input

The first line of the input contains two integers *n* and *m* (![](images/8ce9eb3b66e2ccbb79eae736994b3703b3b8e7d2.png), the number of rows and the number of columns of the table respectively.

Each of the following *n* rows contain *m* integers *a**i*, *j* (1 ≤ *a**i*, *j* ≤ 109) that are the values in the table.

## Output

## Output

 the compressed table in form of *n* lines each containing *m* integers.

If there exist several answers such that the maximum number in the compressed table is minimum possible, you are allowed to output any of them.

## Examples

## Input


```
2 2  
1 2  
3 4  

```
## Output


```
1 2  
2 3  

```
## Input


```
4 3  
20 10 30  
50 40 30  
50 60 70  
90 80 70  

```
## Output


```
2 1 3  
5 4 3  
5 6 7  
9 8 7  

```
## Note

In the first sample test, despite the fact *a*1, 2 ≠ *a*21, they are not located in the same row or column so they may become equal after the compression.



#### tags 

#2200 #dfs_and_similar #dp #dsu #graphs #greedy 