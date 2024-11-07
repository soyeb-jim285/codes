<h1 style='text-align: center;'> G. Sum the Fibonacci</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array *s* of *n* non-negative integers.

A 5-tuple of integers (*a*, *b*, *c*, *d*, *e*) is said to be valid if it satisfies the following conditions: 

* 1 ≤ *a*, *b*, *c*, *d*, *e* ≤ *n*
* (*s**a* | *s**b*) & *s**c* & (*s**d* ^ *s**e*) = 2*i* for some integer *i*
* *s**a* & *s**b* = 0

Here, '|' is the bitwise OR, '&' is the bitwise AND and '^' is the bitwise XOR operation.

Find the sum of *f*(*s**a*|*s**b*) * *f*(*s**c*) * *f*(*s**d*^*s**e*) over all valid 5-tuples (*a*, *b*, *c*, *d*, *e*), where *f*(*i*) is the *i*-th Fibonnaci number (*f*(0) = 0, *f*(1) = 1, *f*(*i*) = *f*(*i* - 1) + *f*(*i* - 2)).

Since answer can be is huge output it modulo 109 + 7.

## Input

The first line of input contains an integer *n* (1 ≤ *n* ≤ 106).

The second line of input contains *n* integers *s**i* (0 ≤ *s**i* < 217).

## Output

## Output

 the sum as described above, modulo 109 + 7

## Examples

## Input


```
2  
1 2  

```
## Output


```
32  

```
## Input


```
3  
7 4 1  

```
## Output


```
3520  

```
## Input


```
10  
1 3 0 7 3 7 6 5 7 5  

```
## Output


```
1235424  

```
## Input


```
10  
50 9 11 44 39 40 5 39 23 7  

```
## Output


```
113860062  

```


#### tags 

#2600 #bitmasks #divide_and_conquer #dp #fft #math 