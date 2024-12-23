<h1 style='text-align: center;'> D. Rat Kwesh and Cheese</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Wet Shark asked Rat Kwesh to generate three positive real numbers *x*, *y* and *z*, from 0.1 to 200.0, inclusive. Wet Krash wants to impress Wet Shark, so all generated numbers will have exactly one digit after the decimal point.

Wet Shark knows Rat Kwesh will want a lot of cheese. So he will give the Rat an opportunity to earn a lot of cheese. He will hand the three numbers *x*, *y* and *z* to Rat Kwesh, and Rat Kwesh will pick one of the these twelve options:

1. *a*1 = *x**y**z*;
2. *a*2 = *x**z**y*;
3. *a*3 = (*x**y*)*z*;
4. *a*4 = (*x**z*)*y*;
5. *a*5 = *y**x**z*;
6. *a*6 = *y**z**x*;
7. *a*7 = (*y**x*)*z*;
8. *a*8 = (*y**z*)*x*;
9. *a*9 = *z**x**y*;
10. *a*10 = *z**y**x*;
11. *a*11 = (*z**x*)*y*;
12. *a*12 = (*z**y*)*x*.

Let *m* be the maximum of all the *a**i*, and *c* be the smallest index (from 1 to 12) such that *a**c* = *m*. Rat's goal is to find that *c*, and he asks you to help him. Rat Kwesh wants to see how much cheese he gets, so he you will have to print the expression corresponding to that *a**c*.

 

## Input

The only line of the input contains three space-separated real numbers *x*, *y* and *z* (0.1 ≤ *x*, *y*, *z* ≤ 200.0). Each of *x*, *y* and *z* is given with exactly one digit after the decimal point.

## Output

Find the maximum value of expression among *x**y**z*, *x**z**y*, (*x**y*)*z*, (*x**z*)*y*, *y**x**z*, *y**z**x*, (*y**x*)*z*, (*y**z*)*x*, *z**x**y*, *z**y**x*, (*z**x*)*y*, (*z**y*)*x* and print the corresponding expression. If there are many maximums, print the one that comes first in the list. 

*x**y**z* should be outputted as x^y^z (without brackets), and (*x**y*)*z* should be outputted as (x^y)^z (quotes for clarity). 

## Examples

## Input


```
1.1 3.4 2.5  

```
## Output


```
z^y^x  

```
## Input


```
2.0 2.0 2.0  

```
## Output


```
x^y^z  

```
## Input


```
1.9 1.8 1.7  

```
## Output


```
(x^y)^z  

```


#### tags 

#2400 #brute_force #constructive_algorithms #math 