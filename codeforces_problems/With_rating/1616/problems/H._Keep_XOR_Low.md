<h1 style='text-align: center;'> H. Keep XOR Low</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$ and an integer $x$.

Find the number of non-empty subsets of indices of this array $1 \leq b_1 < b_2 < \ldots < b_k \leq n$, such that for all pairs $(i, j)$ where $1 \leq i < j \leq k$, the inequality $a_{b_i} \oplus a_{b_j} \leq x$ is held. Here, $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR). As the answer may be very large, output it modulo $998\,244\,353$.

##### Input

The first line of the input contains two integers $n$ and $x$ ($1 \leq n \leq 150\,000$, $0 \leq x < 2^{30}$). Here, $n$ is the size of the array.

The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i < 2^{30}$): the array itself.

##### Output

Print one integer: the number of non-empty subsets such that the bitwise XOR of every pair of elements is at most $x$, modulo $998\,244\,353$.

## Examples

##### Input


```text
4 2
0 1 2 3
```
##### Output


```text
8
```
##### Input


```text
3 6
4 2 2
```
##### Output


```text
7
```
##### Input


```text
4 0
1 1 2 2
```
##### Output


```text
6
```


#### Tags 

#3000 #NOT OK #bitmasks #combinatorics #data_structures #divide_and_conquer #dp #math 

## Blogs
- [All Contest Problems](../Good_Bye_2021:_2022_is_NEAR.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
