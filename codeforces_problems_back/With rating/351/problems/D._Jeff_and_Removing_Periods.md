<h1 style='text-align: center;'> D. Jeff and Removing Periods</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Cosider a sequence, consisting of *n* integers: *a*1, *a*2, ..., *a**n*. Jeff can perform the following operation on sequence *a*:

* take three integers *v*, *t*, *k* (1 ≤ *v*, *t* ≤ *n*; 0 ≤ *k*; *v* + *tk* ≤ *n*), such that *a**v* = *a**v* + *t*, *a**v* + *t* = *a**v* + 2*t*, ..., *a**v* + *t*(*k* - 1) = *a**v* + *tk*;
* remove elements *a**v*, *a**v* + *t*, ..., *a**v* + *t*·*k* from the sequence *a*, the remaining elements should be reindexed *a*1, *a*2, ..., *a**n* - *k* - 1.
* permute in some order the remaining elements of sequence *a*.

A beauty of a sequence *a* is the minimum number of operations that is needed to delete all elements from sequence *a*.

Jeff's written down a sequence of *m* integers *b*1, *b*2, ..., *b**m*. Now he wants to ask *q* questions. Each question can be described with two integers *l**i*, *r**i*. The answer to the question is the beauty of sequence *b**l**i*, *b**l**i* + 1, ..., *b**r**i*. You are given the sequence *b* and all questions. Help Jeff, answer all his questions.

## Input

The first line contains integer *m* (1 ≤ *m* ≤ 105). The next line contains *m* integers *b*1, *b*2, ..., *b**m* (1 ≤ *b**i* ≤ 105). 

The third line contains integer *q* (1 ≤ *q* ≤ 105) — the number of questions. The next *q* lines contain pairs of integers, *i*-th of them contains a pair of integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *m*) — the description of *i*-th question.

## Output

In *q* lines print the answers to Jeff's queries. Print the answers according to the order of questions in input.

## Examples

## Input


```
5  
2 2 1 1 2  
5  
1 5  
1 1  
2 2  
1 3  
2 3  

```
## Output


```
2  
1  
1  
2  
2  

```
## Input


```
10  
2 1 3 3 3 3 1 3 1 1  
10  
4 8  
2 10  
1 10  
4 4  
1 3  
2 4  
6 7  
1 9  
2 5  
1 1  

```
## Output


```
2  
3  
3  
1  
3  
2  
2  
3  
2  
1  

```


#### tags 

#2700 #data_structures 