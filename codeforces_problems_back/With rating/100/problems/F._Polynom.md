<h1 style='text-align: center;'> F. Polynom</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

You are given a polynom in form *p*(*x*) = (*x* + *a*1)·(*x* + *a*2)·... (*x* + *a**n*). Write Pike program to print it in a standard form *p*(*x*) = *x**n* + *b*1*x**n* - 1 + ... + *b**n* - 1*x* + *b**n*. You should write each addend in form «C*X^K» (for example, 5*X^8).

Please, write the polynom in the shortest way, so you should skip unnecessary terms: some terms «C*X^K» should be reduced or even omitted. Look for the samples for clarification.

## Input

The first line of the input contains *n* (1 ≤ *n* ≤ 9). The following *n* lines contain integer *a**i* ( - 10 ≤ *a**i* ≤ 10).

## Output

Print the given polynom in a standard way. Note, that the answer in this problem response uniquely determined.

## Examples

## Input


```
2  
-1  
1  

```
## Output


```
X^2-1  

```
## Input


```
2  
1  
1  

```
## Output


```
X^2+2*X+1  

```


#### tags 

#1800 #*special #implementation 