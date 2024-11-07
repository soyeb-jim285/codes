<h1 style='text-align: center;'> F. Igor and Interesting Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Igor likes hexadecimal notation and considers positive integer in the hexadecimal notation interesting if each digit and each letter in it appears no more than *t* times. For example, if *t* = 3, then integers 13a13322, aaa, abcdef0123456789 are interesting, but numbers aaaa, abababab and 1000000 are not interesting.

Your task is to find the *k*-th smallest interesting for Igor integer in the hexadecimal notation. The integer should not contain leading zeros.

## Input

The first line contains the two integers *k* and *t* (1 ≤ *k* ≤ 2·109, 1 ≤ *t* ≤ 10) — the number of the required integer and the maximum number of times some integer or letter can appear in interesting integer.

It can be shown that the answer always exists for such constraints.

## Output

Print in the hexadecimal notation the only integer that is the *k*-th smallest interesting integer for Igor.

## Examples

## Input


```
17 1  

```
## Output


```
12  

```
## Input


```
1000000 2  

```
## Output


```
fca2c  

```
## Note

The first 20 interesting integers if *t* = 1: 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f, 10, 12, 13, 14, 15. So the answer for the first example equals 12.



#### tags 

#2500 #brute_force #combinatorics #dp #math 