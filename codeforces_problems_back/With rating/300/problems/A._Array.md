<h1 style='text-align: center;'> A. Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vitaly has an array of *n* distinct integers. Vitaly wants to divide this array into three non-empty sets so as the following conditions hold: 

1. The product of all numbers in the first set is less than zero ( < 0).
2. The product of all numbers in the second set is greater than zero ( > 0).
3. The product of all numbers in the third set is equal to zero.
4. Each number from the initial array must occur in exactly one set.

Help Vitaly. Divide the given array.

## Input

The first line of the input contains integer *n* (3 ≤ *n* ≤ 100). The second line contains *n* space-separated distinct integers *a*1, *a*2, ..., *a**n* (|*a**i*| ≤ 103) — the array elements.

## Output

In the first line print integer *n*1 (*n*1 > 0) — the number of elements in the first set. Then print *n*1 numbers — the elements that got to the first set.

In the next line print integer *n*2 (*n*2 > 0) — the number of elements in the second set. Then print *n*2 numbers — the elements that got to the second set.

In the next line print integer *n*3 (*n*3 > 0) — the number of elements in the third set. Then print *n*3 numbers — the elements that got to the third set.

The printed sets must meet the described conditions. It is guaranteed that the solution exists. If there are several solutions, you are allowed to print any of them.

## Examples

## Input


```
3  
-1 2 0  

```
## Output


```
1 -1  
1 2  
1 0  

```
## Input


```
4  
-1 -2 -3 0  

```
## Output


```
1 -1  
2 -3 -2  
1 0  

```


#### tags 

#1100 #brute_force #constructive_algorithms #implementation 