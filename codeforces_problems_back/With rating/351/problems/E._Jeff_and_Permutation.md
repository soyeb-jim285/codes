<h1 style='text-align: center;'> E. Jeff and Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jeff's friends know full well that the boy likes to get sequences and arrays for his birthday. Thus, Jeff got sequence *p*1, *p*2, ..., *p**n* for his birthday.

Jeff hates inversions in sequences. An inversion in sequence *a*1, *a*2, ..., *a**n* is a pair of indexes *i*, *j* (1 ≤ *i* < *j* ≤ *n*), such that an inequality *a**i* > *a**j* holds.

Jeff can multiply some numbers of the sequence *p* by -1. At that, he wants the number of inversions in the sequence to be minimum. Help Jeff and find the minimum number of inversions he manages to get.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 2000). The next line contains *n* integers — sequence *p*1, *p*2, ..., *p**n* (|*p**i*| ≤ 105). The numbers are separated by spaces.

## Output

In a single line print the answer to the problem — the minimum number of inversions Jeff can get.

## Examples

## Input


```
2  
2 1  

```
## Output


```
0  

```
## Input


```
9  
-2 0 -1 0 -1 2 1 0 -1  

```
## Output


```
6  

```


#### tags 

#2200 #greedy 