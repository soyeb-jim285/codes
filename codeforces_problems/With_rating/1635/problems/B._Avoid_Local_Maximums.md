<h1 style='text-align: center;'> B. Avoid Local Maximums</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of size $n$. Each element in this array is an integer between $1$ and $10^9$.

You can perform several operations to this array. During an operation, you can replace an element in the array with any integer between $1$ and $10^9$. 

### Output

 the minimum number of operations needed such that the resulting array doesn't contain any local maximums, and the resulting array after the operations.

An element $a_i$ is a local maximum if it is strictly larger than both of its neighbors (that is, $a_i > a_{i - 1}$ and $a_i > a_{i + 1}$). Since $a_1$ and $a_n$ have only one neighbor each, they will never be a local maximum.

### Input

Each test contains multiple test cases. The first line will contain a single integer $t$ $(1 \leq t \leq 10000)$ — the number of test cases. Then $t$ test cases follow.

The first line of each test case contains a single integer $n$ $(2 \leq n \leq 2 \cdot 10^5)$ — the size of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots ,a_n$ $(1 \leq a_i \leq 10^9)$, the elements of array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, first output a line containing a single integer $m$ — minimum number of operations required. Then ouput a line consist of $n$ integers — the resulting array after the operations. 
## Note

 that this array should differ in exactly $m$ elements from the initial array.

If there are multiple answers, print any.

## Example

### Input


```text
5
3
2 1 2
4
1 2 3 1
5
1 2 1 2 1
9
1 2 1 3 2 3 1 2 1
9
2 1 3 1 3 1 3 1 3
```
### Output


```text
0
2 1 2
1
1 3 3 1
1
1 2 2 2 1
2
1 2 3 3 2 3 3 2 1
2
2 1 3 3 3 1 1 1 3
```
## Note

In the first example, the array contains no local maximum, so we don't need to perform operations.

In the second example, we can change $a_2$ to $3$, then the array don't have local maximums.



#### Tags 

#800 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_772_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
