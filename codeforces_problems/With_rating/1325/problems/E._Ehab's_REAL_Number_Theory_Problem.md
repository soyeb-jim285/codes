<h1 style='text-align: center;'> E. Ehab's REAL Number Theory Problem</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$ that has a special condition: every element in this array has at most 7 divisors. Find the length of the shortest non-empty subsequence of this array product of whose elements is a perfect square.

A sequence $a$ is a subsequence of an array $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) elements.

###### Input

The first line contains an integer $n$ ($1 \le n \le 10^5$) — the length of $a$.

The second line contains $n$ integers $a_1$, $a_2$, $\ldots$, $a_{n}$ ($1 \le a_i \le 10^6$) — the elements of the array $a$.

###### Output

###### Output

 the length of the shortest non-empty subsequence of $a$ product of whose elements is a perfect square. If there are several shortest subsequences, you can find any of them. If there's no such subsequence, print "-1".

## Examples

###### Input


```text
3
1 4 6
```
###### Output


```text
1
```
###### Input

```text

4
2 3 6 6

```
###### Output


```text
2
```
###### Input

```text

3
6 15 10

```
###### Output


```text
3
```
###### Input

```text

4
2 3 5 7

```
###### Output


```text

-1
```
## Note

In the first sample, you can choose a subsequence $[1]$.

In the second sample, you can choose a subsequence $[6, 6]$.

In the third sample, you can choose a subsequence $[6, 15, 10]$.

In the fourth sample, there is no such subsequence.



#### Tags 

#2600 #NOT OK #brute_force #dfs_and_similar #graphs #number_theory #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_628_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
