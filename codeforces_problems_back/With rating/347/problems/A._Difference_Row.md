<h1 style='text-align: center;'> A. Difference Row</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You want to arrange *n* integers *a*1, *a*2, ..., *a**n* in some order in a row. Let's define the value of an arrangement as the sum of differences between all pairs of adjacent integers.

More formally, let's denote some arrangement as a sequence of integers *x*1, *x*2, ..., *x**n*, where sequence *x* is a permutation of sequence *a*. The value of such an arrangement is (*x*1 - *x*2) + (*x*2 - *x*3) + ... + (*x**n* - 1 - *x**n*).

Find the largest possible value of an arrangement. Then, output the lexicographically smallest sequence *x* that corresponds to an arrangement of the largest possible value.

## Input

The first line of the input contains integer *n* (2 ≤ *n* ≤ 100). The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (|*a**i*| ≤ 1000).

## Output

Print the required sequence *x*1, *x*2, ..., *x**n*. Sequence *x* should be the lexicographically smallest permutation of *a* that corresponds to an arrangement of the largest possible value.

## Examples

## Input


```
5  
100 -100 50 0 -50  

```
## Output


```
100 -50 0 50 -100   

```
## Note

In the sample test case, the value of the output arrangement is (100 - ( - 50)) + (( - 50) - 0) + (0 - 50) + (50 - ( - 100)) = 200. No other arrangement has a larger value, and among all arrangements with the value of 200, the output arrangement is the lexicographically smallest one.

Sequence *x*1, *x*2, ... , *x**p* is lexicographically smaller than sequence *y*1, *y*2, ... , *y**p* if there exists an integer *r* (0 ≤ *r* < *p*) such that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 < *y**r* + 1.



#### tags 

#1300 #constructive_algorithms #implementation #sortings 