<h1 style='text-align: center;'> E. Maximum Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array *a* consisting of *n* integers, and additionally an integer *m*. You have to choose some sequence of indices *b*1, *b*2, ..., *b**k* (1 ≤ *b*1 < *b*2 < ... < *b**k* ≤ *n*) in such a way that the value of ![](images/b62c0a7977dc1ab5f3cef631b6eb630ef6d7b8b3.png) is maximized. Chosen sequence can be empty.

Print the maximum possible value of ![](images/b62c0a7977dc1ab5f3cef631b6eb630ef6d7b8b3.png).

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 35, 1 ≤ *m* ≤ 109).

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

## Output

Print the maximum possible value of ![](images/b62c0a7977dc1ab5f3cef631b6eb630ef6d7b8b3.png).

## Examples

## Input


```
4 4  
5 2 4 1  

```
## Output


```
3  

```
## Input


```
3 20  
199 41 299  

```
## Output


```
19  

```
## Note

In the first example you can choose a sequence *b* = {1, 2}, so the sum ![](images/c856546022c2feee13d02a4ec9cd1d361ab3a756.png) is equal to 7 (and that's 3 after taking it modulo 4).

In the second example you can choose a sequence *b* = {3}.



#### tags 

#1800 #bitmasks #divide_and_conquer #meet-in-the-middle 