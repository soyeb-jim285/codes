<h1 style='text-align: center;'> D. Count the Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Your task is to calculate the number of arrays such that:

* each array contains $n$ elements;
* each element is an integer from $1$ to $m$;
* for each array, there is exactly one pair of equal elements;
* for each array $a$, there exists an index $i$ such that the array is strictly ascending before the $i$-th element and strictly descending after it (formally, it means that $a_j < a_{j + 1}$, if $j < i$, and $a_j > a_{j + 1}$, if $j \ge i$).
###### Input

The first line contains two integers $n$ and $m$ ($2 \le n \le m \le 2 \cdot 10^5$).

###### Output

Print one integer — the number of arrays that meet all of the aforementioned conditions, taken modulo $998244353$.

## Examples

###### Input


```text
3 4
```
###### Output


```text
6
```
###### Input


```text
3 5
```
###### Output


```text
10
```
###### Input


```text
42 1337
```
###### Output


```text
806066790
```
###### Input


```text
100000 200000
```
###### Output


```text
707899035
```
## Note

The arrays in the first example are:

* $[1, 2, 1]$;
* $[1, 3, 1]$;
* $[1, 4, 1]$;
* $[2, 3, 2]$;
* $[2, 4, 2]$;
* $[3, 4, 3]$.


#### Tags 

#1700 #NOT OK #combinatorics #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_83_(Rated_for_Div._2).md)
- [Tutorial](../blogs/Tutorial.md)
