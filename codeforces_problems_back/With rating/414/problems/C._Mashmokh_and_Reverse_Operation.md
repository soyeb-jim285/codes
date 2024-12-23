<h1 style='text-align: center;'> C. Mashmokh and Reverse Operation</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Mashmokh's boss, Bimokh, didn't like Mashmokh. So he fired him. Mashmokh decided to go to university and participate in ACM instead of finding a new job. He wants to become a member of Bamokh's team. In order to join he was given some programming tasks and one week to solve them. Mashmokh is not a very experienced programmer. Actually he is not a programmer at all. So he wasn't able to solve them. That's why he asked you to help him with these tasks. One of these tasks is the following.

You have an array *a* of length 2*n* and *m* queries on it. The *i*-th query is described by an integer *q**i*. In order to perform the *i*-th query you must:

* split the array into 2*n* - *q**i* parts, where each part is a subarray consisting of 2*q**i* numbers; the *j*-th subarray (1 ≤ *j* ≤ 2*n* - *q**i*) should contain the elements *a*[(*j* - 1)·2*q**i* + 1], *a*[(*j* - 1)·2*q**i* + 2], ..., *a*[(*j* - 1)·2*q**i* + 2*q**i*];
* reverse each of the subarrays;
* join them into a single array in the same order (this array becomes new array *a*);
* output the number of inversions in the new *a*.

Given initial array *a* and all the queries. Answer all the queries. Please, note that the changes from some query is saved for further queries.

## Input

The first line of input contains a single integer *n* (0 ≤ *n* ≤ 20). 

The second line of input contains 2*n* space-separated integers *a*[1], *a*[2], ..., *a*[2*n*] (1 ≤ *a*[*i*] ≤ 109), the initial array.

The third line of input contains a single integer *m* (1 ≤ *m* ≤ 106). 

The fourth line of input contains *m* space-separated integers *q*1, *q*2, ..., *q**m* (0 ≤ *q**i* ≤ *n*), the queries.

## Note

: since the size of the input and output could be very large, don't use slow output techniques in your language. For example, do not use input and output streams (cin, cout) in C++.

## Output

## Output

 *m* lines. In the *i*-th line print the answer (the number of inversions) for the *i*-th query.

## Examples

## Input


```
2  
2 1 4 3  
4  
1 2 0 2  

```
## Output


```
0  
6  
6  
0  

```
## Input


```
1  
1 2  
3  
0 1 1  

```
## Output


```
0  
1  
0  

```
## Note

If we reverse an array *x*[1], *x*[2], ..., *x*[*n*] it becomes new array *y*[1], *y*[2], ..., *y*[*n*], where *y*[*i*] = *x*[*n* - *i* + 1] for each *i*.

The number of inversions of an array *x*[1], *x*[2], ..., *x*[*n*] is the number of pairs of indices *i*, *j* such that: *i* < *j* and *x*[*i*] > *x*[*j*].



#### tags 

#2100 #combinatorics #divide_and_conquer 