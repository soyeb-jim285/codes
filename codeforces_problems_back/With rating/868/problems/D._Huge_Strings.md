<h1 style='text-align: center;'> D. Huge Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* strings *s*1, *s*2, ..., *s**n* consisting of characters 0 and 1. *m* operations are performed, on each of them you concatenate two existing strings into a new one. On the *i*-th operation the concatenation *s**a**i**s**b**i* is saved into a new string *s**n* + *i* (the operations are numbered starting from 1). After each operation you need to find the maximum positive integer *k* such that all possible strings consisting of 0 and 1 of length *k* (there are 2*k* such strings) are substrings of the new string. If there is no such *k*, print 0.

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 100) — the number of strings. The next *n* lines contain strings *s*1, *s*2, ..., *s**n* (1 ≤ |*s**i*| ≤ 100), one per line. The total length of strings is not greater than 100.

The next line contains single integer *m* (1 ≤ *m* ≤ 100) — the number of operations. *m* lines follow, each of them contains two integers *a**i* abd *b**i* (1 ≤ *a**i*, *b**i* ≤ *n* + *i* - 1) — the number of strings that are concatenated to form *s**n* + *i*.

## Output

Print *m* lines, each should contain one integer — the answer to the question after the corresponding operation.

## Example

## Input


```
5  
01  
10  
101  
11111  
0  
3  
1 2  
6 5  
4 4  

```
## Output


```
1  
2  
0  

```
## Note

On the first operation, a new string "0110" is created. For *k* = 1 the two possible binary strings of length *k* are "0" and "1", they are substrings of the new string. For *k* = 2 and greater there exist strings of length *k* that do not appear in this string (for *k* = 2 such string is "00"). So the answer is 1.

On the second operation the string "01100" is created. Now all strings of length *k* = 2 are present.

On the third operation the string "1111111111" is created. There is no zero, so the answer is 0.



#### tags 

#2200 #bitmasks #brute_force #dp #implementation #strings 