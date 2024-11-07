<h1 style='text-align: center;'> A. Memory and Crow</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* integers *b*1, *b*2, ..., *b**n* written in a row. For all *i* from 1 to *n*, values *a**i* are defined by the crows performing the following procedure:

* The crow sets *a**i* initially 0.
* The crow then adds *b**i* to *a**i*, subtracts *b**i* + 1, adds the *b**i* + 2 number, and so on until the *n*'th number. Thus, *a**i* = *b**i* - *b**i* + 1 + *b**i* + 2 - *b**i* + 3....

Memory gives you the values *a*1, *a*2, ..., *a**n*, and he now wants you to find the initial numbers *b*1, *b*2, ..., *b**n* written in the row? Can you do it?

## Input

The first line of the input contains a single integer *n* (2 ≤ *n* ≤ 100 000) — the number of integers written in the row.

The next line contains *n*, the *i*'th of which is *a**i* ( - 109 ≤ *a**i* ≤ 109) — the value of the *i*'th number.

## Output

Print *n* integers corresponding to the sequence *b*1, *b*2, ..., *b**n*. It's guaranteed that the answer is unique and fits in 32-bit integer type.

## Examples

## Input


```
5  
6 -4 8 -2 3  

```
## Output


```
2 4 6 1 3   

```
## Input


```
5  
3 -2 -1 5 6  

```
## Output


```
1 -3 4 11 6   

```
## Note

In the first sample test, the crows report the numbers 6, - 4, 8, - 2, and 3 when he starts at indices 1, 2, 3, 4 and 5 respectively. It is easy to check that the sequence 2 4 6 1 3 satisfies the reports. For example, 6 = 2 - 4 + 6 - 1 + 3, and  - 4 = 4 - 6 + 1 - 3.

In the second sample test, the sequence 1,  - 3, 4, 11, 6 satisfies the reports. For example, 5 = 11 - 6 and 6 = 6.



#### tags 

#800 #implementation #math 