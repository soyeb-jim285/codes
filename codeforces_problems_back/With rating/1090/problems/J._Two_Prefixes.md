<h1 style='text-align: center;'> J. Two Prefixes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Misha didn't do his math homework for today's lesson once again. As a punishment, his teacher Dr. Andrew decided to give him a hard, but very useless task.

Dr. Andrew has written two strings *s* and *t* of lowercase English letters at the blackboard. He reminded Misha that prefix of a string is a string formed by removing several (possibly none) of its last characters, and a concatenation of two strings is a string formed by appending the second string to the right of the first string.

The teacher asked Misha to write down on the blackboard all strings that are the concatenations of some non-empty prefix of *s* and some non-empty prefix of *t*. When Misha did it, Dr. Andrew asked him how many distinct strings are there. Misha spent almost the entire lesson doing that and completed the task. 

Now he asks you to write a program that would do this task automatically.

## Input

The first line contains the string *s* consisting of lowercase English letters. The second line contains the string *t* consisting of lowercase English letters.

The lengths of both string do not exceed 105.

## Output

## Output

 a single integer — the number of distinct strings that are concatenations of some non-empty prefix of *s* with some non-empty prefix of *t*.

## Examples

## Input


```
aba  
aa  

```
## Output


```
5  

```
## Input


```
aaaaa  
aaaa  

```
## Output


```
8  

```
## Note

In the first example, the string *s* has three non-empty prefixes: {a, ab, aba}. The string *t* has two non-empty prefixes: {a, aa}. In total, Misha has written five distinct strings: {aa, aaa, aba, abaa, abaaa}. The string abaa has been written twice.

In the second example, Misha has written eight distinct strings: {aa, aaa, aaaa, aaaaa, aaaaaa, aaaaaaa, aaaaaaaa, aaaaaaaaa}.



#### tags 

#2600 #strings 