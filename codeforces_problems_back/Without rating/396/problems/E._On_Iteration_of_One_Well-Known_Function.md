<h1 style='text-align: center;'> E. On Iteration of One Well-Known Function</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Of course, many of you can calculate φ(*n*) — the number of positive integers that are less than or equal to *n*, that are coprime with *n*. But what if we need to calculate φ(φ(...φ(*n*))), where function φ is taken *k* times and *n* is given in the canonical decomposition into prime factors? 

You are given *n* and *k*, calculate the value of φ(φ(...φ(*n*))). Print the result in the canonical decomposition into prime factors.

## Input

The first line contains integer *m* (1 ≤ *m* ≤ 105) — the number of distinct prime divisors in the canonical representaion of *n*.

Each of the next *m* lines contains a pair of space-separated integers *p**i*, *a**i* (2 ≤ *p**i* ≤ 106; 1 ≤ *a**i* ≤ 1017) — another prime divisor of number *n* and its power in the canonical representation. The sum of all *a**i* doesn't exceed 1017. Prime divisors in the input follow in the strictly increasing order.

The last line contains integer *k* (1 ≤ *k* ≤ 1018).

## Output

In the first line, print integer *w* — the number of distinct prime divisors of number φ(φ(...φ(*n*))), where function φ is taken *k* times.

Each of the next *w* lines must contain two space-separated integers *q**i*, *b**i* (*b**i* ≥ 1) — another prime divisor and its power in the canonical representaion of the result. Numbers *q**i* must go in the strictly increasing order.

## Examples

## Input


```
1  
7 1  
1  

```
## Output


```
2  
2 1  
3 1  

```
## Input


```
1  
7 1  
2  

```
## Output


```
1  
2 1  

```
## Input


```
1  
2 100000000000000000  
10000000000000000  

```
## Output


```
1  
2 90000000000000000  

```
## Note

You can read about canonical representation of a positive integer here: http://en.wikipedia.org/wiki/Fundamental_theorem_of_arithmetic.

You can read about function φ(*n*) here: http://en.wikipedia.org/wiki/Euler's_totient_function.



#### tags 

#math 