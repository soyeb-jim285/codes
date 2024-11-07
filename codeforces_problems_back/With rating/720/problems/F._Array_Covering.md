<h1 style='text-align: center;'> F. Array Covering</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Misha has an array of integers of length *n*. He wants to choose *k* different continuous subarrays, so that each element of the array belongs to at least one of the chosen subarrays.

Misha wants to choose the subarrays in such a way that if he calculated the sum of elements for each subarray, and then add up all these sums, the resulting value was maximum possible.

## Input

The first line of input contains two integers: *n*, *k* (1 ≤ *n* ≤ 100 000, 1 ≤ *k* ≤ *n*·(*n* + 1) / 2) — the number of elements in the array and the number of different subarrays that must be chosen.

The second line contains *n* integers *a**i* ( - 50 000 ≤ *a**i* ≤ 50 000) — the elements of the array.

## Output

## Output

 one integer — the maximum possible value Misha can get by choosing *k* different subarrays.

## Example

## Input


```
5 4  
6 -4 -10 -4 7  

```
## Output


```
11  

```


#### tags 

#3100 #data_structures 