<h1 style='text-align: center;'> B. GCD of Polynomials</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Suppose you have two polynomials ![](images/c1f80b9ebc1fff5a90e16efeca54e19f317e54bc.png) and ![](images/e93789bf4b5d6fad310adc83d2bb0c83fbb30c44.png). Then polynomial ![](images/1403d2add4fc795addbde5a231d1b18b21ee687d.png) can be uniquely represented in the following way:

![](images/b6a6ad5ba0862c016c1e4aa4a61a7c60de95ebfc.png)This can be done using [long division](https://en.wikipedia.org/wiki/Polynomial_long_division). Here, ![](images/6cf750e7b244ea6a686dad217ee3f3b4e31eb81a.png) denotes the degree of polynomial *P*(*x*). ![](images/4c81bd42c0c44aaaf448ea6ae035fb3e5da7a8b8.png) is called the remainder of division of polynomial ![](images/1403d2add4fc795addbde5a231d1b18b21ee687d.png) by polynomial ![](images/0cf77e402a3ccf9ecc815acb29095e2395e322d3.png), it is also denoted as ![](images/02c2a9fc8f7311b299ac9e974f6fc85c93c4269f.png). 

Since there is a way to divide polynomials with remainder, we can define Euclid's algorithm of finding the greatest common divisor of two polynomials. The algorithm takes two polynomials ![](images/c9d3d226b2b68adecb91a880932c223f68759bcc.png). If the polynomial ![](images/0cf77e402a3ccf9ecc815acb29095e2395e322d3.png) is zero, the result is ![](images/1403d2add4fc795addbde5a231d1b18b21ee687d.png), otherwise the result is the value the algorithm returns for pair ![](images/22eb0a74c812483a9fa46cd54a82b7c63e718bce.png). On each step the degree of the second argument decreases, so the algorithm works in finite number of steps. But how large that number could be? You are to answer this question. 

You are given an integer *n*. You have to build two polynomials with degrees not greater than *n*, such that their coefficients are integers not exceeding 1 by their absolute value, the leading coefficients (ones with the greatest power of *x*) are equal to one, and the described Euclid's algorithm performs exactly *n* steps finding their greatest common divisor. Moreover, the degree of the first polynomial should be greater than the degree of the second. By a step of the algorithm we mean the transition from pair ![](images/c9d3d226b2b68adecb91a880932c223f68759bcc.png) to pair ![](images/22eb0a74c812483a9fa46cd54a82b7c63e718bce.png). 

## Input

You are given a single integer *n* (1 ≤ *n* ≤ 150) — the number of steps of the algorithm you need to reach.

## Output

Print two polynomials in the following format.

In the first line print a single integer *m* (0 ≤ *m* ≤ *n*) — the degree of the polynomial. 

In the second line print *m* + 1 integers between  - 1 and 1 — the coefficients of the polynomial, from constant to leading. 

The degree of the first polynomial should be greater than the degree of the second polynomial, the leading coefficients should be equal to 1. Euclid's algorithm should perform exactly *n* steps when called using these polynomials.

If there is no answer for the given *n*, print -1.

If there are multiple answer, print any of them.

## Examples

## Input


```
1  

```
## Output


```
1  
0 1  
0  
1  

```
## Input


```
2  

```
## Output


```
2  
-1 0 1  
1  
0 1  

```
## Note

In the second example you can print polynomials *x*2 - 1 and *x*. The sequence of transitions is

(*x*2 - 1, *x*) → (*x*,  - 1) → ( - 1, 0).There are two steps in it.



#### tags 

#2200 #constructive_algorithms #math 