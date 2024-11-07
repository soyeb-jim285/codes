<h1 style='text-align: center;'> B. Polo the Penguin and Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little penguin Polo has an *n* × *m* matrix, consisting of integers. Let's index the matrix rows from 1 to *n* from top to bottom and let's index the columns from 1 to *m* from left to right. Let's represent the matrix element on the intersection of row *i* and column *j* as *a**ij*.

In one move the penguin can add or subtract number *d* from some matrix element. Find the minimum number of moves needed to make all matrix elements equal. If the described plan is impossible to carry out, say so.

## Input

The first line contains three integers *n*, *m* and *d* (1 ≤ *n*, *m* ≤ 100, 1 ≤ *d* ≤ 104) — the matrix sizes and the *d* parameter. Next *n* lines contain the matrix: the *j*-th integer in the *i*-th row is the matrix element *a**ij* (1 ≤ *a**ij* ≤ 104).

## Output

In a single line print a single integer — the minimum number of moves the penguin needs to make all matrix elements equal. If that is impossible, print "-1" (without the quotes).

## Examples

## Input


```
2 2 2  
2 4  
6 8  

```
## Output


```
4  

```
## Input


```
1 2 7  
6 7  

```
## Output


```
-1  

```


#### tags 

#1400 #brute_force #dp #implementation #sortings #ternary_search 