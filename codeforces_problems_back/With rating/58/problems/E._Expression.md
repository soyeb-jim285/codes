<h1 style='text-align: center;'> E. Expression</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Vasya was solving arithmetical problems. He wrote down an expression *a* + *b* = *c* in his notebook. When the teacher checked Vasya's work it turned out that Vasya had solved the problem incorrectly. Now Vasya tries to find excuses. He says that he simply forgot to write down several digits in numbers *a*, *b* and *c*, but he can't remember what numbers they actually were. Help Vasya, find such numbers *x*, *y* and *z*, with which the following conditions are met: 

* *x* + *y* = *z*,
* from the expression *x* + *y* = *z* several digits can be erased in such a way that the result will be *a* + *b* = *c*,
* the expression *x* + *y* = *z* should have the minimal length.
## Input

The first and only input line contains the expression *a* + *b* = *c* (1 ≤ *a*, *b*, *c* ≤ 106, *a*, *b* and *c* don't contain leading zeroes) which is the expression Vasya wrote down.

## Output

Print the correct expression *x* + *y* = *z* (*x*, *y* and *z* are non-negative numbers without leading zeroes). The expression *a* + *b* = *c* must be met in *x* + *y* = *z* as a subsequence. The printed solution should have the minimal possible number of characters. If there are several such solutions, you can print any of them.

## Examples

## Input


```
2+4=5  

```
## Output


```
21+4=25  

```
## Input


```
1+1=3  

```
## Output


```
1+31=32  

```
## Input


```
1+1=2  

```
## Output


```
1+1=2  

```


#### tags 

#2400 #dp 