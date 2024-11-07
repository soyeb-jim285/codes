<h1 style='text-align: center;'> F. Madoka and Laziness</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Madoka has become too lazy to write a legend, so let's go straight to the formal description of the problem.

An array of integers $a_1, a_2, \ldots, a_n$ is called a hill if it is not empty and there is an index $i$ in it, for which the following is true: $a_1 < a_2 < \ldots < a_i > a_{i + 1} > a_{i + 2} > \ldots > a_n$.

A sequence $x$ is a subsequence of a sequence $y$ if $x$ can be obtained from $y$ by deletion of several (possibly, zero or all) elements keeping the order of the other elements. For example, for an array $[69, 1000, 228, -7]$ the array $[1000, -7]$ is a subsequence, while $[1]$ and $[-7, 1000]$ are not.

Splitting an array into two subsequences is called good if each element belongs to exactly one subsequence, and also each of these subsequences is a hill.

You are given an array of distinct positive integers $a_1, a_2, \ldots a_n$. It is required to find the number of different pairs of maxima of the first and second subsequences among all good splits. Two pairs that only differ in the order of elements are considered same.

###### Input

The first line of input contains a single integer $n$ ($2 \le n \le 5 \cdot 10^5$) — array size.

The second line of input contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array. It is guaranteed that all $a_i$ are pairwise distinct.

###### Output

In a single line, print exactly one number — the number of different pairs of maxima of the first and second subsequences among all good splits.

## Examples

###### Input


```text
4
1 2 4 3
```
###### Output


```text
3
```
###### Input


```text
8
2 12 13 7 14 6 11 8
```
###### Output


```text
4
```
###### Input


```text
7
9 5 3 10 2 6 8
```
###### Output


```text
0
```
###### Input


```text
8
8 6 10 9 1 5 2 14
```
###### Output


```text
0
```
## Note

In the first test case there are 3 possible pairs: $(3, 4)$, $(2, 4)$, $(1, 4)$. And they are achieved with the following partitions: $[1, 2, 3], [4]$; $[4, 3], [1, 2]$; $[1], [2, 4, 3]$



#### Tags 

#3100 #NOT OK #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_777_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
