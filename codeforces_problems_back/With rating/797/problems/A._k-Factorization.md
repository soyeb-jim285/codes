<h1 style='text-align: center;'> A. k-Factorization</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a positive integer *n*, find *k* integers (not necessary distinct) such that all these integers are strictly greater than 1, and their product is equal to *n*.

## Input

The first line contains two integers *n* and *k* (2 ≤ *n* ≤ 100000, 1 ≤ *k* ≤ 20).

## Output

If it's impossible to find the representation of *n* as a product of *k* numbers, print -1.

Otherwise, print *k* integers in any order. Their product must be equal to *n*. If there are multiple answers, print any of them.

## Examples

## Input


```
100000 2  

```
## Output


```
2 50000   

```
## Input


```
100000 20  

```
## Output


```
-1  

```
## Input


```
1024 5  

```
## Output


```
2 64 2 2 2   

```


#### tags 

#1100 #implementation #math #number_theory 