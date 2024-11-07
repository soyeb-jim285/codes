<h1 style='text-align: center;'> F. Yet Another Minimization Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of *n* integers *a*1... *a**n*. The cost of a subsegment is the number of unordered pairs of distinct indices within the subsegment that contain equal elements. Split the given array into *k* non-intersecting non-empty subsegments so that the sum of their costs is minimum possible. Each element should be present in exactly one subsegment.

## Input

The first line contains two integers *n* and *k* (2 ≤ *n* ≤ 105, 2 ≤ *k* ≤ *min* (*n*, 20))  — the length of the array and the number of segments you need to split the array into.

The next line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ *n*) — the elements of the array.

## Output

Print single integer: the minimum possible total cost of resulting subsegments.

## Examples

## Input


```
7 3  
1 1 3 3 3 2 1  

```
## Output


```
1  

```
## Input


```
10 2  
1 2 1 2 1 2 1 2 1 2  

```
## Output


```
8  

```
## Input


```
13 3  
1 2 2 2 1 2 1 1 1 2 2 1 1  

```
## Output


```
9  

```
## Note

In the first example it's optimal to split the sequence into the following three subsegments: [1], [1, 3], [3, 3, 2, 1]. The costs are 0, 0 and 1, thus the answer is 1.

In the second example it's optimal to split the sequence in two equal halves. The cost for each half is 4.

In the third example it's optimal to split the sequence in the following way: [1, 2, 2, 2, 1], [2, 1, 1, 1, 2], [2, 1, 1]. The costs are 4, 4, 1.



#### tags 

#2500 #divide_and_conquer #dp 