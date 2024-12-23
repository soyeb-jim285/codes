<h1 style='text-align: center;'> B. Little Elephant and Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 0.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Little Elephant loves sortings.

He has an array *a* consisting of *n* integers. Let's number the array elements from 1 to *n*, then the *i*-th element will be denoted as *a**i*. The Little Elephant can make one move to choose an arbitrary pair of integers *l* and *r* (1 ≤ *l* ≤ *r* ≤ *n*) and increase *a**i* by 1 for all *i* such that *l* ≤ *i* ≤ *r*.

Help the Little Elephant find the minimum number of moves he needs to convert array *a* to an arbitrary array sorted in the non-decreasing order. Array *a*, consisting of *n* elements, is sorted in the non-decreasing order if for any *i* (1 ≤ *i* < *n*) *a**i* ≤ *a**i* + 1 holds.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 105) — the size of array *a*. The next line contains *n* integers, separated by single spaces — array *a* (1 ≤ *a**i* ≤ 109). The array elements are listed in the line in the order of their index's increasing.

## Output

In a single line print a single integer — the answer to the problem.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
3  
1 2 3  

```
## Output


```
0  

```
## Input


```
3  
3 2 1  

```
## Output


```
2  

```
## Input


```
4  
7 4 1 47  

```
## Output


```
6  

```
## Note

In the first sample the array is already sorted in the non-decreasing order, so the answer is 0.

In the second sample you need to perform two operations: first increase numbers from second to third (after that the array will be: [3, 3, 2]), and second increase only the last element (the array will be: [3, 3, 3]).

In the third sample you should make at least 6 steps. The possible sequence of the operations is: (2; 3), (2; 3), (2; 3), (3; 3), (3; 3), (3; 3). After that the array converts to [7, 7, 7, 47].



#### tags 

#1400 #brute_force #greedy 