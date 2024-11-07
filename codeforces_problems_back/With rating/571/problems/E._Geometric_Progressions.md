<h1 style='text-align: center;'> E. Geometric Progressions</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Geometric progression with the first element *a* and common ratio *b* is a sequence of numbers *a*, *ab*, *ab*2, *ab*3, ....

You are given *n* integer geometric progressions. Your task is to find the smallest integer *x*, that is the element of all the given progressions, or else state that such integer does not exist.

## Input

The first line contains integer (1 ≤ *n* ≤ 100) — the number of geometric progressions. 

Next *n* lines contain pairs of integers *a*, *b* (1 ≤ *a*, *b* ≤ 109), that are the first element and the common ratio of the corresponding geometric progression.

## Output

If the intersection of all progressions is empty, then print  - 1, otherwise print the remainder of the minimal positive integer number belonging to all progressions modulo 1000000007 (109 + 7).

## Examples

## Input


```
2  
2 2  
4 1  

```
## Output


```
4  

```
## Input


```
2  
2 2  
3 3  

```
## Output


```
-1  

```
## Note

In the second sample test one of the progressions contains only powers of two, the other one contains only powers of three.



#### tags 

#3200 #math 