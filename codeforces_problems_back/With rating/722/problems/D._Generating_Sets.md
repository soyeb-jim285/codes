<h1 style='text-align: center;'> D. Generating Sets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a set *Y* of *n* distinct positive integers *y*1, *y*2, ..., *y**n*.

Set *X* of *n* distinct positive integers *x*1, *x*2, ..., *x**n* is said to generate set *Y* if one can transform *X* to *Y* by applying some number of the following two operation to integers in *X*:

1. Take any integer *x**i* and multiply it by two, i.e. replace *x**i* with 2·*x**i*.
2. Take any integer *x**i*, multiply it by two and add one, i.e. replace *x**i* with 2·*x**i* + 1.

Note that integers in *X* are not required to be distinct after each operation.

Two sets of distinct integers *X* and *Y* are equal if they are equal as sets. In other words, if we write elements of the sets in the array in the increasing order, these arrays would be equal.

Note, that any set of integers (or its permutation) generates itself.

You are given a set *Y* and have to find a set *X* that generates *Y* and the maximum element of *X* is mininum possible.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 50 000) — the number of elements in *Y*.

The second line contains *n* integers *y*1, ..., *y**n* (1 ≤ *y**i* ≤ 109), that are guaranteed to be distinct.

## Output

Print *n* integers — set of distinct integers that generate *Y* and the maximum element of which is minimum possible. If there are several such sets, print any of them.

## Examples

## Input


```
5  
1 2 3 4 5  

```
## Output


```
4 5 2 3 1   

```
## Input


```
6  
15 14 3 13 1 12  

```
## Output


```
12 13 14 7 3 1   

```
## Input


```
6  
9 7 13 17 5 11  

```
## Output


```
4 5 2 6 3 1   

```


#### tags 

#1900 #binary_search #data_structures #dfs_and_similar #greedy #strings #trees 