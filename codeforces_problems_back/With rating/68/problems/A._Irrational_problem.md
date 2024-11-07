<h1 style='text-align: center;'> A. Irrational problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Petya was given this problem for homework:

You are given function ![](images/22d161d4a5bc6cfd41667ca591d56973abfe8655.png) (here ![](images/e91a39ad64cd7a33e8f1b67cd60e5b40257de950.png) represents the operation of taking the remainder). His task is to count the number of integers *x* in range [*a*;*b*] with property *f*(*x*) = *x*.

It is a pity that Petya forgot the order in which the remainders should be taken and wrote down only 4 numbers. Each of 24 possible orders of taking the remainder has equal probability of being chosen. For example, if Petya has numbers 1, 2, 3, 4 then he can take remainders in that order or first take remainder modulo 4, then modulo 2, 3, 1. There also are 22 other permutations of these numbers that represent orders in which remainder can be taken. In this problem 4 numbers wrote down by Petya will be pairwise distinct.

Now it is impossible for Petya to complete the task given by teacher but just for fun he decided to find the number of integers ![](images/66564024af56fb327f06ed6542f6badc5c851715.png) with property that probability that *f*(*x*) = *x* is not less than 31.4159265352718281828459045%. In other words, Petya will pick up the number *x* if there exist at least 7 permutations of numbers *p*1, *p*2, *p*3, *p*4, for which *f*(*x*) = *x*.

## Input

First line of the input will contain 6 integers, separated by spaces: *p*1, *p*2, *p*3, *p*4, *a*, *b* (1 ≤ *p*1, *p*2, *p*3, *p*4 ≤ 1000, 0 ≤ *a* ≤ *b* ≤ 31415). 

It is guaranteed that numbers *p*1, *p*2, *p*3, *p*4 will be pairwise distinct.

## Output

## Output

 the number of integers in the given range that have the given property.

## Examples

## Input


```
2 7 1 8 2 8  

```
## Output


```
0  

```
## Input


```
20 30 40 50 0 100  

```
## Output


```
20  

```
## Input


```
31 41 59 26 17 43  

```
## Output


```
9  

```


#### tags 

#1100 #implementation #number_theory 