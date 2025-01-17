<h1 style='text-align: center;'> E. Hellish Constraints</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Katya recently started to invent programming tasks and prepare her own contests. What she does not like is boring and simple constraints. Katya is fed up with all those "*N* does not exceed a thousand" and "the sum of *a**i* does not exceed a million" and she decided to come up with something a little more complicated.

The last problem written by Katya deals with strings. The input is a string of small Latin letters. To make the statement longer and strike terror into the people who will solve the contest, Katya came up with the following set of *k* restrictions of the same type (characters in restrictions can be repeated and some restrictions may contradict each other): 

* The number of characters *c*1 in a string is not less than *l*1 and not more than *r*1.
* ...
* The number of characters *c**i* in a string is not less than *l**i* and not more than *r**i*.
* ...
* The number of characters *c**k* in a string is not less than *l**k* and not more than *r**k*.

However, having decided that it is too simple and obvious, Katya added the following condition: a string meets no less than *L* and not more than *R* constraints from the above given list.

Katya does not like to compose difficult and mean tests, so she just took a big string *s* and wants to add to the tests all its substrings that meet the constraints. However, Katya got lost in her conditions and asked you to count the number of substrings of the string *s* that meet the conditions (each occurrence of the substring is counted separately).

## Input

The first line contains a non-empty string *s*, consisting of small Latin letters. The length of the string *s* does not exceed 105.

The second line contains three space-separated integers *k*, *L* and *R* (0 ≤ *L* ≤ *R* ≤ *k* ≤ 500).

Next *k* lines contain Katya's constrictions in the following form "*c**i* *l**i* *r**i*". All letters *c**i* are small Latin letters, *l**i* and *r**i* are integers (0 ≤ *l**i* ≤ *r**i* ≤ |*s*|, where |*s*| is the length of string *s*). Letters *c**i* are not necessarily different.

## Output

Print a single number — the number of substrings that meet the constrictions.

Please do not use the %lld specificator to read or write 64-bit integers in С++. It is preferred to use the cout stream or the %I64d specificator.

## Examples

## Input


```
codeforces  
2 0 0  
o 1 2  
e 1 2  

```
## Output


```
7  

```
## Input


```
codeforces  
2 1 1  
o 1 2  
o 1 2  

```
## Output


```
0  

```
## Note

In the first test we should count the number of strings that do not contain characters "e" and "o". All such strings are as follows (in the order of occurrence in the initial string from the left to the right): "c", "d"', "f", "r", "rc", "c", "s".

In the second test we cannot achieve fulfilling exactly one of the two identical constrictions, so the answer is 0.



#### tags 

#2900 #brute_force #dp #two_pointers 