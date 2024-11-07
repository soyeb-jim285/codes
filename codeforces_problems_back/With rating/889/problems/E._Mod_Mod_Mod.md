<h1 style='text-align: center;'> E. Mod Mod Mod</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence of integers *a*1, *a*2, ..., *a**n*. Let ![](images/8767bb4afef7bf6fc8660faf93bd6c301ca33b64.png), and ![](images/fee957ce3bd2c5eda97de1361a029a3ce8188743.png) for 1 ≤ *i* < *n*. Here, ![](images/f52a9a86d828a54c4bc7e70dc407e45e8e5464a6.png) denotes the modulus operation. Find the maximum value of *f*(*x*, 1) over all nonnegative integers *x*. 

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 200000) — the length of the sequence.

The second lines contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1013) — the elements of the sequence.

## Output

## Output

 a single integer — the maximum value of *f*(*x*, 1) over all nonnegative integers *x*.

## Examples

## Input


```
2  
10 5  

```
## Output


```
13  

```
## Input


```
5  
5 4 3 2 1  

```
## Output


```
6  

```
## Input


```
4  
5 10 5 10  

```
## Output


```
16  

```
## Note

In the first example you can choose, for example, *x* = 19.

In the second example you can choose, for example, *x* = 3 or *x* = 2.



#### tags 

#3000 #binary_search #dp #math 