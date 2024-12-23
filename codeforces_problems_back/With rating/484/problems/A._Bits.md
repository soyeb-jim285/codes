<h1 style='text-align: center;'> A. Bits</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's denote as ![](images/6500127ba81ee2a9ffdacf23b301df518aa9cd65.png) the number of bits set ('1' bits) in the binary representation of the non-negative integer *x*.

You are given multiple queries consisting of pairs of integers *l* and *r*. For each query, find the *x*, such that *l* ≤ *x* ≤ *r*, and ![](images/6500127ba81ee2a9ffdacf23b301df518aa9cd65.png) is maximum possible. If there are multiple such numbers find the smallest of them.

## Input

The first line contains integer *n* — the number of queries (1 ≤ *n* ≤ 10000).

Each of the following *n* lines contain two integers *l**i*, *r**i* — the arguments for the corresponding query (0 ≤ *l**i* ≤ *r**i* ≤ 1018).

## Output

For each query print the answer in a separate line.

## Examples

## Input


```
3  
1 2  
2 4  
1 10  

```
## Output


```
1  
3  
7  

```
## Note

The binary representations of numbers from 1 to 10 are listed below:

110 = 12

210 = 102

310 = 112

410 = 1002

510 = 1012

610 = 1102

710 = 1112

810 = 10002

910 = 10012

1010 = 10102



#### tags 

#1700 #bitmasks #constructive_algorithms 