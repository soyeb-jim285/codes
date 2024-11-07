<h1 style='text-align: center;'> A. Two Bases</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After seeing the "ALL YOUR BASE ARE BELONG TO US" meme for the first time, numbers *X* and *Y* realised that they have different bases, which complicated their relations.

You're given a number *X* represented in base *b**x* and a number *Y* represented in base *b**y*. Compare those two numbers.

## Input

The first line of the input contains two space-separated integers *n* and *b**x* (1 ≤ *n* ≤ 10, 2 ≤ *b**x* ≤ 40), where *n* is the number of digits in the *b**x*-based representation of *X*. 

The second line contains *n* space-separated integers *x*1, *x*2, ..., *x**n* (0 ≤ *x**i* < *b**x*) — the digits of *X*. They are given in the order from the most significant digit to the least significant one.

The following two lines describe *Y* in the same way: the third line contains two space-separated integers *m* and *b**y* (1 ≤ *m* ≤ 10, 2 ≤ *b**y* ≤ 40, *b**x* ≠ *b**y*), where *m* is the number of digits in the *b**y*-based representation of *Y*, and the fourth line contains *m* space-separated integers *y*1, *y*2, ..., *y**m* (0 ≤ *y**i* < *b**y*) — the digits of *Y*.

There will be no leading zeroes. Both *X* and *Y* will be positive. All digits of both numbers are given in the standard decimal numeral system.

## Output

## Output

 a single character (quotes for clarity): 

* '<' if *X* < *Y*
* '>' if *X* > *Y*
* '=' if *X* = *Y*
## Examples

## Input


```
6 2  
1 0 1 1 1 1  
2 10  
4 7  

```
## Output


```
=  

```
## Input


```
3 3  
1 0 2  
2 5  
2 4  

```
## Output


```
<  

```
## Input


```
7 16  
15 15 4 0 0 7 10  
7 9  
4 8 0 3 1 5 0  

```
## Output


```
>  

```
## Note

In the first sample, *X* = 1011112 = 4710 = *Y*.

In the second sample, *X* = 1023 = 215 and *Y* = 245 = 1123, thus *X* < *Y*.

In the third sample, ![](images/603a342b0ae3e56fed542d1c50c0a5ff6ce2cbaa.png) and *Y* = 48031509. We may notice that *X* starts with much larger digits and *b**x* is much larger than *b**y*, so *X* is clearly larger than *Y*.



#### tags 

#1100 #brute_force #implementation 