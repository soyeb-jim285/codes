<h1 style='text-align: center;'> B. "Or" Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* numbers *a*1, *a*2, ..., *a**n*. You can perform at most *k* operations. For each operation you can multiply one of the numbers by *x*. We want to make ![](images/1faa5be276f646dfb07d2a01bf67449ad72c0ef7.png) as large as possible, where ![](images/ddbf6923ea3f08cb83b08ed026f40a80751dff3f.png) denotes the bitwise OR. 

Find the maximum possible value of ![](images/1faa5be276f646dfb07d2a01bf67449ad72c0ef7.png) after performing at most *k* operations optimally.

## Input

The first line contains three integers *n*, *k* and *x* (1 ≤ *n* ≤ 200 000, 1 ≤ *k* ≤ 10, 2 ≤ *x* ≤ 8).

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 109).

## Output

## Output

 the maximum value of a bitwise OR of sequence elements after performing operations.

## Examples

## Input


```
3 1 2  
1 1 1  

```
## Output


```
3  

```
## Input


```
4 2 3  
1 2 4 8  

```
## Output


```
79  

```
## Note

For the first sample, any possible choice of doing one operation will result the same three numbers 1, 1, 2 so the result is ![](images/1ee73b671ed4bc53f2f96ed1a85fd98388e1712b.png). 

For the second sample if we multiply 8 by 3 two times we'll get 72. In this case the numbers will become 1, 2, 4, 72 so the OR value will be 79 and is the largest possible result.



#### tags 

#1700 #brute_force #greedy 