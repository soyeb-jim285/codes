<h1 style='text-align: center;'> E. Two Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On an IT lesson Valera studied data compression. The teacher told about a new method, which we shall now describe to you.

Let {*a*1, *a*2, ..., *a**n*} be the given sequence of lines needed to be compressed. Here and below we shall assume that all lines are of the same length and consist only of the digits 0 and 1. Let's define the compression function:

* *f*(empty sequence) = empty string
* *f*(*s*) = *s*.
* *f*(*s*1, *s*2) =  the smallest in length string, which has one of the prefixes equal to *s*1 and one of the suffixes equal to *s*2. For example, *f*(001, 011) = 0011, *f*(111, 011) = 111011.
* *f*(*a*1, *a*2, ..., *a**n*) = *f*(*f*(*a*1, *a*2, *a**n* - 1), *a**n*). For example, *f*(000, 000, 111) = *f*(*f*(000, 000), 111) = *f*(000, 111) = 000111.

Valera faces a real challenge: he should divide the given sequence {*a*1, *a*2, ..., *a**n*} into two subsequences {*b*1, *b*2, ..., *b**k*} and {*c*1, *c*2, ..., *c**m*}, *m* + *k* = *n*, so that the value of *S* = |*f*(*b*1, *b*2, ..., *b**k*)| + |*f*(*c*1, *c*2, ..., *c**m*)| took the minimum possible value. Here |*p*| denotes the length of the string *p*.

## Note

 that it is not allowed to change the relative order of lines in the subsequences. It is allowed to make one of the subsequences empty. Each string from the initial sequence should belong to exactly one subsequence. Elements of subsequences *b* and *c* don't have to be consecutive in the original sequence *a*, i. e. elements of *b* and *c* can alternate in *a* (see samples 2 and 3).

Help Valera to find the minimum possible value of *S*.

## Input

The first line of input data contains an integer *n* — the number of strings (1 ≤ *n* ≤ 2·105). Then on *n* lines follow elements of the sequence — strings whose lengths are from 1 to 20 characters, consisting only of digits 0 and 1. The *i* + 1-th input line contains the *i*-th element of the sequence. Elements of the sequence are separated only by a newline. It is guaranteed that all lines have the same length.

## Output

Print a single number — the minimum possible value of *S*.

## Examples

## Input


```
3  
01  
10  
01  

```
## Output


```
4  

```
## Input


```
4  
000  
111  
110  
001  

```
## Output


```
8  

```
## Input


```
5  
10101  
01010  
11111  
01000  
10010  

```
## Output


```
17  

```
## Note

Detailed answers to the tests:

* The best option is to make one of the subsequences empty, and the second one equal to the whole given sequence. |*f*(01, 10, 01)| = |*f*(*f*(01, 10), 01)| = |*f*(010, 01)| = |0101| = 4.
* The best option is: *b* = {000, 001}, *c* = {111, 110}. *S* = |*f*(000, 001)| + |*f*(111, 110)| = |0001| + |1110| = 8.
* The best option is: *b* = {10101, 01010, 01000}, *c* = {11111, 10010}. *S* = |10101000| + |111110010| = 17.


#### tags 

#2800 #bitmasks #dp 