<h1 style='text-align: center;'> A. Jeff and Rounding</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jeff got 2*n* real numbers *a*1, *a*2, ..., *a*2*n* as a birthday present. The boy hates non-integer numbers, so he decided to slightly "adjust" the numbers he's got. Namely, Jeff consecutively executes *n* operations, each of them goes as follows:

* choose indexes *i* and *j* (*i* ≠ *j*) that haven't been chosen yet;
* round element *a**i* to the nearest integer that isn't more than *a**i* (assign to *a**i*: ⌊ *a**i* ⌋);
* round element *a**j* to the nearest integer that isn't less than *a**j* (assign to *a**j*: ⌈ *a**j* ⌉).

Nevertheless, Jeff doesn't want to hurt the feelings of the person who gave him the sequence. That's why the boy wants to perform the operations so as to make the absolute value of the difference between the sum of elements before performing the operations and the sum of elements after performing the operations as small as possible. Help Jeff find the minimum absolute value of the difference.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 2000). The next line contains 2*n* real numbers *a*1, *a*2, ..., *a*2*n* (0 ≤ *a**i* ≤ 10000), given with exactly three digits after the decimal point. The numbers are separated by spaces.

## Output

In a single line print a single real number — the required difference with exactly three digits after the decimal point.

## Examples

## Input


```
3  
0.000 0.500 0.750 1.000 2.000 3.000  

```
## Output


```
0.250  

```
## Input


```
3  
4469.000 6526.000 4864.000 9356.383 7490.000 995.896  

```
## Output


```
0.279  

```
## Note

In the first test case you need to perform the operations as follows: (*i* = 1, *j* = 4), (*i* = 2, *j* = 3), (*i* = 5, *j* = 6). In this case, the difference will equal |(0 + 0.5 + 0.75 + 1 + 2 + 3) - (0 + 0 + 1 + 1 + 2 + 3)| = 0.25. 



#### tags 

#1800 #dp #greedy #implementation #math 