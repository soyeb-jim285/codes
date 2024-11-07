<h1 style='text-align: center;'> B. Marvolo Gaunt's Ring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Professor Dumbledore is helping Harry destroy the Horcruxes. He went to Gaunt Shack as he suspected a Horcrux to be present there. He saw Marvolo Gaunt's Ring and identified it as a Horcrux. Although he destroyed it, he is still affected by its curse. Professor Snape is helping Dumbledore remove the curse. For this, he wants to give Dumbledore exactly *x* drops of the potion he made. 

Value of *x* is calculated as maximum of *p*·*a**i* + *q*·*a**j* + *r*·*a**k* for given *p*, *q*, *r* and array *a*1, *a*2, ... *a**n* such that 1 ≤ *i* ≤ *j* ≤ *k* ≤ *n*. Help Snape find the value of *x*. Do note that the value of *x* may be negative.

## Input

First line of input contains 4 integers *n*, *p*, *q*, *r* ( - 109 ≤ *p*, *q*, *r* ≤ 109, 1 ≤ *n* ≤ 105).

Next line of input contains *n* space separated integers *a*1, *a*2, ... *a**n* ( - 109 ≤ *a**i* ≤ 109).

## Output

## Output

 a single integer the maximum value of *p*·*a**i* + *q*·*a**j* + *r*·*a**k* that can be obtained provided 1 ≤ *i* ≤ *j* ≤ *k* ≤ *n*.

## Examples

## Input


```
5 1 2 3  
1 2 3 4 5  

```
## Output


```
30  

```
## Input


```
5 1 2 -3  
-1 -2 -3 -4 -5  

```
## Output


```
12  

```
## Note

In the first sample case, we can take *i* = *j* = *k* = 5, thus making the answer as 1·5 + 2·5 + 3·5 = 30.

In second sample case, selecting *i* = *j* = 1 and *k* = 5 gives the answer 12.



#### tags 

#1500 #brute_force #data_structures #dp 