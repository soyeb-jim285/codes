<h1 style='text-align: center;'> F. Double Knapsack</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two multisets *A* and *B*. Each multiset has exactly *n* integers each between 1 and *n* inclusive. Multisets may contain multiple copies of the same number.

You would like to find a nonempty subset of *A* and a nonempty subset of *B* such that the sum of elements in these subsets are equal. Subsets are also multisets, i.e. they can contain elements with equal values.

If no solution exists, print  - 1. Otherwise, print the indices of elements in any such subsets of *A* and *B* that have the same sum.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 1 000 000) — the size of both multisets.

The second line contains *n* integers, denoting the elements of *A*. Each element will be between 1 and *n* inclusive.

The third line contains *n* integers, denoting the elements of *B*. Each element will be between 1 and *n* inclusive.

## Output

If there is no solution, print a single integer  - 1. Otherwise, your solution should be printed on four lines.

The first line should contain a single integer *k**a*, the size of the corresponding subset of *A*. The second line should contain *k**a* distinct integers, the indices of the subset of *A*.

The third line should contain a single integer *k**b*, the size of the corresponding subset of *B*. The fourth line should contain *k**b* distinct integers, the indices of the subset of *B*.

Elements in both sets are numbered from 1 to *n*. If there are multiple possible solutions, print any of them.

## Examples

## Input


```
10  
10 10 10 10 10 10 10 10 10 10  
10 9 8 7 6 5 4 3 2 1  

```
## Output


```
1  
2  
3  
5 8 10  

```
## Input


```
5  
4 4 3 3 3  
2 2 2 2 5  

```
## Output


```
2  
2 3  
2  
3 5  

```


#### tags 

#3000 #constructive_algorithms #two_pointers 