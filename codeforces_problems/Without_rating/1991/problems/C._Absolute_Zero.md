<h1 style='text-align: center;'> C. Absolute Zero</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers.

In one operation, you will perform the following two-step move: 

1. Choose an integer $x$ ($0 \le x \le 10^{9}$).
2. Replace each $a_i$ with $|a_i - x|$, where $|v|$ denotes the [absolute value](https://en.wikipedia.org/wiki/Absolute_value) of $v$.

For example, by choosing $x = 8$, the array $[5, 7, 10]$ will be changed into $[|5-8|, |7-8|, |10-8|] = [3,1,2]$.

Construct a sequence of operations to make all elements of $a$ equal to $0$ in at most $40$ operations or determine that it is impossible. You do not need to minimize the number of operations.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer $-1$ if it is impossible to make all array elements equal to $0$ in at most $40$ operations.

Otherwise, output two lines. The first line of output should contain a single integer $k$ ($0 \le k \le 40$) — the number of operations. The second line of output should contain $k$ integers $x_1, x_2, \ldots, x_k$ ($0 \le x_i \le 10^{9}$) — the sequence of operations, denoting that on the $i$-th operation, you chose $x=x_i$.

If there are multiple solutions, output any of them.

You do not need to minimize the number of operations.

## Example

### Input


```text
51520 034 6 8480 40 20 1051 2 3 4 5
```
### Output

```text

1
5
0

3
6 1 1
7
60 40 20 10 30 25 5
-1
```
## Note

In the first test case, we can perform only one operation by choosing $x = 5$, changing the array from $[5]$ to $[0]$.

In the second test case, no operations are needed because all elements of the array are already $0$.

In the third test case, we can choose $x = 6$ to change the array from $[4, 6, 8]$ to $[2, 0, 2]$, then choose $x = 1$ to change it to $[1, 1, 1]$, and finally choose $x = 1$ again to change the array into $[0, 0, 0]$.

In the fourth test case, we can make all elements $0$ by following the operation sequence $(60, 40, 20, 10, 30, 25, 5)$.

In the fifth test case, it can be shown that it is impossible to make all elements $0$ in at most $40$ operations. Therefore, the output is $-1$.



#### Tags 

#NOT OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Pinely_Round_4_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
