<h1 style='text-align: center;'> A. Vitaly and Strings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vitaly is a diligent student who never missed a lesson in his five years of studying in the university. He always does his homework on time and passes his exams in time. 

During the last lesson the teacher has provided two strings *s* and *t* to Vitaly. The strings have the same length, they consist of lowercase English letters, string *s* is lexicographically smaller than string *t*. Vitaly wondered if there is such string that is lexicographically larger than string *s* and at the same is lexicographically smaller than string *t*. This string should also consist of lowercase English letters and have the length equal to the lengths of strings *s* and *t*. 

Let's help Vitaly solve this easy problem!

## Input

The first line contains string *s* (1 ≤ |*s*| ≤ 100), consisting of lowercase English letters. Here, |*s*| denotes the length of the string.

The second line contains string *t* (|*t*| = |*s*|), consisting of lowercase English letters.

It is guaranteed that the lengths of strings *s* and *t* are the same and string *s* is lexicographically less than string *t*.

## Output

If the string that meets the given requirements doesn't exist, print a single string "No such string" (without the quotes).

If such string exists, print it. If there are multiple valid strings, you may print any of them.

## Examples

## Input


```
a  
c  

```
## Output


```
b  

```
## Input


```
aaa  
zzz  

```
## Output


```
kkk  

```
## Input


```
abcdefg  
abcdefh  

```
## Output


```
No such string  

```
## Note

String *s* = *s*1*s*2... *s**n* is said to be lexicographically smaller than *t* = *t*1*t*2... *t**n*, if there exists such *i*, that *s*1 = *t*1, *s*2 = *t*2, ... *s**i* - 1 = *t**i* - 1, *s**i* < *t**i*.



#### tags 

#1600 #constructive_algorithms #strings 