<h1 style='text-align: center;'> B. Little Pony and Sort by Shift</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day, Twilight Sparkle is interested in how to sort a sequence of integers *a*1, *a*2, ..., *a**n* in non-decreasing order. Being a young unicorn, the only operation she can perform is a unit shift. That is, she can move the last element of the sequence to its beginning:

*a*1, *a*2, ..., *a**n* → *a**n*, *a*1, *a*2, ..., *a**n* - 1. Help Twilight Sparkle to calculate: what is the minimum number of operations that she needs to sort the sequence?

## Input

The first line contains an integer *n* (2 ≤ *n* ≤ 105). The second line contains *n* integer numbers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105).

## Output

If it's impossible to sort the sequence output -1. Otherwise output the minimum number of operations Twilight Sparkle needs to sort it.

## Examples

## Input


```
2  
2 1  

```
## Output


```
1  

```
## Input


```
3  
1 3 2  

```
## Output


```
-1  

```
## Input


```
2  
1 2  

```
## Output


```
0  

```


#### tags 

#1200 #implementation 