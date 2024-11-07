<h1 style='text-align: center;'> D. Iterated Linear Function</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider a linear function *f*(*x*) = *Ax* + *B*. Let's define *g*(0)(*x*) = *x* and *g*(*n*)(*x*) = *f*(*g*(*n* - 1)(*x*)) for *n* > 0. For the given integer values *A*, *B*, *n* and *x* find the value of *g*(*n*)(*x*) modulo 109 + 7.

## Input

The only line contains four integers *A*, *B*, *n* and *x* (1 ≤ *A*, *B*, *x* ≤ 109, 1 ≤ *n* ≤ 1018) — the parameters from the problem statement.

Note that the given value *n* can be too large, so you should use 64-bit integer type to store it. In C++ you can use the long long integer type and in Java you can use long integer type.

## Output

Print the only integer *s* — the value *g*(*n*)(*x*) modulo 109 + 7.

## Examples

## Input


```
3 4 1 1  

```
## Output


```
7  

```
## Input


```
3 4 2 1  

```
## Output


```
25  

```
## Input


```
3 4 3 1  

```
## Output


```
79  

```


#### tags 

#1700 #math #number_theory 