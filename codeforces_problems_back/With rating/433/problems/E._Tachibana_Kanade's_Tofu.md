<h1 style='text-align: center;'> E. Tachibana Kanade's Tofu</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Tachibana Kanade likes Mapo Tofu very much. One day, the canteen cooked all kinds of tofu to sell, but not all tofu is Mapo Tofu, only those spicy enough can be called Mapo Tofu.

Each piece of tofu in the canteen is given a *m*-based number, all numbers are in the range [*l*, *r*] (*l* and *r* being *m*-based numbers), and for every *m*-based integer in the range [*l*, *r*], there exists a piece of tofu with that number.

To judge what tofu is Mapo Tofu, Tachibana Kanade chose *n* *m*-based number strings, and assigned a value to each string. If a string appears in the number of a tofu, the value of the string will be added to the value of that tofu. If a string appears multiple times, then the value is also added that many times. Initially the value of each tofu is zero.

Tachibana Kanade considers tofu with values no more than *k* to be Mapo Tofu. So now Tachibana Kanade wants to know, how many pieces of tofu are Mapo Tofu?

## Input

The first line contains three integers *n*, *m* and *k* (1 ≤ *n* ≤ 200; 2 ≤ *m* ≤ 20; 1 ≤ *k* ≤ 500). Where *n* denotes the number of strings, *m* denotes the base used, and *k* denotes the limit of the value for Mapo Tofu.

The second line represents the number *l*. The first integer in the line is *len* (1 ≤ *len* ≤ 200), describing the length (number of digits in base *m*) of *l*. Then follow *len* integers *a*1, *a*2, ..., *a**len* (0 ≤ *a**i* < *m*; *a*1 > 0) separated by spaces, representing the digits of *l*, with *a*1 being the highest digit and *a**len* being the lowest digit.

The third line represents the number *r* in the same format as *l*. It is guaranteed that 1 ≤ *l* ≤ *r*.

Then follow *n* lines, each line describing a number string. The *i*-th line contains the *i*-th number string and *v**i* — the value of the *i*-th string (1 ≤ *v**i* ≤ 200). All number strings are described in almost the same format as *l*, the only difference is number strings may contain necessary leading zeros (see the first example). The sum of the lengths of all number strings does not exceed 200.

## Output

## Output

 the number of pieces of Mapo Tofu modulo 1000000007 (109 + 7). The answer should be a decimal integer.

## Examples

## Input


```
2 10 1  
1 1  
3 1 0 0  
1 1 1  
1 0 1  

```
## Output


```
97  

```
## Input


```
2 10 12  
2 5 9  
6 6 3 5 4 9 7  
2 0 6 1  
3 6 7 2 1  

```
## Output


```
635439  

```
## Input


```
4 2 6  
6 1 0 1 1 1 0  
6 1 1 0 1 0 0  
1 1 2  
3 0 1 0 5  
4 0 1 1 0 4  
3 1 0 1 2  

```
## Output


```
2  

```
## Note

In the first sample, 10, 11 and 100 are the only three decimal numbers in [1, 100] with a value greater than 1. Here the value of 1 is 1 but not 2, since numbers cannot contain leading zeros and thus cannot be written as "01".

In the second sample, no numbers in the given interval have a value greater than 12.

In the third sample, 110000 and 110001 are the only two binary numbers in the given interval with a value no greater than 6.



#### tags 

#2500 #dp 