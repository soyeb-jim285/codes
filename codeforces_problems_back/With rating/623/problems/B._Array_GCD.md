<h1 style='text-align: center;'> B. Array GCD</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given array *a**i* of length *n*. You may consecutively apply two operations to this array:

* remove some subsegment (continuous subsequence) of length *m* < *n* and pay for it *m*·*a* coins;
* change some elements of the array by at most 1, and pay *b* coins for each change.

Please note that each of operations may be applied at most once (and may be not applied at all) so you can remove only one segment and each number may be changed (increased or decreased) by at most 1. Also note, that you are not allowed to delete the whole array.

Your goal is to calculate the minimum number of coins that you need to spend in order to make the greatest common divisor of the elements of the resulting array be greater than 1.

## Input

The first line of the input contains integers *n*, *a* and *b* (1 ≤ *n* ≤ 1 000 000, 0 ≤ *a*, *b* ≤ 109) — the length of the array, the cost of removing a single element in the first operation and the cost of changing an element, respectively.

The second line contains *n* integers *a**i* (2 ≤ *a**i* ≤ 109) — elements of the array.

## Output

Print a single number — the minimum cost of changes needed to obtain an array, such that the greatest common divisor of all its elements is greater than 1.

## Examples

## Input


```
3 1 4  
4 2 3  

```
## Output


```
1  

```
## Input


```
5 3 2  
5 17 13 5 6  

```
## Output


```
8  

```
## Input


```
8 3 4  
3 7 5 4 3 12 9 4  

```
## Output


```
13  

```
## Note

In the first sample the optimal way is to remove number 3 and pay 1 coin for it.

In the second sample you need to remove a segment [17, 13] and then decrease number 6. The cost of these changes is equal to 2·3 + 2 = 8 coins.



#### tags 

#2300 #dp #greedy #number_theory 