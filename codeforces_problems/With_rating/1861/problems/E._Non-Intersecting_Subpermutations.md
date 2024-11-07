<h1 style='text-align: center;'> E. Non-Intersecting Subpermutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given two integers $n$ and $k$.

For an array of length $n$, let's define its cost as the maximum number of contiguous subarrays of this array that can be chosen so that: 

* each element belongs to at most one subarray;
* the length of each subarray is exactly $k$;
* each subarray contains each integer from $1$ to $k$ exactly once.

For example, if $n = 10$, $k = 3$ and the array is $[1, 2, 1, 3, 2, 3, 2, 3, 1, 3]$, its cost is $2$ because, for example, we can choose the subarrays from the $2$-nd element to the $4$-th element and from the $7$-th element to the $9$-th element, and we can show that it's impossible to choose more than $2$ subarrays.

Calculate the sum of costs over all arrays of length $n$ consisting of integers from $1$ to $k$, and print it modulo $998244353$.

##### Input

The only line of the input contains two integers $n$ and $k$ ($2 \le k \le n \le 4000$).

##### Output

Print one integer — the sum of costs of all arrays of length $n$ consisting of integers from $1$ to $k$ taken modulo $998244353$.

## Examples

##### Input


```text
10 3
```
##### Output


```text
71712
```
##### Input


```text
2 2
```
##### Output


```text
2
```
##### Input


```text
1337 42
```
##### Output


```text
524933698
```


#### Tags 

#2300 #NOT OK #combinatorics #dp #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_154_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
