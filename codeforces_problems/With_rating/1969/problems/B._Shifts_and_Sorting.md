<h1 style='text-align: center;'> B. Shifts and Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's define a cyclic shift of some string $s$ as a transformation from $s_1 s_2 \dots s_{n-1} s_{n}$ into $s_{n} s_1 s_2 \dots s_{n-1}$. In other words, you take one last character $s_n$ and place it before the first character while moving all other characters to the right.

You are given a binary string $s$ (a string consisting of only 0-s and/or 1-s).

In one operation, you can choose any substring $s_l s_{l+1} \dots s_r$ ($1 \le l < r \le |s|$) and cyclically shift it. The cost of such operation is equal to $r - l + 1$ (or the length of the chosen substring).

You can perform the given operation any number of times. What is the minimum total cost to make $s$ sorted in non-descending order?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first and only line of each test case contains a binary string $s$ ($2 \le |s| \le 2 \cdot 10^5$; $s_i \in$ {0, 1}) — the string you need to sort.

Additional constraint on the input: the sum of lengths of strings over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print the single integer — the minimum total cost to make string sorted using operation above any number of times.

## Example

### Input


```text
51000001100010101101101001
```
### Output

```text

2
0
9
5
11

```
## Note

In the first test case, you can choose the whole string and perform a cyclic shift: 10 $\rightarrow$ 01. The length of the substring is $2$, so the cost is $2$.

In the second test case, the string is already sorted, so you don't need to perform any operations.

In the third test case, one of the optimal strategies is the next: 

1. choose substring $[1, 3]$: 11000 $\rightarrow$ 01100;
2. choose substring $[2, 4]$: 01100 $\rightarrow$ 00110;
3. choose substring $[3, 5]$: 00110 $\rightarrow$ 00011.

 The total cost is $3 + 3 + 3 = 9$.

#### Tags 

#1000 #OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_165_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
