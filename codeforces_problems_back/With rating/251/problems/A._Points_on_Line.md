<h1 style='text-align: center;'> A. Points on Line</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Petya likes points a lot. Recently his mom has presented him *n* points lying on the line *OX*. Now Petya is wondering in how many ways he can choose three distinct points so that the distance between the two farthest of them doesn't exceed *d*.

## Note

 that the order of the points inside the group of three chosen points doesn't matter.

## Input

The first line contains two integers: *n* and *d* (1 ≤ *n* ≤ 105; 1 ≤ *d* ≤ 109). The next line contains *n* integers *x*1, *x*2, ..., *x**n*, their absolute value doesn't exceed 109 — the *x*-coordinates of the points that Petya has got.

It is guaranteed that the coordinates of the points in the input strictly increase.

## Output

Print a single integer — the number of groups of three points, where the distance between two farthest points doesn't exceed *d*.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
4 3  
1 2 3 4  

```
## Output


```
4  

```
## Input


```
4 2  
-3 -2 -1 0  

```
## Output


```
2  

```
## Input


```
5 19  
1 10 20 30 50  

```
## Output


```
1  

```
## Note

In the first sample any group of three points meets our conditions.

In the seconds sample only 2 groups of three points meet our conditions: {-3, -2, -1} and {-2, -1, 0}.

In the third sample only one group does: {1, 10, 20}.



#### tags 

#1300 #binary_search #combinatorics #two_pointers 