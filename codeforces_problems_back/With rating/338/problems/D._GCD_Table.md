<h1 style='text-align: center;'> D. GCD Table</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider a table *G* of size *n* × *m* such that *G*(*i*, *j*) = *GCD*(*i*, *j*) for all 1 ≤ *i* ≤ *n*, 1 ≤ *j* ≤ *m*. *GCD*(*a*, *b*) is the greatest common divisor of numbers *a* and *b*.

You have a sequence of positive integer numbers *a*1, *a*2, ..., *a**k*. We say that this sequence occurs in table *G* if it coincides with consecutive elements in some row, starting from some position. More formally, such numbers 1 ≤ *i* ≤ *n* and 1 ≤ *j* ≤ *m* - *k* + 1 should exist that *G*(*i*, *j* + *l* - 1) = *a**l* for all 1 ≤ *l* ≤ *k*.

Determine if the sequence *a* occurs in table *G*.

## Input

The first line contains three space-separated integers *n*, *m* and *k* (1 ≤ *n*, *m* ≤ 1012; 1 ≤ *k* ≤ 10000). The second line contains *k* space-separated integers *a*1, *a*2, ..., *a**k* (1 ≤ *a**i* ≤ 1012).

## Output

Print a single word "YES", if the given sequence occurs in table *G*, otherwise print "NO".

## Examples

## Input


```
100 100 5  
5 2 1 2 1  

```
## Output


```
YES  

```
## Input


```
100 8 5  
5 2 1 2 1  

```
## Output


```
NO  

```
## Input


```
100 100 7  
1 2 3 4 5 6 7  

```
## Output


```
NO  

```
## Note

Sample 1. The tenth row of table *G* starts from sequence {1, 2, 1, 2, 5, 2, 1, 2, 1, 10}. As you can see, elements from fifth to ninth coincide with sequence *a*.

Sample 2. This time the width of table *G* equals 8. Sequence *a* doesn't occur there.



#### tags 

#2900 #chinese_remainder_theorem #math #number_theory 