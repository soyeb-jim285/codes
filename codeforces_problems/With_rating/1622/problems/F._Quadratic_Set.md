<h1 style='text-align: center;'> F. Quadratic Set</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a set of positive integers $a_1, a_2, \dots, a_k$ quadratic if the product of the factorials of its elements is a square of an integer, i. e. $\prod\limits_{i=1}^{k} a_i! = m^2$, for some integer $m$.

You are given a positive integer $n$.

Your task is to find a quadratic subset of a set $1, 2, \dots, n$ of maximum size. If there are multiple answers, print any of them.

###### Input

A single line contains a single integer $n$ ($1 \le n \le 10^6$).

###### Output

In the first line, print a single integer — the size of the maximum subset. In the second line, print the subset itself in an arbitrary order.

## Examples

###### Input


```text
1
```
###### Output


```text
1
1 
```
###### Input


```text
4
```
###### Output


```text
3
1 3 4 
```
###### Input


```text
7
```
###### Output


```text
4
1 4 5 6 
```
###### Input


```text
9
```
###### Output


```text
7
1 2 4 5 6 7 9 
```


#### Tags 

#2900 #NOT OK #constructive_algorithms #hashing #math #number_theory 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_120_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
