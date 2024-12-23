<h1 style='text-align: center;'> E. Binary Key</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's assume that *p* and *q* are strings of positive length, called the container and the key correspondingly, string *q* only consists of characters 0 and 1. Let's take a look at a simple algorithm that extracts message *s* from the given container *p*:


```
  
i = 0;  
j = 0;  
s = <>;  
while i is less than the length of the string p  
{  
    if q[j] == 1, then add to the right of string s character p[i];  
    increase variables i, j by one;  
    if the value of the variable j equals the length of the string q, then j = 0;   
}  

```
In the given pseudocode *i*, *j* are integer variables, *s* is a string, '=' is an assignment operator, '==' is a comparison operation, '[]' is the operation of obtaining the string character with the preset index, '<>' is an empty string. We suppose that in all strings the characters are numbered starting from zero. 

We understand that implementing such algorithm is quite easy, so your task is going to be slightly different. You need to construct the lexicographically minimum key of length *k*, such that when it is used, the algorithm given above extracts message *s* from container *p* (otherwise find out that such key doesn't exist).

## Input

The first two lines of the input are non-empty strings *p* and *s* (1 ≤ |*p*| ≤ 106, 1 ≤ |*s*| ≤ 200), describing the container and the message, correspondingly. The strings can contain any characters with the ASCII codes from 32 to 126, inclusive.

The third line contains a single integer *k* (1 ≤ *k* ≤ 2000) — the key's length.

## Output

Print the required key (string of length *k*, consisting only of characters 0 and 1). If the key doesn't exist, print the single character 0.

## Examples

## Input


```
abacaba  
aba  
6  

```
## Output


```
100001  

```
## Input


```
abacaba  
aba  
3  

```
## Output


```
0  

```
## Note

String *x* = *x*1*x*2... *x**p* is lexicographically smaller than string *y* = *y*1*y*2... *y**q*, if either *p* < *q* and *x*1 = *y*1, *x*2 = *y*2, ... , *x**p* = *y**p*, or there exists such integer *r* (0 ≤ *r* < *min*(*p*, *q*)) that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 < *y**r* + 1. Symbols are compared according to their ASCII codes.



#### tags 

#2400 #dp #greedy #implementation 