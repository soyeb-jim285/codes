<h1 style='text-align: center;'> C. Representative Edges</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array $a_1, a_2, \ldots, a_n$ is good if and only if for every subsegment $1 \leq l \leq r \leq n$, the following holds: $a_l + a_{l + 1} + \ldots + a_r = \frac{1}{2}(a_l + a_r) \cdot (r - l + 1)$. 

You are given an array of integers $a_1, a_2, \ldots, a_n$. In one operation, you can replace any one element of this array with any real number. Find the minimum number of operations you need to make this array good.

### Input

The first line of input contains one integer $t$ ($1 \leq t \leq 100$): the number of test cases.

Each of the next $t$ lines contains the description of a test case.

In the first line you are given one integer $n$ ($1 \leq n \leq 70$): the number of integers in the array.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-100 \leq a_i \leq 100$): the initial array.

### Output

For each test case, print one integer: the minimum number of elements that you need to replace to make the given array good.

## Example

### Input


```text
5
4
1 2 3 4
4
1 1 2 2
2
0 -1
6
3 -2 4 -1 -4 0
1
-100
```
### Output


```text
0
2
0
3
0
```
## Note

In the first test case, the array is good already.

In the second test case, one of the possible good arrays is $[1, 1, \underline{1}, \underline{1}]$ (replaced elements are underlined).

In the third test case, the array is good already.

In the fourth test case, one of the possible good arrays is $[\underline{-2.5}, -2, \underline{-1.5}, -1, \underline{-0.5}, 0]$.



#### Tags 

#1500 #NOT OK #brute_force #geometry #implementation #math 

## Blogs
- [All Contest Problems](../Good_Bye_2021:_2022_is_NEAR.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
