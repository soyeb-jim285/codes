<h1 style='text-align: center;'> D. Lucky Pair</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya loves lucky numbers very much. Everybody knows that lucky numbers are positive integers whose decimal record contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya has an array *a* of *n* integers. The numbers in the array are numbered starting from 1. Unfortunately, Petya has been misbehaving and so, his parents don't allow him play with arrays that have many lucky numbers. It is guaranteed that no more than 1000 elements in the array *a* are lucky numbers. 

Petya needs to find the number of pairs of non-intersecting segments [*l*1;*r*1] and [*l*2;*r*2] (1 ≤ *l*1 ≤ *r*1 < *l*2 ≤ *r*2 ≤ *n*, all four numbers are integers) such that there's no such lucky number that occurs simultaneously in the subarray *a*[*l*1..*r*1] and in the subarray *a*[*l*2..*r*2]. Help Petya count the number of such pairs.

## Input

The first line contains an integer *n* (2 ≤ *n* ≤ 105) — the size of the array *a*. The second line contains *n* space-separated integers *a**i* (1 ≤ *a**i* ≤ 109) — array *a*. It is guaranteed that no more than 1000 elements in the array *a* are lucky numbers. 

## Output

On the single line print the only number — the answer to the problem.

Please do not use the %lld specificator to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specificator.

## Examples

## Input


```
4  
1 4 2 4  

```
## Output


```
9  

```
## Input


```
2  
4 7  

```
## Output


```
1  

```
## Input


```
4  
4 4 7 7  

```
## Output


```
9  

```
## Note

The subarray *a*[*l*..*r*] is an array that consists of elements *a**l*, *a**l* + 1, ..., *a**r*.

In the first sample there are 9 possible pairs that satisfy the condition: [1, 1] and [2, 2], [1, 1] and [2, 3], [1, 1] and [2, 4], [1, 1] and [3, 3], [1, 1] and [3, 4], [1, 1] and [4, 4], [1, 2] and [3, 3], [2, 2] and [3, 3], [3, 3] and [4, 4].

In the second sample there is only one pair of segments — [1;1] and [2;2] and it satisfies the condition.



#### tags 

#2900 #combinatorics #data_structures #implementation 