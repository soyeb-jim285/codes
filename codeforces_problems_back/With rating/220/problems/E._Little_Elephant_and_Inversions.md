<h1 style='text-align: center;'> E. Little Elephant and Inversions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Little Elephant has array *a*, consisting of *n* positive integers, indexed from 1 to *n*. Let's denote the number with index *i* as *a**i*.

The Little Elephant wants to count, how many pairs of integers *l* and *r* are there, such that 1 ≤ *l* < *r* ≤ *n* and sequence *b* = *a*1*a*2... *a**l**a**r**a**r* + 1... *a**n* has no more than *k* inversions. 

An inversion in sequence *b* is a pair of elements of the sequence *b*, that change their relative order after a stable sorting of the sequence. In other words, an inversion is a pair of integers *i* and *j*, such that 1 ≤ *i* < *j* ≤ |*b*| and *b**i* > *b**j*, where |*b*| is the length of sequence *b*, and *b**j* is its *j*-th element.

Help the Little Elephant and count the number of the described pairs.

## Input

The first line contains two integers *n* and *k* (2 ≤ *n* ≤ 105, 0 ≤ *k* ≤ 1018) — the size of array *a* and the maximum allowed number of inversions respectively. The next line contains *n* positive integers, separated by single spaces, *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109) — elements of array *a*.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specifier.

## Output

In a single line print a single number — the answer to the problem.

## Examples

## Input


```
3 1  
1 3 2  

```
## Output


```
3  

```
## Input


```
5 2  
1 3 2 1 7  

```
## Output


```
6  

```


#### tags 

#2400 #data_structures #two_pointers 