<h1 style='text-align: center;'> B. Good Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Squirrel Liss is interested in sequences. She also has preferences of integers. She thinks *n* integers *a*1, *a*2, ..., *a**n* are good.

Now she is interested in good sequences. A sequence *x*1, *x*2, ..., *x**k* is called good if it satisfies the following three conditions:

* The sequence is strictly increasing, i.e. *x**i* < *x**i* + 1 for each *i* (1 ≤ *i* ≤ *k* - 1).
* No two adjacent elements are coprime, i.e. *gcd*(*x**i*, *x**i* + 1) > 1 for each *i* (1 ≤ *i* ≤ *k* - 1) (where *gcd*(*p*, *q*) denotes the greatest common divisor of the integers *p* and *q*).
* All elements of the sequence are good integers.

Find the length of the longest good sequence.

## Input

The input consists of two lines. The first line contains a single integer *n* (1 ≤ *n* ≤ 105) — the number of good integers. The second line contains a single-space separated list of good integers *a*1, *a*2, ..., *a**n* in strictly increasing order (1 ≤ *a**i* ≤ 105; *a**i* < *a**i* + 1).

## Output

Print a single integer — the length of the longest good sequence.

## Examples

## Input


```
5  
2 3 4 6 9  

```
## Output


```
4  

```
## Input


```
9  
1 2 3 5 6 7 8 9 10  

```
## Output


```
4  

```
## Note

In the first example, the following sequences are examples of good sequences: [2; 4; 6; 9], [2; 4; 6], [3; 9], [6]. The length of the longest good sequence is 4.



#### tags 

#1500 #dp #number_theory 