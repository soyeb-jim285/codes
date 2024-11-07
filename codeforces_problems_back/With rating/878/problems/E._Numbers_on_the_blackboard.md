<h1 style='text-align: center;'> E. Numbers on the blackboard</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A sequence of *n* integers is written on a blackboard. Soon Sasha will come to the blackboard and start the following actions: let *x* and *y* be two adjacent numbers (*x* before *y*), then he can remove them and write *x* + 2*y* instead of them. He will perform these operations until one number is left. Sasha likes big numbers and will get the biggest possible number.

Nikita wants to get to the blackboard before Sasha and erase some of the numbers. He has *q* options, in the option *i* he erases all numbers to the left of the *l**i*-th number and all numbers to the right of *r**i*-th number, i. e. all numbers between the *l**i*-th and the *r**i*-th, inclusive, remain on the blackboard. For each of the options he wants to know how big Sasha's final number is going to be. This number can be very big, so output it modulo 109 + 7.

## Input

The first line contains two integers *n* and *q* (1 ≤ *n*, *q* ≤ 105) — the number of integers on the blackboard and the number of Nikita's options.

The next line contains *n* integers *a*1, *a*2, ..., *a**n* ( - 109 ≤ *a**i* ≤ 109) — the sequence on the blackboard.

Each of the next *q* lines contains two integers *l**i* and *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*), describing Nikita's options.

## Output

For each option output Sasha's result modulo 109 + 7.

## Examples

## Input


```
3 3  
1 2 3  
1 3  
1 2  
2 3  

```
## Output


```
17  
5  
8  

```
## Input


```
3 1  
1 2 -3  
1 3  

```
## Output


```
1000000006  

```
## Input


```
4 2  
1 1 1 -1  
1 4  
3 4  

```
## Output


```
5  
1000000006  

```
## Note

In the second sample Nikita doesn't erase anything. Sasha first erases the numbers 1 and 2 and writes 5. Then he erases 5 and -3 and gets -1. -1 modulo 109 + 7 is 109 + 6.



#### tags 

#3300 #combinatorics #dp 