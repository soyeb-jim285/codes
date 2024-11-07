<h1 style='text-align: center;'> C. Ehab and Prefix MEXs</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a$ of length $n$, find another array, $b$, of length $n$ such that:

* for each $i$ $(1 \le i \le n)$ $MEX(\{b_1$, $b_2$, $\ldots$, $b_i\})=a_i$.

The $MEX$ of a set of integers is the smallest non-negative integer that doesn't belong to this set.

If such array doesn't exist, determine this.

##### Input

The first line contains an integer $n$ ($1 \le n \le 10^5$) — the length of the array $a$.

The second line contains $n$ integers $a_1$, $a_2$, $\ldots$, $a_n$ ($0 \le a_i \le i$) — the elements of the array $a$. It's guaranteed that $a_i \le a_{i+1}$ for $1\le i < n$. 

##### Output

If there's no such array, print a single line containing $-1$.

Otherwise, print a single line containing $n$ integers $b_1$, $b_2$, $\ldots$, $b_n$ ($0 \le b_i \le 10^6$)

If there are multiple answers, print any.

## Examples

##### Input


```text
3
1 2 3
```
##### Output


```text
0 1 2 
```
##### Input

```text

4
0 0 0 2

```
##### Output


```text
1 3 4 0 
```
##### Input

```text

3
1 1 3

```
##### Output


```text

0 2 1 
```
## Note

In the second test case, other answers like $[1,1,1,0]$, for example, are valid.



#### Tags 

#1600 #NOT OK #brute_force #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_649_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
