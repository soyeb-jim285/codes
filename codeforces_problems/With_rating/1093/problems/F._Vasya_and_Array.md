<h1 style='text-align: center;'> F. Vasya and Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Vasya has got an array consisting of $n$ integers, and two integers $k$ and $len$ in addition. All numbers in the array are either between $1$ and $k$ (inclusive), or equal to $-1$. The array is good if there is no segment of $len$ consecutive equal numbers.

Vasya will replace each $-1$ with some number from $1$ to $k$ (inclusive) in such a way that the resulting array is good. Tell him the number of ways to do this replacement. Since the answer may be large, print it modulo $998244353$.

##### Input

The first line contains three integers $n, k$ and $len$ ($1 \le n \le 10^5, 1 \le k \le 100, 1 \le len \le n$).

The second line contains $n$ numbers — the array. Each number is either $-1$ or between $1$ and $k$ (inclusive).

##### Output

Print one integer — the number of ways to replace each $-1$ with some number from $1$ to $k$ (inclusive) so the array is good. The answer may be large, so print it modulo $998244353$.

## Examples

##### Input


```text
5 2 3
1 -1 1 -1 2
```
##### Output


```text
2
```
##### Input


```text
6 3 2
1 1 -1 -1 -1 -1
```
##### Output


```text
0
```
##### Input


```text
10 42 7
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
```
##### Output


```text
645711643
```
## Note

Possible answers in the first test: 

1. $[1, 2, 1, 1, 2]$;
2. $[1, 2, 1, 2, 2]$.

There is no way to make the array good in the second test, since first two elements are equal.

There are too many answers in the third test, so we won't describe any of them.



#### Tags 

#2400 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_56_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
