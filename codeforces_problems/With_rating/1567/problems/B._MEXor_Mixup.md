<h1 style='text-align: center;'> B. MEXor Mixup</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice gave Bob two integers $a$ and $b$ ($a > 0$ and $b \ge 0$). Being a curious boy, Bob wrote down an array of non-negative integers with $\operatorname{MEX}$ value of all elements equal to $a$ and $\operatorname{XOR}$ value of all elements equal to $b$.

What is the shortest possible length of the array Bob wrote?

Recall that the $\operatorname{MEX}$ ([Minimum EXcluded](https://en.wikipedia.org/wiki/Mex_(mathematics))) of an array is the minimum non-negative integer that does not belong to the array and the $\operatorname{XOR}$ of an array is the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all the elements of the array.

### Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 5 \cdot 10^4$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $a$ and $b$ ($1 \leq a \leq 3 \cdot 10^5$; $0 \leq b \leq 3 \cdot 10^5$) — the $\operatorname{MEX}$ and $\operatorname{XOR}$ of the array, respectively.

### Output

For each test case, output one (positive) integer — the length of the shortest array with $\operatorname{MEX}$ $a$ and $\operatorname{XOR}$ $b$. We can show that such an array always exists.

## Example

### Input


```text
5
1 1
2 1
2 0
1 10000
2 10000
```
### Output


```text
3
2
3
2
3
```
## Note

In the first test case, one of the shortest arrays with $\operatorname{MEX}$ $1$ and $\operatorname{XOR}$ $1$ is $[0, 2020, 2021]$.

In the second test case, one of the shortest arrays with $\operatorname{MEX}$ $2$ and $\operatorname{XOR}$ $1$ is $[0, 1]$.

It can be shown that these arrays are the shortest arrays possible.



#### Tags 

#1000 #NOT OK #bitmasks #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_742_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
