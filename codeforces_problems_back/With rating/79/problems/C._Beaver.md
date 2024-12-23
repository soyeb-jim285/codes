<h1 style='text-align: center;'> C. Beaver</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After Fox Ciel got off a bus, she found that the bus she was on was a wrong bus and she lost her way in a strange town. However, she fortunately met her friend Beaver Taro and asked which way to go to her castle. Taro's response to her was a string *s*, and she tried to remember the string *s* correctly.

However, Ciel feels *n* strings *b*1, *b*2, ... , *b**n* are really boring, and unfortunately she dislikes to remember a string that contains a boring substring. To make the thing worse, what she can remember is only the contiguous substring of *s*.

Determine the longest contiguous substring of *s* that does not contain any boring string, so that she can remember the longest part of Taro's response.

## Input

In the first line there is a string *s*. The length of *s* will be between 1 and 105, inclusive.

In the second line there is a single integer *n* (1 ≤ *n* ≤ 10). Next *n* lines, there is a string *b**i* (1 ≤ *i* ≤ *n*). Each length of *b**i* will be between 1 and 10, inclusive.

Each character of the given strings will be either a English alphabet (both lowercase and uppercase) or a underscore ('_') or a digit. Assume that these strings are case-sensitive.

## Output

## Output

 in the first line two space-separated integers *len* and *pos*: the length of the longest contiguous substring of *s* that does not contain any *b**i*, and the first position of the substring (0-indexed). The position *pos* must be between 0 and |*s*| - *len* inclusive, where |*s*| is the length of string *s*.

If there are several solutions, output any.

## Examples

## Input


```
Go_straight_along_this_street  
5  
str  
long  
tree  
biginteger  
ellipse  

```
## Output


```
12 4  

```
## Input


```
IhaveNoIdea  
9  
I  
h  
a  
v  
e  
N  
o  
I  
d  

```
## Output


```
0 0  

```
## Input


```
unagioisii  
2  
ioi  
unagi  

```
## Output


```
5 5  

```
## Note

In the first sample, the solution is traight_alon.

In the second sample, the solution is an empty string, so the output can be «0 0», «0 1», «0 2», and so on.

In the third sample, the solution is either nagio or oisii.



#### tags 

#1800 #data_structures #dp #greedy #hashing #strings #two_pointers 