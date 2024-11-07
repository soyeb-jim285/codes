<h1 style='text-align: center;'> G. Even-Odd XOR</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an integer $n$, find any array $a$ of $n$ distinct nonnegative integers less than $2^{31}$ such that the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of the elements on odd indices equals the bitwise XOR of the elements on even indices.

### Input

The first line of the input contains an integer $t$ ($1 \leq t \leq 629$) — the number of test cases.

Then $t$ lines follow, each containing a single integer $n$ $(3 \leq n \leq 2\cdot10^5)$ — the length of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, output one line containing $n$ distinct integers that satisfy the conditions.

If there are multiple answers, you can output any of them.

## Example

### Input


```text
7
8
3
4
5
6
7
9
```
### Output


```text

4 2 1 5 0 6 7 3
2 1 3
2 1 3 0
2 0 4 5 3
4 1 2 12 3 8
1 2 3 4 5 6 7
8 2 3 7 4 0 5 6 9
```
## Note

In the first test case the XOR on odd indices is $4 \oplus 1 \oplus 0 \oplus 7 = 2$ and the XOR on even indices is $2 \oplus 5 \oplus 6 \oplus 3= 2$.



#### Tags 

#1500 #OK #bitmasks #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_817_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
