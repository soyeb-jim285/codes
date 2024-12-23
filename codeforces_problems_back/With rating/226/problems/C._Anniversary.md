<h1 style='text-align: center;'> C. Anniversary</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are less than 60 years left till the 900-th birthday anniversary of a famous Italian mathematician Leonardo Fibonacci. Of course, such important anniversary needs much preparations.

Dima is sure that it'll be great to learn to solve the following problem by the Big Day: You're given a set *A*, consisting of numbers *l*, *l* + 1, *l* + 2, ..., *r*; let's consider all its *k*-element subsets; for each such subset let's find the largest common divisor of Fibonacci numbers with indexes, determined by the subset elements. Among all found common divisors, Dima is interested in the largest one.

Dima asked to remind you that Fibonacci numbers are elements of a numeric sequence, where *F*1 = 1, *F*2 = 1, *F**n* = *F**n* - 1 + *F**n* - 2 for *n* ≥ 3.

Dima has more than half a century ahead to solve the given task, but you only have two hours. Count the residue from dividing the sought largest common divisor by *m*.

## Input

The first line contains four space-separated integers *m*, *l*, *r* and *k* (1 ≤ *m* ≤ 109; 1 ≤ *l* < *r* ≤ 1012; 2 ≤ *k* ≤ *r* - *l* + 1).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specifier.

## Output

Print a single integer — the residue from dividing the sought greatest common divisor by *m*.

## Examples

## Input


```
10 1 8 2  

```
## Output


```
3  

```
## Input


```
10 1 8 3  

```
## Output


```
1  

```


#### tags 

#2400 #data_structures #implementation #math #matrices #number_theory 