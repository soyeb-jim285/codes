<h1 style='text-align: center;'> A. Pride</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array *a* with length *n*, you can perform operations. Each operation is like this: choose two adjacent elements from *a*, say *x* and *y*, and replace one of them with *gcd*(*x*, *y*), where *gcd* denotes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor).

What is the minimum number of operations you need to make all of the elements equal to 1?

## Input

The first line of the input contains one integer *n* (1 ≤ *n* ≤ 2000) — the number of elements in the array.

The second line contains *n* space separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109) — the elements of the array.

## Output

Print -1, if it is impossible to turn all numbers to 1. Otherwise, print the minimum number of operations needed to make all numbers equal to 1.

## Examples

## Input


```
5  
2 2 3 4 6  

```
## Output


```
5  

```
## Input


```
4  
2 4 6 8  

```
## Output


```
-1  

```
## Input


```
3  
2 6 9  

```
## Output


```
4  

```
## Note

In the first sample you can turn all numbers to 1 using the following 5 moves:

* [2, 2, 3, 4, 6].
* [2, 1, 3, 4, 6]
* [2, 1, 3, 1, 6]
* [2, 1, 1, 1, 6]
* [1, 1, 1, 1, 6]
* [1, 1, 1, 1, 1]

We can prove that in this case it is not possible to make all numbers one using less than 5 moves.



#### tags 

#1500 #brute_force #dp #greedy #math #number_theory 