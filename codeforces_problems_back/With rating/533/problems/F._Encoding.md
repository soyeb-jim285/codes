<h1 style='text-align: center;'> F. Encoding</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp invented a new way to encode strings. Let's assume that we have string *T*, consisting of lowercase English letters. Let's choose several pairs of letters of the English alphabet in such a way that each letter occurs in at most one pair. Then let's replace each letter in *T* with its pair letter if there is a pair letter for it. For example, if you chose pairs (l, r), (p, q) and (a, o), then word "parallelogram" according to the given encoding principle transforms to word "qolorreraglom".

Polycarpus already has two strings, *S* and *T*. He suspects that string *T* was obtained after applying the given encoding method from some substring of string *S*. Find all positions *m**i* in *S* (1 ≤ *m**i* ≤ |*S*| - |*T*| + 1), such that *T* can be obtained fro substring *S**m**i**S**m**i* + 1... *S**m**i* + |*T*| - 1 by applying the described encoding operation by using some set of pairs of English alphabet letters

## Input

The first line of the input contains two integers, |*S*| and |*T*| (1 ≤ |*T*| ≤ |*S*| ≤ 2·105) — the lengths of string *S* and string *T*, respectively.

The second and third line of the input contain strings *S* and *T*, respectively. Both strings consist only of lowercase English letters.

## Output

Print number *k* — the number of suitable positions in string *S*.

In the next line print *k* integers *m*1, *m*2, ..., *m**k* — the numbers of the suitable positions in the increasing order.

## Examples

## Input


```
11 5  
abacabadaba  
acaba  

```
## Output


```
3  
1 3 7  

```
## Input


```
21 13  
paraparallelogramgram  
qolorreraglom  

```
## Output


```
1  
5  

```


#### tags 

#2400 #hashing #string_suffix_structures #strings 