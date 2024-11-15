<h1 style='text-align: center;'> E. Martian Luck</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You know that the Martians use a number system with base *k*. Digit *b* (0 ≤ *b* < *k*) is considered lucky, as the first contact between the Martians and the Earthlings occurred in year *b* (by Martian chronology).

A digital root *d*(*x*) of number *x* is a number that consists of a single digit, resulting after cascading summing of all digits of number *x*. Word "cascading" means that if the first summing gives us a number that consists of several digits, then we sum up all digits again, and again, until we get a one digit number.

For example, *d*(35047) = *d*((3 + 5 + 0 + 4)7) = *d*(157) = *d*((1 + 5)7) = *d*(67) = 67. In this sample the calculations are performed in the 7-base notation.

If a number's digital root equals *b*, the Martians also call this number lucky.

You have string *s*, which consists of *n* digits in the *k*-base notation system. Your task is to find, how many distinct substrings of the given string are lucky numbers. Leading zeroes are permitted in the numbers.

## Note

 that substring *s*[*i*... *j*] of the string *s* = *a*1*a*2... *a**n* (1 ≤ *i* ≤ *j* ≤ *n*) is the string *a**i**a**i* + 1... *a**j*. Two substrings *s*[*i*1... *j*1] and *s*[*i*2... *j*2] of the string *s* are different if either *i*1 ≠ *i*2 or *j*1 ≠ *j*2.

## Input

The first line contains three integers *k*, *b* and *n* (2 ≤ *k* ≤ 109, 0 ≤ *b* < *k*, 1 ≤ *n* ≤ 105).

The second line contains string *s* as a sequence of *n* integers, representing digits in the *k*-base notation: the *i*-th integer equals *a**i* (0 ≤ *a**i* < *k*) — the *i*-th digit of string *s*. The numbers in the lines are space-separated.

## Output

Print a single integer — the number of substrings that are lucky numbers.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
10 5 6  
3 2 0 5 6 1  

```
## Output


```
5
```
## Input


```
7 6 4  
3 5 0 4  

```
## Output


```
1
```
## Input


```
257 0 3  
0 0 256  

```
## Output


```
3
```
## Note

In the first sample the following substrings have the sought digital root: *s*[1... 2] = "3 2", *s*[1... 3] = "3 2 0", *s*[3... 4] = "0 5", *s*[4... 4] = "5" and *s*[2... 6] = "2 0 5 6 1".



#### tags 

#2000 #math #number_theory 