<h1 style='text-align: center;'> C. Find Maximum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valera has array *a*, consisting of *n* integers *a*0, *a*1, ..., *a**n* - 1, and function *f*(*x*), taking an integer from 0 to 2*n* - 1 as its single argument. Value *f*(*x*) is calculated by formula ![](images/eba4794e67d3b5ce144adcffa5217705a92db70f.png), where value *bit*(*i*) equals one if the binary representation of number *x* contains a 1 on the *i*-th position, and zero otherwise.

For example, if *n* = 4 and *x* = 11 (11 = 20 + 21 + 23), then *f*(*x*) = *a*0 + *a*1 + *a*3.

Help Valera find the maximum of function *f*(*x*) among all *x*, for which an inequality holds: 0 ≤ *x* ≤ *m*.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of array elements. The next line contains *n* space-separated integers *a*0, *a*1, ..., *a**n* - 1 (0 ≤ *a**i* ≤ 104) — elements of array *a*.

The third line contains a sequence of digits zero and one without spaces *s*0*s*1... *s**n* - 1 — the binary representation of number *m*. Number *m* equals ![](images/77407fd65d8594ac862f8de69093d5a75e54d3c5.png).

## Output

Print a single integer — the maximum value of function *f*(*x*) for all ![](images/82bfd78b9ec5ce07767875a86696eb7b2eb3031c.png).

## Examples

## Input


```
2  
3 8  
10  

```
## Output


```
3  

```
## Input


```
5  
17 0 10 2 1  
11010  

```
## Output


```
27  

```
## Note

In the first test case *m* = 20 = 1, *f*(0) = 0, *f*(1) = *a*0 = 3.

In the second sample *m* = 20 + 21 + 23 = 11, the maximum value of function equals *f*(5) = *a*0 + *a*2 = 17 + 10 = 27.



#### tags 

#1600 #implementation #math #number_theory 