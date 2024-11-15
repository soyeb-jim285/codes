<h1 style='text-align: center;'> C. Balance</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A system of *n* vessels with water is given. Several pairs of vessels are connected by tubes with transfusion mechanisms. One may transfer an integer amount of liters of water between two vessels connected by such tube (tube works in both directions). There might be multiple tubes between two vessels. Total number of tubes equals *e*. Volume of each vessel equals *v* liters. Of course, the amount of the water in any vessel cannot exceed *v* liters in the process of transfusions.

Given the initial amounts *a**i* of water in the vessels and the desired amounts *b**i* find a sequence of transfusions that deals with the task. Total number of transfusions must not exceed 2·*n*2.

## Input

First line of the input contains integers *n*, *v*, *e* (1 ≤ *n* ≤ 300, 1 ≤ *v* ≤ 109, 0 ≤ *e* ≤ 50000).

Next two lines contain *n* integers each: initial *a**i* and the desired amounts *b**i* of water in corresponding vessels (0 ≤ *a**i*, *b**i* ≤ *v*).

Next *e* lines describe one tube each in the format *x* *y* (1 ≤ *x*, *y* ≤ *n*, *x* ≠ *y*) for a tube between vessels number *x* and *y*. There might be multiple tubes between two vessels. You may assume that vessels are numbered from 1 to *n* in some way.

## Output

Print "NO" (without quotes), if such sequence of transfusions does not exist.

Otherwise print any suitable sequence in the following format. On the first line print the total number of transfusions *k* (*k* should not exceed 2·*n*2). In the following *k* lines print transfusions in the format *x* *y* *d* (transfusion of *d* liters from the vessel number *x* to the vessel number *y*, *x* and *y* must be distinct). For all transfusions *d* must be a non-negative integer.

## Examples

## Input


```
2 10 1  
1 9  
5 5  
1 2  

```
## Output


```
1  
2 1 4  

```
## Input


```
2 10 0  
5 2  
4 2  

```
## Output


```
NO  

```
## Input


```
2 10 0  
4 2  
4 2  

```
## Output


```
0  

```


#### tags 

#2500 #constructive_algorithms #dfs_and_similar #graphs #trees 