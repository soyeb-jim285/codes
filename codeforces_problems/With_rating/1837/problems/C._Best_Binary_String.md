<h1 style='text-align: center;'> C. Best Binary String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of the characters 0, 1 and/or ?. Let's call it a pattern.

Let's say that the binary string (a string where each character is either 0 or 1) matches the pattern if you can replace each character ? with 0 or 1 (for each character, the choice is independent) so that the strings become equal. For example, 0010 matches ?01?, but 010 doesn't match 1??, ??, or ????.

Let's define the cost of the binary string as the minimum number of operations of the form "reverse an arbitrary contiguous substring of the string" required to sort the string in non-descending order.

You have to find a binary string with the minimum possible cost among those that match the given pattern. If there are multiple answers, print any of them.

### Input

The first line contains a single integer $t$ ($1 \le t \le 3 \cdot 10^4$) — the number of test cases.

The first and only line of each test case contains the string $s$ ($1 \le |s| \le 3 \cdot 10^5$) consisting of characters 0, 1, and/or ?.

The sum of the string lengths over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, print a binary string with the minimum possible cost among those that match the given pattern. If there are multiple answers, print any of them.

## Example

### Input


```text
4??01?101001??10?0?1?10?10
```
### Output

```text

00011
10100
111101
011110010

```
## Note

In the first test case of the example, the cost of the resulting string is $0$.

In the second test case, the cost of the resulting string is $2$: we can reverse the substring from the $1$-st character to the $5$-th character, and we obtain the string 00101. Then we reverse the substring from the $3$-rd to the $4$-th character, and we obtain the string 00011, which is sorted in non-descending order.



#### Tags 

#1000 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_149_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
