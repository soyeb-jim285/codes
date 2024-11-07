<h1 style='text-align: center;'> G. Almost Increasing Array</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

We call an array almost increasing if we can erase not more than one element from it so that the array becomes strictly increasing (that is, every element is striclty greater than every element before it).

You are given an array *a* consisting of *n* elements. You are allowed to replace any element with any integer number (and you may do so any number of times you need). What is the minimum number of replacements you have to perform in order to make the array almost increasing?

## Input

The first line contains one integer *n* (2 ≤ *n* ≤ 200000) — the number of elements in *a*.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109) — the array *a*.

## Output

Print the minimum number of replaces you have to perform so that *a* is almost increasing.

## Examples

## Input


```
5  
5 4 3 2 1  

```
## Output


```
3  

```
## Input


```
5  
1 2 8 9 5  

```
## Output


```
0  

```


#### tags 

#2500 #data_structures #dp 