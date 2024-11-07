<h1 style='text-align: center;'> C. Marina and Vasya</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Marina loves strings of the same length and Vasya loves when there is a third string, different from them in exactly *t* characters. Help Vasya find at least one such string.

More formally, you are given two strings *s*1, *s*2 of length *n* and number *t*. Let's denote as *f*(*a*, *b*) the number of characters in which strings *a* and *b* are different. Then your task will be to find any string *s*3 of length *n*, such that *f*(*s*1, *s*3) = *f*(*s*2, *s*3) = *t*. If there is no such string, print  - 1.

## Input

The first line contains two integers *n* and *t* (1 ≤ *n* ≤ 105, 0 ≤ *t* ≤ *n*).

The second line contains string *s*1 of length *n*, consisting of lowercase English letters.

The third line contain string *s*2 of length *n*, consisting of lowercase English letters.

## Output

Print a string of length *n*, differing from string *s*1 and from *s*2 in exactly *t* characters. Your string should consist only from lowercase English letters. If such string doesn't exist, print -1.

## Examples

## Input


```
3 2  
abc  
xyc  

```
## Output


```
ayd
```
## Input


```
1 0  
c  
b  

```
## Output


```
-1  

```


#### tags 

#1700 #constructive_algorithms #greedy #strings 