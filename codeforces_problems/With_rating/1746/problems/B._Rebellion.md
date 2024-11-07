<h1 style='text-align: center;'> B. Rebellion</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ of size $n$ consisting only of zeroes and ones. You can do the following operation:

* choose two indices $1 \le i , j \le n$, $i \ne j$,
* add $a_{i}$ to $a_{j}$,
* remove $a_{i}$ from $a$.

## Note

 that elements of $a$ can become bigger than $1$ after performing some operations. Also note that $n$ becomes $1$ less after the operation.

What is the minimum number of operations needed to make $a$ non-decreasing, i. e. that each element is not less than the previous element?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 10^5$), the size of array $a$.

Next line contains $n$ integers $a_{1}, a_{2}, \ldots a_{n}$ ($a_i$ is $0$ or $1$), elements of array $a$.

It's guaranteed that sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case print a single integer, minimum number of operations needed to make $a$ non-decreasing.

## Example

### Input


```text
480 0 1 1 1 1 1 151 0 0 1 121 0111 1 0 0 1 0 0 1 1 1 0
```
### Output

```text

0
1
1
3

```
## Note

In the first test case, $a$ is already non-decreasing, so you don't need to do any operations and the answer is $0$.

In the second test case, you can perform an operation for $i = 1$ and $j = 5$, so $a$ will be equal to $[0, 0, 1, 2]$ and it becomes non-decreasing.

In the third test case, you can perform an operation for $i = 2$ and $j = 1$, so $a$ will be equal to $[1]$ and it becomes non-decreasing.



#### Tags 

#800 #OK #constructive_algorithms #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_23.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
