<h1 style='text-align: center;'> B. Interesting Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We'll call an array of *n* non-negative integers *a*[1], *a*[2], ..., *a*[*n*] interesting, if it meets *m* constraints. The *i*-th of the *m* constraints consists of three integers *l**i*, *r**i*, *q**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*) meaning that value ![](images/397fb9b81e3beb6e247c52db31e732fc1b0dd230.png) should be equal to *q**i*. 

Your task is to find any interesting array of *n* elements or state that such array doesn't exist.

Expression *x*&*y* means the bitwise AND of numbers *x* and *y*. In programming languages C++, Java and Python this operation is represented as "&", in Pascal — as "and".

## Input

The first line contains two integers *n*, *m* (1 ≤ *n* ≤ 105, 1 ≤ *m* ≤ 105) — the number of elements in the array and the number of limits.

Each of the next *m* lines contains three integers *l**i*, *r**i*, *q**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*, 0 ≤ *q**i* < 230) describing the *i*-th limit.

## Output

If the interesting array exists, in the first line print "YES" (without the quotes) and in the second line print *n* integers *a*[1], *a*[2], ..., *a*[*n*] (0 ≤ *a*[*i*] < 230) decribing the interesting array. If there are multiple answers, print any of them.

If the interesting array doesn't exist, print "NO" (without the quotes) in the single line.

## Examples

## Input


```
3 1  
1 3 3  

```
## Output


```
YES  
3 3 3  

```
## Input


```
3 2  
1 3 3  
1 3 2  

```
## Output


```
NO  

```


#### tags 

#1800 #constructive_algorithms #data_structures #trees 