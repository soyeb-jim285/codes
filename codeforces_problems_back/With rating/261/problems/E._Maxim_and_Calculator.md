<h1 style='text-align: center;'> E. Maxim and Calculator</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Maxim has got a calculator. The calculator has two integer cells. Initially, the first cell contains number 1, and the second cell contains number 0. In one move you can perform one of the following operations:

1. Let's assume that at the current time the first cell contains number *a*, and the second cell contains number *b*. Write to the second cell number *b* + 1;
2. Let's assume that at the current time the first cell contains number *a*, and the second cell contains number *b*. Write to the first cell number *a*·*b*.

Maxim is wondering, how many integers *x* (*l* ≤ *x* ≤ *r*) are there, such that we can write the number *x* to the first cell of the calculator, having performed at most *p* moves.

## Input

The first line contains three integers: *l*, *r*, *p* (2 ≤ *l* ≤ *r* ≤ 109, 1 ≤ *p* ≤ 100). 

The numbers in the line are separated by single spaces.

## Output

In a single line print a single integer — the answer to the problem.

## Examples

## Input


```
2 10 3  

```
## Output


```
1  

```
## Input


```
2 111 100  

```
## Output


```
106  

```
## Input


```
2 111 11  

```
## Output


```
47  

```


#### tags 

#2800 #brute_force #dp #two_pointers 