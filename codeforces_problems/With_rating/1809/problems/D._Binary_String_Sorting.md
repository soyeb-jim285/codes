<h1 style='text-align: center;'> D. Binary String Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$ consisting of only characters 0 and/or 1.

You can perform several operations on this string (possibly zero). There are two types of operations: 

* choose two consecutive elements and swap them. In order to perform this operation, you pay $10^{12}$ coins;
* choose any element from the string and remove it. In order to perform this operation, you pay $10^{12}+1$ coins.

Your task is to calculate the minimum number of coins required to sort the string $s$ in non-decreasing order (i. e. transform $s$ so that $s_1 \le s_2 \le \dots \le s_m$, where $m$ is the length of the string after applying all operations). An empty string is also considered sorted in non-decreasing order.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains the string $s$ ($1 \le |s| \le 3 \cdot 10^5$), consisting of only characters 0 and/or 1.

The sum of lengths of all given strings doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print a single integer — the minimum number of coins required to sort the string $s$ in non-decreasing order.

## Example

### Input


```text
61000010100101101100110111111
```
### Output

```text

1000000000001
0
1000000000000
2000000000001
2000000000002
0

```
## Note

In the first example, you have to remove the $1$-st element, so the string becomes equal to 00.

In the second example, the string is already sorted.

In the third example, you have to swap the $2$-nd and the $3$-rd elements, so the string becomes equal to 0011.

In the fourth example, you have to swap the $3$-rd and the $4$-th elements, so the string becomes equal to 00011101, and then remove the $7$-th element, so the string becomes equal to 0001111.

In the fifth example, you have to remove the $1$-st element, so the string becomes equal to 001101, and then remove the $5$-th element, so the string becomes equal to 00111.

In the sixth example, the string is already sorted.



#### Tags 

#1800 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_145_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
