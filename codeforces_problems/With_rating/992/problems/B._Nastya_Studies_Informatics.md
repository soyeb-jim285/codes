<h1 style='text-align: center;'> B. Nastya Studies Informatics</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Today on Informatics class Nastya learned about GCD and LCM (see links below). Nastya is very intelligent, so she solved all the tasks momentarily and now suggests you to solve one of them as well.

We define a pair of integers (*a*, *b*) good, if *GCD*(*a*, *b*) = *x* and *LCM*(*a*, *b*) = *y*, where *GCD*(*a*, *b*) denotes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of *a* and *b*, and *LCM*(*a*, *b*) denotes the [least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple) of *a* and *b*.

You are given two integers *x* and *y*. You are to find the number of good pairs of integers (*a*, *b*) such that *l* ≤ *a*, *b* ≤ *r*. 
## Note

 that pairs (*a*, *b*) and (*b*, *a*) are considered different if *a* ≠ *b*.

##### Input

The only line contains four integers *l*, *r*, *x*, *y* (1 ≤ *l* ≤ *r* ≤ 109, 1 ≤ *x* ≤ *y* ≤ 109).

##### Output

In the only line print the only integer — the answer for the problem.

## Examples

##### Input


```text
1 2 1 2  

```
##### Output


```text
2  

```
##### Input


```text
1 12 1 12  

```
##### Output


```text
4  

```
##### Input


```text
50 100 3 30  

```
##### Output


```text
0  

```
## Note

In the first example there are two suitable good pairs of integers (*a*, *b*): (1, 2) and (2, 1).

In the second example there are four suitable good pairs of integers (*a*, *b*): (1, 12), (12, 1), (3, 4) and (4, 3).

In the third example there are good pairs of integers, for example, (3, 30), but none of them fits the condition *l* ≤ *a*, *b* ≤ *r*.



#### Tags 

#1600 #NOT OK #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_489_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
