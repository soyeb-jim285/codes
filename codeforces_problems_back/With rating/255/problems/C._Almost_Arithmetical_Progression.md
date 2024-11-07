<h1 style='text-align: center;'> C. Almost Arithmetical Progression</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gena loves sequences of numbers. Recently, he has discovered a new type of sequences which he called an almost arithmetical progression. A sequence is an almost arithmetical progression, if its elements can be represented as:

* *a*1 = *p*, where *p* is some integer;
* *a**i* = *a**i* - 1 + ( - 1)*i* + 1·*q* (*i* > 1), where *q* is some integer.

Right now Gena has a piece of paper with sequence *b*, consisting of *n* integers. Help Gena, find there the longest subsequence of integers that is an almost arithmetical progression.

Sequence *s*1,  *s*2,  ...,  *s**k* is a subsequence of sequence *b*1,  *b*2,  ...,  *b**n*, if there is such increasing sequence of indexes *i*1, *i*2, ..., *i**k* (1  ≤  *i*1  <  *i*2  < ...   <  *i**k*  ≤  *n*), that *b**i**j*  =  *s**j*. In other words, sequence *s* can be obtained from *b* by crossing out some elements.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 4000). The next line contains *n* integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ 106).

## Output

Print a single integer — the length of the required longest subsequence.

## Examples

## Input


```
2  
3 5  

```
## Output


```
2  

```
## Input


```
4  
10 20 10 30  

```
## Output


```
3  

```
## Note

In the first test the sequence actually is the suitable subsequence. 

In the second test the following subsequence fits: 10, 20, 10.



#### tags 

#1500 #brute_force #dp 