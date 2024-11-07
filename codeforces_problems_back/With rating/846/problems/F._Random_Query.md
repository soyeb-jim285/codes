<h1 style='text-align: center;'> F. Random Query</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array *a* consisting of *n* positive integers. You pick two integer numbers *l* and *r* from 1 to *n*, inclusive (numbers are picked randomly, equiprobably and independently). If *l* > *r*, then you swap values of *l* and *r*. You have to calculate the expected value of the number of unique elements in segment of the array from index *l* to index *r*, inclusive (1-indexed).

## Input

The first line contains one integer number *n* (1 ≤ *n* ≤ 106). The second line contains *n* integer numbers *a*1, *a*2, ... *a**n* (1 ≤ *a**i* ≤ 106) — elements of the array.

## Output

Print one number — the expected number of unique elements in chosen segment. 

Your answer will be considered correct if its absolute or relative error doesn't exceed 10- 4 — formally, the answer is correct if ![](images/8e6753bb7c233d712f20d63937221dcfd71cab0e.png), where *x* is jury's answer, and *y* is your answer.

## Examples

## Input


```
2  
1 2  

```
## Output


```
1.500000  

```
## Input


```
2  
2 2  

```
## Output


```
1.000000  

```


#### tags 

#1800 #data_structures #math #probabilities #two_pointers 