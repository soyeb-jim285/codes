<h1 style='text-align: center;'> D. Not Quick Transformation</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let *a* be an array consisting of *n* numbers. The array's elements are numbered from 1 to *n*, *even* is an array consisting of the numerals whose numbers are even in *a* (*even**i* = *a*2*i*, 1 ≤ 2*i* ≤ *n*), *odd* is an array consisting of the numberals whose numbers are odd in *а* (*odd**i* = *a*2*i* - 1, 1 ≤ 2*i* - 1 ≤ *n*). Then let's define the transformation of array *F*(*a*) in the following manner:

* if *n* > 1, *F*(*a*) = *F*(*odd*) + *F*(*even*), where operation " + " stands for the arrays' concatenation (joining together)
* if *n* = 1, *F*(*a*) = *a*

Let *a* be an array consisting of *n* numbers 1, 2, 3, ..., *n*. Then *b* is the result of applying the transformation to the array *a* (so *b* = *F*(*a*)). You are given *m* queries (*l*, *r*, *u*, *v*). Your task is to find for each query the sum of numbers *b**i*, such that *l* ≤ *i* ≤ *r* and *u* ≤ *b**i* ≤ *v*. You should print the query results modulo *mod*.

## Input

The first line contains three integers *n*, *m*, *mod* (1 ≤ *n* ≤ 1018, 1 ≤ *m* ≤ 105, 1 ≤ *mod* ≤ 109). Next *m* lines describe the queries. Each query is defined by four integers *l*, *r*, *u*, *v* (1 ≤ *l* ≤ *r* ≤ *n*, 1 ≤ *u* ≤ *v* ≤ 1018).

Please do not use the %lld specificator to read or write 64-bit integers in C++. Use %I64d specificator.

## Output

Print *m* lines each containing an integer — remainder modulo *mod* of the query result.

## Examples

## Input


```
4 5 10000  
2 3 4 5  
2 4 1 3  
1 2 2 4  
2 3 3 5  
1 3 3 4  

```
## Output


```
0  
5  
3  
3  
3  

```
## Input


```
2 5 10000  
1 2 2 2  
1 1 4 5  
1 1 2 5  
1 1 1 3  
1 2 5 5  

```
## Output


```
2  
0  
0  
1  
0  

```
## Note

Let's consider the first example. First let's construct an array *b* = *F*(*a*) = *F*([1, 2, 3, 4]). 

* Step 1. *F*([1, 2, 3, 4]) = *F*([1, 3]) + *F*([2, 4])
* Step 2. *F*([1, 3]) = *F*([1]) + *F*([3]) = [1] + [3] = [1, 3]
* Step 3. *F*([2, 4]) = *F*([2]) + *F*([4]) = [2] + [4] = [2, 4]
* Step 4. *b* = *F*([1, 2, 3, 4]) = *F*([1, 3]) + *F*([2, 4]) = [1, 3] + [2, 4] = [1, 3, 2, 4]

 Thus *b* = [1, 3, 2, 4]. Let's consider the first query *l* = 2, *r* = 3, *u* = 4, *v* = 5. The second and third positions in the array *b* do not have numbers in the range [4, 5], so the sum obviously equals zero. Let's consider the second query *l* = 2, *r* = 4, *u* = 1, *v* = 3. The second and third positions have two numbers that belong to the range [1, 3], their sum equals 5.

#### tags 

#2500 #divide_and_conquer #math 