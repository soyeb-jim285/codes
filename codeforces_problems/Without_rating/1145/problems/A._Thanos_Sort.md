<h1 style='text-align: center;'> A. Thanos Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Thanos sort](https://codegolf.stackexchange.com/questions/182221/implement-the-thanos-sorting-algorithm) is a supervillain sorting algorithm, which works as follows: if the array is not sorted, snap your fingers* to remove the first or the second half of the items, and repeat the process.

Given an input array, what is the size of the longest sorted array you can obtain from it using Thanos sort?

*Infinity Gauntlet required.

##### Input

The first line of input contains a single number $n$ ($1 \le n \le 16$) — the size of the array. $n$ is guaranteed to be a power of 2.

The second line of input contains $n$ space-separated integers $a_i$ ($1 \le a_i \le 100$) — the elements of the array.

##### Output

Return the maximal length of a sorted array you can obtain using Thanos sort. The elements of the array have to be sorted in non-decreasing order.

## Examples

##### Input


```text
4
1 2 2 4
```
##### Output


```text
4
```
##### Input


```text
8
11 12 1 2 13 14 3 4
```
##### Output


```text
2
```
##### Input


```text
4
7 6 5 4
```
##### Output


```text
1
```
## Note

In the first example the array is already sorted, so no finger snaps are required.

In the second example the array actually has a subarray of 4 sorted elements, but you can not remove elements from different sides of the array in one finger snap. Each time you have to remove either the whole first half or the whole second half, so you'll have to snap your fingers twice to get to a 2-element sorted array.

In the third example the array is sorted in decreasing order, so you can only save one element from the ultimate destruction.



#### Tags 

#NOT OK #implementation 

## Blogs
- [All Contest Problems](../April_Fools_Day_Contest_2019.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
