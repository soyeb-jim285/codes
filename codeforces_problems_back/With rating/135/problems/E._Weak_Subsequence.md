<h1 style='text-align: center;'> E. Weak Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Petya very much likes strings. Recently he has received a voucher to purchase a string as a gift from his mother. The string can be bought in the local shop. One can consider that the shop has all sorts of strings over the alphabet of fixed size. The size of the alphabet is equal to *k*. However, the voucher has a string type limitation: specifically, the voucher can be used to purchase string *s* if the length of string's longest substring that is also its weak subsequence (see the definition given below) equals *w*.

String *a* with the length of *n* is considered the weak subsequence of the string *s* with the length of *m*, if there exists such a set of indexes 1 ≤ *i*1 < *i*2 < ... < *i**n* ≤ *m*, that has the following two properties: 

* *a**k* = *s**i**k* for all *k* from 1 to *n*;
* there exists at least one such *k* (1 ≤ *k* < *n*), for which *i**k* + 1 – *i**k* > 1.

Petya got interested how many different strings are available for him to purchase in the shop. As the number of strings can be very large, please find it modulo 1000000007 (109 + 7). If there are infinitely many such strings, print "-1".

## Input

The first line contains two integers *k* (1 ≤ *k* ≤ 106) and *w* (2 ≤ *w* ≤ 109) — the alphabet size and the required length of the maximum substring that also is the weak subsequence, correspondingly.

## Output

Print a single number — the number of strings Petya can buy using the voucher, modulo 1000000007 (109 + 7). If there are infinitely many such strings, print "-1" (without the quotes).

## Examples

## Input


```
2 2  

```
## Output


```
10  

```
## Input


```
3 5  

```
## Output


```
1593  

```
## Input


```
2 139  

```
## Output


```
717248223  

```
## Note

In the first sample Petya can buy the following strings: aaa, aab, abab, abb, abba, baa, baab, baba, bba, bbb.



#### tags 

#3000 #combinatorics 