<h1 style='text-align: center;'> D. Increase Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Peter has a sequence of integers *a*1, *a*2, ..., *a**n*. Peter wants all numbers in the sequence to equal *h*. He can perform the operation of "adding one on the segment [*l*, *r*]": add one to all elements of the sequence with indices from *l* to *r* (inclusive). At that, Peter never chooses any element as the beginning of the segment twice. Similarly, Peter never chooses any element as the end of the segment twice. In other words, for any two segments [*l*1, *r*1] and [*l*2, *r*2], where Peter added one, the following inequalities hold: *l*1 ≠ *l*2 and *r*1 ≠ *r*2.

How many distinct ways are there to make all numbers in the sequence equal *h*? Print this number of ways modulo 1000000007 (109 + 7). Two ways are considered distinct if one of them has a segment that isn't in the other way.

## Input

The first line contains two integers *n*, *h* (1 ≤ *n*, *h* ≤ 2000). The next line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 2000).

## Output

Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).

## Examples

## Input


```
3 2  
1 1 1  

```
## Output


```
4  

```
## Input


```
5 1  
1 1 1 1 1  

```
## Output


```
1  

```
## Input


```
4 3  
3 2 1 1  

```
## Output


```
0  

```


#### tags 

#2100 #combinatorics #dp 