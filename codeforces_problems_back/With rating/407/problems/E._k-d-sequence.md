<h1 style='text-align: center;'> E. k-d-sequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We'll call a sequence of integers a good *k*-*d* sequence if we can add to it at most *k* numbers in such a way that after the sorting the sequence will be an arithmetic progression with difference *d*.

You got hold of some sequence *a*, consisting of *n* integers. Your task is to find its longest contiguous subsegment, such that it is a good *k*-*d* sequence.

## Input

The first line contains three space-separated integers *n*, *k*, *d* (1 ≤ *n* ≤ 2·105; 0 ≤ *k* ≤ 2·105; 0 ≤ *d* ≤ 109). The second line contains *n* space-separated integers: *a*1, *a*2, ..., *a**n* ( - 109 ≤ *a**i* ≤ 109) — the actual sequence.

## Output

Print two space-separated integers *l*, *r* (1 ≤ *l* ≤ *r* ≤ *n*) show that sequence *a**l*, *a**l* + 1, ..., *a**r* is the longest subsegment that is a good *k*-*d* sequence.

If there are multiple optimal answers, print the one with the minimum value of *l*.

## Examples

## Input


```
6 1 2  
4 3 2 8 6 2  

```
## Output


```
3 5  

```
## Note

In the first test sample the answer is the subsegment consisting of numbers 2, 8, 6 — after adding number 4 and sorting it becomes sequence 2, 4, 6, 8 — the arithmetic progression with difference 2.



#### tags 

#3100 #data_structures 