<h1 style='text-align: center;'> F. Product transformation</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider an array *A* with *N* elements, all being the same integer *a*.

Define the product transformation as a simultaneous update *A**i* = *A**i*·*A**i* + 1, that is multiplying each element to the element right to it for ![](images/bab7e22f732dff71f7d64d3ebfc08bb437dcd67f.png), with the last number *A**N* remaining the same. For example, if we start with an array *A* with *a* = 2 and *N* = 4, then after one product transformation *A* = [4,  4,  4,  2], and after two product transformations *A* = [16,  16,  8,  2].

Your simple task is to calculate the array *A* after *M* product transformations. Since the numbers can get quite big you should output them modulo *Q*.

## Input

The first and only line of input contains four integers *N*, *M*, *a*, *Q* (7 ≤ *Q* ≤ 109 + 123, 2 ≤ *a* ≤ 106 + 123, ![](images/2ac3dce719aaa3202862fcb75cce57e5994e48b1.png), ![](images/9e311783e65b119bb1fd35c8a4f2a4d6933d358d.png) is prime), where ![](images/9e311783e65b119bb1fd35c8a4f2a4d6933d358d.png) is the multiplicative order of the integer *a* modulo *Q*, see notes for definition.

## Output

You should output the array *A* from left to right.

## Example

## Input


```
2 2 2 7  

```
## Output


```
1 2 
```
## Note

The multiplicative order of a number *a* modulo *Q* ![](images/38b13c1f6db75ae72784f8602e8230429b26cf2a.png), is the smallest natural number *x* such that *a**x* *mod* *Q* = 1. For example, ![](images/64b53b8160eddc004a5b65223bf29dd636bb1832.png).



#### tags 

#2200 #combinatorics #math #number_theory 