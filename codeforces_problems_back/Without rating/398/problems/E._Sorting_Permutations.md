<h1 style='text-align: center;'> E. Sorting Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We are given a permutation sequence *a*1, *a*2, ..., *a**n* of numbers from 1 to *n*. Let's assume that in one second, we can choose some disjoint pairs (*u*1, *v*1), (*u*2, *v*2), ..., (*u**k*, *v**k*) and swap all *a**u**i* and *a**v**i* for every *i* at the same time (1 ≤ *u**i* < *v**i* ≤ *n*). The pairs are disjoint if every *u**i* and *v**j* are different from each other.

We want to sort the sequence completely in increasing order as fast as possible. Given the initial permutation, calculate the number of ways to achieve this. Two ways are different if and only if there is a time *t*, such that the set of pairs used for swapping at that time are different as sets (so ordering of pairs doesn't matter). If the given permutation is already sorted, it takes no time to sort, so the number of ways to sort it is 1.

To make the problem more interesting, we have *k* holes inside the permutation. So exactly *k* numbers of *a*1, *a*2, ..., *a**n* are not yet determined. For every possibility of filling the holes, calculate the number of ways, and print the total sum of these values modulo 1000000007 (109 + 7).

## Input

The first line contains two integers *n* (1 ≤ *n* ≤ 105) and *k* (0 ≤ *k* ≤ 12). The second line contains the permutation sequence *a*1, ..., *a**n* (0 ≤ *a**i* ≤ *n*). If a number is not yet determined, it is denoted as 0. There are exactly *k* zeroes. All the numbers *a**i* that aren't equal to zero are distinct.

## Output

Print the total sum of the number of ways modulo 1000000007 (109 + 7).

## Examples

## Input


```
5 0  
1 5 2 4 3  

```
## Output


```
6  

```
## Input


```
5 2  
1 0 2 4 0  

```
## Output


```
7  

```


#### tags 

