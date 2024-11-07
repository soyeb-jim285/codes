<h1 style='text-align: center;'> A. Transformation: from A to B</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasily has a number *a*, which he wants to turn into a number *b*. For this purpose, he can do two types of operations:

* multiply the current number by 2 (that is, replace the number *x* by 2·*x*);
* append the digit 1 to the right of current number (that is, replace the number *x* by 10·*x* + 1).

You need to help Vasily to transform the number *a* into the number *b* using only the operations described above, or find that it is impossible.

Note that in this task you are not required to minimize the number of operations. It suffices to find any way to transform *a* into *b*.

## Input

The first line contains two positive integers *a* and *b* (1 ≤ *a* < *b* ≤ 109) — the number which Vasily has and the number he wants to have.

## Output

If there is no way to get *b* from *a*, print "NO" (without quotes).

Otherwise print three lines. On the first line print "YES" (without quotes). The second line should contain single integer *k* — the length of the transformation sequence. On the third line print the sequence of transformations *x*1, *x*2, ..., *x**k*, where:

* *x*1 should be equal to *a*,
* *x**k* should be equal to *b*,
* *x**i* should be obtained from *x**i* - 1 using any of two described operations (1 < *i* ≤ *k*).

If there are multiple answers, print any of them.

## Examples

## Input


```
2 162  

```
## Output


```
YES  
5  
2 4 8 81 162   

```
## Input


```
4 42  

```
## Output


```
NO  

```
## Input


```
100 40021  

```
## Output


```
YES  
5  
100 200 2001 4002 40021   

```


#### tags 

#1000 #brute_force #dfs_and_similar #math 