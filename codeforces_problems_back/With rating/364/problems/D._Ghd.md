<h1 style='text-align: center;'> D. Ghd</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

John Doe offered his sister Jane Doe find the gcd of some set of numbers *a*.

Gcd is a positive integer *g*, such that all number from the set are evenly divisible by *g* and there isn't such *g*' (*g*' > *g*), that all numbers of the set are evenly divisible by *g*'.

Unfortunately Jane couldn't cope with the task and John offered her to find the ghd of the same subset of numbers.

Ghd is a positive integer *g*, such that at least half of numbers from the set are evenly divisible by *g* and there isn't such *g*' (*g*' > *g*) that at least half of the numbers from the set are evenly divisible by *g*'.

Jane coped with the task for two hours. Please try it, too.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 106) showing how many numbers are in set *a*. The second line contains space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1012). Please note, that given set can contain equal numbers.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the %I64d specifier.

## Output

Print a single integer *g* — the Ghd of set *a*.

## Examples

## Input


```
6  
6 2 3 4 5 6  

```
## Output


```
3  

```
## Input


```
5  
5 5 6 10 15  

```
## Output


```
5  

```


#### tags 

#2900 #brute_force #math #probabilities 